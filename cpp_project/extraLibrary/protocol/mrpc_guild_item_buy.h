#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_guild_item_buy_cs : public RpcPacket 	// // 문파 상점 아이템 구입 패킷
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	private:
		bool flag_update_item = false;
		mps_item_add update_item;
		mps_item_add* p_update_item = nullptr;
	public:
		bool has_update_item() const
		{
			return flag_update_item;
		}
		mps_item_add* alloc_update_item()
		{
			flag_update_item = true;
			return &update_item;
		}
		const mps_item_add* get_update_item() const
		{
			if (true == flag_update_item)
			{
				if (nullptr == p_update_item)
				{
					return &update_item;
				}
				return p_update_item;
			}
			return nullptr;
		}
		void set_update_item(mps_item_add* in_update_item)
		{
			if (nullptr == p_update_item)
			{
				p_update_item = in_update_item;
				flag_update_item = true;
			}
		}

	public:
		mrpc_guild_item_buy_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_item_buy_cs, tag)
		{
		}
		mrpc_guild_item_buy_cs() : RpcPacket(mpe_rpc_cmd::guild_item_buy_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &flag_update_item);
			if (true == flag_update_item)
			{
				if (nullptr != p_update_item)
					protocol::SerializeType(pBuffer, p_update_item);
				else
					protocol::SerializeType(pBuffer, &update_item);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_item_buy_sc : public RpcPacket 	// // 문파 상점 아이템 구입 패킷
	{
	public:
		int64_t cuid{};
	private:
		bool flag_update_item = false;
		mps_item_add update_item;
		mps_item_add* p_update_item = nullptr;
	public:
		bool has_update_item() const
		{
			return flag_update_item;
		}
		mps_item_add* alloc_update_item()
		{
			flag_update_item = true;
			return &update_item;
		}
		const mps_item_add* get_update_item() const
		{
			if (true == flag_update_item)
			{
				if (nullptr == p_update_item)
				{
					return &update_item;
				}
				return p_update_item;
			}
			return nullptr;
		}
		void set_update_item(mps_item_add* in_update_item)
		{
			if (nullptr == p_update_item)
			{
				p_update_item = in_update_item;
				flag_update_item = true;
			}
		}

	public:
		mrpc_guild_item_buy_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_item_buy_sc, tag)
		{
		}
		mrpc_guild_item_buy_sc() : RpcPacket(mpe_rpc_cmd::guild_item_buy_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_update_item);
			if (true == flag_update_item)
			{
				if (nullptr != p_update_item)
					protocol::SerializeType(pBuffer, p_update_item);
				else
					protocol::SerializeType(pBuffer, &update_item);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
