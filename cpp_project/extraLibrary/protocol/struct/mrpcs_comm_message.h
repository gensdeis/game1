#pragma once
#include <vector>
#include <string>
#include "mrpcs_comm_message_data.h"

namespace mir3d
{
	class mrpcs_comm_message 
	{
	public:
		int64_t send_uid{};
	public:
		int64_t target_uid{};
	public:
		mrpce_community_object_message_type message_type{};
	private:
		bool flag_message_data = false;
		mrpcs_comm_message_data message_data;
		mrpcs_comm_message_data* p_message_data = nullptr;
	public:
		bool has_message_data() const
		{
			return flag_message_data;
		}
		mrpcs_comm_message_data* alloc_message_data()
		{
			flag_message_data = true;
			return &message_data;
		}
		const mrpcs_comm_message_data* get_message_data() const
		{
			if (true == flag_message_data)
			{
				if (nullptr == p_message_data)
				{
					return &message_data;
				}
				return p_message_data;
			}
			return nullptr;
		}
		void set_message_data(mrpcs_comm_message_data* in_message_data)
		{
			if (nullptr == p_message_data)
			{
				p_message_data = in_message_data;
				flag_message_data = true;
			}
		}
	public:
		mpe_error error_code{};

	public:
		mrpcs_comm_message()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &send_uid);
			protocol::SerializeType(pBuffer, &target_uid);
			protocol::SerializeEnum(pBuffer, &message_type);
			protocol::SerializeType(pBuffer, &flag_message_data);
			if (true == flag_message_data)
			{
				if (nullptr != p_message_data)
					protocol::SerializeType(pBuffer, p_message_data);
				else
					protocol::SerializeType(pBuffer, &message_data);
			}
			protocol::SerializeEnum(pBuffer, &error_code);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
