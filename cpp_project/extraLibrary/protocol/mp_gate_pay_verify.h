#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_pay_verify_cs : public BasePacket 
	{
	public:
		std::string pay_id{};
	public:
		std::string player_key{};
	public:
		int64_t account_uid{};
	public:
		int64_t character_uid{};
	public:
		std::string user_agent{};
	public:
		std::string purchase_token{};
	public:
		std::string store_type{};
	public:
		std::string store_appid{};

	public:
		mp_gate_pay_verify_cs() : BasePacket(mpe_cmd::gate_pay_verify_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &pay_id);
			protocol::SerializeType(pBuffer, &player_key);
			protocol::SerializeType(pBuffer, &account_uid);
			protocol::SerializeType(pBuffer, &character_uid);
			protocol::SerializeType(pBuffer, &user_agent);
			protocol::SerializeType(pBuffer, &purchase_token);
			protocol::SerializeType(pBuffer, &store_type);
			protocol::SerializeType(pBuffer, &store_appid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_pay_verify_sc : public BasePacket 
	{
	public:
		int32_t code{};
	public:
		int32_t purchase_quantity{};
	public:
		int32_t result{};

	public:
		mp_gate_pay_verify_sc() : BasePacket(mpe_cmd::gate_pay_verify_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &code);
			protocol::SerializeType(pBuffer, &purchase_quantity);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
