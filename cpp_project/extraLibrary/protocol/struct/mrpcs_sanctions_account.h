#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_sanctions_account 
	{
	public:
		int64_t auid{};
	public:
		int32_t start_date{};
	public:
		int32_t end_date{};

	public:
		mrpcs_sanctions_account()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &start_date);
			protocol::SerializeType(pBuffer, &end_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
