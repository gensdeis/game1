﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_skill.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mp_skill_learn_cs : public BasePacket 
	{
	public:
		int64_t iuid{};

	public:
		mp_skill_learn_cs() : BasePacket(mpe_cmd::skill_learn_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_skill_learn_sc : public BasePacket 
	{
	public:
		float weight{};
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
	private:
		bool flag_info = false;
		mps_item_count_update info;	// 수정 -> mps_item_add
		mps_item_count_update* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_count_update* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_count_update* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mps_item_count_update* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_skill_learn_sc() : BasePacket(mpe_cmd::skill_learn_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &weight);
			protocol::SerializeType(pBuffer, &flag_skill);
			if (true == flag_skill)
			{
				if (nullptr != p_skill)
					protocol::SerializeType(pBuffer, p_skill);
				else
					protocol::SerializeType(pBuffer, &skill);
			}
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}