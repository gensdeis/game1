#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mgms_gmuser.h"

namespace mir3d
{
	class mweb_gm_gmuser_list_cs : public WebBasePacket 
	{
	public:
		std::string access_token{};

	public:
		mweb_gm_gmuser_list_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &access_token);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_gmuser_list_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	public:
		std::vector<mgms_gmuser> list{};

	public:
		mweb_gm_gmuser_list_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
