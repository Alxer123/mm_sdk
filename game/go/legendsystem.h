#pragma once

#include "go.h"

class CLegendSystem {
public:
	CSaveInfo m_SaveInfo;
	CMatrix4f m_WorldMatrix;
	int m_NrGriffaTokens;
	int m_TotalCollectedGriffaTokens;
	int m_LegendLevel;
	int m_LegendRank;
};
