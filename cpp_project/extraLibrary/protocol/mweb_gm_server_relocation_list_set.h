#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_server_relocation_list.h"

namespace mir3d
{
	class mweb_gm_server_relocation_list_set_cs : public WebBasePacket 
	{
	public:
		std::vector<mps_server_relocation_list> server_list{};

	public:
		mweb_gm_server_relocation_list_set_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &server_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_server_relocation_list_set_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};

	public:
		mweb_gm_server_relocation_list_set_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
