#pragma once

#include <cstdint>
#include <mm/hookmgr.h>

class CEconomyResource
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

    static SMETHOD(0x1401E8060, 0x141D9B690, void, SetResourceSilent(uint16_t resourceId, uint64_t unk, bool flag, int amount), resourceId, unk, flag, amount)

    static SMETHOD(0x1401E8300, 0x1431CB4D0, void, SetResourceWithUI(uint16_t resourceId, uint64_t unk, bool flag, int amount), resourceId, unk, flag, amount)
};