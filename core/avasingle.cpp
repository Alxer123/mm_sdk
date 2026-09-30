#include "avasingle.h"
#include "mm/std.h"
#include "mm/hookmgr.h"

#include "mm/core/graphics/graphicsengine.h"
#include "mm/core/input.h"

class CCharacterManager;
class CCameraControlManager;
class CWorldTime;
class CLandscapeManager;
class CSaveManager;
class CGameState;
class CVideoManager;

#define AVASINGLE(gog, steam, inst) inst*& CAvaSingle<inst>::Instance = *(inst**)ADDRESS(gog, steam);

AVASINGLE(0x141715B50, 0x1417F4EC8, NGraphicsEngine::CGraphicsEngine);
AVASINGLE(0x141715B88, 0x0, CDeviceManager_AVA); // Updated
AVASINGLE(0x0, 0x1417F4EF0, CDeviceManager_STEAM);
AVASINGLE(0x141715FB8, 0x1417F5338, CCharacterManager); // Updated
AVASINGLE(0x141711B78, 0x1417F5378, CCameraControlManager);
AVASINGLE(0x141716030, 0x1417F53B0, CWorldTime); // Updated
AVASINGLE(0x141716B90, 0x0, CLandscapeManager);
AVASINGLE(0x141715B48, 0x0, CSaveManager);
AVASINGLE(0x14171DF00, 0x0, CVideoManager);