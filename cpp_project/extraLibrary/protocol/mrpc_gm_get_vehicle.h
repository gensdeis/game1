#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_vehicle.h"

namespace mir3d
{
	class mrpc_gm_get_vehicle_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_vehicle> list{};

	public:
		mrpc_gm_get_vehicle_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_get_vehicle_cs, tag)
		{
		}
		mrpc_gm_get_vehicle_cs() : RpcPacket(mpe_rpc_cmd::gm_get_vehicle_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_get_vehicle_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_gm_get_vehicle_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_get_vehicle_sc, tag)
		{
		}
		mrpc_gm_get_vehicle_sc() : RpcPacket(mpe_rpc_cmd::gm_get_vehicle_sc)
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
