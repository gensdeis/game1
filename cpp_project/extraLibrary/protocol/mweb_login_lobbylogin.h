#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_login_lobby_info.h"
#include "struct/mps_server_info.h"

namespace mir3d
{
	class mweb_login_lobbylogin_cs : public WebBasePacket 	// 로비 서버 정보
	{
	public:
		std::string username{};
	public:
		bool quicklogin{};
	public:
		int32_t gid{};
	public:
		std::string device_id{};
	public:
		mpe_os_type os_type{};
	public:
		mpe_channel_type channel_type{};
	public:
		mpe_store_type store_type{};
	public:
		std::string ip_address{};
	public:
		std::string mac_addr{};
	public:
		std::string cookie_uncheater{};

	public:
		mweb_login_lobbylogin_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &quicklogin);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &device_id);
			protocol::SerializeEnum(pBuffer, &os_type);
			protocol::SerializeEnum(pBuffer, &channel_type);
			protocol::SerializeEnum(pBuffer, &store_type);
			protocol::SerializeType(pBuffer, &ip_address);
			protocol::SerializeType(pBuffer, &mac_addr);
			protocol::SerializeType(pBuffer, &cookie_uncheater);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_login_lobbylogin_sc : public WebBasePacket 	// 로비 서버 정보
	{
	public:
		int32_t result{};
	public:
		std::string access_token{};
	public:
		std::vector<mps_login_lobby_info> list_lobby{};	// gate에서 안씀
	public:
		std::vector<mps_server_info> list_gate{};	// gate 용
	public:
		int32_t awaiter_count{};

	public:
		mweb_login_lobbylogin_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &list_lobby);
			protocol::SerializeType(pBuffer, &list_gate);
			protocol::SerializeType(pBuffer, &awaiter_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
