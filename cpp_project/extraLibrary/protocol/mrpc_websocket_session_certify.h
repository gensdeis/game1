#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_websocket_session_certify_cs : public RpcPacket 
	{
	public:
		std::string access_token{};

	public:
		mrpc_websocket_session_certify_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::websocket_session_certify_cs, tag)
		{
		}
		mrpc_websocket_session_certify_cs() : RpcPacket(mpe_rpc_cmd::websocket_session_certify_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &access_token);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_websocket_session_certify_sc : public RpcPacket 
	{
	public:
		std::string access_token{};

	public:
		mrpc_websocket_session_certify_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::websocket_session_certify_sc, tag)
		{
		}
		mrpc_websocket_session_certify_sc() : RpcPacket(mpe_rpc_cmd::websocket_session_certify_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &access_token);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
