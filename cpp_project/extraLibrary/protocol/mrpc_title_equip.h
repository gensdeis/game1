#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_title_equip_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t title_id{};
	public:
		int32_t clear_title_id{};

	public:
		mrpc_title_equip_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::title_equip_cs, tag)
		{
		}
		mrpc_title_equip_cs() : RpcPacket(mpe_rpc_cmd::title_equip_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &title_id);
			protocol::SerializeType(pBuffer, &clear_title_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_title_equip_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_title_equip_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::title_equip_sc, tag)
		{
		}
		mrpc_title_equip_sc() : RpcPacket(mpe_rpc_cmd::title_equip_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
