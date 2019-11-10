#pragma once
#include <map>
#include <vector>

enum EffectType : int;

struct EffectInfo
{
public:
	EffectInfo(const char* name, const char* id, bool isTimed = false, std::vector<EffectType> incompatibleList = {}, bool shortDur = false)
		: Name(name), Id(id), IsTimed(isTimed), IsShortDuration(shortDur), IncompatibleWith(incompatibleList)
	{}
	//EffectInfo() : Name("???"), Id("???"), IsTimed(false), IsShortDuration(false), IncompatibleWith({}) {}

public:
	const char* Name;
	const char* Id;
	const bool IsTimed;
	const bool IsShortDuration;
	const std::vector<EffectType> IncompatibleWith;
};

enum EffectType : int
{
	EFFECT_KILL,
	EFFECT_PLUS_2_STARS,
	EFFECT_5_STARS,
	EFFECT_CLEAR_STARS,
	EFFECT_NEVER_WANTED,
	EFFECT_STRIP_WEAPONS,
	EFFECT_GIVE_RPG,
	EFFECT_GIVE_MINIGUN,
	EFFECT_GIVE_PARACHUTE,
	EFFECT_GIVE_PISTOL,
	EFFECT_GIVE_TAZER,
	EFFECT_GIVE_RAILGUN,
	EFFECT_GIVE_KNIFE,
	EFFECT_GIVE_BATTLEAXE,
	EFFECT_HEAL,
	EFFECT_ARMOR,
	EFFECT_IGNITE,
	EFFECT_ANGRY_JESUS,
	EFFECT_IGNITE_PEDS,
	EFFECT_EXPLODE_VEHS,
	EFFECT_PLAYER_LAUNCH,
	EFFECT_PLAYER_VEH_LAUNCH,
	EFFECT_VEHS_LAUNCH,
	EFFECT_PLAYER_VEH_LOCK,
	EFFECT_NOTHING,
	EFFECT_KILL_ENGINE,
	EFFECT_TIME_MORNING,
	EFFECT_TIME_DAY,
	EFFECT_TIME_EVENING,
	EFFECT_TIME_NIGHT,
	EFFECT_WEATHER_SUNNY,
	EFFECT_WEATHER_EXTRASUNNY,
	EFFECT_WEATHER_RAINY,
	EFFECT_WEATHER_THUNDER,
	EFFECT_WEATHER_FOGGY,
	EFFECT_WEATHER_NEUTRAL,
	EFFECT_WEATHER_XMAS,
	EFFECT_TP_LSAIRPORT,
	EFFECT_TP_MAZETOWER,
	EFFECT_TP_FORTZANCUDO,
	EFFECT_TP_MOUNTCHILLIAD,
	EFFECT_NO_PHONE,
	EFFECT_SET_INTO_CLOSEST_VEH,
	EFFECT_EXIT_CURRENT_VEH,
	EFFECT_GAMESPEED_X05,
	EFFECT_GAMESPEED_X02,
	EFFECT_GAMESPEED_LAG,
	EFFECT_PEDS_RIOT,
	EFFECT_RED_VEHS,
	EFFECT_BLUE_VEHS,
	EFFECT_GREEN_VEHS,
	EFFECT_BLACK_VEHS,
	EFFECT_CHROME_VEHS,
	EFFECT_PINK_VEHS,
	EFFECT_RAINBOW_VEHS,
	EFFECT_FORCED_FP,
	EFFECT_SLIPPERY_VEHS,
	EFFECT_NO_GRAV_VEHS,
	EFFECT_PLAYER_INVINCIBLE,
	EFFECT_2XENGINE_VEHS,
	EFFECT_10XENGINE_VEHS,
	EFFECT_05XENGINE_VEHS,
	EFFECT_SPAWN_TANK,
	EFFECT_SPAWN_ADDER,
	EFFECT_SPAWN_DUMP,
	EFFECT_SPAWN_MONSTER,
	EFFECT_SPAWN_BMX,
	EFFECT_SPAWN_TUG,
	EFFECT_SPAWN_CARGO,
	EFFECT_SPAWN_BUS,
	EFFECT_SPAWN_BLIMP,
	EFFECT_SPAWN_BUZZARD,
	EFFECT_SPAWN_FAGGIO,
	EFFECT_SPAWN_RUINER3,
	EFFECT_NO_VEHS,
	EFFECT_NO_PEDS,
	EFFECT_EXPLODE_CUR_VEH,
	EFFECT_PEDS_INVISIBLE,
	EFFECT_VEHS_INVISIBLE,
	EFFECT_NO_RADAR,
	EFFECT_NO_HUD,
	EFFECT_SUPER_RUN,
	EFFECT_SUPER_JUMP,
	EFFECT_PLAYER_RAGDOLL,
	EFFECT_PEDS_RAGDOLL_ON_TOUCH,
	EFFECT_PLUS_100K,
	EFFECT_MINUS_100K,
	EFFECT_PEDS_FOLLOW_PLAYER,
	EFFECT_PLAYER_DRUNK,
	EFFECT_PEDS_OHKO,
	EFFECT_PEDS_NO_FEAR,
	EFFECT_SCREEN_BLOOM,
	EFFECT_SCREEN_LSD,
	EFFECT_SCREEN_REALLSD,
	EFFECT_SCREEN_CHOPVISION,
	EFFECT_PEDS_IGNORE_PLAYER,
	EFFECT_HONK_BOOSTING,
	EFFECT_MIN_DAMAGE,
	EFFECT_NO_HEADSHOTS,
	EFFECT_PEDS_FROZEN,
	EFFECT_LOW_GRAV,
	EFFECT_VERY_LOW_GRAV,
	EFFECT_INSANE_GRAV,
	EFFECT_VEH_REPAIR,
	EFFECT_VEH_POP_TIRES,
	EFFECT_ALL_VEH_POP_TIRES,
	EFFECT_NO_SPECIAL_ABILITY,
	EFFECT_IN_THE_HOOD,
	EFFECT_FORCED_CINEMATIC,
	EFFECT_PEDS_FLEE,
	EFFECT_BREAK_VEH_DOORS,
	EFFECT_ZOMBIES,
	EFFECT_METEOR_RAIN,
	EFFECT_BLIND,
	EFFECT_BLACKOUT,
	EFFECT_QUICK_TIME,
	EFFECT_PAUSE_TIME,
	EFFECT_MOV_NO_UD,
	EFFECT_MOV_NO_LR,
	EFFECT_BREAK,
	EFFECT_EVERYONE_RPG,
	EFFECT_EVERYONE_TAZER,
	EFFECT_EVERYONE_MINIGUN,
	EFFECT_PEDS_FAST_FIRING,
	EFFECT_NO_SPRINT,
	EFFECT_NO_JUMP,
	EFFECT_EVERYONE_INVINCIBLE,
	EFFECT_VEHS_INVINCIBLE,
	EFFECT_PLAYER_SHOT_RAGDOLL,
	EFFECT_JUMPY_VEHS,
	EFFECT_LOCK_VEHS,
	EFFECT_TOTAL_CHAOS,
	EFFECT_NO_RAGDOLL,
	EFFECT_VEHS_HORN,
	EFFECT_TP_WAYPOINT,
	EFFECT_PEDS_SAY_HI,
	EFFECT_PEDS_INSULT,
	EFFECT_EXPLOSIVE_BULLETS,
	EFFECT_EXPLOSIVE_PUNCH,
	EFFECT_GIVE_ALL_WEPS,
	_EFFECT_ENUM_MAX
};

const std::map<EffectType, EffectInfo> g_effectsMap =
{
	{EFFECT_KILL, {"Suicide", "player_suicide"}},
	{EFFECT_PLUS_2_STARS, {"+2 Wanted Stars", "player_plus2stars"}},
	{EFFECT_5_STARS, {"5 Wanted Stars", "player_5stars"}},
	{EFFECT_CLEAR_STARS, {"Clear Wanted Level", "player_clearwanted"}},
	{EFFECT_NEVER_WANTED, {"Never Wanted", "player_neverwanted", true}},
	{EFFECT_STRIP_WEAPONS, {"Remove Weapons From Everyone", "peds_remweps"}},
	{EFFECT_GIVE_RPG, {"Give RPG", "player_giverpg"}},
	{EFFECT_GIVE_MINIGUN, {"Give Minigun", "player_giveminigun"}},
	{EFFECT_GIVE_PARACHUTE, {"Give Parachute", "player_giveparachute"}},
	{EFFECT_GIVE_PISTOL, {"Give Pistol", "player_givepistol"}},
	{EFFECT_GIVE_TAZER, {"Give Stungun", "player_givestungun"}},
	{EFFECT_GIVE_RAILGUN, {"Give Railgun", "player_giverailgun"}},
	{EFFECT_GIVE_KNIFE, {"Give Knife", "player_giveknife"}},
	{EFFECT_GIVE_BATTLEAXE, {"Give Battleaxe", "player_givebattleaxe"}},
	{EFFECT_HEAL, {"Heal Player", "player_heal"}},
	{EFFECT_ARMOR, {"Give Armor", "player_armor"}},
	{EFFECT_IGNITE, {"Ignite Player", "player_ignite"}},
	{EFFECT_ANGRY_JESUS, {"Spawn Griefer Jesus", "spawn_grieferjesus"}},
	{EFFECT_IGNITE_PEDS, {"Ignite All Nearby Peds", "peds_ignite"}},
	{EFFECT_EXPLODE_VEHS, {"Explode All Nearby Vehicles", "vehs_explode"}},
	{EFFECT_PLAYER_LAUNCH, {"Launch Player Up", "player_upupaway"}},
	{EFFECT_PLAYER_VEH_LAUNCH, {"Launch Current Vehicle Up", "playerveh_upupaway"}},
	{EFFECT_VEHS_LAUNCH, {"Launch All Vehicles Up", "vehs_upupaway"}},
	{EFFECT_PLAYER_VEH_LOCK, {"Lock Vehicle Player Is In", "playerveh_lock"}},
	{EFFECT_NOTHING, {"Nothing", "nothing"}},
	{EFFECT_KILL_ENGINE, {"Kill Engine Of Current Vehicle", "playerveh_killengine"}},
	{EFFECT_TIME_MORNING, {"Set Time To Morning", "time_morning"}},
	{EFFECT_TIME_DAY, {"Set Time To Daytime", "time_day"}},
	{EFFECT_TIME_EVENING, {"Set Time To Evening", "time_evening"}},
	{EFFECT_TIME_NIGHT, {"Set Time To Night", "time_night"}},
	{EFFECT_WEATHER_SUNNY, {"Sunny Weather", "weather_sunny"}},
	{EFFECT_WEATHER_EXTRASUNNY, {"Extra Sunny Weather", "weather_extrasunny"}},
	{EFFECT_WEATHER_RAINY, {"Rainy Weather", "weather_rainy"}},
	{EFFECT_WEATHER_THUNDER, {"Stormy Weather", "weather_stormy"}},
	{EFFECT_WEATHER_FOGGY, {"Foggy Weather", "weather_foggy"}},
	{EFFECT_WEATHER_NEUTRAL, {"Neutral Weather", "weather_neutral"}},
	{EFFECT_WEATHER_XMAS, {"Snowy Weather", "weather_snowy"}},
	{EFFECT_TP_LSAIRPORT, {"Teleport To LS Airport", "tp_lsairport"}},
	{EFFECT_TP_MAZETOWER, {"Teleport To Top Of Maze Bank Tower", "tp_mazebanktower"}},
	{EFFECT_TP_FORTZANCUDO, {"Teleport To Fort Zancudo", "tp_fortzancudo"}},
	{EFFECT_TP_MOUNTCHILLIAD, {"Teleport To Mount Chilliad", "tp_mountchilliad"}},
	{EFFECT_NO_PHONE, {"No Phone", "player_nophone", true}},
	{EFFECT_SET_INTO_CLOSEST_VEH, {"Set Player Into Closest Vehicle", "player_tpclosestveh"}},
	{EFFECT_EXIT_CURRENT_VEH, {"Exit Current Vehicle", "playerveh_exit"}},
	{EFFECT_GAMESPEED_X02, {"x0.2 Gamespeed", "time_x02", true, { EFFECT_GAMESPEED_X05, EFFECT_GAMESPEED_LAG }}},
	{EFFECT_GAMESPEED_X05, {"x0.5 Gamespeed", "time_x05", true, { EFFECT_GAMESPEED_X02, EFFECT_GAMESPEED_LAG }}},
	{EFFECT_GAMESPEED_LAG, {"Lag", "time_lag", true, { EFFECT_GAMESPEED_X02, EFFECT_GAMESPEED_X05 }}},
	{EFFECT_PEDS_RIOT, {"Peds Riot", "peds_riot", true}},
	{EFFECT_RED_VEHS, {"Red Traffic", "vehs_red", true, { EFFECT_BLUE_VEHS, EFFECT_GREEN_VEHS, EFFECT_BLACK_VEHS, EFFECT_RAINBOW_VEHS, EFFECT_VEHS_INVISIBLE, EFFECT_CHROME_VEHS, EFFECT_PINK_VEHS }}},
	{EFFECT_BLUE_VEHS, {"Blue Traffic", "vehs_blue", true, { EFFECT_RED_VEHS, EFFECT_GREEN_VEHS, EFFECT_BLACK_VEHS, EFFECT_RAINBOW_VEHS, EFFECT_VEHS_INVISIBLE, EFFECT_CHROME_VEHS, EFFECT_PINK_VEHS }}},
	{EFFECT_GREEN_VEHS, {"Green Traffic", "vehs_green", true, { EFFECT_RED_VEHS, EFFECT_BLUE_VEHS, EFFECT_BLACK_VEHS, EFFECT_RAINBOW_VEHS, EFFECT_VEHS_INVISIBLE, EFFECT_CHROME_VEHS, EFFECT_PINK_VEHS }}},
	{EFFECT_BLACK_VEHS, {"Black Traffic", "vehs_black", true, { EFFECT_RED_VEHS, EFFECT_BLUE_VEHS, EFFECT_GREEN_VEHS, EFFECT_RAINBOW_VEHS, EFFECT_VEHS_INVISIBLE, EFFECT_CHROME_VEHS, EFFECT_PINK_VEHS }}},
	{EFFECT_CHROME_VEHS, {"Chrome Traffic", "vehs_chrome", true, { EFFECT_RED_VEHS, EFFECT_BLUE_VEHS, EFFECT_GREEN_VEHS, EFFECT_RAINBOW_VEHS, EFFECT_BLACK_VEHS, EFFECT_VEHS_INVISIBLE, EFFECT_PINK_VEHS }}},
	{EFFECT_PINK_VEHS, {"Hot Traffic", "vehs_pink", true, { EFFECT_RED_VEHS, EFFECT_BLUE_VEHS, EFFECT_GREEN_VEHS, EFFECT_RAINBOW_VEHS, EFFECT_BLACK_VEHS, EFFECT_VEHS_INVISIBLE, EFFECT_CHROME_VEHS }}},
	{EFFECT_RAINBOW_VEHS, {"Rainbow Traffic", "vehs_rainbow", true, { EFFECT_RED_VEHS, EFFECT_BLUE_VEHS, EFFECT_GREEN_VEHS, EFFECT_BLACK_VEHS, EFFECT_VEHS_INVISIBLE, EFFECT_CHROME_VEHS, EFFECT_PINK_VEHS }}},
	{EFFECT_FORCED_FP, {"First Person", "player_firstperson", true, { EFFECT_FORCED_CINEMATIC }}},
	{EFFECT_SLIPPERY_VEHS, {"Slippery Vehicles", "vehs_slippery", true}},
	{EFFECT_NO_GRAV_VEHS, {"Vehicles Have No Gravity", "vehs_nogravity", true, {}, true}},
	{EFFECT_PLAYER_INVINCIBLE, {"Invincibility", "player_invincible", true}},
	{EFFECT_2XENGINE_VEHS, {"2x Vehicle Engine Speed", "vehs_x2engine", true, { EFFECT_10XENGINE_VEHS, EFFECT_05XENGINE_VEHS }}},
	{EFFECT_10XENGINE_VEHS, {"10x Vehicle Engine Speed", "vehs_x10engine", true, { EFFECT_2XENGINE_VEHS, EFFECT_05XENGINE_VEHS }}},
	{EFFECT_05XENGINE_VEHS, {"0.5x Vehicle Engine Speed", "vehs_x05engine", true, { EFFECT_2XENGINE_VEHS, EFFECT_10XENGINE_VEHS }}},
	{EFFECT_SPAWN_TANK, {"Spawn Rhino", "spawn_rhino"}},
	{EFFECT_SPAWN_ADDER, {"Spawn Adder", "spawn_adder"}},
	{EFFECT_SPAWN_DUMP, {"Spawn Dump", "spawn_dump"}},
	{EFFECT_SPAWN_MONSTER, {"Spawn Monster", "spawn_monster"}},
	{EFFECT_SPAWN_BMX, {"Spawn BMX", "spawn_bmx"}},
	{EFFECT_SPAWN_TUG, {"Spawn Tug", "spawn_tug"}},
	{EFFECT_SPAWN_CARGO, {"Spawn Cargo Plane", "spawn_cargo"}},
	{EFFECT_SPAWN_BUS, {"Spawn Bus", "spawn_bus"}},
	{EFFECT_SPAWN_BLIMP, {"Spawn Blimp", "spawn_blimp"}},
	{EFFECT_SPAWN_BUZZARD, {"Spawn Buzzard", "spawn_buzzard"}},
	{EFFECT_SPAWN_FAGGIO, {"Spawn Faggio", "spawn_faggio"}},
	{EFFECT_SPAWN_RUINER3, {"Spawn Ruined Ruiner", "spawn_ruiner3"}},
	{EFFECT_NO_VEHS, {"No Traffic", "notraffic", true}},
	{EFFECT_NO_PEDS, {"No Pedestrians", "nopeds", true}},
	{EFFECT_EXPLODE_CUR_VEH, {"Explode Current Vehicle", "playerveh_explode"}},
	{EFFECT_PEDS_INVISIBLE, {"Everyone Is A Ghost", "peds_ghost", true}},
	{EFFECT_VEHS_INVISIBLE, {"Invisible Vehicles", "vehs_ghost", true, { EFFECT_RED_VEHS, EFFECT_BLUE_VEHS, EFFECT_GREEN_VEHS, EFFECT_BLACK_VEHS, EFFECT_RAINBOW_VEHS, EFFECT_RAINBOW_VEHS }}},
	{EFFECT_NO_RADAR, {"No Radar", "no_radar", true, { EFFECT_NO_HUD }}},
	{EFFECT_NO_HUD, {"No HUD", "no_hud", true, { EFFECT_NO_RADAR } }},
	{EFFECT_SUPER_RUN, {"Super Run", "player_superrun", true }},
	{EFFECT_SUPER_JUMP, {"Super Jump", "player_superjump", true }},
	{EFFECT_PLAYER_RAGDOLL, {"Ragdoll", "player_ragdoll"}},
	{EFFECT_PEDS_RAGDOLL_ON_TOUCH, {"Sensitive Touch", "peds_sensitivetouch", true}},
	{EFFECT_PLUS_100K, {"+$100.000", "richboi"}},
	{EFFECT_MINUS_100K, {"-$100.000", "poorboi"}},
	{EFFECT_PEDS_FOLLOW_PLAYER, {"You Are Famous", "player_famous"}},
	{EFFECT_PLAYER_DRUNK, {"Drunk", "player_drunk", true}},
	{EFFECT_PEDS_OHKO, {"One Hit KO", "player_ohko", true}},
	{EFFECT_PEDS_NO_FEAR, {"Peds Have No Fear", "peds_nofear", true}},
	{EFFECT_SCREEN_BLOOM, {"Bloom", "screen_bloom", true, { EFFECT_SCREEN_LSD }}},
	{EFFECT_SCREEN_LSD, {"LSD", "screen_lsd", true, { EFFECT_SCREEN_BLOOM }}},
	{EFFECT_SCREEN_REALLSD, {"Actual LSD", "screen_lsd2", true}},
	{EFFECT_SCREEN_CHOPVISION, {"Chop Vision", "screen_chop", true}},
	{EFFECT_PEDS_IGNORE_PLAYER, {"Peds Ignore Player", "peds_ignoreplayer", true}},
	{EFFECT_HONK_BOOSTING, {"Honk Boosting", "vehs_honkboost", true}},
	{EFFECT_MIN_DAMAGE, {"Minimal Damage", "peds_mindmg", true, { EFFECT_NO_HEADSHOTS }}},
	{EFFECT_NO_HEADSHOTS, {"No Headshots", "peds_noheadshot", true, { EFFECT_MIN_DAMAGE }}},
	{EFFECT_PEDS_FROZEN, {"Peds Are Brainless", "peds_frozen", true}},
	{EFFECT_LOW_GRAV, {"Low Gravity", "lowgravity", true, { EFFECT_VERY_LOW_GRAV }}},
	{EFFECT_VERY_LOW_GRAV, {"Very Low Gravity", "verylowgravity", true, { EFFECT_LOW_GRAV }}},
	{EFFECT_INSANE_GRAV, {"Insane Gravity", "insanegravity", true, {}, true}},
	{EFFECT_VEH_REPAIR, {"Repair Current Vehicle", "playerveh_repair"}},
	{EFFECT_VEH_POP_TIRES, {"Pop Tires Of Current Vehicle", "playerveh_poptires"}},
	{EFFECT_ALL_VEH_POP_TIRES, {"Now This Is Some Tire Poppin'", "vehs_poptiresconstant", true}},
	{EFFECT_NO_SPECIAL_ABILITY, {"No Special Ability", "player_nospecial", true}},
	{EFFECT_IN_THE_HOOD, {"In The Hood", "peds_dance", true}},
	{EFFECT_FORCED_CINEMATIC, {"Cinematic Vehicle Cam", "player_forcedcinematiccam", true, { EFFECT_FORCED_FP }}},
	{EFFECT_PEDS_FLEE, {"All Nearby Peds Are Fleeing", "peds_flee"}},
	{EFFECT_BREAK_VEH_DOORS, {"Break All Doors Of Current Vehicle", "playerveh_breakdoors"}},
	{EFFECT_ZOMBIES, {"Zombies", "zombies", true}},
	{EFFECT_METEOR_RAIN, {"Meteor Shower", "meteorrain", true}},
	{EFFECT_BLIND, {"Blind", "screen_blind", true, {}, true}},
	{EFFECT_BLACKOUT, {"Blackout", "world_blackout", true}},
	{EFFECT_QUICK_TIME, {"Timelapse", "time_quickday", true, { EFFECT_PAUSE_TIME }}},
	{EFFECT_PAUSE_TIME, {"Pause Clock", "time_slowday", true, { EFFECT_QUICK_TIME }}},
	{EFFECT_MOV_NO_UD, {"Disable Forwards / Backwards Movement", "player_noforwardbackward", true}},
	{EFFECT_MOV_NO_LR, {"Disable Left / Right Movement", "player_noleftright", true}},
	{EFFECT_BREAK, {"It's Time For A Break", "player_break", true, {}, true}},
	{EFFECT_EVERYONE_RPG, {"Give Everyone An RPG", "peds_giverpg"}},
	{EFFECT_EVERYONE_TAZER, {"Give Everyone A Stungun", "peds_stungun"}},
	{EFFECT_EVERYONE_MINIGUN, {"Give Everyone A Minigun", "peds_minigun"}},
	{EFFECT_PEDS_FAST_FIRING, {"Peds Shoot Fast", "peds_fastshooting", true}},
	{EFFECT_NO_SPRINT, {"No Sprint", "player_nosprint", true}},
	{EFFECT_NO_JUMP, {"No Jump", "player_nojump", true}},
	{EFFECT_EVERYONE_INVINCIBLE, {"Everyone Is Invincible", "peds_invincible", true}},
	{EFFECT_VEHS_INVINCIBLE, {"All Vehicles Are Invulnerable", "vehs_invincible", true}},
	{EFFECT_PLAYER_SHOT_RAGDOLL, {"Player Ragdolls When Shot", "player_ragdollondmg", true, { EFFECT_NO_RAGDOLL }}},
	{EFFECT_JUMPY_VEHS, {"Jumpy Vehicles", "vehs_jumpy", true}},
	{EFFECT_LOCK_VEHS, {"Lock All Vehicles", "vehs_lockdoors"}},
	{EFFECT_TOTAL_CHAOS, {"Doomsday", "chaosmode", true}},
	{EFFECT_NO_RAGDOLL, {"No Ragdoll", "player_noragdoll", true, { EFFECT_PLAYER_SHOT_RAGDOLL }}},
	{EFFECT_VEHS_HORN, {"All Vehicles Honk", "vehs_honkconstant", true}},
	{EFFECT_TP_WAYPOINT, {"Teleport To Waypoint", "player_tptowaypoint"}},
	{EFFECT_PEDS_SAY_HI, {"Friendly Neighborhood", "peds_sayhi", true, { EFFECT_PEDS_INSULT }}},
	{EFFECT_PEDS_INSULT, {"Unfriendly Neighborhood", "peds_insult", true, { EFFECT_PEDS_SAY_HI }}},
	{EFFECT_EXPLOSIVE_BULLETS, {"Explosive Bullets", "player_explosivebullets", true}},
	{EFFECT_EXPLOSIVE_PUNCH, {"Explosive Punch", "player_explosivepunch", true}},
	{EFFECT_GIVE_ALL_WEPS, {"Give All Weapons", "player_allweps"}},
};

class Effects
{
public:
	Effects() {}

public:
	void StartEffect(EffectType effectType);
	void StopEffect(EffectType effectType);
	void UpdateEffects();

private:
	bool m_effectActive[_EFFECT_ENUM_MAX] = { false };
};