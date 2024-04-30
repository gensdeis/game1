#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_lobby_character_delete_cs : public RpcPacket 	// 캐릭터 삭제 로비
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string access_token{};
	public:
		mpe_os_type os_type{};
	public:
		std::string ip_address{};

	public:
		mrpc_gate_lobby_character_delete_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_lobby_character_delete_cs, tag)
		{
		}
		mrpc_gate_lobby_character_delete_cs() : RpcPacket(mpe_rpc_cmd::gate_lobby_character_delete_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeEnum(pBuffer, &os_type);
			protocol::SerializeType(pBuffer, &ip_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_lobby_character_delete_sc : public RpcPacket 	// 캐릭터 삭제 로비
	{
	public:
		int64_t key{};
	public:
		int32_t delete_date{};

	public:
		mrpc_gate_lobby_character_delete_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_lobby_character_delete_sc, tag)
		{
		}
		mrpc_gate_lobby_character_delete_sc() : RpcPacket(mpe_rpc_cmd::gate_lobby_character_delete_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &delete_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
