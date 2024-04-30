#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_wallet_login_cs : public BasePacket 	// 지갑 로그인
	{
	public:
		std::string token{};	// 클라이언트가 SDK로그인을 통해서 받은 정보

	public:
		mp_wallet_login_cs() : BasePacket(mpe_cmd::wallet_login_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &token);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_wallet_login_sc : public BasePacket 	// 지갑 로그인
	{
	public:
		std::string wallet_address{};	// 유저 월렛 주소

	public:
		mp_wallet_login_sc() : BasePacket(mpe_cmd::wallet_login_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &wallet_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
