#pragma once
#include <vector>
#include <string>
#include "mrpcs_reserved_mail.h"

namespace mir3d
{
	class mrpcs_reserved_mail_list 
	{
	public:
		std::vector<mrpcs_reserved_mail> info{};

	public:
		mrpcs_reserved_mail_list()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
