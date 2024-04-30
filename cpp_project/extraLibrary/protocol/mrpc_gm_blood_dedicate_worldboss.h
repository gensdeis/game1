#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_blood_dedicate_worldboss_cs : public RpcPacket 	// 치트키 - 봉혈 월드보스
	{
	public:
		int64_t key{};	// 세션 아이디
	public:
		mpe_gm_blood_dedicate_worldboss_type type{};	// 치트키 타입
	public:
		int32_t contribution_point{};	// 보스소환 기여도

	public:
		mrpc_gm_blood_dedicate_worldboss_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_blood_dedicate_worldboss_cs, tag)
		{
		}
		mrpc_gm_blood_dedicate_worldboss_cs() : RpcPacket(mpe_rpc_cmd::gm_blood_dedicate_worldboss_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &contribution_point);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_blood_dedicate_worldboss_sc : public RpcPacket 	// 치트키 - 봉혈 월드보스
	{

	public:
		mrpc_gm_blood_dedicate_worldboss_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_blood_dedicate_worldboss_sc, tag)
		{
		}
		mrpc_gm_blood_dedicate_worldboss_sc() : RpcPacket(mpe_rpc_cmd::gm_blood_dedicate_worldboss_sc)
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
