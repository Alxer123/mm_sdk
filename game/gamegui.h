#pragma once

#include <cstdint>
#include "mm/std.h"
#include "mm/core/hash.h"

enum GameGuiInitState : uint32_t
{
	Ok = 0,
	LoadCSV = 1,
	WaitForGameSystems = 2,
	WaitStats = 3,
	WaitStrings = 4,
	Error = 5
};

class GameGuiData
{
public:
	char pad_0[96692];			//0x0
	bool skip_front_end;		//0x179B4
	char pad_179B5[2795];		//0x179B5
};

class CGameGui
{
public:
	char pad_0[10672];				//0x0
	GameGuiInitState init_state;	//0x29B0
	char pad_29B4[33];				//0x29B4
	bool switched_on;				//0x29D5
	bool visible;					//0x29D6
	bool in_focus;					//0x29D7
	bool occlude_main_draw;			//0x29D8
	bool hide_tutorials;			//0x29D9
	char pad_29DA[4886];			//0x29DA

	CMETHOD(0x1402661B0, 0x0, uint64_t, RequestStateTransition(CHashString transition_name), transition_name)
};

class CGameGuiCallbacks
{
public:
	GameGuiData game_data;			//0x0
	char pad_184A0[8272];			//0x184A0
	bool teleported_player;			//0x1A4F0
	bool input_enabled;				//0x1A4F1
	char pad_1A4F2[14];				//0x1A4F2
};

MMASSERT(CGameGui, 0x3CF0);
MMASSERT(GameGuiInitState, 0x4);
MMASSERT(CGameGuiCallbacks, 0x1A500);
MMASSERT(GameGuiData, 0x184A0);