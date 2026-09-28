#pragma once

#include <cstdint>
#include <mm/hookmgr.h>
#include "go.h"

class CEconomyResource : public CGameObject
{
public:
	enum EconomyResourceType : uint16_t
	{
        Water = 0,
        Food = 1,
        Fuel = 2,
        Scrap = 3,
        Threat = 4,
        Ammo_Shotgun = 5,
        Ammo_Sniper = 6,
        Ammo_Thunderstick = 7,
        Shiv = 8
	};

};