#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_storage_share_extend_cs : public BasePacket 	// 문파 공유 창고 확장
	{
	public:
		int32_t extend_slot_count{};

	public:
		mp_guild_storage_share_extend_cs() : BasePacket(mpe_cmd::guild_storage_share_extend_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &extend_slot_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_storage_share_extend_sc : public BasePacket 	// 문파 공유 창고 확장
	{
	public:
		int32_t total_slot_count{};
	public:
		int32_t update_guild_gold{};
	public:
		int32_t total_guild_gold{};

	public:
		mp_guild_storage_share_extend_sc() : BasePacket(mpe_cmd::guild_storage_share_extend_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &total_slot_count);
			protocol::SerializeType(pBuffer, &update_guild_gold);
			protocol::SerializeType(pBuffer, &total_guild_gold);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
