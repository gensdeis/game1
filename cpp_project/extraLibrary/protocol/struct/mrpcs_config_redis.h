#pragma once
#include <vector>
#include <string>
#include "mrpcs_config_address.h"
#include "mrpcs_config_address.h"

namespace mir3d
{
	class mrpcs_config_redis 
	{
	public:
		std::string name{};
	private:
		bool flag_address = false;
		mrpcs_config_address address;
		mrpcs_config_address* p_address = nullptr;
	public:
		bool has_address() const
		{
			return flag_address;
		}
		mrpcs_config_address* alloc_address()
		{
			flag_address = true;
			return &address;
		}
		const mrpcs_config_address* get_address() const
		{
			if (true == flag_address)
			{
				if (nullptr == p_address)
				{
					return &address;
				}
				return p_address;
			}
			return nullptr;
		}
		void set_address(mrpcs_config_address* in_address)
		{
			if (nullptr == p_address)
			{
				p_address = in_address;
				flag_address = true;
			}
		}
	public:
		std::vector<mrpcs_config_address> multi_address{};
	public:
		std::string pwd{};
	public:
		bool ssl{};

	public:
		mrpcs_config_redis()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &flag_address);
			if (true == flag_address)
			{
				if (nullptr != p_address)
					protocol::SerializeType(pBuffer, p_address);
				else
					protocol::SerializeType(pBuffer, &address);
			}
			protocol::SerializeType(pBuffer, &multi_address);
			protocol::SerializeType(pBuffer, &pwd);
			protocol::SerializeType(pBuffer, &ssl);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
