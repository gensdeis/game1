#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_darksteel_storage_darksteel_pay_to_mail 
	{
	public:
		int64_t cuid{};
	public:
		int64_t huid{};
	public:
		int64_t muid{};
	public:
		std::string nickname{};

	public:
		mrpcs_darksteel_storage_darksteel_pay_to_mail()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &huid);
			protocol::SerializeType(pBuffer, &muid);
			protocol::SerializeType(pBuffer, &nickname);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
