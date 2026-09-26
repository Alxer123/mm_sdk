#pragma once

#include "mm/game/events.h"
#include "avatar.h"

class CPlayer : public NEvent::CEventHandler, public CAvatar
{
public:
	char pad_0x68[1024];	//0x68
};