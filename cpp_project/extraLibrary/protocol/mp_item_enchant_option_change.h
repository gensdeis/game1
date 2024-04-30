#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_enchant_options.h"
#include "struct/mps_profesion.h"

namespace mir3d
{
	class mp_item_enchant_option_change_cs : public BasePacket 
	{
	public:
		int64_t iuid{};
	public:
		mpe_item_reinforce_position pos{};
	public:
		std::vector<int32_t> list_tid{};

	public:
		mp_item_enchant_option_change_cs() : BasePacket(mpe_cmd::item_enchant_option_change_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeEnum(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &list_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_item_enchant_option_change_sc : public BasePacket 
	{
	public:
		int64_t iuid{};
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
	private:
		bool flag_option_list = false;
		mps_enchant_options option_list;
		mps_enchant_options* p_option_list = nullptr;
	public:
		bool has_option_list() const
		{
			return flag_option_list;
		}
		mps_enchant_options* alloc_option_list()
		{
			flag_option_list = true;
			return &option_list;
		}
		const mps_enchant_options* get_option_list() const
		{
			if (true == flag_option_list)
			{
				if (nullptr == p_option_list)
				{
					return &option_list;
				}
				return p_option_list;
			}
			return nullptr;
		}
		void set_option_list(mps_enchant_options* in_option_list)
		{
			if (nullptr == p_option_list)
			{
				p_option_list = in_option_list;
				flag_option_list = true;
			}
		}
	private:
		bool flag_profesion_info = false;
		mps_profesion profesion_info;
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
		int32_t add_exp{};	// 장인 총 획득 경험치

	public:
		mp_item_enchant_option_change_sc() : BasePacket(mpe_cmd::item_enchant_option_change_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &flag_option_list);
			if (true == flag_option_list)
			{
				if (nullptr != p_option_list)
					protocol::SerializeType(pBuffer, p_option_list);
				else
					protocol::SerializeType(pBuffer, &option_list);
			}
			protocol::SerializeType(pBuffer, &flag_profesion_info);
			if (true == flag_profesion_info)
			{
				if (nullptr != p_profesion_info)
					protocol::SerializeType(pBuffer, p_profesion_info);
				else
					protocol::SerializeType(pBuffer, &profesion_info);
			}
			protocol::SerializeType(pBuffer, &add_exp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
