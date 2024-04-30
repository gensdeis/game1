#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_white_list_address.h"

namespace mir3d
{
	class mweb_api_white_list_address_add_cs : public WebBasePacket 
	{
	private:
		bool flag_white_list_address = false;
		mrpcs_white_list_address white_list_address;
		mrpcs_white_list_address* p_white_list_address = nullptr;
	public:
		bool has_white_list_address() const
		{
			return flag_white_list_address;
		}
		mrpcs_white_list_address* alloc_white_list_address()
		{
			flag_white_list_address = true;
			return &white_list_address;
		}
		const mrpcs_white_list_address* get_white_list_address() const
		{
			if (true == flag_white_list_address)
			{
				if (nullptr == p_white_list_address)
				{
					return &white_list_address;
				}
				return p_white_list_address;
			}
			return nullptr;
		}
		void set_white_list_address(mrpcs_white_list_address* in_white_list_address)
		{
			if (nullptr == p_white_list_address)
			{
				p_white_list_address = in_white_list_address;
				flag_white_list_address = true;
			}
		}

	public:
		mweb_api_white_list_address_add_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_white_list_address);
			if (true == flag_white_list_address)
			{
				if (nullptr != p_white_list_address)
					protocol::SerializeType(pBuffer, p_white_list_address);
				else
					protocol::SerializeType(pBuffer, &white_list_address);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_api_white_list_address_add_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};

	public:
		mweb_api_white_list_address_add_sc() : WebBasePacket()
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
