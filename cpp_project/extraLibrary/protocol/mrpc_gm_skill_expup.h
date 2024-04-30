#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_skill.h"

namespace mir3d
{
	class mrpc_gm_skill_expup_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_skill = false;
		mps_skill skill;
		mps_skill* p_skill = nullptr;
	public:
		bool has_skill() const
		{
			return flag_skill;
		}
		mps_skill* alloc_skill()
		{
			flag_skill = true;
			return &skill;
		}
		const mps_skill* get_skill() const
		{
			if (true == flag_skill)
			{
				if (nullptr == p_skill)
				{
					return &skill;
				}
				return p_skill;
			}
			return nullptr;
		}
		void set_skill(mps_skill* in_skill)
		{
			if (nullptr == p_skill)
			{
				p_skill = in_skill;
				flag_skill = true;
			}
		}

	public:
		mrpc_gm_skill_expup_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_skill_expup_cs, tag)
		{
		}
		mrpc_gm_skill_expup_cs() : RpcPacket(mpe_rpc_cmd::gm_skill_expup_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_skill);
			if (true == flag_skill)
			{
				if (nullptr != p_skill)
					protocol::SerializeType(pBuffer, p_skill);
				else
					protocol::SerializeType(pBuffer, &skill);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_skill_expup_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_gm_skill_expup_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_skill_expup_sc, tag)
		{
		}
		mrpc_gm_skill_expup_sc() : RpcPacket(mpe_rpc_cmd::gm_skill_expup_sc)
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
