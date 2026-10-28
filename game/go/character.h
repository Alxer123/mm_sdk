#pragma once

#include "damageable.h"
#include "vehicle.h"

class CVehicle;
class CInventory;
// temp
class IPfxCharacter
{
public:
	virtual ~IPfxCharacter() = 0;
	virtual class CCharacter* GetPfxGameObject() = 0;
};

namespace NCharacterSystem
{
	class CCharacterBase : public IPfxCharacter, public CRtti
	{
	public:
		char pad_10[8];				//0x10
		CMatrix4f matrix;			//0x18
		CMatrix4f previous_matrix;	//0x58
		char pad_98[344];			//0x98

		CMETHOD(0x14063F940, 0x142287340, void, RotateInstantly(float yaw), yaw)
	};
}

class CCharacter : public CDamageable, public NCharacterSystem::CCharacterBase, public IPhysicsGameObjectListenable
{
public:
	virtual ~CCharacter() = 0;
	virtual IPfxInstance get_pfx_instance() = 0;

	char pad_3B0[12022];

	CVector3f* GetPosition() {
		return (CVector3f*)((uintptr_t)this + 0x208);
	}

	void Teleport(CVector3f targetCoords)
	{
		CMatrix4f targetMatrix;
		CVehicle* tVehicle = this->GetVehiclePtr();
		CGameObject* pTargetGO = nullptr;

		if (tVehicle) {
			pTargetGO = tVehicle;
			tVehicle->SetVelocity(CVector3f()); // Stop momentum
			tVehicle->GetTransform(&targetMatrix);
		}
		else {
			pTargetGO = this;
			this->ForceNeutralState(); // Safe state
			this->GetTransform(&targetMatrix);
		}

		targetMatrix.SetPosition(targetCoords);
		pTargetGO->SetTransform(&targetMatrix);
	}

	CMETHODV(0x140139A20, 0x141CD69B0, void, ForceNeutralState())
	CMETHODV(0x1400EE860, 0x141C82910, CVehicle*, GetVehiclePtr())
	CMETHOD(0x140600290, 0x14223C9C0, void, SetLinkTarget(CGameObject* link_target)) // Updated
	SMETHOD(0x140179F90, 0x141D1BAE0, CGameObject*, FindBestTarget(CCharacter* pPlayer, float a2, float a3, float a4, char a5, char a6, float a7), pPlayer, a2, a3, a4, a5, a6, a7) // Updated
	SMETHOD(0x140176C50, 0x141D18520, int64_t, GetPotentialTargets(CCharacter* pPlayer, float a2, float a3, float a4, char a5, int maxTargets, int64_t a7), pPlayer, a2, a3, a4, a5, maxTargets, a7) // Updated
	CMETHODV(0x1400CE120,0x141C59CB0, CInventory*, GetInventory()) // Updated
	SMETHOD(0x1403DE410, 0x141FD8530, int, GetScrapResourceId(CInventory* pPlayerInventory), pPlayerInventory) // Updated
	SMETHOD(0x1401D40E0, 0x141D83750, float, GetEconomyResourceAmount(int resourceId), resourceId) // Updated
	SMETHOD(0x1401E8060, 0x141D9AD90, void, SetEconomyResource(int resourceId, float amount, bool bShowUI, uint32_t contextHash), resourceId, amount, bShowUI, contextHash) // Updated
};

MMASSERT(NCharacterSystem::CCharacterBase, 0x1F0);
MMASSERT(CCharacter, 0x32B0);
