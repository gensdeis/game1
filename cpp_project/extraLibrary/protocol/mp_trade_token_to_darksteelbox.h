#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_trade_token_to_darksteelbox_cs : public BasePacket 	// 제련소 흑철상자를 코인으로 바꿔
	{
	public:
		int64_t item_uid{};	// 흑철상자 아이템 아이디
	public:
		std::string conteact_address{};
	public:
		std::string signature{};	// 유저 사인값
	public:
		std::string contract{};	// contract address 정보 요청한 값
	public:
		std::string user{};	// 유저 wallet id
	public:
		std::string nonce{};	// 컨트랙트 서버에서 조회한 nonce 값
	public:
		std::string column{};	// 액션에 대한 bytes32 값
	public:
		std::string amount{};	// 교환 수량

	public:
		mp_trade_token_to_darksteelbox_cs() : BasePacket(mpe_cmd::trade_token_to_darksteelbox_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &item_uid);
			protocol::SerializeType(pBuffer, &conteact_address);
			protocol::SerializeType(pBuffer, &signature);
			protocol::SerializeType(pBuffer, &contract);
			protocol::SerializeType(pBuffer, &user);
			protocol::SerializeType(pBuffer, &nonce);
			protocol::SerializeType(pBuffer, &column);
			protocol::SerializeType(pBuffer, &amount);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_trade_token_to_darksteelbox_sc : public BasePacket 	// 제련소 흑철상자를 코인으로 바꿔
	{
	public:
		mpe_error result{};

	public:
		mp_trade_token_to_darksteelbox_sc() : BasePacket(mpe_cmd::trade_token_to_darksteelbox_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
