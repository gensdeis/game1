#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_storage_share_request_get_item.h"

namespace mir3d
{
	class mp_guild_storage_share_request_get_item_list_cs : public BasePacket 	// 문파 공유 창고 아이템 요청 알림
	{

	public:
		mp_guild_storage_share_request_get_item_list_cs() : BasePacket(mpe_cmd::guild_storage_share_request_get_item_list_cs)
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

	class mp_guild_storage_share_request_get_item_list_sc : public BasePacket 	// 문파 공유 창고 아이템 요청 알림
	{
	public:
		std::vector<mps_guild_storage_share_request_get_item> list_request{};

	public:
		mp_guild_storage_share_request_get_item_list_sc() : BasePacket(mpe_cmd::guild_storage_share_request_get_item_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_request);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
