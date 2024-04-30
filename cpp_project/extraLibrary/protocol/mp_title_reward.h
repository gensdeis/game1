#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_title.h"

namespace mir3d
{
	class mp_title_reward_cs : public BasePacket 
	{
	public:
		int32_t tid{};
	public:
		uint16_t index{};

	public:
		mp_title_reward_cs() : BasePacket(mpe_cmd::title_reward_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_title_reward_sc : public BasePacket 
	{
	private:
		bool flag_item_add = false;
		mps_item_add item_add;	// 보상 아이템
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
	private:
		bool flag_title_info = false;
		mps_title title_info;	// 갱신된 업적정보
		mps_title* p_title_info = nullptr;
	public:
		bool has_title_info() const
		{
			return flag_title_info;
		}
		mps_title* alloc_title_info()
		{
			flag_title_info = true;
			return &title_info;
		}
		const mps_title* get_title_info() const
		{
			if (true == flag_title_info)
			{
				if (nullptr == p_title_info)
				{
					return &title_info;
				}
				return p_title_info;
			}
			return nullptr;
		}
		void set_title_info(mps_title* in_title_info)
		{
			if (nullptr == p_title_info)
			{
				p_title_info = in_title_info;
				flag_title_info = true;
			}
		}

	public:
		mp_title_reward_sc() : BasePacket(mpe_cmd::title_reward_sc)
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
			protocol::SerializeType(pBuffer, &flag_title_info);
			if (true == flag_title_info)
			{
				if (nullptr != p_title_info)
					protocol::SerializeType(pBuffer, p_title_info);
				else
					protocol::SerializeType(pBuffer, &title_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
