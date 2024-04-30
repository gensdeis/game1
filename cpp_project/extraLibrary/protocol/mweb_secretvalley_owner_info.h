#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_secretvalley_owner_info.h"

namespace mir3d
{
	class mweb_secretvalley_owner_info_cs : public WebBasePacket 
	{

	public:
		mweb_secretvalley_owner_info_cs() : WebBasePacket()
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

	class mweb_secretvalley_owner_info_sc : public WebBasePacket 
	{
	public:
		std::vector<mps_secretvalley_owner_info> secretvalley_infos{};

	public:
		mweb_secretvalley_owner_info_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &secretvalley_infos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
