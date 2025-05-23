class TerritoryHQ: ItemBase
{	
	static const int RPC_SYNC_AUTH_LIST = 1396355;		
	static autoptr array<TerritoryHQ> All_HQs = {};
	
	protected ref array<string> m_AuthorizationList = {};	
		
	// a numerical representation of how much the base has decayed. since the amount
	// of nails is always an integer value
	protected float m_DecaySubValue;
	
	protected TerritoryTrigger m_TerritoryTrigger;
	
#ifdef GameLabs
	protected ref _Event m_TerritoryHQEvent;
#endif
			
	protected int m_MaxPlayers = int.MAX;
	protected int m_PlaceTimestamp = int.MAX;
	protected float m_UpkeepCost;
	protected float m_Radius = RearmedConstants.BASE_RADIUS;
	protected bool m_IsUpgrading;
	
	void TerritoryHQ()
	{
		if (!All_HQs) {
			All_HQs = {};
		}
		
		All_HQs.Insert(this);
		
		RegisterNetSyncVariableInt("m_MaxPlayers");
		RegisterNetSyncVariableInt("m_PlaceTimestamp");
		RegisterNetSyncVariableFloat("m_UpkeepCost");
		RegisterNetSyncVariableFloat("m_Radius");
		RegisterNetSyncVariableBool("m_IsUpgrading");
		
#ifdef SERVER
#ifdef REARMED_SERVER
		RearmedServerId server_id = g_Game.GetRearmedAPI().GetCurrentServerId();
		switch (server_id) {
			case RearmedServerId.US3:
			case RearmedServerId.EU3:
			case RearmedServerId.AU2: { 
				m_MaxPlayers = 5;
				break;
			}

			case RearmedServerId.US4: {
				m_MaxPlayers = 3;
				break;
			}
		}
#endif
		
		SetSynchDirty();
		
						
#ifdef GameLabs
		m_TerritoryHQEvent = new _Event(GetType(), "pennant", this);
		GetGameLabs().RegisterEvent(m_TerritoryHQEvent);
#endif
#endif		
	}
		
	void ~TerritoryHQ()
	{
		if (All_HQs) {
			All_HQs.RemoveItem(this);
		}
		
		delete m_AuthorizationList;
		
#ifdef SERVER
		if (g_Game && m_TerritoryTrigger) {
			g_Game.ObjectDelete(m_TerritoryTrigger);
		}
#endif
		
#ifdef GameLabs
		if (GetGameLabs()) {
			GetGameLabs().RemoveEvent(m_TerritoryHQEvent);		
		}
		
		delete m_TerritoryHQEvent;
#endif
	}
		
	override void EEInit()
	{
		super.EEInit();
		
#ifdef SERVER
		if (!IsRuined()) {
			m_TerritoryTrigger = TerritoryTrigger.Cast(g_Game.CreateObjectEx("TerritoryTrigger", GetPosition(), ECE_NONE));		
			m_TerritoryTrigger.SetHQ(this);
		}
#else
		
		ScriptRPC().Send(this, RPC_SYNC_AUTH_LIST, true);
#endif
		if (!m_TerritoryTrigger) {
			return;
		}
		
		if (m_Radius != m_TerritoryTrigger.GetCollisionRadius()) {
			Print("[Kowalski] radius isn't the same size, onceupdate worth");
			m_TerritoryTrigger.SetRadius(m_Radius);
		}
	}
				
	bool HasEquity()
	{
		// Nails are deleted when they hit zero
		if (FindAttachmentBySlotName("HQ_Nails")) {
			return true;
		}
		
		return false;
	}
	
	int GetEquity()
	{
		int equity;
		// Nails are deleted when they hit zero
		ItemBase nail_item = ItemBase.Cast(FindAttachmentBySlotName("HQ_Nails"));
		if (nail_item) {
			equity += nail_item.GetQuantity();
		}
		
		return equity;
	}
	
	//! todo: refactor. its slower than we want (way faster than before but still)
	void RegisterItem(ItemBase base_item)
	{
		if (base_item.GetCostToUpkeep() <= 0) {
			return;
		}
		m_UpkeepCost += base_item.GetCostToUpkeep();
		base_item.SetCurrentHQ(this);
		SetSynchDirty();
	}
	
	void UnregisterItem(ItemBase base_item)
	{
		if (base_item.GetCostToUpkeep() <= 0) {
			return;
		}
		m_UpkeepCost -= base_item.GetCostToUpkeep();
		base_item.SetCurrentHQ(this);
		SetSynchDirty();
	}

	override float GetCostToUpkeep()
	{
		return 50;
	}
	
	float GetBaseUpkeepCost()
	{		
		return m_UpkeepCost;
	}
	
	// Only works on server
	TerritoryTrigger GetTerritoryTrigger()
	{
		return m_TerritoryTrigger;
	}
	
	//@ returns false if failed to consume. damage should be applied
	bool ConsumeNails(float amount)
	{
		if (!g_Game.IsServer()) {
			return false;
		}
		
		ItemBase nails = ItemBase.Cast(FindAttachmentBySlotName("HQ_Nails"));
		
		// No nails to consume
		if (!nails) {
			return false;
		}
		
		// Add to decay, if decay is greater than 1 consume the nails, then remove that value from the decay
		//		its like removing fractions of a nail
		m_DecaySubValue += amount;
		int rounded_value = Math.Floor(m_DecaySubValue);
		if (!nails.AddQuantity(-rounded_value)) {
			m_DecaySubValue -= rounded_value;
		}
		
		return true;
	}
	
	int GetRemainingTimeUntilDecay()
	{
		float base_cost = GetBaseUpkeepCost();
		if (base_cost == 0) {
			return int.MAX;
		}
		
		return (GetEquity() / base_cost) * 60 * 24;
	}
	
	protected void SyncAuthorizationList(PlayerIdentity target = null)
	{
		if (g_Game.IsServer()) {
			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(m_AuthorizationList);
			rpc.Send(this, RPC_SYNC_AUTH_LIST, true, target);
		}
	}
	
	override bool NameOverride(out string output)
	{
		Man local_player = g_Game.GetPlayer();
		if (!local_player) {
			return false;
		}
		
		// only displaying the remaining decay time to authed individuals
		if (!IsAuthorized(local_player)) {
			return false;
		}
		
		int minutes = GetRemainingTimeUntilDecay();
		if (minutes == int.MAX) {
			return false;
		}
		
		if (minutes == 0) {
			output = string.Format("Territory HQ - [DECAYING]");
			return true;
		}
		
		int hours = minutes / 60;
		int days = minutes / (24 * 60);
		
		hours -= days * 24;
		minutes -= (hours * 60) + (days * 24 * 60);
		
		output = string.Format("Territory HQ - [%1d %2h %3m]", days.ToStringLen(2), hours.ToStringLen(2), minutes.ToStringLen(2));
		return true;
	}

	void AuthorizePlayer(Man player)
	{		
		AuthorizePlayer(player.GetIdentity().GetId());
	}
	
	void AuthorizePlayer(string player_id)
	{
		m_AuthorizationList.Insert(player_id);
		SyncAuthorizationList();
	}
	
	void DeauthorizePlayer(Man player)
	{
		DeauthorizePlayer(player.GetIdentity().GetId());
	}
	
	void DeauthorizePlayer(string player_id)
	{
		m_AuthorizationList.RemoveItem(player_id);
		SyncAuthorizationList();
	}
	
	void ClearAuthorizations()
	{
		m_AuthorizationList.Clear();
		SyncAuthorizationList();
	}
	
	bool IsAuthorized(Man player)
	{		
		return (m_AuthorizationList && m_AuthorizationList.Find(player.GetIdentity().GetId()) != -1);
	}
		
	bool IsAuthorized(string player_id)
	{
		return (m_AuthorizationList && m_AuthorizationList.Find(player_id) != -1);
	}
	
	void SetRadius(float radius)
	{
		if (!g_Game.IsServer()) {
			return;
		}
		
		m_Radius = radius;
		SetSynchDirty();
	}
	
	void AddRadius(float add_radius)
	{
		SetRadius(GetRadius() + add_radius);
	}
	
	float GetRadius()
	{
		return m_Radius;
	}
	
	PositionWithRadius2D GetZoneInfo()
	{
		return new PositionWithRadius2D(GetPosition(), GetRadius());
	}
			
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{		
		switch (rpc_type) {
			case RPC_SYNC_AUTH_LIST: {				
				// client recieved
				if (!g_Game.IsDedicatedServer()) {
					m_AuthorizationList.Clear();					
					if (!ctx.Read(m_AuthorizationList)) {
						Error("Failed to read authlist");
						break;
					}
				}
				
				// server recieved a client request update, send them the auth list
				if (g_Game.IsServer()) {
					SyncAuthorizationList(sender);
				}
				
				break;
			}
		}
		
		super.OnRPC(sender, rpc_type, ctx);
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAdminTerritoryAuthorize);
		AddAction(ActionTerritoryAuthorize);
		AddAction(ActionTerritoryDeauthorize);
		AddAction(ActionTerritoryClearAuthorization);
	}
	
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		ctx.Write(m_AuthorizationList);
		ctx.Write(m_DecaySubValue);
		ctx.Write(m_PlaceTimestamp);
	}
	
	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if (!super.OnStoreLoad(ctx, version)) {
			return false;
		}
		
		return ctx.Read(m_AuthorizationList) && ctx.Read(m_DecaySubValue) && ctx.Read(m_PlaceTimestamp);
	}
	
	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}
	
	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}
	
	override bool CanPutAsAttachment(EntityAI parent)
	{
		return false;
	}
		
	int GetMaxPlayers()
	{
		return m_MaxPlayers;
	}

	void SetPlacementTimestamp(int timestamp)
	{
		if (!g_Game.IsServer()) {
			return;
		}
		
		m_PlaceTimestamp = timestamp;
		SetSynchDirty();
	}

	int GetPlacementTimestamp()
	{
		return m_PlaceTimestamp;
	}
	
	bool HasMaxPlayers()
	{
		return (m_AuthorizationList.Count() >= m_MaxPlayers);
	}

	override void OnDamageDestroyed(int oldLevel)
	{
		super.OnDamageDestroyed(oldLevel);

		if (All_HQs) {
			All_HQs.RemoveItem(this);
		}
		
		delete m_AuthorizationList;
		
#ifdef SERVER
		if (g_Game && m_TerritoryTrigger) {
			g_Game.ObjectDelete(m_TerritoryTrigger);
		}
#endif
		
#ifdef GameLabs
		if (GetGameLabs()) {
			GetGameLabs().RemoveEvent(m_TerritoryHQEvent);		
		}
		
		delete m_TerritoryHQEvent;
#endif

		g_Game.ObjectDelete(FindAttachmentBySlotName("CodeLock"));
	}
	
	override bool IsInventoryVisible()
	{
		return (IsAuthorized(g_Game.GetPlayer()) || IsRuined());
    }

	override string GetKit()
	{
		return "TerritoryHQ_Kit";
	}

	// works on client and server, very fast
	static bool IsWithinTerritoryRange(Man player, vector position)
	{		
		array<TerritoryHQ> overlapped_hqs = {};
		foreach (TerritoryHQ hq: All_HQs) {
			if (hq.IsHologram()) {
				continue;	
			}
			
			// player is in the zone
			if (vector.Distance(position, hq.GetPosition()) <= hq.GetRadius()) {
				return true;
			}
		}
		
		return false;
	}
		
	// works on client and server, very fast
	static bool HasPermissionsAtPosition(Man player, vector position)
	{		
		array<TerritoryHQ> overlapped_hqs = {};
		foreach (TerritoryHQ hq: All_HQs) {
			if (hq.IsHologram()) {
				continue;	
			}
			
			// player is in the zone
			if (vector.Distance(position, hq.GetPosition()) <= hq.GetRadius()) {
				overlapped_hqs.Insert(hq);
			}
		}
		
		TerritoryHQ oldest_hq = GetOldestHQ(overlapped_hqs);
		return (!oldest_hq || oldest_hq.IsAuthorized(player));
	}
	
	static bool HasPermissionsAtPositionEx(Man player, vector position, out notnull array<TerritoryHQ> unauthorized_hqs)
	{
		foreach (TerritoryHQ hq: All_HQs) {
			if (hq.IsHologram()) {
				continue;	
			}
			
			// player is in the zone
			if (vector.Distance(position, hq.GetPosition()) <= hq.GetRadius()) {
				if (!hq.IsAuthorized(player)) {
					unauthorized_hqs.Insert(hq);
				}
			}
		}
		
		TerritoryHQ oldest_hq = GetOldestHQ(unauthorized_hqs);
		return (!oldest_hq || oldest_hq.IsAuthorized(player));
	}

	static TerritoryHQ GetOldestHQ(notnull array<TerritoryHQ> hqs)
	{
		// optimization, most of the time this will be the case
		if (hqs.Count() == 1) {
			return hqs[0];
		}
		
		TerritoryHQ oldest_hq;
		int timestamp = int.MAX;
		foreach (TerritoryHQ hq: hqs) {
			if (hq && hq.GetPlacementTimestamp() < timestamp) {
				timestamp = hq.GetPlacementTimestamp();
				oldest_hq = hq;
			}
		}

		return oldest_hq;
	}
	
	static bool IsInFlagRadius(vector position)
	{
		foreach (TerritoryHQ hq: All_HQs) {
			if (vector.Distance(position, hq.GetPosition()) <= hq.GetRadius()) {
				return true;
			}
		}
		
		return false;
	}
}