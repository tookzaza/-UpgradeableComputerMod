class CfgPatches
{
    class UpgradeableComputerMod
    {
        units[] = {"Upgradeable_ComputerBase", "CircuitBoard_T1", "CircuitBoard_T2", "CircuitBoard_T3", "CircuitBoard_T4"};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data"};
    };
};

class CfgVehicles
{
    class HouseNoDestruct; // Base class for placeables

    // Placeable Upgradeable Computer
    class Upgradeable_ComputerBase: HouseNoDestruct
    {
        scope = 2;
        displayName = "Upgradeable Computer";
        descriptionShort = "A placeable computer that can be upgraded with circuit boards to increase storage.";
        model = "@UpgradeableComputerMod\models\computer.p3d";

        // Allow placement like tents
        canBePlaced = 1;

        // Storage setup
        cargoSize[] = {20, 5}; // Base cargo size (width, height grid)
        // No attachments for now, or you can add empty attachments array if needed
        attachments[] = {};

        // Optional: Damage system, sounds, etc can be added here
    };

    // Base circuit board class (inventory item)
    class Inventory_Base;

    class CircuitBoard_Base: Inventory_Base
    {
        scope = 0;
        displayName = "Circuit Board";
        descriptionShort = "An upgrade circuit board.";
        model = "@UpgradeableComputerMod\models\circuitboard.p3d";
        itemSize[] = {1,1};
        weight = 50;
        canBeDropped = 1;
    };

    // Circuit board tiers
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
