#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_blood_dedicate_reward_change_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};	// 캐릭터 아이디
	public:
		int32_t fixed_object_id{};	// 봉혈 오브젝트 아이디
	public:
		int32_t id{};	// 테이블 아이디

	public:
		mrpc_blood_dedicate_reward_change_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blood_dedicate_reward_change_cs, tag)
		{
		}
		mrpc_blood_dedicate_reward_change_cs() : RpcPacket(mpe_rpc_cmd::blood_dedicate_reward_change_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &fixed_object_id);
			protocol::SerializeType(pBuffer, &id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_blood_dedicate_reward_change_sc : public RpcPacket 
	{

	public:
		mrpc_blood_dedicate_reward_change_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blood_dedicate_reward_change_sc, tag)
		{
		}
		mrpc_blood_dedicate_reward_change_sc() : RpcPacket(mpe_rpc_cmd::blood_dedicate_reward_change_sc)
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
