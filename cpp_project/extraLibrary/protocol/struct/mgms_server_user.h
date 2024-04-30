#pragma once
#include <vector>
#include <string>
#include "mrpcs_server_info.h"

namespace mir3d
{
	class mgms_server_user 
	{
	private:
		bool flag_server_info = false;
		mrpcs_server_info server_info;
		mrpcs_server_info* p_server_info = nullptr;
	public:
		bool has_server_info() const
		{
			return flag_server_info;
		}
		mrpcs_server_info* alloc_server_info()
		{
			flag_server_info = true;
			return &server_info;
		}
		const mrpcs_server_info* get_server_info() const
		{
			if (true == flag_server_info)
			{
				if (nullptr == p_server_info)
				{
					return &server_info;
				}
				return p_server_info;
			}
			return nullptr;
		}
		void set_server_info(mrpcs_server_info* in_server_info)
		{
			if (nullptr == p_server_info)
			{
				p_server_info = in_server_info;
				flag_server_info = true;
			}
		}
	public:
		short play_user{};

	public:
		mgms_server_user()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &flag_server_info);
			if (true == flag_server_info)
			{
				if (nullptr != p_server_info)
					protocol::SerializeType(pBuffer, p_server_info);
				else
					protocol::SerializeType(pBuffer, &server_info);
			}
			protocol::SerializeType(pBuffer, &play_user);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
