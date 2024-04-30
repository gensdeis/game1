#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gm_add_expert_exp_cs : public BasePacket 
	{
	public:
		int64_t expert_exp{};

	public:
		mp_gm_add_expert_exp_cs() : BasePacket(mpe_cmd::gm_add_expert_exp_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &expert_exp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_add_expert_exp_sc : public BasePacket 
	{
	public:
		int32_t expert_level{};
	public:
		int64_t expert_exp{};

	public:
		mp_gm_add_expert_exp_sc() : BasePacket(mpe_cmd::gm_add_expert_exp_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &expert_level);
			protocol::SerializeType(pBuffer, &expert_exp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
