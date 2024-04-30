﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_achieve_gid_info.h"
#include "struct/mps_item_add.h"
#include "struct/mps_title_info.h"
#include "struct/mps_achieve_info.h"

namespace mir3d
{
	class mp_achieve_reward_cs : public BasePacket 
	{
	public:
		std::vector<mps_achieve_gid_info> gid_list{};

	public:
		mp_achieve_reward_cs() : BasePacket(mpe_cmd::achieve_reward_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_achieve_reward_sc : public BasePacket 
	{
	private:
		bool flag_item_add = false;
		mps_item_add item_add;	// 획득 아이템
		mps_item_add* p_item_add = nullptr;
	public:
		bool has_item_add() const
		{
			return flag_item_add;
		}
		mps_item_add* alloc_item_add()
		{
			flag_item_add = true;
			return &item_add;
		}
		const mps_item_add* get_item_add() const
		{
			if (true == flag_item_add)
			{
				if (nullptr == p_item_add)
				{
					return &item_add;
				}
				return p_item_add;
			}
			return nullptr;
		}
		void set_item_add(mps_item_add* in_item_add)
		{
			if (nullptr == p_item_add)
			{
				p_item_add = in_item_add;
				flag_item_add = true;
			}
		}
	public:
		std::vector<mps_title_info> title_info{};	// 획득 칭호
	public:
		std::vector<mps_achieve_info> achieve_info{};	// 업적정보

	public:
		mp_achieve_reward_sc() : BasePacket(mpe_cmd::achieve_reward_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_item_add);
			if (true == flag_item_add)
			{
				if (nullptr != p_item_add)
					protocol::SerializeType(pBuffer, p_item_add);
				else
					protocol::SerializeType(pBuffer, &item_add);
			}
			protocol::SerializeType(pBuffer, &title_info);
			protocol::SerializeType(pBuffer, &achieve_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
