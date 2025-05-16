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
    class Inventory_Base;

    class Upgradeable_ComputerBase: Inventory_Base
    {
        scope = 2;
        scopeInventory = 2;
        simulation = "inventoryItem";

        displayName = "Upgradeable Computer";
        descriptionShort = "A placeable computer that can be upgraded with circuit boards to increase storage.";
        model = "\UpgradeableComputerMod\models\computer.p3d";

        itemSize[] = {4,4};
        itemsCargoSize[] = {20, 5};

        canBePlaced = 1;
        rotationFlags = 17;

        allowOwnedCargoManipulation = 1;

        // Optional: You can add attachments here if you want to allow upgrades as attachments
        // attachments[] = {};
    };

    class CircuitBoard_Base: Inventory_Base
    {
        scope = 0;
        scopeInventory = 0;
        simulation = "inventoryItem";

        displayName = "Circuit Board";
        descriptionShort = "An upgrade circuit board.";
        model = "\UpgradeableComputerMod\models\circuitboard.p3d";

        itemSize[] = {1,1};
        weight = 50;

        canBeDropped = 1;
        allowOwnedCargoManipulation = 1;
    };

    class CircuitBoard_T1: CircuitBoard_Base
    {
        scope = 2;
        scopeInventory = 2;

        displayName = "Circuit Board Tier 1";
        descriptionShort = "Adds 250 slots when used on the computer.";
    };

    class CircuitBoard_T2: CircuitBoard_Base
    {
        scope = 2;
        scopeInventory = 2;

        displayName = "Circuit Board Tier 2";
        descriptionShort = "Adds 500 slots when used on the computer.";
    };

    class CircuitBoard_T3: CircuitBoard_Base
    {
        scope = 2;
        scopeInventory = 2;

        displayName = "Circuit Board Tier 3";
        descriptionShort = "Adds 750 slots when used on the computer.";
    };

    class CircuitBoard_T4: CircuitBoard_Base
    {
        scope = 2;
        scopeInventory = 2;

        displayName = "Circuit Board Tier 4";
        descriptionShort = "Adds 1000 slots when used on the computer.";
    };
};
