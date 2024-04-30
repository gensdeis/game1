#pragma once
#include <vector>
#include <string>
#include "mps_darksteel_box_keep_server.h"
#include "mps_darksteel_box_keep_server.h"

namespace mir3d
{
	class mps_darksteel_box_keep_server_info 
	{
	public:
		int64_t occupationwar_uid{};
	public:
		int32_t week_number{};
	public:
		std::vector<mps_darksteel_box_keep_server> list{};
	public:
		std::vector<mps_darksteel_box_keep_server> list_decide{};

	public:
		mps_darksteel_box_keep_server_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &occupationwar_uid);
			protocol::SerializeType(pBuffer, &week_number);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &list_decide);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
