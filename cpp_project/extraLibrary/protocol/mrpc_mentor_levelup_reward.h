#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_mail.h"
#include "struct/mrpcs_mail.h"

namespace mir3d
{
	class mrpc_mentor_levelup_reward_cs : public RpcPacket 
	{
	public:
		int64_t mentor_auid{};
	public:
		int64_t mentor_cuid{};
	public:
		std::vector<mrpcs_mail> mentor_info{};
	public:
		int64_t mentee_auid{};
	public:
		int64_t mentee_cuid{};
	public:
		std::vector<mrpcs_mail> mentee_info{};

	public:
		mrpc_mentor_levelup_reward_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mentor_levelup_reward_cs, tag)
		{
		}
		mrpc_mentor_levelup_reward_cs() : RpcPacket(mpe_rpc_cmd::mentor_levelup_reward_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &mentor_auid);
			protocol::SerializeType(pBuffer, &mentor_cuid);
			protocol::SerializeType(pBuffer, &mentor_info);
			protocol::SerializeType(pBuffer, &mentee_auid);
			protocol::SerializeType(pBuffer, &mentee_cuid);
			protocol::SerializeType(pBuffer, &mentee_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_mentor_levelup_reward_sc : public RpcPacket 
	{

	public:
		mrpc_mentor_levelup_reward_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mentor_levelup_reward_sc, tag)
		{
		}
		mrpc_mentor_levelup_reward_sc() : RpcPacket(mpe_rpc_cmd::mentor_levelup_reward_sc)
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
