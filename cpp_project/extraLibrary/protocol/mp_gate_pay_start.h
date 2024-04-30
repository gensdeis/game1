#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_pay_start_cs : public BasePacket 
	{
	public:
		std::string game_code{};
	public:
		std::string player_key{};
	public:
		int64_t account_uid{};
	public:
		int64_t character_uid{};
	public:
		std::string user_agent{};
	public:
		std::string user_agent_id{};
	public:
		std::string item_name{};
	public:
		std::string product_id{};
	public:
		int32_t total_price{};
	public:
		std::string ip_address{};
	public:
		std::string store_appid{};
	public:
		std::string store_type{};

	public:
		mp_gate_pay_start_cs() : BasePacket(mpe_cmd::gate_pay_start_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &game_code);
			protocol::SerializeType(pBuffer, &player_key);
			protocol::SerializeType(pBuffer, &account_uid);
			protocol::SerializeType(pBuffer, &character_uid);
			protocol::SerializeType(pBuffer, &user_agent);
			protocol::SerializeType(pBuffer, &user_agent_id);
			protocol::SerializeType(pBuffer, &item_name);
			protocol::SerializeType(pBuffer, &product_id);
			protocol::SerializeType(pBuffer, &total_price);
			protocol::SerializeType(pBuffer, &ip_address);
			protocol::SerializeType(pBuffer, &store_appid);
			protocol::SerializeType(pBuffer, &store_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_pay_start_sc : public BasePacket 
	{
	public:
		int32_t code{};
	public:
		std::string pay_id{};
	public:
		std::string token{};
	public:
		std::string payment_url{};
	public:
		int32_t result{};

	public:
		mp_gate_pay_start_sc() : BasePacket(mpe_cmd::gate_pay_start_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &code);
			protocol::SerializeType(pBuffer, &pay_id);
			protocol::SerializeType(pBuffer, &token);
			protocol::SerializeType(pBuffer, &payment_url);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
