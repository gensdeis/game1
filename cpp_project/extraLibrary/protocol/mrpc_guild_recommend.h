#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_other_guild_info.h"

namespace mir3d
{
	class mrpc_guild_recommend_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};

	public:
		mrpc_guild_recommend_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_recommend_cs, tag)
		{
		}
		mrpc_guild_recommend_cs() : RpcPacket(mpe_rpc_cmd::guild_recommend_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_recommend_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		mpe_error error{};
	public:
		std::vector<mps_other_guild_info> list_guild{};
	public:
		std::vector<int64_t> list_request_guid{};

	public:
		mrpc_guild_recommend_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_recommend_sc, tag)
		{
		}
		mrpc_guild_recommend_sc() : RpcPacket(mpe_rpc_cmd::guild_recommend_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &error);
			protocol::SerializeType(pBuffer, &list_guild);
			protocol::SerializeType(pBuffer, &list_request_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
