#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_white_list_account.h"
#include "struct/mrpcs_white_list_address.h"

namespace mir3d
{
	class mweb_api_white_list_cs : public WebBasePacket 
	{

	public:
		mweb_api_white_list_cs() : WebBasePacket()
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

	class mweb_api_white_list_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	public:
		std::vector<mrpcs_white_list_account> list_white_list_account{};
	public:
		std::vector<mrpcs_white_list_address> list_white_list_address{};

	public:
		mweb_api_white_list_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &list_white_list_account);
			protocol::SerializeType(pBuffer, &list_white_list_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
