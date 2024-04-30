#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_auto_matching_state_cs : public RpcPacket 
	{
	public:
		mrpce_auto_matching_type match_type{};
	public:
		bool is_pause{};	// true:pause/false: resume
	public:
		int64_t cuid{};
	public:
		int64_t puid{};

	public:
		mrpc_auto_matching_state_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::auto_matching_state_cs, tag)
		{
		}
		mrpc_auto_matching_state_cs() : RpcPacket(mpe_rpc_cmd::auto_matching_state_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &match_type);
			protocol::SerializeType(pBuffer, &is_pause);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &puid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_auto_matching_state_sc : public RpcPacket 
	{

	public:
		mrpc_auto_matching_state_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::auto_matching_state_sc, tag)
		{
		}
		mrpc_auto_matching_state_sc() : RpcPacket(mpe_rpc_cmd::auto_matching_state_sc)
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
