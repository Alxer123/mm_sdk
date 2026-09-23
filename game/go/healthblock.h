#pragma once
#include <cstdint>

class CHealthBlockModel
{
public:
	float GetMasterHealth() {
		return *(float*)((uintptr_t)this + 0x5BC);
	}

	void SetMasterHealth(float fHealth) {
		*(float*)((uintptr_t)this + 0x5BC) = fHealth;
	}
};