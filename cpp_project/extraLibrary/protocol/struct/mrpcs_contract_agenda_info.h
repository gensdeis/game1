#pragma once
#include <vector>
#include <string>
#include "mrpcs_contract_sector.h"

namespace mir3d
{
	class mrpcs_contract_agenda_info 
	{
	public:
		mpe_governance_contents_type type{};
	public:
		int32_t agenda_id{};
	public:
		std::vector<mrpcs_contract_sector> list{};

	public:
		mrpcs_contract_agenda_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &agenda_id);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
