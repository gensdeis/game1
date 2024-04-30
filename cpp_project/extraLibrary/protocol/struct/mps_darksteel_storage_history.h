#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_darksteel_storage_history 
	{
	public:
		mpe_darksteel_storage_pay_type t{};
	public:
		std::string s{};
	public:
		std::string n{};
	public:
		int32_t p{};
	public:
		int32_t c{};
	public:
		int32_t d{};

	public:
		mps_darksteel_storage_history()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &t);
			protocol::SerializeType(pBuffer, &s);
			protocol::SerializeType(pBuffer, &n);
			protocol::SerializeType(pBuffer, &p);
			protocol::SerializeType(pBuffer, &c);
			protocol::SerializeType(pBuffer, &d);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
