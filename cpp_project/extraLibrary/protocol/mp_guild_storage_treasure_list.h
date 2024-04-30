#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_storage_treasure_item.h"
#include "struct/mps_guild_storage_treasure_my_request.h"

namespace mir3d
{
	class mp_guild_storage_treasure_list_cs : public BasePacket 	// 문파 보물 창고 조회
	{

	public:
		mp_guild_storage_treasure_list_cs() : BasePacket(mpe_cmd::guild_storage_treasure_list_cs)
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

	class mp_guild_storage_treasure_list_sc : public BasePacket 	// 문파 보물 창고 조회
	{
	public:
		std::vector<mps_guild_storage_treasure_item> list_item{};
	public:
		std::vector<mps_guild_storage_treasure_my_request> list_my_request{};
	public:
		int32_t current_request_count{};

	public:
		mp_guild_storage_treasure_list_sc() : BasePacket(mpe_cmd::guild_storage_treasure_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_item);
			protocol::SerializeType(pBuffer, &list_my_request);
			protocol::SerializeType(pBuffer, &current_request_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
