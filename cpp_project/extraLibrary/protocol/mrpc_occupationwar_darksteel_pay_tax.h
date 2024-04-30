#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_darksteel_box_keep_server.h"
#include "struct/mrpcs_darksteel_pay_tax_info.h"

namespace mir3d
{
	class mrpc_occupationwar_darksteel_pay_tax_cs : public RpcPacket 	// 비곡창고 비곡점령전 미진행 서버들 조공...
	{
	public:
		int64_t occupationwar_uid{};
	public:
		std::vector<int32_t> list_tax{};
	public:
		std::vector<mps_darksteel_box_keep_server> list{};

	public:
		mrpc_occupationwar_darksteel_pay_tax_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::occupationwar_darksteel_pay_tax_cs, tag)
		{
		}
		mrpc_occupationwar_darksteel_pay_tax_cs() : RpcPacket(mpe_rpc_cmd::occupationwar_darksteel_pay_tax_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &occupationwar_uid);
			protocol::SerializeType(pBuffer, &list_tax);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_occupationwar_darksteel_pay_tax_sc : public RpcPacket 	// 비곡창고 비곡점령전 미진행 서버들 조공...
	{
	public:
		int64_t occupationwar_uid{};
	public:
		std::vector<mrpcs_darksteel_pay_tax_info> list{};

	public:
		mrpc_occupationwar_darksteel_pay_tax_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::occupationwar_darksteel_pay_tax_sc, tag)
		{
		}
		mrpc_occupationwar_darksteel_pay_tax_sc() : RpcPacket(mpe_rpc_cmd::occupationwar_darksteel_pay_tax_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &occupationwar_uid);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
