#pragma once
#include <vector>
#include <string>
#include "mrpcs_exchange_buybag_item_ex.h"

namespace mir3d
{
	class mrpcs_exchange_buybag 
	{
	public:
		int64_t cuid{};
	public:
		std::vector<mrpcs_exchange_buybag_item_ex> list{};

	public:
		mrpcs_exchange_buybag()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
