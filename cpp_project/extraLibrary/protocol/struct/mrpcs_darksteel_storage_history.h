#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_darksteel_storage_history 
	{
	public:
		int64_t huid{};
	public:
		mpe_darksteel_storage_pay_type type{};
	public:
		std::string sender{};
	public:
		std::string nickname{};
	public:
		int32_t count{};
	public:
		int32_t percent{};
	public:
		int32_t reg_date{};

	public:
		mrpcs_darksteel_storage_history()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &huid);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &sender);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &percent);
			protocol::SerializeType(pBuffer, &reg_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
