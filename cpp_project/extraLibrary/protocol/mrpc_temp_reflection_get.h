#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_temp_reflection.h"

namespace mir3d
{
	class mrpc_temp_reflection_get_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};

	public:
		mrpc_temp_reflection_get_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::temp_reflection_get_cs, tag)
		{
		}
		mrpc_temp_reflection_get_cs() : RpcPacket(mpe_rpc_cmd::temp_reflection_get_cs)
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

	class mrpc_temp_reflection_get_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_temp_reflection> list_temp{};

	public:
		mrpc_temp_reflection_get_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::temp_reflection_get_sc, tag)
		{
		}
		mrpc_temp_reflection_get_sc() : RpcPacket(mpe_rpc_cmd::temp_reflection_get_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &list_temp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
