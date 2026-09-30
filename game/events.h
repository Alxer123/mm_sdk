#pragma once

#include <cstdint>
#include "mm/mm.h"

namespace NEvent
{
    enum EventTypeID : uint64_t
    {
        TYPE_ID_NULL = 255,
        TYPE_ID_I32 = 1,
        TYPE_ID_F32 = 2,
        TYPE_ID_CSTRING = 3,
        TYPE_ID_MATRIX4 = 4,
        TYPE_ID_U32 = 5,
        TYPE_ID_GAME_OBJECT = 11,
        TYPE_ID_CHARACTER = 12,
        TYPE_ID_OPTION_MASK = 128
    };
    
    struct CEventID
    {
        CHashString hash;
        CHashString m_namespace;

        CEventID() = default;

        CEventID(CHashString h, CHashString ns) : hash(h), m_namespace(ns) {}
    };

    class CEventSystem
    {
    public:
        virtual ~CEventSystem() = 0;

        char pad_0x8[1548416];      //0x8
    };
    
    class CEventImpl { };

    struct CEventBase
    {
        unsigned __int16* m_EventImpl;
    };

    struct CBaseSendEvent
    {
        CEventBase* event_base;
    };

    template<typename arg0 = void, typename arg1 = void, typename arg2 = void, typename arg3 = void, typename arg4 = void>
    class CSendEvent : public CBaseSendEvent
    {
    public:

        static SMETHOD(0x140007CB0, 0x141B74930, void, SendMsg(const char* a), a)

        static SMETHOD(0x1401C9D20, 0x141D76550, void, SendMsg(uint32_t hash), hash)

        static void SendMsg(const char* event_name, class CGameObject* t1);
    };




    template<typename arg0 = void, typename arg1 = void, typename arg2 = void, typename arg3 = void, typename arg4 = void>
    class CReceiveEvent
    {
        CEventBase Impl;
    };

    class CEventHandler
    {
    public:
        void* m_SubscribedTo;

    public:
        virtual ~CEventHandler() {};
        virtual void HandleEvent(NEvent::CEventImpl const* event, void* data) {};
    };
}

MMASSERT(NEvent::CEventHandler, 0x10);
MMASSERT(NEvent::CBaseSendEvent, 0x8);
MMASSERT(NEvent::CEventBase, 0x8);
MMASSERT(NEvent::CEventHandler, 0x10);
MMASSERT(NEvent::CEventID, 0x8);
MMASSERT(NEvent::CEventSystem, 0x17A088);

