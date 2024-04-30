#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_darksteel_storage_daily_pay_info 
	{
	public:
		int64_t huid{};
	public:
		int64_t guid{};
	public:
		mpe_darksteel_storage_pay_type type{};
	public:
		int64_t uid{};
	public:
		std::string nickname{};
	public:
		int32_t count{};
	public:
		int32_t tax{};
	public:
		int32_t total{};
	public:
		int32_t reg_date{};

	public:
		mrpcs_darksteel_storage_daily_pay_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &huid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &tax);
			protocol::SerializeType(pBuffer, &total);
			protocol::SerializeType(pBuffer, &reg_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
