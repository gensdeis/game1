#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_account_storage 
	{
	public:
		uint16_t size{};
	public:
		int32_t gold{};

	public:
		mps_account_storage()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &size);
			protocol::SerializeType(pBuffer, &gold);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
