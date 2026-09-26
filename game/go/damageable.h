#pragma once

#include "physgo.h"
#include "mm/game/events.h"
#include "mm/game/go/healthblock.h"

class CDamageable : public CPhysicsGameObject, public NEvent::CEventHandler
{
public:

    virtual ~CDamageable() = 0;
    virtual float InflictDamage() = 0;
    virtual float CalculateDamage() = 0;
    virtual bool IsTargetable() = 0;
    virtual void OnDestroyed(CHashString) = 0;
    virtual void SendOnDestroyEvent(CHashString) = 0;

    CHealthBlockModel* GetHealthBlockModel() {
        return *(CHealthBlockModel**)((uintptr_t)this + 0x1A10);
    }

    float GetHealth() {
        CHealthBlockModel* pHealthBlock = GetHealthBlockModel();
        if (pHealthBlock != nullptr) {
            return pHealthBlock->GetMasterHealth();
        }
    }

    void SetHealth(float fHealth) {
        CHealthBlockModel* pHealthBlock = GetHealthBlockModel();
        if (pHealthBlock != nullptr) {
            pHealthBlock->SetMasterHealth(fHealth);
        }
    }
    
    void SetInvulnerable(bool invulnerable) { m_Invulnerable = invulnerable; }

    bool m_Destroyed;       //0xE8
    bool m_Invulnerable;    //0xE9 
    char pad_EA[150];       //0xEA
    float max_health;       //0x180
    float current_health;   //0x184
    float last_health;      //0x188
    char pad_18C[52];       //0x18C
};