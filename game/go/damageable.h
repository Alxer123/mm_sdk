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

    bool m_Destroyed;
    bool m_Invulnerable;
    char unk234[214];
};