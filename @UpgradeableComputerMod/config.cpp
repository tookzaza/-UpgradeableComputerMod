class CfgPatches
{
    class UpgradeableComputerMod
    {
        units[] = {
            "Upgradeable_ComputerBase",
            "CircuitBoard_T1",
            "CircuitBoard_T2",
            "CircuitBoard_T3",
            "CircuitBoard_T4"
        };
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data"};
    };
};

class CfgVehicles
{
    class Container_Base;

    class Upgradeable_ComputerBase: Container_Base
    {
        scope = 2;
        displayName = "Upgradeable Computer";
        descriptionShort = "A placeable computer that can be upgraded with circuit boards.";
        model = "\UpgradeableComputerMod\models\computer.p3d";
        weight = 10000;
        itemSize[] = {5,5};
        itemsCargoSize[] = {10,10};
        cargoIsOpen = 1;
        varQuantityDestroyOnMin = 1;
        physLayer = "item_large";
        hiddenSelections[] = {};
        hiddenSelectionsTextures[] = {};
        attachments[] = {};
        placement = "vertical";
        canBeDigged = 0;
        canBePlaced = 1;
        lootCategory = "Crafted";
        isMeleeWeapon = 0;
        allowOwnedCargoManipulation = 1;
        overrideDrawArea = "5.0";
        class AnimationSources {};
        class GUIInventoryAttachmentsProps {};
    };

    class Inventory_Base;

    class CircuitBoard_Base: Inventory_Base
    {
        scope = 0;
        displayName = "Circuit Board";
        descriptionShort = "An upgrade circuit board.";
        model = "\UpgradeableComputerMod\models\circuitboard.p3d";
        itemSize[] = {1,1};
        weight = 50;
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
