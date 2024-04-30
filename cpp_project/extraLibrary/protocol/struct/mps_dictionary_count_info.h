#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_dictionary_count_info 
	{
	public:
		mpe_dictionary_type type{};
	public:
		int32_t total{};
	public:
		int32_t complet{};

	public:
		mps_dictionary_count_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &total);
			protocol::SerializeType(pBuffer, &complet);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
