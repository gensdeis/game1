#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_friend_request_response_all_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		bool is_accept{};

	public:
		mrpc_friend_request_response_all_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::friend_request_response_all_cs, tag)
		{
		}
		mrpc_friend_request_response_all_cs() : RpcPacket(mpe_rpc_cmd::friend_request_response_all_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &is_accept);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_friend_request_response_all_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};

	public:
		mrpc_friend_request_response_all_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::friend_request_response_all_sc, tag)
		{
		}
		mrpc_friend_request_response_all_sc() : RpcPacket(mpe_rpc_cmd::friend_request_response_all_sc)
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
