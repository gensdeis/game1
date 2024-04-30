#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_darksteel_pay_tax_info 
	{
	public:
		int32_t gid{};
	public:
		int32_t target_gid{};
	public:
		mpe_occupationwar_map_type map_type{};
	public:
		mpe_darksteel_storage_pay_type pay_type{};
	public:
		int32_t percent{};
	public:
		int64_t total{};

	public:
		mrpcs_darksteel_pay_tax_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &target_gid);
			protocol::SerializeEnum(pBuffer, &map_type);
			protocol::SerializeEnum(pBuffer, &pay_type);
			protocol::SerializeType(pBuffer, &percent);
			protocol::SerializeType(pBuffer, &total);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
