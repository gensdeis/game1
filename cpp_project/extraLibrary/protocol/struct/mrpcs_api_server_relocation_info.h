#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_api_server_relocation_info 
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int32_t gid{};
	public:
		int64_t data_size{};
	public:
		std::string nickname{};
	public:
		uint8_t is_delete{};
	public:
		int64_t server_relocation_time{};

	public:
		mrpcs_api_server_relocation_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &data_size);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &is_delete);
			protocol::SerializeType(pBuffer, &server_relocation_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
