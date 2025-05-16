class CfgPatches
{
    class UpgradeableComputerMod
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data"};
    };
};

class CfgVehicles
{
    // The placeable computer base entity
    class Inventory_Base;

    class Upgradeable_ComputerBase: Inventory_Base
    {
        scope = 2;
        displayName = "Upgradeable Computer";
        descriptionShort = "A placeable computer that can be upgraded with circuit boards to increase storage.";
        model = "\UpgradeableComputerMod\models\computer.p3d";
        inventorySlot[] = {};
        itemSize[] = {4,4};
        itemsCargoSize[] = {20, 5}; // base cargo size, will be increased by upgrades
        // Custom variables or attachments if needed
        // For simplicity, no attachments here, upgrades handled by scripts
        
        canBePlaced = 1;
        // You can add more properties like sound, damage system, etc.
    };

    // Circuit boards as inventory items
    class CircuitBoard_Base: Inventory_Base
    {
        scope = 0;
        displayName = "Circuit Board";
        descriptionShort = "An upgrade circuit board.";
        model = "\UpgradeableComputerMod\models\circuitboard.p3d";
        itemSize[] = {1,1};
        weight = 50;
        // No cargo space
        canBeDropped = 1;
    };

    class CircuitBoard_T1: CircuitBoard_Base
    {
        scope = 2;
        displayName = "Circuit Board Tier 1";
        descriptionShort = "Adds 250 slots when used on the computer.";
    };

    class CircuitBoard_T2: CircuitBoard_Base
    {
        scope = 2;
        displayName = "Circuit Board Tier 2";
        descriptionShort = "Adds 500 slots when used on the computer.";
    };

    class CircuitBoard_T3: CircuitBoard_Base
    {
        scope = 2;
        displayName = "Circuit Board Tier 3";
        descriptionShort = "Adds 750 slots when used on the computer.";
    };

    class CircuitBoard_T4: CircuitBoard_Base
    {
        scope = 2;
        displayName = "Circuit Board Tier 4";
        descriptionShort = "Adds 1000 slots when used on the computer.";
    };
};
