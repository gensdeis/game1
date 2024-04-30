#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_global_exchange_gold_withdraw_cs : public BasePacket 	// 거래소-판매된 아이템 정산
	{
	public:
		mpe_exchange_type type{};
	public:
		std::vector<int64_t> euid{};
	public:
		std::string nonce{};
	public:
		std::string signature{};
	public:
		std::string contract_address{};

	public:
		mp_global_exchange_gold_withdraw_cs() : BasePacket(mpe_cmd::global_exchange_gold_withdraw_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &euid);
			protocol::SerializeType(pBuffer, &nonce);
			protocol::SerializeType(pBuffer, &signature);
			protocol::SerializeType(pBuffer, &contract_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_global_exchange_gold_withdraw_sc : public BasePacket 	// 거래소-판매된 아이템 정산
	{
	public:
		mpe_error result{};
	public:
		mpe_exchange_type type{};
	public:
		std::vector<int64_t> euid{};

	public:
		mp_global_exchange_gold_withdraw_sc() : BasePacket(mpe_cmd::global_exchange_gold_withdraw_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &euid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
