#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_occupationwar_base_info 
	{
	public:
		int64_t occupationwar_uid{};
	public:
		int32_t week_number{};
	public:
		std::string reg_datetime{};

	public:
		mrpcs_occupationwar_base_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &occupationwar_uid);
			protocol::SerializeType(pBuffer, &week_number);
			protocol::SerializeType(pBuffer, &reg_datetime);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
