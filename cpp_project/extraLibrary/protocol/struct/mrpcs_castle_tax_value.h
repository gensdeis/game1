#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_castle_tax_value 
	{
	public:
		int32_t castle_id{};
	public:
		int32_t update{};

	public:
		mrpcs_castle_tax_value()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &castle_id);
			protocol::SerializeType(pBuffer, &update);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
