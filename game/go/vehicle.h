#pragma once


#include "damageable.h"

class CCharacter;

class __declspec(align(8)) CArcadeVehicleEngine
{
public:
	char pad_00[48];



	CMETHODV(0x1405728F0, 0x0, float, GetTopSpeed());
	CMETHOD(0x140572900, 0x142493370, void, SetTopSpeed(float topSpeed), topSpeed)
};


class __declspec(align(16)) CVehicle : public CDamageable {
public:
	virtual void StopPartAnimation(unsigned int) = 0;
	virtual void SetWheelSkew(int, float) = 0;
	virtual void UpdatePfxPreSim() = 0;
	virtual void UpdatePfxPostSimStep() = 0;
	virtual void Update() = 0;
	virtual void Clear() = 0;
	virtual void SetVisibilityModelsAndEffects(bool) = 0;
	virtual void OnEntering(CCharacter*, bool, bool) = 0;
	virtual void OnEnter(CCharacter*, bool, bool) = 0;
	virtual void OnExit(CCharacter*, bool, bool) = 0;
	virtual void SetVelocity(const CVector3f&) = 0;
	virtual void SetTargetHeight(float) = 0;
	virtual void SetLOD(bool, unsigned __int8, unsigned __int8) = 0;
	virtual int GetNumberOfWheelsOnGround() = 0;
	virtual float GetTrust() = 0;
	virtual float GetTargetHeight() = 0;
	virtual void GetAABB(CAABox*) = 0;
	virtual void GetLocalAABB(CAABox*) = 0;
	virtual void AttachObject(boost::shared_ptr<CGameObject>*, unsigned int) = 0;
	virtual void FadeIn(float) = 0;
	virtual char GetSpawnTypeId() = 0;
	virtual char GetSpawnVariationIndex() = 0;
	virtual char GetSpawnTeam() = 0;
	virtual void KillPhysics() = 0;
	virtual float CalculateLod(float, const CVector3f*) = 0;
	virtual void OnEmerge() = 0;
	virtual void OnSubmerge() = 0;
	virtual void SetDirtyWheels() = 0;
	virtual void UpdateAiEntityInstance() = 0;
	virtual void GetAngularVelocity(CVector3f*) = 0;
	virtual void GetVelocity(CVector3f*) = 0;
	virtual const CVector3f*  GetVelocityLastFrame() = 0;
	virtual void GetAcceleration(CVector3f*) = 0;
	virtual const CHashString*  GetState() = 0;


	char pad_1C0[8];				//0x1C0
	float opacity;					//0x1C8
	char pad_1CC[4];				//0x1CC
	CArcadeVehicleEngine m_AVEngine;//0x1D0
	char pad_200[5];				//0x200
	bool driving_enabled;			//0x205
	char pad_206[463];				//0x206
	bool engine_running;			//0x3D5
	char pad_3D6[2];				//0x3D6
	bool visibile;					//0x3D8
	char pad_3D9[1];				//0x3D9
	bool enabled;					//0x3DA
	char pad_3DB[5];				//0x3DB
	bool is_occupied;				//0x3E0
	bool is_occupied_by_player;		//0x3E1
	char pad_3E2[15150];			//0x3E2



	//CMETHODV(0x1405AE1F0, 0x1421E2E85, double, GetFuelAmount()) // Updated
};

MMASSERT(CVehicle, 0x3F10);
MMASSERT(CArcadeVehicleEngine, 0x30);