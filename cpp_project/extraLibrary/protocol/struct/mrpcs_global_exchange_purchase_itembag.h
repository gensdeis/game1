#pragma once
#include <vector>
#include <string>
#include "mrpcs_global_exchange_purchase_item.h"

namespace mir3d
{
	class mrpcs_global_exchange_purchase_itembag 
	{
	public:
		int64_t cuid{};
	public:
		std::vector<mrpcs_global_exchange_purchase_item> list{};

	public:
		mrpcs_global_exchange_purchase_itembag()
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
