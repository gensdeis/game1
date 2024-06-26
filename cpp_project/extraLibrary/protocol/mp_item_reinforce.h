﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_iuid_list.h"
#include "struct/mps_item_option_update.h"
#include "struct/mps_item_add.h"
#include "struct/mps_profesion.h"

namespace mir3d
{
	class mp_item_reinforce_cs : public BasePacket 
	{
	public:
		int64_t iuid{};
	public:
		mpe_item_reinforce_position flag{};
	private:
		bool flag_info = false;
		mps_item_iuid_list info;
		mps_item_iuid_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_iuid_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_iuid_list* get_info() const
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
		void set_info(mps_item_iuid_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		std::vector<int32_t> list_tid{};

	public:
		mp_item_reinforce_cs() : BasePacket(mpe_cmd::item_reinforce_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeEnum(pBuffer, &flag);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &list_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_item_reinforce_sc : public BasePacket 
	{
	public:
		mpe_reinforce_result result{};
	private:
		bool flag_item_option = false;
		mps_item_option_update item_option;
		mps_item_option_update* p_item_option = nullptr;
	public:
		bool has_item_option() const
		{
			return flag_item_option;
		}
		mps_item_option_update* alloc_item_option()
		{
			flag_item_option = true;
			return &item_option;
		}
		const mps_item_option_update* get_item_option() const
		{
			if (true == flag_item_option)
			{
				if (nullptr == p_item_option)
				{
					return &item_option;
				}
				return p_item_option;
			}
			return nullptr;
		}
		void set_item_option(mps_item_option_update* in_item_option)
		{
			if (nullptr == p_item_option)
			{
				p_item_option = in_item_option;
				flag_item_option = true;
			}
		}
	private:
		bool flag_info = false;
		mps_item_add info;
		mps_item_add* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_add* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_add* get_info() const
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
		void set_info(mps_item_add* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		uint16_t max_durability{};	// 생활장비 최대 내구도
	private:
		bool flag_profesion_info = false;
		mps_profesion profesion_info;	// 장인 정보
		mps_profesion* p_profesion_info = nullptr;
	public:
		bool has_profesion_info() const
		{
			return flag_profesion_info;
		}
		mps_profesion* alloc_profesion_info()
		{
			flag_profesion_info = true;
			return &profesion_info;
		}
		const mps_profesion* get_profesion_info() const
		{
			if (true == flag_profesion_info)
			{
				if (nullptr == p_profesion_info)
				{
					return &profesion_info;
				}
				return p_profesion_info;
			}
			return nullptr;
		}
		void set_profesion_info(mps_profesion* in_profesion_info)
		{
			if (nullptr == p_profesion_info)
			{
				p_profesion_info = in_profesion_info;
				flag_profesion_info = true;
			}
		}

	public:
		mp_item_reinforce_sc() : BasePacket(mpe_cmd::item_reinforce_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &flag_item_option);
			if (true == flag_item_option)
			{
				if (nullptr != p_item_option)
					protocol::SerializeType(pBuffer, p_item_option);
				else
					protocol::SerializeType(pBuffer, &item_option);
			}
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &max_durability);
			protocol::SerializeType(pBuffer, &flag_profesion_info);
			if (true == flag_profesion_info)
			{
				if (nullptr != p_profesion_info)
					protocol::SerializeType(pBuffer, p_profesion_info);
				else
					protocol::SerializeType(pBuffer, &profesion_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
