#pragma once

#include <cstdint>
#include "mm/std.h"

class CVideoManager
{
public:
	char pad_0[425];		//0x0
	bool playing;			//0x1A9
	char pad_1AA[30];		//0x1AA
	bool transition;		//0x1C8
	char pad_1C9[7];		//0x1C9

	CMETHODV(0x1405d9ff0, 0x0, bool, isPlayingFullScreen())
	CMETHODV(0x1405d9f40, 0x0, void, stopVideo())
};

MMASSERT(CVideoManager, 0x1D0);