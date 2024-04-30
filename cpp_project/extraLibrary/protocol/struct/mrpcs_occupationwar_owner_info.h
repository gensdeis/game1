#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_occupationwar_owner_info 
	{
	public:
		int32_t week_number{};
	public:
		int64_t guid{};
	public:
		std::string name{};

	public:
		mrpcs_occupationwar_owner_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &week_number);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
