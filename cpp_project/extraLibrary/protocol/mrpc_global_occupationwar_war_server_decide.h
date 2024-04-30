#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_occupationwar_server_info_total.h"

namespace mir3d
{
	class mrpc_global_occupationwar_war_server_decide_cs : public RpcPacket 	// 비곡창고 비곡점령전 서버결정...
	{
	public:
		int32_t type{};

	public:
		mrpc_global_occupationwar_war_server_decide_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_occupationwar_war_server_decide_cs, tag)
		{
		}
		mrpc_global_occupationwar_war_server_decide_cs() : RpcPacket(mpe_rpc_cmd::global_occupationwar_war_server_decide_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_global_occupationwar_war_server_decide_sc : public RpcPacket 	// 비곡창고 비곡점령전 서버결정...
	{
	public:
		int32_t type{};
	public:
		int64_t occupationwar_uid{};
	public:
		int32_t week_number{};
	public:
		std::vector<mrpcs_occupationwar_server_info_total> list_decide{};
	public:
		std::vector<int32_t> list_tax{};

	public:
		mrpc_global_occupationwar_war_server_decide_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_occupationwar_war_server_decide_sc, tag)
		{
		}
		mrpc_global_occupationwar_war_server_decide_sc() : RpcPacket(mpe_rpc_cmd::global_occupationwar_war_server_decide_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &occupationwar_uid);
			protocol::SerializeType(pBuffer, &week_number);
			protocol::SerializeType(pBuffer, &list_decide);
			protocol::SerializeType(pBuffer, &list_tax);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
