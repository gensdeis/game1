#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_title_send_info 
	{
	public:
		int32_t title_id{};
	public:
		std::string title_name{};
	public:
		mpe_title_type type{};

	public:
		mps_title_send_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &title_id);
			protocol::SerializeType(pBuffer, &title_name);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
