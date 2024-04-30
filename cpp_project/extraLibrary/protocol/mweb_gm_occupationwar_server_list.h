#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mgms_gmserver_info.h"
#include "struct/mrpcs_redis_serverinfo.h"

namespace mir3d
{
	class mweb_gm_occupationwar_server_list_cs : public WebBasePacket 
	{

	public:
		mweb_gm_occupationwar_server_list_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_occupationwar_server_list_sc : public WebBasePacket 
	{
	public:
		std::vector<mgms_gmserver_info> info_gmserver{};
	public:
		std::vector<mrpcs_redis_serverinfo> info_worldboard{};

	public:
		mweb_gm_occupationwar_server_list_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info_gmserver);
			protocol::SerializeType(pBuffer, &info_worldboard);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
