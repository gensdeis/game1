#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_account_uncheater 
	{
	public:
		bool check_complete{};
	public:
		int64_t reg_datetime{};
	public:
		std::string seed{};

	public:
		mrpcs_account_uncheater()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &check_complete);
			protocol::SerializeType(pBuffer, &reg_datetime);
			protocol::SerializeType(pBuffer, &seed);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
