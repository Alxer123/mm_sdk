#pragma once

#include <cstdint>
#include "go/go.h"

class CTurnTakerHelperStaticRaycastTracker
{
public:
	uint64_t m_TurnTakerId;	//0x0
	bool m_LastTestVisible;	//0x8
	bool m_RegisteredWithTurnTaker;	//0x9
	char pad_A[6];	//0xA
	boost::weak_ptr<CGameObject> m_wpTurnTaker; //0x10
};

MMASSERT(CTurnTakerHelperStaticRaycastTracker, 0x20);