#pragma once
#include <vector>
#include <string>
#include "mrpcs_not_allow_packet.h"

namespace mir3d
{
	class mrpcs_not_allow_packet_list 
	{
	public:
		std::vector<mrpcs_not_allow_packet> list{};

	public:
		mrpcs_not_allow_packet_list()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
