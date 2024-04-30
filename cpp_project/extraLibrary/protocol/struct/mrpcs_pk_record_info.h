#pragma once
#include <vector>
#include <string>
#include "mps_pk_record.h"
#include "mps_pk_revenge.h"

namespace mir3d
{
	class mrpcs_pk_record_info 
	{
	public:
		std::vector<mps_pk_record> list_pk_record{};
	public:
		std::vector<mps_pk_revenge> list_pk_revenge{};

	public:
		mrpcs_pk_record_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list_pk_record);
			protocol::SerializeType(pBuffer, &list_pk_revenge);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
