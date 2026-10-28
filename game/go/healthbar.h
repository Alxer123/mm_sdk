#pragma once

#include "go.h"
#include "mm/game/events.h"
#include "mm/game/turntaker.h"

enum EHealthbarType : int32_t
{
	VEHICLE = 0x0,
	FOLLOW_CHAR = 0x1,
	BIGBOSS = 0x2,
	BIGBOSS_SCROTUS = 0x3,
	BIGBOSS_STANKGUM = 0x4,
	BIGBOSS_TENDERLOIN = 0x5,
	ON_INFOBOX = 0x6,
	AIMED_AT_STRUCTURE = 0x7,
};

class CHealthbar : public CGameObject, NEvent::CEventHandler
{
public:
	CMatrix4f m_LocalTransform;	//0xE0
	CMatrix4f m_WorldMatrix;	//0x120
	CMatrix4f m_LastRenderTransform;	//0x160
	bool m_Enabled;	//0x1A0
	bool m_Registered; //0x1A1
	char pad_1A2[2];	//0x1A2
	EHealthbarType m_Type;	//0x1A4
	SObjectID m_InfoboxId;	//0x1A8
	uint64_t m_DisplayObjectId;	//0x1B0
	bool m_ShowOnInfobox;	//0x1B8
	char pad_1B9[3];	//0x1B9
	SObjectID m_TargetId; //0x1BC
	bool m_ShowOnlyWhenAimingAtTarget; //0x1C4
	bool m_IsAimedAt;	//0x1C5
	char pad_1C6[2];	//0x1C6
	SObjectID m_GroupId;	//0x1C8
	bool m_IsGroupHealthbar;	//0x1D0
	char pad_1D1[7];	//0x1D1
	NEvent::CReceiveEvent<void, void, void, void, void> m_DisableEvent;	//0x1D8
	NEvent::CReceiveEvent<void, void, void, void, void> m_EnableEvent;	//0x1E0
	float m_UnitHealth;	//0x1E8
	float m_CurrentUnitDamage;	//0x1EC
	float m_ArmourValue;	//0x1F0
	float m_ArmourWeighting;	//0x1F4
	float m_UnitHealthWeightingScalar;	//0x1F8
	uint8_t m_ArmourLevel;	//0x1FC
	char pad_1FD[3];	//0x1FD
	EUpdateType m_UpdateType;	//0x200
	char pad_204[4];	//0x204
	CTurnTakerHelperStaticRaycastTracker m_TurnTakerRaycast;	//0x208
	float m_CullingValidationRange;	//0x228
	float m_CullFadeFactor;	//0x22C
	float m_CullFadeTime;	//0x230
	char pad_234[4]; //0x234
};


MMASSERT(CHealthbar, 0x238);