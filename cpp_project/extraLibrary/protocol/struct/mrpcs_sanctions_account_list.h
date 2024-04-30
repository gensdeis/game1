#pragma once
#include <vector>
#include <string>
#include "mrpcs_sanctions_account.h"

namespace mir3d
{
	class mrpcs_sanctions_account_list 
	{
	public:
		std::vector<mrpcs_sanctions_account> list_sanctions_account{};

	public:
		mrpcs_sanctions_account_list()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list_sanctions_account);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
