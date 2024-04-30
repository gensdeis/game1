#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_friend_request_response_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t target_cuid{};
	public:
		bool is_accept{};

	public:
		mrpc_friend_request_response_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::friend_request_response_cs, tag)
		{
		}
		mrpc_friend_request_response_cs() : RpcPacket(mpe_rpc_cmd::friend_request_response_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &is_accept);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_friend_request_response_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};

	public:
		mrpc_friend_request_response_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::friend_request_response_sc, tag)
		{
		}
		mrpc_friend_request_response_sc() : RpcPacket(mpe_rpc_cmd::friend_request_response_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
