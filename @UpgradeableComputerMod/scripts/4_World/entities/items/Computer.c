class Computer extends Inventory_Base
{
    // Max number of upgrades allowed
    static const int MAX_UPGRADES = 8;

    // Array to hold attached upgrade entities (CircuitBoard_UpgradeEntity)
    ref array<CircuitBoard_UpgradeEntity> m_UpgradeEntities;

    // Total extra cargo slots added by upgrades
    int m_ExtraCargoSlots = 0;

    void Computer()
    {
        m_UpgradeEntities = new array<CircuitBoard_UpgradeEntity>;
    }

    override bool CanPutInCargo(EntityAI parent)
    {
        // Computer itself can be put in cargo like normal items (optional)
        return true;
    }

    override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
        // Don't allow regular attachments, upgrades only happen via UseCircuitBoard method
        return false;
    }

    // This function is called when player uses a circuit board on the computer
    bool UseCircuitBoard(CircuitBoard board)
    {
        if (m_UpgradeEntities.Count() >= MAX_UPGRADES)
        {
            GetGame().Message("Computer is fully upgraded!");
            return false;
        }

        // Create the upgrade entity that attaches to this computer
        CircuitBoard_UpgradeEntity upgrade = CircuitBoard_UpgradeEntity.Cast(GetGame().CreateObject("CircuitBoard_UpgradeEntity", GetPosition()));
        if (!upgrade)
            return false;

        // Set upgrade tier from the circuit board used
        upgrade.SetTier(board.GetTier());

        // Attach upgrade to computer (we will handle the logic, not physical attachment)
        m_UpgradeEntities.Insert(upgrade);

        // Increase cargo space
        m_ExtraCargoSlots += upgrade.GetAddedSlots();

        // You can update cargo capacity here if you have custom cargo extension logic
        UpdateCargoCapacity();

        // Destroy the circuit board item (used up)
        board.Delete();

        GetGame().Message("Computer upgraded with tier " + upgrade.GetTier());

        return true;
    }

    void UpdateCargoCapacity()
    {
        // TODO: Here you’d add code to expand the cargo size of the computer dynamically.
        // DayZ base game doesn’t support dynamic cargo size changes at runtime easily.
        // For now, just a placeholder function.
    }

    // For debugging: get total slots including base + upgrades
    int GetTotalCargoSlots()
    {
        int baseSlots = 0; // Set your base cargo size here
        return baseSlots + m_ExtraCargoSlots;
    }

    // Save/load upgrades for persistence (if you want)
    override void OnStoreSave(ParamsWriteContext ctx)
    {
        super.OnStoreSave(ctx);
        ctx.Write(m_UpgradeEntities.Count());

        foreach (CircuitBoard_UpgradeEntity upgrade : m_UpgradeEntities)
        {
            ctx.Write(upgrade.GetTier());
        }
    }

    override bool OnStoreLoad(ParamsReadContext ctx, int version)
    {
        if (!super.OnStoreLoad(ctx, version))
            return false;

        int count;
        if (!ctx.Read(count))
            return false;

        for (int i = 0; i < count; i++)
        {
            int tier;
            if (!ctx.Read(tier))
                return false;

            CircuitBoard_UpgradeEntity upgrade = CircuitBoard_UpgradeEntity.Cast(GetGame().CreateObject("CircuitBoard_UpgradeEntity", GetPosition()));
            upgrade.SetTier(tier);
            m_UpgradeEntities.Insert(upgrade);
            m_ExtraCargoSlots += upgrade.GetAddedSlots();
        }

        UpdateCargoCapacity();

        return true;
    }
}
