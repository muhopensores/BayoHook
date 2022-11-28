#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <string>

#include "../utils/config.hpp"
#include "libmem++/libmem.hpp"
#include "MinHook/include/MinHook.h"
#include "../utils/FunctionHook.hpp"

class GameHook {
public:
	// addresses
	static uintptr_t playerPointerAddress;
	static uintptr_t halosAddress;
	static uintptr_t chaptersPlayedAddress;
	static uintptr_t playerMagicAddress;
	static uintptr_t comboPointsAddress;
	static uintptr_t currentCharacterAddress;
	static uintptr_t thirdAccessoryAddress;
	static uintptr_t hudDisplayAddress;
	static uintptr_t enemySlotsAddress;

	// patch toggles
	static bool takeNoDamage_toggle;
	static bool focusPatch_toggle;
	static bool infJumps_toggle;
	static bool disableClicking_toggle;
	static bool noClip_toggle;
	// patch functions
	static void TakeNoDamage(bool enabled);
	static void FocusPatch(bool enabled);
	static void InfJumps(bool enabled);
	static void DisableClicking(bool enabled);
	static void NoClip(bool enabled);

	// detour values
	static bool witchTimeMultiplier_toggle;
	static float witchTimeMultiplier;
	static bool enemyHP_no_damage_toggle;
	static bool enemyHP_one_hit_kill_toggle;
	static bool inf_magic_toggle;
	static bool outgoingDamageMultiplier_toggle;
	static float outgoingDamageMultiplierMult;
	static bool customCameraDistance_toggle;
	static float customCameraDistanceMultiplierMult;
	static bool lessClothes_toggle;
	static bool inputIcons_toggle;
	static int inputIconsValue;
	static bool haloDisplay_toggle;
	static int haloDisplayValue;
	static bool animSwap_toggle;
	static int animSwapCurrentAnim;
	static int animSwapSourceAnim1;
	static int animSwapDesiredAnim1;

	// update
	static uintptr_t actorPlayable;
	static float xyzpos[3];
	static int halos;
	static int chaptersPlayed;
	static int playerHealth;
	static float remainingWitchTimeDuration;
	static float playerMagic;
	static int comboPoints;
	static int currentCharacter;
	static int thirdAccessory;
	static bool hudDisplay;
	static float enemyDazeDisplay;

	static int saveStates_CurrentEnemy;
	static int saveStates_CurrentEnemyMoveID;
	static int saveStates_SavedEnemyMoveID;
	static float saveStates_CurrentEnemyAnimFrame;
	static float saveStates_SavedEnemyAnimFrame;
	static float saveStates_CurrentEnemyXYZPos[3];
	static float saveStates_SavedEnemyXYZPos[3];

	static int saveStates_CurrentPlayerMoveID;
	static int saveStates_SavedPlayerMoveID;
	static float saveStates_SavedPlayerXYZPos[3];

	static void SaveStates_SaveState();
	static void SaveStates_LoadState();

	// dev functions
	static void _patch(char* dst, char* src, int size);
	static void _nop(char* dst, unsigned int size);
	static void InitializeDetours();
	static void onConfigLoad(const utils::Config& cfg);
	static void onConfigSave(utils::Config& cfg);
	static void Update(void);

	static inline const char* cfgString{ "../bayo_hook.cfg" };
	static inline utils::Config cfg{ "bayo_hook.cfg" };
	static inline const char* dllName{"BayoHook 0.4"};
	static inline const char* repoUrl{ "https://github.com/SSSiyan/BayoHook" };

	// imgui
	static void GameImGui(void);
	static void ImGuiStyle(void);

private:
};