#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_drop_probalility_info 
	{
	public:
		int32_t id{};
	public:
		uint16_t count{};

	public:
		mrpcs_drop_probalility_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
