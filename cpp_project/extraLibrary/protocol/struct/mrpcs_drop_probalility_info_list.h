#pragma once
#include <vector>
#include <string>
#include "mrpcs_drop_probalility_info.h"

namespace mir3d
{
	class mrpcs_drop_probalility_info_list 
	{
	public:
		std::vector<mrpcs_drop_probalility_info> list{};

	public:
		mrpcs_drop_probalility_info_list()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
