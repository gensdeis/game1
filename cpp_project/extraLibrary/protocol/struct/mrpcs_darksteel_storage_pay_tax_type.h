#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_darksteel_storage_pay_tax_type 
	{
	public:
		int64_t huid{};
	public:
		int32_t gid{};
	public:
		uint8_t rank{};
	public:
		int32_t value{};

	public:
		mrpcs_darksteel_storage_pay_tax_type()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &huid);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &rank);
			protocol::SerializeType(pBuffer, &value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
