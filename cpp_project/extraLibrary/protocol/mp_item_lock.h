#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_item_lock_cs : public BasePacket 
	{
	public:
		int64_t iuid{};
	public:
		mpe_item_reinforce_position flag{};	// "// 아이템 위치(장비,인벤)"
	public:
		bool locked{};

	public:
		mp_item_lock_cs() : BasePacket(mpe_cmd::item_lock_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeEnum(pBuffer, &flag);
			protocol::SerializeType(pBuffer, &locked);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_item_lock_sc : public BasePacket 
	{
	public:
		int64_t iuid{};
	public:
		mpe_item_reinforce_position flag{};	// "// 아이템 위치(장비,인벤)"
	public:
		bool locked{};

	public:
		mp_item_lock_sc() : BasePacket(mpe_cmd::item_lock_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeEnum(pBuffer, &flag);
			protocol::SerializeType(pBuffer, &locked);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
