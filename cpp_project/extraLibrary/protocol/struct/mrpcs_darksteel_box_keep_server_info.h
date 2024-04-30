#pragma once
#include <vector>
#include <string>
#include "mrpcs_occupationwar_server_info_total.h"

namespace mir3d
{
	class mrpcs_darksteel_box_keep_server_info 
	{
	public:
		int64_t occupationwar_uid{};
	public:
		int32_t week_number{};
	public:
		std::vector<mrpcs_occupationwar_server_info_total> list_decide{};

	public:
		mrpcs_darksteel_box_keep_server_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &occupationwar_uid);
			protocol::SerializeType(pBuffer, &week_number);
			protocol::SerializeType(pBuffer, &list_decide);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
