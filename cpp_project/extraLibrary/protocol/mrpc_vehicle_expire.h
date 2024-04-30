#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_vehicle_expire_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t vehicle_tid{};
	public:
		int32_t satiety{};
	public:
		int32_t cur_vehicle{};	// 장착된 탈것 ( 기간제를 위함 )

	public:
		mrpc_vehicle_expire_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::vehicle_expire_cs, tag)
		{
		}
		mrpc_vehicle_expire_cs() : RpcPacket(mpe_rpc_cmd::vehicle_expire_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &vehicle_tid);
			protocol::SerializeType(pBuffer, &satiety);
			protocol::SerializeType(pBuffer, &cur_vehicle);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_vehicle_expire_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_vehicle_expire_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::vehicle_expire_sc, tag)
		{
		}
		mrpc_vehicle_expire_sc() : RpcPacket(mpe_rpc_cmd::vehicle_expire_sc)
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
