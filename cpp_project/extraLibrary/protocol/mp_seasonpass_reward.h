#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_seasonpass.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_seasonpass_reward_cs : public BasePacket 
	{
	public:
		mpe_seasonpass_reward_type type{};
	public:
		int32_t index{};
	public:
		int32_t season_number{};

	public:
		mp_seasonpass_reward_cs() : BasePacket(mpe_cmd::seasonpass_reward_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &season_number);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_seasonpass_reward_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_seasonpass info;
		mps_seasonpass* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_seasonpass* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_seasonpass* get_info() const
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
		void set_info(mps_seasonpass* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
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

	public:
		mp_seasonpass_reward_sc() : BasePacket(mpe_cmd::seasonpass_reward_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &flag_item_add);
			if (true == flag_item_add)
			{
				if (nullptr != p_item_add)
					protocol::SerializeType(pBuffer, p_item_add);
				else
					protocol::SerializeType(pBuffer, &item_add);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
