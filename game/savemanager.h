#pragma once

#include <cstdint>
#include "events.h"

enum class SaveManagerState : uint32_t
{
	None = 0x0,
	Idle = 0x1,
	SetupDevices = 0x2,
	InitDevices = 0x4,
	SavePhase1 = 0x8,
	SavePhase2 = 0x10,
	SavePhase3 = 0x20,
	Saving = 0x40,
	SavingProfile = 0x80,
	SavingWaitMinFrames = 0x100,
	SavingFailedWaitMinFrames = 0x200,
	Loading = 0x400,
	Restoring = 0x800,
	EnumerateSlots = 0x1000,
	EnumerateRestoreSlot = 0x2000,
	Deleting = 0x4000,
	DeletingWaitMinFrames = 0x8000,
	Formatting = 0x10000,
	NeedDeviceStates = 0x17CF8, // Composite flag mask
	ShowIconStates = 0x16BF8, // Composite flag mask
	SetupStates = 0x3006   // Composite flag mask
};

enum class SaveManagerErrorState : uint32_t
{
	None = 0x0,
	NoSpace = 0x1,
	WaitNoSpace = 0x2,
	EnumerateFileWrongVersion = 0x3,
	WaitEnumerateFileWrongVersion = 0x4,
	EnumerateFileCorrupt = 0x5,
	WaitEnumerateFileCorrupt = 0x6,
	WaitEnumerateBACKUP = 0x7,
	EnumerateRestoreFileOk = 0x8,
	WaitEnumerateRestoreFileOk = 0x9,
	EnumerateRestoreFileFail = 0xA,
	WaitEnumerateRestoreFileFail = 0xB,
	LoadFileCorrupt = 0xC,
	WaitLoadFileCorrupt = 0xD,
	RestoreOk = 0xE,
	WaitRestoreOk = 0xF,
	RestoreFail = 0x10,
	WaitRestoreFail = 0x11,
	QueueLoadFailed = 0x12,
	WaitQueueLoadFailed = 0x13,
	QueueSaveFailed = 0x14,
	ExitMessage = 0x15,
	Deleting = 0x16,
	WaitDeleteMessage = 0x17,
	WaitGUI = 0x18,
};

enum class SaveDeviceStatus : uint32_t
{
	Finished = 0,
	NotFinished = 1,
	Failed = 2
};

class CSaveDeviceWin32
{
public:
	virtual ~CSaveDeviceWin32() = default;
	virtual bool is_initialized() {}
	virtual SaveDeviceStatus initialize() {}
	virtual void reset() {}
	virtual void _vfunc_4() {}
	virtual void _vfunc_5() {}
	virtual void _vfunc_6() {}
	virtual void _vfunc_7() {}
	virtual void _vfunc_8() {}
	virtual void _vfunc_9() {}
	virtual SaveDeviceStatus load(const char* file_name, const uint8_t* save_data, uint64_t save_data_size, bool load_backup) {}
	virtual SaveDeviceStatus save(const char* file_name, const uint8_t* save_data, uint64_t save_data_size) {}
	virtual SaveDeviceStatus delete_save(const char* file_name) {}
	virtual void _vfunc_13() {}
	virtual void _vfunc_14() {}
	virtual void _vfunc_15() {}
	virtual bool is_processing() {}

	bool initialized;		//0x8
	char pad_9[247];		//0x9
};

class CSaveManager : public NEvent::CEventHandler
{
public:
	char pad_10[3088];						//0x10
	uint32_t auto_save_slot;				//0xC20
	uint32_t current_slot;					//0xC24
	uint32_t error_slot;					//0xC28
	SaveManagerState state;					//0xC2C
	SaveManagerErrorState error_state;		//0xC30
	char pad_C34[216];						//0xC34
	bool meta_data_loaded;					//0xD0C
	char pad_D0D[27];						//0xD0D
	CSaveDeviceWin32 save_device;			//0xD28
	SaveDeviceStatus device_status;			//0xE28
	SaveDeviceStatus delete_device_status;	//0xE2C
	char pad_E30[112];						//0xE30
};

MMASSERT(CSaveManager, 0xEA0);
MMASSERT(SaveManagerState, 0x4);
MMASSERT(SaveManagerErrorState, 0x4);
MMASSERT(SaveDeviceStatus, 0x4);
MMASSERT(CSaveDeviceWin32, 0x100);