class CfgPatches
{
    class UpgradeableComputerMod
    {
        units[] = {"Upgradeable_ComputerBase", "CircuitBoard_UpgradeEntity"};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data"};
    };
};

class CfgVehicles
{
    class HouseNoDestruct;

    // The placeable computer base entity
    class Upgradeable_ComputerBase : HouseNoDestruct
    {
        scope = 2;
        displayName = "Upgradeable Computer";
        descriptionShort = "A placeable computer that can be upgraded with circuit boards to increase storage.";
        model = "\@UpgradeableComputerMod\models\computer.p3d";
        vehicleClass = "Fortifications";
        canBePlaced = 1;
        rotationFlags = 17; // allows free rotation when placing

        inventorySize[] = {20,5}; // base cargo size

        cargoCanBeSplit = 0;

        attachments[] = {
            "UpgradeSlot1",
            "UpgradeSlot2",
            "UpgradeSlot3",
            "UpgradeSlot4",
            "UpgradeSlot5",
            "UpgradeSlot6",
            "UpgradeSlot7",
            "UpgradeSlot8"
        };

        // Optional: prevent the computer from being destroyed to keep upgrades safe
        destructible = 0;
    };

    // Upgrade module entity attached to the computer
    class CircuitBoard_UpgradeEntity : HouseNoDestruct
    {
        scope = 1; // hidden from spawn menu (only created by scripts)
        displayName = "Computer Upgrade Module";
        descriptionShort = "An upgrade module for the computer.";
        model = "\@UpgradeableComputerMod\models\circuitboard_upgrade.p3d"; // make sure this file exists!
        vehicleClass = "Fortifications";

        canBePlaced = 0; // not placeable by players manually

        inventorySize[] = {10,5}; // storage added by this upgrade (example size)

        cargoCanBeSplit = 0;

        // no attachments needed here
        attachments[] = {};
    };

    // Circuit board items that player holds in inventory (not placeable)
    class Inventory_Base;

    class CircuitBoard_Base : Inventory_Base
    {
        scope = 0; // base class, no spawn in inventory
        displayName = "Circuit Board";
        descriptionShort = "An upgrade circuit board.";
        model = "\@UpgradeableComputerMod\models\circuitboard.p3d";
        itemSize[] = {1,1};
        weight = 50;
        canBeDropped = 1;
    };

    class CircuitBoard_T1 : CircuitBoard_Base
    {
        scope = 2;
        displayName = "Circuit Board Tier 1";
        descriptionShort = "Adds 250 slots when used on the computer.";
    };

    class CircuitBoard_T2 : CircuitBoard_Base
    {
        scope = 2;
        displayName = "Circuit Board Tier 2";
        descriptionShort = "Adds 500 slots when used on the computer.";
    };

    class CircuitBoard_T3 : CircuitBoard_Base
    {
        scope = 2;
        displayName = "Circuit Board Tier 3";
        descriptionShort = "Adds 750 slots when used on the computer.";
    };

    class CircuitBoard_T4 : CircuitBoard_Base
    {
        scope = 2;
        displayName = "Circuit Board Tier 4";
        descriptionShort = "Adds 1000 slots when used on the computer.";
    };
};
