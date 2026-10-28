#pragma once
#include <cstdint>

class CRuntimeContainer;
class CSaveContainer;
class CDamageable;

class CHealthBlockModel
{
public:
	virtual ~CHealthBlockModel() = 0;
	virtual const CRttiTypeId* GetTypeId() = 0;
	virtual bool IsType(const CRttiTypeId* pTypeId) = 0;
	virtual void WrapDamageable(CDamageable* pDamageable) = 0;
	virtual void SetProperties(const CRuntimeContainer* pContainer) = 0;
	virtual void Update(const float fhealth, CDamageable* pDamageable) = 0;
	virtual void Revive() = 0;
	virtual void Save(CSaveContainer* pContainer) = 0;
	virtual void Load(CSaveContainer* pContainer) = 0;

	float GetMasterHealth() {
		return *(float*)((uintptr_t)this + 0x5BC);
	}

	void SetMasterHealth(float fHealth) {
		*(float*)((uintptr_t)this + 0x5BC) = fHealth;
	}
};