#pragma once

#include "character.h"

class CAvatar
{
public:
    virtual void _vfunc_0() = 0;
    virtual void _vfunc_1() = 0;
    virtual void _vfunc_2() = 0;
    virtual void _vfunc_3() = 0;
    virtual void _vfunc_4() = 0;
    virtual void _vfunc_5() = 0;
    virtual void set_opacity(float val) = 0;

    char pad_8[8];                          //0x08
    CCharacter* character;                  //0x10
    boost::weak_ptr<CAvatar> weak_this;      //0x18
    char pad_28[48];                        //0x28
};