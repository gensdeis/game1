#pragma once
#include <vector>
#include <string>
#include "mrpcs_occupationwar_base_info.h"
#include "mrpcs_darksteel_box_keep_server_info.h"
#include "mps_occupationwar_schedule_info_list.h"
#include "mrpcs_contract_agenda_info.h"

namespace mir3d
{
	class mrpcs_occupationwar_server_info 
	{
	private:
		bool flag_base_info = false;
		mrpcs_occupationwar_base_info base_info;	// 기본 정보
		mrpcs_occupationwar_base_info* p_base_info = nullptr;
	public:
		bool has_base_info() const
		{
			return flag_base_info;
		}
		mrpcs_occupationwar_base_info* alloc_base_info()
		{
			flag_base_info = true;
			return &base_info;
		}
		const mrpcs_occupationwar_base_info* get_base_info() const
		{
			if (true == flag_base_info)
			{
				if (nullptr == p_base_info)
				{
					return &base_info;
				}
				return p_base_info;
			}
			return nullptr;
		}
		void set_base_info(mrpcs_occupationwar_base_info* in_base_info)
		{
			if (nullptr == p_base_info)
			{
				p_base_info = in_base_info;
				flag_base_info = true;
			}
		}
	private:
		bool flag_dakrsteelbox_info = false;
		mrpcs_darksteel_box_keep_server_info dakrsteelbox_info;
		mrpcs_darksteel_box_keep_server_info* p_dakrsteelbox_info = nullptr;
	public:
		bool has_dakrsteelbox_info() const
		{
			return flag_dakrsteelbox_info;
		}
		mrpcs_darksteel_box_keep_server_info* alloc_dakrsteelbox_info()
		{
			flag_dakrsteelbox_info = true;
			return &dakrsteelbox_info;
		}
		const mrpcs_darksteel_box_keep_server_info* get_dakrsteelbox_info() const
		{
			if (true == flag_dakrsteelbox_info)
			{
				if (nullptr == p_dakrsteelbox_info)
				{
					return &dakrsteelbox_info;
				}
				return p_dakrsteelbox_info;
			}
			return nullptr;
		}
		void set_dakrsteelbox_info(mrpcs_darksteel_box_keep_server_info* in_dakrsteelbox_info)
		{
			if (nullptr == p_dakrsteelbox_info)
			{
				p_dakrsteelbox_info = in_dakrsteelbox_info;
				flag_dakrsteelbox_info = true;
			}
		}
	private:
		bool flag_schedule_info = false;
		mps_occupationwar_schedule_info_list schedule_info;
		mps_occupationwar_schedule_info_list* p_schedule_info = nullptr;
	public:
		bool has_schedule_info() const
		{
			return flag_schedule_info;
		}
		mps_occupationwar_schedule_info_list* alloc_schedule_info()
		{
			flag_schedule_info = true;
			return &schedule_info;
		}
		const mps_occupationwar_schedule_info_list* get_schedule_info() const
		{
			if (true == flag_schedule_info)
			{
				if (nullptr == p_schedule_info)
				{
					return &schedule_info;
				}
				return p_schedule_info;
			}
			return nullptr;
		}
		void set_schedule_info(mps_occupationwar_schedule_info_list* in_schedule_info)
		{
			if (nullptr == p_schedule_info)
			{
				p_schedule_info = in_schedule_info;
				flag_schedule_info = true;
			}
		}
	private:
		bool flag_contract_info = false;
		mrpcs_contract_agenda_info contract_info;
		mrpcs_contract_agenda_info* p_contract_info = nullptr;
	public:
		bool has_contract_info() const
		{
			return flag_contract_info;
		}
		mrpcs_contract_agenda_info* alloc_contract_info()
		{
			flag_contract_info = true;
			return &contract_info;
		}
		const mrpcs_contract_agenda_info* get_contract_info() const
		{
			if (true == flag_contract_info)
			{
				if (nullptr == p_contract_info)
				{
					return &contract_info;
				}
				return p_contract_info;
			}
			return nullptr;
		}
		void set_contract_info(mrpcs_contract_agenda_info* in_contract_info)
		{
			if (nullptr == p_contract_info)
			{
				p_contract_info = in_contract_info;
				flag_contract_info = true;
			}
		}

	public:
		mrpcs_occupationwar_server_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &flag_base_info);
			if (true == flag_base_info)
			{
				if (nullptr != p_base_info)
					protocol::SerializeType(pBuffer, p_base_info);
				else
					protocol::SerializeType(pBuffer, &base_info);
			}
			protocol::SerializeType(pBuffer, &flag_dakrsteelbox_info);
			if (true == flag_dakrsteelbox_info)
			{
				if (nullptr != p_dakrsteelbox_info)
					protocol::SerializeType(pBuffer, p_dakrsteelbox_info);
				else
					protocol::SerializeType(pBuffer, &dakrsteelbox_info);
			}
			protocol::SerializeType(pBuffer, &flag_schedule_info);
			if (true == flag_schedule_info)
			{
				if (nullptr != p_schedule_info)
					protocol::SerializeType(pBuffer, p_schedule_info);
				else
					protocol::SerializeType(pBuffer, &schedule_info);
			}
			protocol::SerializeType(pBuffer, &flag_contract_info);
			if (true == flag_contract_info)
			{
				if (nullptr != p_contract_info)
					protocol::SerializeType(pBuffer, p_contract_info);
				else
					protocol::SerializeType(pBuffer, &contract_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
