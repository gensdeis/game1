#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_contract_sector 
	{
	public:
		int32_t gid{};
	public:
		int32_t sector_id{};

	public:
		mrpcs_contract_sector()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &sector_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
