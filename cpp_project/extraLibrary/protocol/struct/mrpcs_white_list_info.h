#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_white_list_info 
	{
	public:
		std::vector<int64_t> list_account{};
	public:
		std::vector<std::string> list_ip_address{};
	public:
		std::vector<std::string> list_mac_address{};

	public:
		mrpcs_white_list_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list_account);
			protocol::SerializeType(pBuffer, &list_ip_address);
			protocol::SerializeType(pBuffer, &list_mac_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
