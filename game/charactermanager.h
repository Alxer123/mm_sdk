#pragma once

#include "go/character.h"
#include "go/player.h"

class __declspec(align(16)) CCharacterManager
{
public:
	virtual ~CCharacterManager() = 0;
	virtual void _vfunc_1() = 0;
	virtual void _vfunc_2() = 0;
	virtual bool is_player_paused() = 0;
	virtual void pause_player(bool despawn_vehicle) = 0;
	virtual void unpause_player() = 0;

	char pad_8[14240];										//0x8
	mm::std::vector<boost::shared_ptr<CPlayer>> player;		//0x37A8
	char pad_37B8[840];										//0x37B8
	
	CMETHODV(0x1400FBD30, 0x141C91250, CCharacter*, GetPlayerCharacter())
};