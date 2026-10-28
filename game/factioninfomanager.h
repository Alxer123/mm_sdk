#pragma once

#include "plugin.h"

enum EFactionRelation : int32_t
{
    E_RELATION_NONE = -1,
    E_RELATION_ALLIED = 0,
    E_RELATION_HOSTILE = 1,
    NOF_RELATIONS = 2,
};


class CFactionInfoManager
{
public:


};

inline SMETHOD(0x1406F7C60, 0x142351FE0, void, GameFactionsSetRelation(int factionA, int factionB, EFactionRelation relation), factionA, factionB, relation)
inline SMETHOD(0x1406F7B00, 0x142351E60, EFactionRelation, GetRelation(int factionA, int factionB), factionA, factionB)
inline SMETHOD(0x1406F7BB0, 0x142351F10, bool, GameFactionsIsHostile(int factionA, int factionB), factionA, factionB)
inline SMETHODV(0x1406F7AA0, 0x142351DE0, void, GameFactionsReset())
inline SMETHODV(0x1406F7AD0, 0x142351E30, void, GameFactionsDestroy()) //CAUTION: USING THIS AT OWN RISK, COULD MAKE YOUR SAVE UNPLAYABLE
// All above updated