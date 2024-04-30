#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_player_connect_info_cs : public RpcPacket 
	{
	public:
		int32_t gid{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int64_t access_token{};
	public:
		int32_t flag{};

	public:
		mrpc_player_connect_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::player_connect_info_cs, tag)
		{
		}
		mrpc_player_connect_info_cs() : RpcPacket(mpe_rpc_cmd::player_connect_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &flag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_player_connect_info_sc : public RpcPacket 
	{
	public:
		int32_t flag{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int64_t access_token{};
	public:
		int32_t gid{};

	public:
		mrpc_player_connect_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::player_connect_info_sc, tag)
		{
		}
		mrpc_player_connect_info_sc() : RpcPacket(mpe_rpc_cmd::player_connect_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
