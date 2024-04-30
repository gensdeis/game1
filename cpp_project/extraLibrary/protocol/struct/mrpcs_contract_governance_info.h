#pragma once
#include <vector>
#include <string>
#include "mrpcs_contract_agenda_info.h"

namespace mir3d
{
	class mrpcs_contract_governance_info 
	{
	public:
		std::vector<mrpcs_contract_agenda_info> list{};

	public:
		mrpcs_contract_governance_info()
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
