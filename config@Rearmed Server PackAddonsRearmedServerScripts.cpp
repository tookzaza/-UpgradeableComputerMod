class CfgPatches
{
	class RearmedServer_Scripts
	{
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Scripts",
			"JM_CF_Scripts",
			"DF_Scripts",
			"Lugge_Chiemsee_Scripts",
			"ChiemseeScripts"
		};
		units[]={};
		weapons[]={};
	};
};
class CfgMods
{
	delete Lugge_Chiemsee_Scripts;
	delete ChiemseeScripts;
	class RearmedServer
	{
		name="Rearmed";
		dir="RearmedServer";
		credits="Designful, InclementDab, Specops, Gormirn, AJ45";
		author="Designful";
		creditsJson="RearmedServer/Scripts/Data/Credits.json";
		versionPath="RearmedServer/Scripts/Data/Version.hpp";
		inputs="RearmedServer/Scripts/Data/Inputs.xml";
		type="mod";
		defines[]=
		{
			"REARMED_SERVER"
		};
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class imageSets
			{
				files[]=
				{
					"RearmedServer/GUI/images/EarPro.imageset",
					"RearmedServer/GUI/images/Coat.imageset",
					"RearmedServer/GUI/imagesets/KeyIcons.imageset",
					"RearmedServer/GUI/imagesets/RubbleIcon.imageset",
					"RearmedServer/GUI/imagesets/ironsight.imageset",
					"RearmedServer/GUI/imagesets/m4buttstock.imageset",
					"RearmedServer/GUI/imagesets/RA.imageset",
					"RearmedServer/GUI/imagesets/BaseBuilding_Icons.imageset",
					"RearmedServer/GUI/imagesets/Buttons.imageset",
					"RearmedServer/GUI/icons/icons.imageset",
					"RearmedServer/GUI/imagesets/TF.imageset",
					"RearmedServer/GUI/imagesets/Styles.imageset"
				};
			};
			class widgetStyles
			{
				files[]=
				{
					"RearmedServer/gui/looknfeel/Rearmed.styles"
				};
			};
			class engineScriptModule
			{
				files[]=
				{
					"RearmedServer/Scripts/1_core"
				};
			};
			class gameScriptModule
			{
				files[]=
				{
					"RearmedServer/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				files[]=
				{
					"RearmedServer/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				files[]=
				{
					"RearmedServer/Scripts/5_Mission"
				};
			};
			class workbenchScriptModule
			{
				files[]=
				{
					"RearmedServer/scripts/Editor/Plugins"
				};
			};
		};
	};
};
class CfgSoundSets
{
	class baseFootsteps_SoundSet;
	class walkErc_cp_broadleaf_dense1_Char_SoundSet: baseFootsteps_SoundSet
	{
		soundShaders[]=
		{
			"walkErc_cp_broadleaf_dense1_boots_shoes_walkErc_Char_SoundShader",
			"walkErc_cp_broadleaf_dense1_sneakers_shoes_walkErc_Char_SoundShader",
			"walkErc_cp_broadleaf_dense1_cp_broadleaf_dense1_walkErc_Char_SoundShader",
			"walkErc_cp_broadleaf_dense1_grass_dry_ext_walkErc_Char_SoundShader",
			"walkErc_cp_broadleaf_dense1_bare_cp_broadleaf_dense1_walkErc_Char_SoundShader",
			"walkErc_cp_broadleaf_dense1_cp_broadleaf_dense1_walkErc_creak_Char_SoundShader"
		};
	};
	class runErc_cp_broadleaf_dense1_Char_SoundSet: baseFootsteps_SoundSet
	{
		soundShaders[]=
		{
			"runErc_cp_broadleaf_dense1_boots_shoes_runErc_Char_SoundShader",
			"runErc_cp_broadleaf_dense1_sneakers_shoes_runErc_Char_SoundShader",
			"runErc_cp_broadleaf_dense1_cp_broadleaf_dense1_runErc_Char_SoundShader",
			"runErc_cp_broadleaf_dense1_grass_dry_ext_runErc_Char_SoundShader",
			"runErc_cp_broadleaf_dense1_bare_cp_broadleaf_dense1_runErc_Char_SoundShader",
			"runErc_cp_broadleaf_dense1_cp_broadleaf_dense1_walkErc_creak_Char_SoundShader"
		};
	};
	class sprintErc_cp_broadleaf_dense1_Char_SoundSet: baseFootsteps_SoundSet
	{
		soundShaders[]=
		{
			"sprintErc_cp_broadleaf_dense1_boots_shoes_sprintErc_Char_SoundShader",
			"sprintErc_cp_broadleaf_dense1_sneakers_shoes_sprintErc_Char_SoundShader",
			"sprintErc_cp_broadleaf_dense1_cp_broadleaf_dense1_sprintErc_Char_SoundShader",
			"sprintErc_cp_broadleaf_dense1_grass_dry_ext_sprintErc_Char_SoundShader",
			"sprintErc_cp_broadleaf_dense1_bare_cp_broadleaf_dense1_sprintErc_Char_SoundShader",
			"sprintErc_cp_broadleaf_dense1_cp_broadleaf_dense1_walkErc_creak_Char_SoundShader"
		};
	};
};
class CfgSlots
{
	class Slot_CodeLock
	{
		name="CodeLock";
		displayName="Code Lock";
		ghostIcon="set:BaseBuilding_Icons image:CodeLock";
		ghostIconSize=0.80000001;
	};
	class Slot_compensatorSuppressor
	{
		name="compensatorSuppressor";
		displayName="Suppressor";
		ghostIcon="set:dayz_inventory image:supressor";
	};
	class Slot_TerritoryHQ_L1_Upgrade
	{
		name="TerritoryHQ_L1_Upgrade";
		displayName="Territory HQ Upgrade";
		ghostIcon="set:dayz_inventory image:paper";
	};
	class Slot_TerritoryHQ_L2_Upgrade
	{
		name="TerritoryHQ_L2_Upgrade";
		displayName="Territory HQ Upgrade";
		ghostIcon="set:dayz_inventory image:paper";
	};
	class Slot_TerritoryHQ_L3_Upgrade
	{
		name="TerritoryHQ_L3_Upgrade";
		displayName="Territory HQ Upgrade";
		ghostIcon="set:dayz_inventory image:paper";
	};
	class Slot_TerritoryHQ_L4_Upgrade
	{
		name="TerritoryHQ_L4_Upgrade";
		displayName="Territory HQ Upgrade";
		ghostIcon="set:dayz_inventory image:paper";
	};
	class Slot_HQ_Nails
	{
		name="HQ_Nails";
		displayName="#STR_CfgNails0";
		ghostIcon="set:dayz_inventory image:nails";
		stackMax=1500;
	};
	class Slot_DirectCookingD
	{
		name="DirectCookingD";
		displayName="#STR_CfgDirectCooking0";
		ghostIcon="set:dayz_inventory image:directcooking";
	};
	class Slot_DirectCookingE
	{
		name="DirectCookingE";
		displayName="#STR_CfgDirectCooking0";
		ghostIcon="set:dayz_inventory image:directcooking";
	};
	class Slot_DirectCookingF
	{
		name="DirectCookingF";
		displayName="#STR_CfgDirectCooking0";
		ghostIcon="set:dayz_inventory image:directcooking";
	};
	class Slot_EarProtection
	{
		name="EarProtection";
		displayName="Ear Protection";
		ghostIcon="set:EarPro image:EarPro";
		ghostIconSize=0.80000001;
	};
	class Slot_Coat
	{
		name="Coat";
		displayName="Coat";
		ghostIcon="set:Coat image:Coat";
		ghostIconSize=0.80000001;
	};
	class Slot_IdentificationCard
	{
		name="IdentificationCard";
		displayName="Identification Card";
		ghostIcon="set:icons image:idcard";
		ghostIconSize=0.80000001;
	};
	class Slot_TagBag
	{
		name="TagBag";
		displayName="Identification Card";
		ghostIcon="set:icons image:idcard";
		ghostIconSize=0.80000001;
		stackMax=100;
	};
	class Slot_Crate1
	{
		name="Crate1";
		displayName="Storage";
		ghostIcon="set:dayz_inventory image:cat_common_cargo";
	};
	class Slot_Crate2
	{
		name="Crate2";
		displayName="Storage";
		ghostIcon="set:dayz_inventory image:cat_common_cargo";
	};
	class Slot_Crate3
	{
		name="Crate3";
		displayName="Storage";
		ghostIcon="set:dayz_inventory image:cat_common_cargo";
	};
	class Slot_StorageContainer
	{
		name="StorageContainer";
		displayName="Storage";
		ghostIcon="set:dayz_inventory image:cat_common_cargo";
	};
	class Slot_WeaponHandguardPKM
	{
		name="WeaponHandguardPKM";
		displayName="#STR_CfgHandguard0";
		ghostIcon="handguard";
	};
	class Slot_WeaponHandguardL85
	{
		name="WeaponHandguardL85";
		displayName="#STR_CfgHandguard0";
		ghostIcon="handguard";
	};
	class Slot_weaponHandguardAKSU
	{
		name="weaponHandguardAKSU";
		displayName="#STR_CfgHandguard0";
		ghostIcon="handguard";
	};
	class Slot_weaponButtstockPKM
	{
		name="weaponButtstockPKM";
		displayName="#STR_CfgButtstock0";
		ghostIcon="buttstock";
	};
	class Slot_weaponButtstockScar
	{
		name="weaponButtstockScar";
		displayName="#STR_CfgButtstock0";
		ghostIcon="buttstock";
	};
	class Slot_weaponButtstockSVD
	{
		name="weaponButtstockSVD";
		displayName="#STR_CfgButtstock0";
		ghostIcon="buttstock";
	};
	class Slot_weaponHandguardSVD
	{
		name="weaponHandguardSVD";
		displayName="#STR_CfgHandguard0";
		ghostIcon="handguard";
	};
	class Slot_weaponHandguardFAL
	{
		name="weaponHandguardFAL";
		displayName="#STR_CfgHandguard0";
		ghostIcon="handguard";
	};
	class Slot_weaponBipod
	{
		name="weaponBipod";
		displayName="$STR_weaponBipod";
		ghostIcon="set:TF image:bipod";
	};
	class Slot_Helmet_SLAAP
	{
		name="Helmet_SLAAP";
		displayName="SLAAP";
	};
	class Slot_Helmet_IR
	{
		name="Helmet_IR";
		displayName="IR Marker";
	};
	class Slot_Cassette
	{
		name="Cassette";
		displayName="Cassette";
		ghostIcon="set:icons image:cassette_tape";
		ghostIconSize=0.80000001;
	};
	class Slot_weaponOpticsHandguard
	{
		name="weaponOpticsHandguard";
		displayName="Handguard Optic";
		ghostIcon="set:dayz_inventory image:weaponopticssmall";
	};
	class Slot_weaponIrons
	{
		name="weaponIrons";
		displayName="Iron Sights";
		ghostIcon="set:ironsighticon image:ironsight";
	};
	class Slot_weaponOpticsCover
	{
		name="weaponOpticsCover";
		displayName="weaponOpticsCover";
		ghostIcon="set:dayz_inventory image:weaponoptics";
	};
	class Slot_weaponHandguardG36
	{
		name="weaponHandguardG36";
		displayName="G36 Handguard";
		ghostIcon="set:dayz_inventory image:handguard";
	};
	class Slot_weaponHandguardG28
	{
		name="weaponHandguardG28";
		displayName="G28 Handguard";
		ghostIcon="set:dayz_inventory image:handguard";
	};
	class Slot_weaponHandguardAR10
	{
		name="weaponHandguardAR10";
		displayName="AR10 Handguard";
		ghostIcon="set:dayz_inventory image:handguard";
	};
	class Slot_weaponHandguard9A91
	{
		name="weaponHandguard9A91";
		displayName="weaponHandguard9A91";
		ghostIcon="set:dayz_inventory image:handguard";
	};
	class Slot_weaponCoverAK
	{
		name="weaponCoverAK";
		displayName="#STR_weaponAKReceiver";
		ghostIcon="set:TF image:cover";
	};
	class Slot_Patch
	{
		name="Patch";
		displayName="Patch";
		ghostIcon="set:icons image:patch";
		ghostIconSize=0.69999999;
	};
	class Slot_Carabiner1
	{
		name="Carabiner1";
		displayName="Carabiner";
		ghostIcon="set:icons image:carabiner";
		ghostIconSize=0.69999999;
	};
	class Slot_Carabiner2
	{
		name="Carabiner2";
		displayName="Carabiner";
		ghostIcon="set:icons image:carabiner";
		ghostIconSize=0.69999999;
	};
	class Slot_AdminPouch
	{
		name="AdminPouch";
		displayName="Admin Pouch";
		ghostIcon="set:icons image:phone";
		ghostIconSize=0.69999999;
	};
	class Slot_DumpPouch
	{
		name="DumpPouch";
		displayName="Dump Pouch";
	};
	class Slot_SidePouch1
	{
		name="SidePouch1";
		displayName="Pouch";
		ghostIcon="set:RA image:magpouch";
	};
	class Slot_SidePouch2
	{
		name="SidePouch2";
		displayName="Pouch";
		ghostIcon="set:RA image:magpouch";
	};
	class Slot_SidePouch3
	{
		name="SidePouch3";
		displayName="Pouch";
		ghostIcon="set:RA image:magpouch";
	};
	class Slot_SidePouch4
	{
		name="SidePouch4";
		displayName="Pouch";
		ghostIcon="set:RA image:magpouch";
	};
	class Slot_Armor_Vest
	{
		name="Armor_Vest";
		displayName="Armor_Vest";
	};
	class Slot_weaponDMRAdapter
	{
		name="weaponDMRAdapter";
		displayName="weaponDMRAdapter";
	};
	class Slot_weaponForegrip
	{
		name="weaponForegrip";
		displayName="$STR_weaponGrip";
		ghostIcon="set:TF image:angled";
	};
	class Slot_weaponPistolGrip
	{
		name="weaponPistolGrip";
		displayName="$STR_TF_PistolGrip";
		ghostIcon="set:TF image:pistolgrip";
	};
	class Slot_weaponPistolGripAK
	{
		name="weaponPistolGripAK";
		displayName="$STR_TF_PistolGrip";
		ghostIcon="set:TF image:pistolgrip";
	};
	class Slot_weaponPistolGripFAL
	{
		name="weaponPistolGripFAL";
		displayName="$STR_TF_PistolGrip";
		ghostIcon="set:TF image:pistolgrip";
	};
	class Slot_weaponButtstockG36
	{
		name="weaponButtstockG36";
		displayName="weaponButtstockG36";
		ghostIcon="set:m4buttstockicon image:m4buttstock";
	};
	class Slot_weaponButtstockVAL
	{
		name="weaponButtstockVAL";
		displayName="weaponButtstockVAL";
		ghostIcon="set:dayz_inventory image:buttstock";
	};
	class Slot_weaponButtstock9A91
	{
		name="weaponButtstock9A91";
		displayName="weaponButtstock9A91";
		ghostIcon="set:dayz_inventory image:buttstock";
	};
	class Slot_weaponButtstockVSS
	{
		name="weaponButtstockVSS";
		displayName="weaponButtstockVSS";
		ghostIcon="set:dayz_inventory image:buttstock";
	};
	class Slot_weaponButtstockM4
	{
		name="weaponButtstockM4";
		displayName="#STR_CfgButtstock0";
		ghostIcon="set:m4buttstockicon image:m4buttstock";
	};
	class Slot_weaponButtstockAPS
	{
		name="weaponButtstockAPS";
		displayName="weaponButtstockAPS";
		ghostIcon="set:dayz_inventory image:buttstock";
	};
	class Slot_Helmet_Pouch
	{
		name="Helmet_Pouch";
		displayName="Pouch";
	};
	class Slot_TraumaRoll
	{
		name="TraumaRoll";
		displayName="Fanny Pouch";
	};
	class Slot_TraumaRoll1
	{
		name="TraumaRoll1";
		displayName="Medical Item";
		ghostIcon="set:dayz_inventory image:medicalbandage";
	};
	class Slot_TraumaRoll2
	{
		name="TraumaRoll2";
		displayName="Medical Item";
		ghostIcon="set:dayz_inventory image:medicalbandage";
	};
	class Slot_TraumaRoll3
	{
		name="TraumaRoll3";
		displayName="Medical Item";
		ghostIcon="set:dayz_inventory image:medicalbandage";
	};
	class Slot_TraumaRoll4
	{
		name="TraumaRoll4";
		displayName="Medical Item";
		ghostIcon="set:dayz_inventory image:medicalbandage";
	};
	class Slot_TraumaRoll5
	{
		name="TraumaRoll5";
		displayName="Medical Item";
		ghostIcon="set:dayz_inventory image:medicalbandage";
	};
	class Slot_Mag1
	{
		name="Mag1";
		displayName="Magazine";
		ghostIcon="set:dayz_inventory image:magazine2";
	};
	class Slot_Mag2
	{
		name="Mag2";
		displayName="Magazine";
		ghostIcon="set:dayz_inventory image:magazine2";
	};
	class Slot_Mag3
	{
		name="Mag3";
		displayName="Magazine";
		ghostIcon="set:dayz_inventory image:magazine2";
	};
	class Slot_Mag4
	{
		name="Mag4";
		displayName="Magazine";
		ghostIcon="set:dayz_inventory image:magazine2";
	};
	class Slot_Mag5
	{
		name="Mag5";
		displayName="Magazine";
		ghostIcon="set:dayz_inventory image:magazine2";
	};
	class Slot_SMGMag1
	{
		name="SMGMag1";
		displayName="Pistol Magazine";
		ghostIcon="set:dayz_inventory image:magazine3";
	};
	class Slot_SMGMag2
	{
		name="SMGMag2";
		displayName="Pistol Magazine";
		ghostIcon="set:dayz_inventory image:magazine3";
	};
	class Slot_SMGMag3
	{
		name="SMGMag3";
		displayName="Pistol Magazine";
		ghostIcon="set:dayz_inventory image:magazine3";
	};
	class Slot_SMGMag4
	{
		name="SMGMag4";
		displayName="Pistol Magazine";
		ghostIcon="set:dayz_inventory image:magazine3";
	};
	class Slot_Fast_Ears
	{
		name="Fast_Ears";
		displayName="Ears";
	};
	class Slot_Helmet_Visor
	{
		name="Helmet_Visor";
		displayName="Visor";
		ghostIcon="set:dayz_inventory image:gorkavisor";
	};
	class Slot_Helmet_Cover
	{
		name="Helmet_Cover";
		displayName="Helmet_Cover";
		ghostIcon="headgear";
	};
	class Slot_Helmet_Goggles
	{
		name="Helmet_Goggles";
		displayName="Helmet Goggles";
		ghostIcon="set:dayz_inventory image:eyewear";
	};
	class Slot_Weapon01
	{
		name="Weapon01";
		displayName="Weapon01";
	};
	class Slot_weaponMuzzle9A91
	{
		name="weaponMuzzle9A91";
		displayName="9A-91 Suppressor";
		ghostIcon="set:dayz_inventory image:supressor";
	};
	class Slot_weaponMuzzle762
	{
		name="weaponMuzzle762";
		displayName="7.62 Muzzle";
		ghostIcon="set:dayz_inventory image:supressor";
	};
	class Slot_weaponMuzzleShotGun
	{
		name="weaponMuzzleShotGun";
		displayName="12 Gauge Muzzle";
		ghostIcon="set:dayz_inventory image:supressor";
	};
	class Slot_weaponMuzzleASH
	{
		name="weaponMuzzleASH";
		displayName="ASH12 Suppressor";
		ghostIcon="set:dayz_inventory image:supressor";
	};
	class Slot_338_Muzzle
	{
		name="338_Muzzle";
		displayName=".338 Muzzle";
		ghostIcon="set:dayz_inventory image:supressor";
	};
	class Slot_weaponMuzzle308
	{
		name="weaponMuzzle308";
		displayName=".308 Muzzle";
		ghostIcon="set:dayz_inventory image:supressor";
	};
	class Slot_weaponMagnifier
	{
		name="weaponMagnifier";
		displayName="Magnifier";
		ghostIcon="set:dayz_inventory image:weaponopticssmall";
	};
	class Slot_WatchCompass
	{
		name="WatchCompass";
		displayName="WatchCompass";
	};
	class Slot_AH6Rockets
	{
		name="AH6Rockets";
		displayName="AH6Rockets";
		stackMax=14;
	};
	class Slot_ruble_1
	{
		name="ruble_1";
		displayName="Rubles";
		ghostIcon="set:RubbleIcon image:Rubbles_Icon";
	};
	class Slot_ruble_2
	{
		name="ruble_2";
		displayName="Rubles";
		ghostIcon="set:RubbleIcon image:Rubbles_Icon";
	};
	class Slot_ruble_3
	{
		name="ruble_3";
		displayName="Rubles";
		ghostIcon="set:RubbleIcon image:Rubbles_Icon";
	};
	class Slot_ruble_4
	{
		name="ruble_4";
		displayName="Rubles";
		ghostIcon="set:RubbleIcon image:Rubbles_Icon";
	};
	class Slot_ruble_5
	{
		name="ruble_5";
		displayName="Rubles";
		ghostIcon="set:RubbleIcon image:Rubbles_Icon";
	};
	class Slot_key_1
	{
		name="key_1";
		displayName="Key";
		ghostIcon="set:KeyIcons image:Keys";
	};
	class Slot_key_2
	{
		name="key_2";
		displayName="Key";
		ghostIcon="set:KeyIcons image:Keys";
	};
	class Slot_key_3
	{
		name="key_3";
		displayName="Key";
		ghostIcon="set:KeyIcons image:Keys";
	};
	class Slot_key_4
	{
		name="key_4";
		displayName="Key";
		ghostIcon="set:KeyIcons image:Keys";
	};
	class Slot_key_5
	{
		name="key_5";
		displayName="Key";
		ghostIcon="set:KeyIcons image:Keys";
	};
	class Slot_key_6
	{
		name="key_6";
		displayName="Key";
		ghostIcon="set:KeyIcons image:Keys";
	};
	class Slot_keycard_1
	{
		name="keycard_1";
		displayName="Key Card";
		ghostIcon="set:KeyIcons image:KeyCards";
	};
	class Slot_keycard_2
	{
		name="keycard_2";
		displayName="Key Card";
		ghostIcon="set:KeyIcons image:KeyCards";
	};
	class Slot_keycard_3
	{
		name="keycard_3";
		displayName="Key Card";
		ghostIcon="set:KeyIcons image:KeyCards";
	};
	class Slot_keycard_4
	{
		name="keycard_4";
		displayName="Key Card";
		ghostIcon="set:KeyIcons image:KeyCards";
	};
	class Slot_window
	{
		name="window";
		displayName="Window";
	};
	class Slot_shutters1
	{
		name="shutters1";
		displayName="Shutters";
	};
	class Slot_shutters2
	{
		name="shutters2";
		displayName="Shutters";
	};
	class Slot_AmmoBox1
	{
		name="AmmoBox1";
		displayName="Ammo Box";
		ghostIcon="set:dayz_inventory image:cat_common_cargo";
	};
	class Slot_AmmoBox2
	{
		name="AmmoBox2";
		displayName="Ammo Box";
		ghostIcon="set:dayz_inventory image:cat_common_cargo";
	};
	class Slot_AmmoBox3
	{
		name="AmmoBox3";
		displayName="Ammo Box";
		ghostIcon="set:dayz_inventory image:cat_common_cargo";
	};
	class Slot_AmmoBox4
	{
		name="AmmoBox4";
		displayName="Ammo Box";
		ghostIcon="set:dayz_inventory image:cat_common_cargo";
	};
	class Slot_AmmoBox5
	{
		name="AmmoBox5";
		displayName="Ammo Box";
		ghostIcon="set:dayz_inventory image:cat_common_cargo";
	};
	class Slot_Pistol1
	{
		name="Pistol1";
		displayName="Pistol";
		ghostIcon="pistol";
	};
	class Slot_Pistol2
	{
		name="Pistol2";
		displayName="Pistol";
		ghostIcon="pistol";
	};
	class Slot_Pistol3
	{
		name="Pistol3";
		displayName="Pistol";
		ghostIcon="pistol";
	};
	class Slot_Pistol4
	{
		name="Pistol4";
		displayName="Pistol";
		ghostIcon="pistol";
	};
	class Slot_Pistol5
	{
		name="Pistol5";
		displayName="Pistol";
		ghostIcon="pistol";
	};
	class Slot_Pistol6
	{
		name="Pistol6";
		displayName="Pistol";
		ghostIcon="pistol";
	};
	class Slot_Pistol7
	{
		name="Pistol7";
		displayName="Pistol";
		ghostIcon="pistol";
	};
	class Slot_Pistol8
	{
		name="Pistol8";
		displayName="Pistol";
		ghostIcon="pistol";
	};
	class Slot_Pistol9
	{
		name="Pistol9";
		displayName="Pistol";
		ghostIcon="pistol";
	};
	class Slot_Pistol10
	{
		name="Pistol10";
		displayName="Pistol";
		ghostIcon="pistol";
	};
	class Slot_Shoulder1
	{
		name="Shoulder1";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder2
	{
		name="Shoulder2";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder3
	{
		name="Shoulder3";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder4
	{
		name="Shoulder4";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder5
	{
		name="Shoulder5";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder6
	{
		name="Shoulder6";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder7
	{
		name="Shoulder7";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder8
	{
		name="Shoulder8";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder9
	{
		name="Shoulder9";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder10
	{
		name="Shoulder10";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder11
	{
		name="Shoulder11";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder12
	{
		name="Shoulder12";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder13
	{
		name="Shoulder13";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder14
	{
		name="Shoulder14";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder15
	{
		name="Shoulder15";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder16
	{
		name="Shoulder16";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder17
	{
		name="Shoulder17";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder18
	{
		name="Shoulder18";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder19
	{
		name="Shoulder19";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder20
	{
		name="Shoulder20";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_bandage1
	{
		name="bandage1";
		displayName="Bandage";
		ghostIcon="";
	};
	class Slot_bandage2
	{
		name="bandage2";
		displayName="Bandage";
		ghostIcon="";
	};
	class Slot_bandage3
	{
		name="bandage3";
		displayName="Bandage";
		ghostIcon="";
	};
	class Slot_bandage4
	{
		name="bandage4";
		displayName="Bandage";
		ghostIcon="";
	};
	class Slot_bandage5
	{
		name="bandage5";
		displayName="Bandage";
		ghostIcon="";
	};
	class Slot_bandage6
	{
		name="bandage6";
		displayName="Bandage";
		ghostIcon="";
	};
	class Slot_bandage7
	{
		name="bandage7";
		displayName="Bandage";
		ghostIcon="";
	};
	class Slot_bandage8
	{
		name="bandage8";
		displayName="Bandage";
		ghostIcon="";
	};
	class Slot_medbag1
	{
		name="medbag1";
		displayName="Transfusion Bags";
		ghostIcon="";
	};
	class Slot_medbag2
	{
		name="medbag2";
		displayName="Transfusion Bags";
		ghostIcon="";
	};
	class Slot_medbag3
	{
		name="medbag3";
		displayName="Transfusion Bags";
		ghostIcon="";
	};
	class Slot_medbag4
	{
		name="medbag4";
		displayName="Transfusion Bags";
		ghostIcon="";
	};
	class Slot_medstick1
	{
		name="medstick1";
		displayName="Medical Stim";
		ghostIcon="";
	};
	class Slot_medstick2
	{
		name="medstick2";
		displayName="Medical Stim";
		ghostIcon="";
	};
	class Slot_medstick3
	{
		name="medstick3";
		displayName="Medical Stim";
		ghostIcon="";
	};
	class Slot_medstick4
	{
		name="medstick4";
		displayName="Medical Stim";
		ghostIcon="";
	};
	class Slot_medstick5
	{
		name="medstick5";
		displayName="Medical Stim";
		ghostIcon="";
	};
	class Slot_medstick6
	{
		name="medstick6";
		displayName="Medical Stim";
		ghostIcon="";
	};
	class Slot_medstick7
	{
		name="medstick7";
		displayName="Medical Stim";
		ghostIcon="";
	};
	class Slot_medstick8
	{
		name="medstick8";
		displayName="Medical Stim";
		ghostIcon="";
	};
	class Slot_splint1
	{
		name="splint1";
		displayName="ALU Splint";
		ghostIcon="";
	};
	class Slot_splint2
	{
		name="splint2";
		displayName="ALU Splint";
		ghostIcon="";
	};
	class Slot_splint3
	{
		name="splint3";
		displayName="ALU Splint";
		ghostIcon="";
	};
	class Slot_grenade1
	{
		name="grenade1";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade2
	{
		name="grenade2";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade3
	{
		name="grenade3";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade4
	{
		name="grenade4";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade5
	{
		name="grenade5";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade6
	{
		name="grenade6";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade7
	{
		name="grenade7";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade8
	{
		name="grenade8";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade9
	{
		name="grenade9";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade10
	{
		name="grenade10";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade11
	{
		name="grenade11";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade12
	{
		name="grenade12";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade13
	{
		name="grenade13";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade14
	{
		name="grenade14";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade15
	{
		name="grenade15";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade16
	{
		name="grenade16";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade17
	{
		name="grenade17";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade18
	{
		name="grenade18";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade19
	{
		name="grenade19";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_grenade20
	{
		name="grenade20";
		displayName="#STR_CfgVestGrenade0";
		ghostIcon="set:dayz_inventory image:grenade";
	};
	class Slot_Gun_Bag_1
	{
		name="Gun_Bag_1";
		displayName="Gun_Bag_1";
	};
	class Slot_Gun_Bag_2
	{
		name="Gun_Bag_2";
		displayName="Gun_Bag_2";
	};
	class Slot_Gun_Bag_3
	{
		name="Gun_Bag_3";
		displayName="Gun_Bag_3";
	};
	class Slot_Gun_Bag_4
	{
		name="Gun_Bag_4";
		displayName="Gun_Bag_4";
	};
	class Slot_Gun_Bag_5
	{
		name="Gun_Bag_5";
		displayName="Gun_Bag_5";
	};
	class Slot_Gun_Bag_6
	{
		name="Gun_Bag_6";
		displayName="Gun_Bag_6";
	};
	class Slot_LargeTool1
	{
		name="LargeTool1";
		displayName="Large Tool";
		ghostIcon="set:icons image:shovel";
		ghostIconSize=0.60000002;
	};
	class Slot_LargeTool2
	{
		name="LargeTool2";
		displayName="Large Tool";
		ghostIcon="set:icons image:shovel";
		ghostIconSize=0.60000002;
	};
	class Slot_LargeTool3
	{
		name="LargeTool3";
		displayName="Large Tool";
		ghostIcon="set:icons image:shovel";
		ghostIconSize=0.60000002;
	};
	class Slot_LargeTool4
	{
		name="LargeTool4";
		displayName="Large Tool";
		ghostIcon="set:icons image:shovel";
		ghostIconSize=0.60000002;
	};
	class Slot_SmallTool1
	{
		name="SmallTool1";
		displayName="Small Tool";
		ghostIcon="set:icons image:hammer";
		ghostIconSize=0.69999999;
	};
	class Slot_SmallTool2
	{
		name="SmallTool2";
		displayName="Small Tool";
		ghostIcon="set:icons image:hammer";
		ghostIconSize=0.69999999;
	};
	class Slot_SmallTool3
	{
		name="SmallTool3";
		displayName="Small Tool";
		ghostIcon="set:icons image:hammer";
		ghostIconSize=0.69999999;
	};
	class Slot_SmallTool4
	{
		name="SmallTool4";
		displayName="Small Tool";
		ghostIcon="set:icons image:hammer";
		ghostIconSize=0.69999999;
	};
	class Slot_SmallTool5
	{
		name="SmallTool5";
		displayName="Small Tool";
		ghostIcon="set:icons image:hammer";
		ghostIconSize=0.69999999;
	};
	class Slot_SmallTool6
	{
		name="SmallTool6";
		displayName="Small Tool";
		ghostIcon="set:icons image:hammer";
		ghostIconSize=0.69999999;
	};
	class Slot_SmallTool7
	{
		name="SmallTool7";
		displayName="Small Tool";
		ghostIcon="set:icons image:hammer";
		ghostIconSize=0.69999999;
	};
	class Slot_SmallTool8
	{
		name="SmallTool8";
		displayName="Small Tool";
		ghostIcon="set:icons image:hammer";
		ghostIconSize=0.69999999;
	};
	class Slot_SmallTool9
	{
		name="SmallTool9";
		displayName="Small Tool";
		ghostIcon="set:icons image:hammer";
		ghostIconSize=0.69999999;
	};
	class Slot_SmallTool10
	{
		name="SmallTool10";
		displayName="Small Tool";
		ghostIcon="set:icons image:hammer";
		ghostIconSize=0.69999999;
	};
	class Slot_SmallTool11
	{
		name="SmallTool11";
		displayName="Small Tool";
		ghostIcon="set:icons image:hammer";
		ghostIconSize=0.69999999;
	};
	class Slot_SmallTool12
	{
		name="SmallTool12";
		displayName="Small Tool";
		ghostIcon="set:icons image:hammer";
		ghostIconSize=0.69999999;
	};
	class Slot_SmallTool13
	{
		name="SmallTool13";
		displayName="Small Tool";
		ghostIcon="set:icons image:hammer";
		ghostIconSize=0.69999999;
	};
	class Slot_SmallTool14
	{
		name="SmallTool14";
		displayName="Small Tool";
		ghostIcon="set:icons image:hammer";
		ghostIconSize=0.69999999;
	};
	class Slot_SmallTool15
	{
		name="SmallTool15";
		displayName="Small Tool";
		ghostIcon="set:icons image:hammer";
		ghostIconSize=0.69999999;
	};
	class Slot_SmallTool16
	{
		name="SmallTool16";
		displayName="Small Tool";
		ghostIcon="set:icons image:hammer";
		ghostIconSize=0.69999999;
	};
	class Slot_Mask1
	{
		name="Mask1";
		displayName="#STR_CfgMask0";
		ghostIcon="set:dayz_inventory image:mask";
	};
	class Slot_Eyewear1
	{
		name="Eyewear1";
		displayName="#STR_CfgEyewear0";
		ghostIcon="set:dayz_inventory image:eyewear";
	};
	class Slot_Hands1
	{
		name="Hands1";
		displayName="";
		ghostIcon="set:dayz_inventory image:hands";
		boneName="RightHand";
	};
	class Slot_Gloves1
	{
		name="Gloves1";
		displayName="#STR_CfgGloves0";
		ghostIcon="set:dayz_inventory image:gloves";
	};
	class Slot_Armband1
	{
		name="Armband1";
		displayName="#STR_CfgArmband0";
		ghostIcon="set:dayz_inventory image:armband";
	};
	class Slot_Vest1
	{
		name="Vest1";
		displayName="#STR_CfgVest0";
		ghostIcon="set:dayz_inventory image:vest";
	};
	class Slot_Body1
	{
		name="Body1";
		displayName="#STR_CfgBody0";
		ghostIcon="set:dayz_inventory image:body";
	};
	class Slot_Back1
	{
		name="Back1";
		displayName="#STR_CfgBack0";
		ghostIcon="set:dayz_inventory image:back";
	};
	class Slot_Hips1
	{
		name="Hips1";
		displayName="#STR_CfgHips0";
		ghostIcon="set:dayz_inventory image:hips";
	};
	class Slot_Legs1
	{
		name="Legs1";
		displayName="#STR_CfgLegs0";
		ghostIcon="set:dayz_inventory image:legs";
	};
	class Slot_Feet1
	{
		name="Feet1";
		displayName="#STR_CfgFeet0";
		ghostIcon="set:dayz_inventory image:feet";
	};
	class Slot_Mask2
	{
		name="Mask2";
		displayName="#STR_CfgMask0";
		ghostIcon="set:dayz_inventory image:mask";
	};
	class Slot_Eyewear2
	{
		name="Eyewear2";
		displayName="#STR_CfgEyewear0";
		ghostIcon="set:dayz_inventory image:eyewear";
	};
	class Slot_Hands2
	{
		name="Hands2";
		displayName="";
		ghostIcon="set:dayz_inventory image:hands";
		boneName="RightHand";
	};
	class Slot_Gloves2
	{
		name="Gloves2";
		displayName="#STR_CfgGloves0";
		ghostIcon="set:dayz_inventory image:gloves";
	};
	class Slot_Armband2
	{
		name="Armband2";
		displayName="#STR_CfgArmband0";
		ghostIcon="set:dayz_inventory image:armband";
	};
	class Slot_Vest2
	{
		name="Vest2";
		displayName="#STR_CfgVest0";
		ghostIcon="set:dayz_inventory image:vest";
	};
	class Slot_Body2
	{
		name="Body2";
		displayName="#STR_CfgBody0";
		ghostIcon="set:dayz_inventory image:body";
	};
	class Slot_Back2
	{
		name="Back2";
		displayName="#STR_CfgBack0";
		ghostIcon="set:dayz_inventory image:back";
	};
	class Slot_Hips2
	{
		name="Hips2";
		displayName="#STR_CfgHips0";
		ghostIcon="set:dayz_inventory image:hips";
	};
	class Slot_Legs2
	{
		name="Legs2";
		displayName="#STR_CfgLegs0";
		ghostIcon="set:dayz_inventory image:legs";
	};
	class Slot_Feet2
	{
		name="Feet2";
		displayName="#STR_CfgFeet0";
		ghostIcon="set:dayz_inventory image:feet";
	};
	class Slot_Mask3
	{
		name="Mask3";
		displayName="#STR_CfgMask0";
		ghostIcon="set:dayz_inventory image:mask";
	};
	class Slot_Eyewear3
	{
		name="Eyewear3";
		displayName="#STR_CfgEyewear0";
		ghostIcon="set:dayz_inventory image:eyewear";
	};
	class Slot_Hands3
	{
		name="Hands3";
		displayName="";
		ghostIcon="set:dayz_inventory image:hands";
		boneName="RightHand";
	};
	class Slot_Gloves3
	{
		name="Gloves3";
		displayName="#STR_CfgGloves0";
		ghostIcon="set:dayz_inventory image:gloves";
	};
	class Slot_Armband3
	{
		name="Armband3";
		displayName="#STR_CfgArmband0";
		ghostIcon="set:dayz_inventory image:armband";
	};
	class Slot_Vest3
	{
		name="Vest3";
		displayName="#STR_CfgVest0";
		ghostIcon="set:dayz_inventory image:vest";
	};
	class Slot_Body3
	{
		name="Body3";
		displayName="#STR_CfgBody0";
		ghostIcon="set:dayz_inventory image:body";
	};
	class Slot_Back3
	{
		name="Back3";
		displayName="#STR_CfgBack0";
		ghostIcon="set:dayz_inventory image:back";
	};
	class Slot_Hips3
	{
		name="Hips3";
		displayName="#STR_CfgHips0";
		ghostIcon="set:dayz_inventory image:hips";
	};
	class Slot_Legs3
	{
		name="Legs3";
		displayName="#STR_CfgLegs0";
		ghostIcon="set:dayz_inventory image:legs";
	};
	class Slot_Feet3
	{
		name="Feet3";
		displayName="#STR_CfgFeet0";
		ghostIcon="set:dayz_inventory image:feet";
	};
};
