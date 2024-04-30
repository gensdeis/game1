#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_obtain_reflection.h"
#include "struct/mps_temp_reflection.h"

namespace mir3d
{
	class mrpc_gm_reflection_add_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_obtain_reflection> list{};
	public:
		std::vector<mps_temp_reflection> list_temp_reflection{};

	public:
		mrpc_gm_reflection_add_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_reflection_add_cs, tag)
		{
		}
		mrpc_gm_reflection_add_cs() : RpcPacket(mpe_rpc_cmd::gm_reflection_add_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &list_temp_reflection);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_reflection_add_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_gm_reflection_add_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_reflection_add_sc, tag)
		{
		}
		mrpc_gm_reflection_add_sc() : RpcPacket(mpe_rpc_cmd::gm_reflection_add_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
