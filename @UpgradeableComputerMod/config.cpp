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
    class HouseNoDestruct; // base class for placeable tents/buildings
    class Inventory_Base; // base for inventory items

    // Placeable computer, inherits from HouseNoDestruct so it can be placed in the world
    class Upgradeable_ComputerBase: HouseNoDestruct
    {
        scope = 2;
        displayName = "Upgradeable Computer";
        descriptionShort = "A placeable computer that can be upgraded with circuit boards to increase storage.";
        model = "@UpgradeableComputerMod\models\computer.p3d";
        canBePlaced = 1;
        rotationFlags = 17; // allows rotation while placing
        vehicleClass = "Fortifications";
        
        cargoSize[] = {20, 5}; // base cargo size (width x height)
        hiddenSelections[] = {}; // add if needed for texture variations
        attachments[] = {}; // no attachments by default
        
        // Optional sound parameters to avoid silent placement
        soundBuilding = "houseBuilding_SoundSet";
        noiseRadius = 15;

        // Other optional settings can be added here
    };

    // Base circuit board item class
    class CircuitBoard_Base: Inventory_Base
    {
        scope = 0;
        displayName = "Circuit Board";
        descriptionShort = "An upgrade circuit board.";
        model = "@UpgradeableComputerMod\models\circuitboard.p3d";
        itemSize[] = {1, 1};
        weight = 50;
        canBeDropped = 1;
    };

    // Circuit board tier 1
    class CircuitBoard_T1: CircuitBoard_Base
    {
        scope = 2;
        displayName = "Circuit Board Tier 1";
        descriptionShort = "Adds 250 slots when used on the computer.";
    };

    // Circuit board tier 2
    class CircuitBoard_T2: CircuitBoard_Base
    {
        scope = 2;
        displayName = "Circuit Board Tier 2";
        descriptionShort = "Adds 500 slots when used on the computer.";
    };

    // Circuit board tier 3
    class CircuitBoard_T3: CircuitBoard_Base
    {
        scope = 2;
        displayName = "Circuit Board Tier 3";
        descriptionShort = "Adds 750 slots when used on the computer.";
    };

    // Circuit board tier 4
    class CircuitBoard_T4: CircuitBoard_Base
    {
        scope = 2;
        displayName = "Circuit Board Tier 4";
        descriptionShort = "Adds 1000 slots when used on the computer.";
    };
};
