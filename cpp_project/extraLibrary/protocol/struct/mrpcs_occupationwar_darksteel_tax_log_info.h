#pragma once
#include <vector>
#include <string>
#include "mrpcs_occupationwar_darksteel_tax_log.h"

namespace mir3d
{
	class mrpcs_occupationwar_darksteel_tax_log_info 
	{
	public:
		int64_t occupationwar_uid{};
	public:
		int32_t reg_datetime{};
	public:
		std::vector<mrpcs_occupationwar_darksteel_tax_log> list{};

	public:
		mrpcs_occupationwar_darksteel_tax_log_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &occupationwar_uid);
			protocol::SerializeType(pBuffer, &reg_datetime);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
