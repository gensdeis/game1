#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_contract_agenda 
	{
	public:
		mpe_governance_contents_type type{};
	public:
		int32_t agenda_id{};

	public:
		mrpcs_contract_agenda()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &agenda_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
