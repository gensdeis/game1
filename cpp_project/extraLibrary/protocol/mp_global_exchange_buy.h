#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_global_exchange_buy_cs : public BasePacket 	// 거래소-아이템 구매
	{
	public:
		int64_t euid{};
	public:
		float price{};
	public:
		mpe_exchange_type type{};
	public:
		std::string nonce{};
	public:
		std::string product{};
	public:
		std::string signature{};
	public:
		std::string contract_address{};

	public:
		mp_global_exchange_buy_cs() : BasePacket(mpe_cmd::global_exchange_buy_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &euid);
			protocol::SerializeType(pBuffer, &price);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &nonce);
			protocol::SerializeType(pBuffer, &product);
			protocol::SerializeType(pBuffer, &signature);
			protocol::SerializeType(pBuffer, &contract_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_global_exchange_buy_sc : public BasePacket 	// 거래소-아이템 구매
	{
	public:
		mpe_error result{};
	public:
		mpe_exchange_type type{};

	public:
		mp_global_exchange_buy_sc() : BasePacket(mpe_cmd::global_exchange_buy_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
