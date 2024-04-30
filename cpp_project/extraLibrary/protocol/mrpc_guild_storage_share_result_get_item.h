#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_storage_share_result_get_item_cs : public RpcPacket 	// 문파 공유 창고 아이템 요청 결과
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int64_t request_uid{};
	public:
		bool accept{};

	public:
		mrpc_guild_storage_share_result_get_item_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_storage_share_result_get_item_cs, tag)
		{
		}
		mrpc_guild_storage_share_result_get_item_cs() : RpcPacket(mpe_rpc_cmd::guild_storage_share_result_get_item_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &request_uid);
			protocol::SerializeType(pBuffer, &accept);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_storage_share_result_get_item_sc : public RpcPacket 	// 문파 공유 창고 아이템 요청 결과
	{
	public:
		int64_t cuid{};
	public:
		int64_t request_uid{};
	public:
		bool accept{};

	public:
		mrpc_guild_storage_share_result_get_item_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_storage_share_result_get_item_sc, tag)
		{
		}
		mrpc_guild_storage_share_result_get_item_sc() : RpcPacket(mpe_rpc_cmd::guild_storage_share_result_get_item_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &request_uid);
			protocol::SerializeType(pBuffer, &accept);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
