#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_storage_share_item.h"

namespace mir3d
{
	class mp_guild_storage_share_list_cs : public BasePacket 	// 문파 공유 창고 조회
	{

	public:
		mp_guild_storage_share_list_cs() : BasePacket(mpe_cmd::guild_storage_share_list_cs)
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

	class mp_guild_storage_share_list_sc : public BasePacket 	// 문파 공유 창고 조회
	{
	public:
		std::vector<mps_guild_storage_share_item> list_item{};
	public:
		int32_t slot_count{};
	public:
		uint8_t current_request_count{};

	public:
		mp_guild_storage_share_list_sc() : BasePacket(mpe_cmd::guild_storage_share_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_item);
			protocol::SerializeType(pBuffer, &slot_count);
			protocol::SerializeType(pBuffer, &current_request_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
