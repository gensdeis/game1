#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_lord_worship_cs : public RpcPacket 
	{
	public:
		int32_t castle_id{};
	public:
		int32_t update_bless_point{};

	public:
		mrpc_lord_worship_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::lord_worship_cs, tag)
		{
		}
		mrpc_lord_worship_cs() : RpcPacket(mpe_rpc_cmd::lord_worship_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &castle_id);
			protocol::SerializeType(pBuffer, &update_bless_point);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_lord_worship_sc : public RpcPacket 
	{
	public:
		int32_t castle_id{};
	public:
		int32_t total_bless_point{};

	public:
		mrpc_lord_worship_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::lord_worship_sc, tag)
		{
		}
		mrpc_lord_worship_sc() : RpcPacket(mpe_rpc_cmd::lord_worship_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &castle_id);
			protocol::SerializeType(pBuffer, &total_bless_point);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
