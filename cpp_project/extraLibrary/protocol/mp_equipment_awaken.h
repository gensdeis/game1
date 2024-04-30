#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_option_update.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_equipment_awaken_cs : public BasePacket 
	{
	public:
		int64_t target_iuid{};
	public:
		int64_t material_iuid{};
	public:
		uint8_t awaken_step{};

	public:
		mp_equipment_awaken_cs() : BasePacket(mpe_cmd::equipment_awaken_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_iuid);
			protocol::SerializeType(pBuffer, &material_iuid);
			protocol::SerializeType(pBuffer, &awaken_step);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_equipment_awaken_sc : public BasePacket 
	{
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
		mp_equipment_awaken_sc() : BasePacket(mpe_cmd::equipment_awaken_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
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
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
