#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_lobby_character_create_cs : public RpcPacket 	// 캐릭터 생성
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		std::string nickname{};
	public:
		std::string access_token{};
	public:
		int32_t id{};
	public:
		uint16_t customzing_data{};
	public:
		mpe_os_type os_type{};
	public:
		std::string ip_address{};

	public:
		mrpc_gate_lobby_character_create_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_lobby_character_create_cs, tag)
		{
		}
		mrpc_gate_lobby_character_create_cs() : RpcPacket(mpe_rpc_cmd::gate_lobby_character_create_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &customzing_data);
			protocol::SerializeEnum(pBuffer, &os_type);
			protocol::SerializeType(pBuffer, &ip_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_lobby_character_create_sc : public RpcPacket 	// 캐릭터 생성
	{
	public:
		int64_t key{};
	public:
		std::string nickname{};
	public:
		int32_t id{};
	public:
		int64_t cuid{};
	public:
		uint16_t customzing_data{};

	public:
		mrpc_gate_lobby_character_create_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_lobby_character_create_sc, tag)
		{
		}
		mrpc_gate_lobby_character_create_sc() : RpcPacket(mpe_rpc_cmd::gate_lobby_character_create_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &customzing_data);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
