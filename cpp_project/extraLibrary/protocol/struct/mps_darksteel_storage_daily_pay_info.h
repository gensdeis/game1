#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_darksteel_storage_daily_pay_info 
	{
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
		mps_darksteel_storage_daily_pay_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &tax);
			protocol::SerializeType(pBuffer, &total);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
