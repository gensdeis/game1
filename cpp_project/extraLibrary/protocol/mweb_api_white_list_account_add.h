#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_white_list_account.h"

namespace mir3d
{
	class mweb_api_white_list_account_add_cs : public WebBasePacket 
	{
	private:
		bool flag_white_list_account = false;
		mrpcs_white_list_account white_list_account;
		mrpcs_white_list_account* p_white_list_account = nullptr;
	public:
		bool has_white_list_account() const
		{
			return flag_white_list_account;
		}
		mrpcs_white_list_account* alloc_white_list_account()
		{
			flag_white_list_account = true;
			return &white_list_account;
		}
		const mrpcs_white_list_account* get_white_list_account() const
		{
			if (true == flag_white_list_account)
			{
				if (nullptr == p_white_list_account)
				{
					return &white_list_account;
				}
				return p_white_list_account;
			}
			return nullptr;
		}
		void set_white_list_account(mrpcs_white_list_account* in_white_list_account)
		{
			if (nullptr == p_white_list_account)
			{
				p_white_list_account = in_white_list_account;
				flag_white_list_account = true;
			}
		}

	public:
		mweb_api_white_list_account_add_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_white_list_account);
			if (true == flag_white_list_account)
			{
				if (nullptr != p_white_list_account)
					protocol::SerializeType(pBuffer, p_white_list_account);
				else
					protocol::SerializeType(pBuffer, &white_list_account);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_api_white_list_account_add_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};

	public:
		mweb_api_white_list_account_add_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
