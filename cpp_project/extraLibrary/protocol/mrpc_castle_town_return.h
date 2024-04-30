#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_castle_town_return_cs : public RpcPacket 	// 장원 반납
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		bool is_manual_return{};	// 자진 반납 여부
	public:
		int32_t town_id{};

	public:
		mrpc_castle_town_return_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_return_cs, tag)
		{
		}
		mrpc_castle_town_return_cs() : RpcPacket(mpe_rpc_cmd::castle_town_return_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &is_manual_return);
			protocol::SerializeType(pBuffer, &town_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_castle_town_return_sc : public RpcPacket 	// 장원 반납
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int32_t town_id{};

	public:
		mrpc_castle_town_return_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_return_sc, tag)
		{
		}
		mrpc_castle_town_return_sc() : RpcPacket(mpe_rpc_cmd::castle_town_return_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &town_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
