#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_character_last_time_change_cs : public RpcPacket 
	{
	public:
		std::string target_name{};	// "대상캐릭터 닉네임."
	public:
		int32_t add_sec{};	// "현재시간(utcnow.tounixtime) + 이값. 저장."

	public:
		mrpc_gm_character_last_time_change_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_character_last_time_change_cs, tag)
		{
		}
		mrpc_gm_character_last_time_change_cs() : RpcPacket(mpe_rpc_cmd::gm_character_last_time_change_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_name);
			protocol::SerializeType(pBuffer, &add_sec);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_character_last_time_change_sc : public RpcPacket 
	{

	public:
		mrpc_gm_character_last_time_change_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_character_last_time_change_sc, tag)
		{
		}
		mrpc_gm_character_last_time_change_sc() : RpcPacket(mpe_rpc_cmd::gm_character_last_time_change_sc)
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
