#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_white_list_address 
	{
	public:
		int32_t seq{};
	public:
		int32_t address_type{};
	public:
		std::string address{};
	public:
		std::string content{};
	public:
		int32_t reg_date{};
	public:
		std::string reg_user{};

	public:
		mrpcs_white_list_address()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &seq);
			protocol::SerializeType(pBuffer, &address_type);
			protocol::SerializeType(pBuffer, &address);
			protocol::SerializeType(pBuffer, &content);
			protocol::SerializeType(pBuffer, &reg_date);
			protocol::SerializeType(pBuffer, &reg_user);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
