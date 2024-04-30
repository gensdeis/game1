#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_goods_info.h"
#include "struct/mps_item_id.h"

namespace mir3d
{
	class mp_gate_guild_dungeon_goods_cs : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int32_t tid{};
	public:
		int32_t open_count{};

	public:
		mp_gate_guild_dungeon_goods_cs() : BasePacket(mpe_cmd::gate_guild_dungeon_goods_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &open_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_guild_dungeon_goods_sc : public BasePacket 
	{
	public:
		int32_t result{};
	public:
		std::vector<mps_guild_goods_info> goods_info{};
	public:
		std::vector<mps_item_id> list_item{};
	public:
		int32_t open_count{};

	public:
		mp_gate_guild_dungeon_goods_sc() : BasePacket(mpe_cmd::gate_guild_dungeon_goods_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &goods_info);
			protocol::SerializeType(pBuffer, &list_item);
			protocol::SerializeType(pBuffer, &open_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
