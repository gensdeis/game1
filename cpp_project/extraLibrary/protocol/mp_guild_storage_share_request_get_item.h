#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_storage_share_request_get_item_cs : public BasePacket 	// 문파 공유 창고 아이템 요청
	{
	public:
		int64_t iuid{};
	public:
		int32_t item_count{};

	public:
		mp_guild_storage_share_request_get_item_cs() : BasePacket(mpe_cmd::guild_storage_share_request_get_item_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &item_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_storage_share_request_get_item_sc : public BasePacket 	// 문파 공유 창고 아이템 요청
	{
	public:
		int64_t iuid{};
	public:
		int32_t current_request_count{};

	public:
		mp_guild_storage_share_request_get_item_sc() : BasePacket(mpe_cmd::guild_storage_share_request_get_item_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &current_request_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
