class CfgPatches
{
	class RearmedServer_Gear_CircuitBoard
	{
		units[]=
		{
			"RA_CircuitBoard",
			"TerritoryHQ_Workbench",
			"TerritoryHQ_RadiusUpgrade",
			"TerritoryHQ_StorageUpgrade"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class RA_CircuitBoard_Base: Inventory_Base
	{
		scope=0;
		displayName="Circuit Board";
		descriptionShort="";
		model="RearmedServer\Gear\Tools\CircuitBoard\CircuitBoard.p3d";
		itemSize[]={1,1};
		weight=100;
		absorbency=0;
		simulation="inventoryItem";
		hiddenSelections[]=
		{
			"camo"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"rearmedserver\gear\data\bag.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"rearmedserver\gear\data\bag.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"rearmedserver\gear\data\bag_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"rearmedserver\gear\data\bag_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"rearmedserver\gear\data\bag_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class RA_CircuitBoard: RA_CircuitBoard_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"RearmedServer\Gear\Tools\CircuitBoard\data\CircuitBoard_co.paa"
		};
	};
	class TerritoryHQ_UpgradeModuleBase: RA_CircuitBoard
	{
		scope=0;
		itemSize[]={1,1};
		inventorySlot[]=
		{
			"TerritoryHQ_L1_Upgrade",
			"TerritoryHQ_L2_Upgrade",
			"TerritoryHQ_L3_Upgrade",
			"TerritoryHQ_L4_Upgrade"
		};
		weight=50;
	};
	class TerritoryHQ_Workbench: TerritoryHQ_UpgradeModuleBase
	{
		scope=2;
		displayName="Territory Workbench Upgrade";
		descriptionShort="Attach to your Territory HQ to have access to a crafting workbench";
		class Cargo
		{
			itemsCargoSize[]={10,15};
			allowOwnedCargoManipulation=1;
		};
	};
	class TerritoryHQ_RadiusUpgrade: TerritoryHQ_UpgradeModuleBase
	{
		scope=2;
		displayName="Territory Radius Upgrade";
		descriptionShort="Attach to your Territory HQ to increase its protection radius by 15 meters";
	};
	class TerritoryHQ_StorageUpgrade: TerritoryHQ_UpgradeModuleBase
	{
		scope=2;
		displayName="Territory Storage Upgrade";
		descriptionShort="Attach to your Territory HQ to add 1000 slots to your HQ";
		class Cargo
		{
			itemsCargoSize[]={10,100};
			allowOwnedCargoManipulation=1;
		};
	};
};
