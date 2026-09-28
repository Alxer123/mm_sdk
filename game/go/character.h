#pragma once

#include "damageable.h"
#include "vehicle.h"

class CVehicle;

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
};