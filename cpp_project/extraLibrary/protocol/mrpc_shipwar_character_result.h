#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_shipwar_character_result.h"

namespace mir3d
{
	class mrpc_shipwar_character_result_cs : public RpcPacket 
	{
	public:
		std::vector<mrpcs_shipwar_character_result> list_character{};

	public:
		mrpc_shipwar_character_result_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::shipwar_character_result_cs, tag)
		{
		}
		mrpc_shipwar_character_result_cs() : RpcPacket(mpe_rpc_cmd::shipwar_character_result_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_character);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_shipwar_character_result_sc : public RpcPacket 
	{

	public:
		mrpc_shipwar_character_result_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::shipwar_character_result_sc, tag)
		{
		}
		mrpc_shipwar_character_result_sc() : RpcPacket(mpe_rpc_cmd::shipwar_character_result_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
