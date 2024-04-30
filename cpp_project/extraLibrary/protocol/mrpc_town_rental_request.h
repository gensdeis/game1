#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_town_rental_request_cs : public RpcPacket 
	{
	public:
		uint8_t town_grade{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};

	public:
		mrpc_town_rental_request_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::town_rental_request_cs, tag)
		{
		}
		mrpc_town_rental_request_cs() : RpcPacket(mpe_rpc_cmd::town_rental_request_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &town_grade);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_town_rental_request_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};

	public:
		mrpc_town_rental_request_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::town_rental_request_sc, tag)
		{
		}
		mrpc_town_rental_request_sc() : RpcPacket(mpe_rpc_cmd::town_rental_request_sc)
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
