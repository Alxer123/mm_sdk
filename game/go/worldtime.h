#pragma once

#include <cstdint>

class CWorldTime
{
public:
    virtual ~CWorldTime() = 0;
    virtual void _vfunc_1() = 0;
    virtual void _vfunc_2() = 0;
    virtual void _vfunc_3() = 0;
    virtual void _vfunc_4() = 0;

    char pad_8[32];             //0x08 - 8
    float m_CurrentTimeOfDay;   //0x28 - 40
    char pad_2C[4];             //2C - 44
};

MMASSERT(CWorldTime, 0x30);