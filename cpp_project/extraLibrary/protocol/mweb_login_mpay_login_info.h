#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_server_info.h"

namespace mir3d
{
	class mweb_login_mpay_login_info_cs : public WebBasePacket 
	{
	public:
		std::string username{};

	public:
		mweb_login_mpay_login_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &username);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_login_mpay_login_info_sc : public WebBasePacket 
	{
	public:
		bool is_playing{};
	public:
		std::vector<mps_server_info> list_gate{};
	public:
		int32_t result{};

	public:
		mweb_login_mpay_login_info_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &is_playing);
			protocol::SerializeType(pBuffer, &list_gate);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
