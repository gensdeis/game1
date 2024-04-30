#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_profesion 
	{
	public:
		uint16_t type{};
	public:
		uint16_t level{};
	public:
		int32_t exp{};
	public:
		uint16_t grade{};

	public:
		mps_profesion()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &exp);
			protocol::SerializeType(pBuffer, &grade);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
