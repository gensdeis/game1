#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gm_guild_storage_treasure_insert_item_cs : public BasePacket 	// 문파 보물 창고 아이템 넣기 (test용)
	{
	public:
		int32_t item_tid{};
	public:
		int32_t add_minute{};

	public:
		mp_gm_guild_storage_treasure_insert_item_cs() : BasePacket(mpe_cmd::gm_guild_storage_treasure_insert_item_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &item_tid);
			protocol::SerializeType(pBuffer, &add_minute);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_guild_storage_treasure_insert_item_sc : public BasePacket 	// 문파 보물 창고 아이템 넣기 (test용)
	{

	public:
		mp_gm_guild_storage_treasure_insert_item_sc() : BasePacket(mpe_cmd::gm_guild_storage_treasure_insert_item_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
