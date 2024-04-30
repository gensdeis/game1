#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_player_duplication_login_info_cs : public RpcPacket 
	{
	public:
		int64_t auid{};

	public:
		mrpc_player_duplication_login_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::player_duplication_login_info_cs, tag)
		{
		}
		mrpc_player_duplication_login_info_cs() : RpcPacket(mpe_rpc_cmd::player_duplication_login_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_player_duplication_login_info_sc : public RpcPacket 
	{
	public:
		int64_t auid{};
	public:
		int32_t gid{};
	public:
		std::string username{};

	public:
		mrpc_player_duplication_login_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::player_duplication_login_info_sc, tag)
		{
		}
		mrpc_player_duplication_login_info_sc() : RpcPacket(mpe_rpc_cmd::player_duplication_login_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &username);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
