#pragma once

#include "go.h"
#include "physgo.h"

class CExplosives : public CPhysicsGameObject
{
public:
	CMatrix4f m_WorldMatrixT1;
	CQuaternion m_Q0;
	CQuaternion m_Q1;
	CVector3f m_T0;
	char pad_144[4];

};