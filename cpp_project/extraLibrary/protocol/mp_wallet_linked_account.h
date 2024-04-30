#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_wallet_linked_account_cs : public BasePacket 	// 지갑 계정 연동
	{
	public:
		std::string wallet_address{};	// 서버로부터 전달받은 월렛 주소

	public:
		mp_wallet_linked_account_cs() : BasePacket(mpe_cmd::wallet_linked_account_cs)
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

	class mp_wallet_linked_account_sc : public BasePacket 	// 지갑 계정 연동
	{

	public:
		mp_wallet_linked_account_sc() : BasePacket(mpe_cmd::wallet_linked_account_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
