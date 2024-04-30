#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_mentor_party_buff_cs : public RpcPacket 
	{

	public:
		mrpc_mentor_party_buff_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mentor_party_buff_cs, tag)
		{
		}
		mrpc_mentor_party_buff_cs() : RpcPacket(mpe_rpc_cmd::mentor_party_buff_cs)
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

	class mrpc_mentor_party_buff_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t target_cuid{};
	public:
		bool connect{};
	public:
		int32_t zone_id{};

	public:
		mrpc_mentor_party_buff_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mentor_party_buff_sc, tag)
		{
		}
		mrpc_mentor_party_buff_sc() : RpcPacket(mpe_rpc_cmd::mentor_party_buff_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &connect);
			protocol::SerializeType(pBuffer, &zone_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
