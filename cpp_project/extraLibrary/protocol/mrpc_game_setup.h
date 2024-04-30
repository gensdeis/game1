#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_game_setup_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		uint16_t version{};	// 클라버전정보
	public:
		std::vector<uint8_t> data{};

	public:
		mrpc_game_setup_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::game_setup_cs, tag)
		{
		}
		mrpc_game_setup_cs() : RpcPacket(mpe_rpc_cmd::game_setup_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &version);
			protocol::SerializeType(pBuffer, &data);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_game_setup_sc : public RpcPacket 
	{

	public:
		mrpc_game_setup_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::game_setup_sc, tag)
		{
		}
		mrpc_game_setup_sc() : RpcPacket(mpe_rpc_cmd::game_setup_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
