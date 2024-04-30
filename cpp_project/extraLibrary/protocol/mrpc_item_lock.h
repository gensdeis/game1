#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_item_lock_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t last_reward_date{};
	public:
		int64_t iuid{};
	public:
		bool locked{};

	public:
		mrpc_item_lock_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::item_lock_cs, tag)
		{
		}
		mrpc_item_lock_cs() : RpcPacket(mpe_rpc_cmd::item_lock_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &last_reward_date);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &locked);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_item_lock_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t iuid{};
	public:
		bool locked{};

	public:
		mrpc_item_lock_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::item_lock_sc, tag)
		{
		}
		mrpc_item_lock_sc() : RpcPacket(mpe_rpc_cmd::item_lock_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &locked);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
