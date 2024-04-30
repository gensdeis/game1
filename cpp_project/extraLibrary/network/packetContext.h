#pragma once

#include <memory>
#include "define.h"

namespace mir3d
{
	class CSocket;

	// received socket buffer context
	struct packetContext
	{
		uint16_t						cmd = 0;
		int64_t							session_id = 0;
		char*							buffer = nullptr;
		int32_t							size = 0;
		int32_t							zone_tag = 0;
		int32_t							pool_index = 0;
		CSocket*						socket = nullptr;	
		//int64_t							pop_time = 0;

		packetContext()
		{
			buffer = new char[MAX_SOCKET_BUFFER_SIZE];
		}

		~packetContext()
		{
			if (nullptr != buffer)
			{
				delete buffer;
				buffer = nullptr;
			}
		}
	};

}	// namespace mir3d
