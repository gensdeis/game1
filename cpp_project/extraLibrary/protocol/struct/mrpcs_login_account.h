#pragma once
#include <vector>
#include <string>
#include "mps_login_account.h"
#include "mrpcs_account_ticket_item.h"

namespace mir3d
{
	class mrpcs_login_account 
	{
	private:
		bool flag_base_info = false;
		mps_login_account base_info;
		mps_login_account* p_base_info = nullptr;
	public:
		bool has_base_info() const
		{
			return flag_base_info;
		}
		mps_login_account* alloc_base_info()
		{
			flag_base_info = true;
			return &base_info;
		}
		const mps_login_account* get_base_info() const
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
		void set_base_info(mps_login_account* in_base_info)
		{
			if (nullptr == p_base_info)
			{
				p_base_info = in_base_info;
				flag_base_info = true;
			}
		}
	private:
		bool flag_account_ticket_item = false;
		mrpcs_account_ticket_item account_ticket_item;
		mrpcs_account_ticket_item* p_account_ticket_item = nullptr;
	public:
		bool has_account_ticket_item() const
		{
			return flag_account_ticket_item;
		}
		mrpcs_account_ticket_item* alloc_account_ticket_item()
		{
			flag_account_ticket_item = true;
			return &account_ticket_item;
		}
		const mrpcs_account_ticket_item* get_account_ticket_item() const
		{
			if (true == flag_account_ticket_item)
			{
				if (nullptr == p_account_ticket_item)
				{
					return &account_ticket_item;
				}
				return p_account_ticket_item;
			}
			return nullptr;
		}
		void set_account_ticket_item(mrpcs_account_ticket_item* in_account_ticket_item)
		{
			if (nullptr == p_account_ticket_item)
			{
				p_account_ticket_item = in_account_ticket_item;
				flag_account_ticket_item = true;
			}
		}

	public:
		mrpcs_login_account()
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
			protocol::SerializeType(pBuffer, &flag_account_ticket_item);
			if (true == flag_account_ticket_item)
			{
				if (nullptr != p_account_ticket_item)
					protocol::SerializeType(pBuffer, p_account_ticket_item);
				else
					protocol::SerializeType(pBuffer, &account_ticket_item);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
