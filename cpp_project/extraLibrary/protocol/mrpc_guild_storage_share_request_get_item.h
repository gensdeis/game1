#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item.h"
#include "struct/mrpcs_item_stone_pair.h"

namespace mir3d
{
	class mrpc_guild_storage_share_request_get_item_cs : public RpcPacket 	// 문파 공유 창고 아이템 요청
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int64_t iuid{};
	public:
		int32_t item_count{};

	public:
		mrpc_guild_storage_share_request_get_item_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_storage_share_request_get_item_cs, tag)
		{
		}
		mrpc_guild_storage_share_request_get_item_cs() : RpcPacket(mpe_rpc_cmd::guild_storage_share_request_get_item_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &item_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_storage_share_request_get_item_sc : public RpcPacket 	// 문파 공유 창고 아이템 요청
	{
	public:
		int64_t cuid{};
	public:
		bool master{};
	private:
		bool flag_item = false;
		mps_item item;
		mps_item* p_item = nullptr;
	public:
		bool has_item() const
		{
			return flag_item;
		}
		mps_item* alloc_item()
		{
			flag_item = true;
			return &item;
		}
		const mps_item* get_item() const
		{
			if (true == flag_item)
			{
				if (nullptr == p_item)
				{
					return &item;
				}
				return p_item;
			}
			return nullptr;
		}
		void set_item(mps_item* in_item)
		{
			if (nullptr == p_item)
			{
				p_item = in_item;
				flag_item = true;
			}
		}
	private:
		bool flag_stone = false;
		mrpcs_item_stone_pair stone;
		mrpcs_item_stone_pair* p_stone = nullptr;
	public:
		bool has_stone() const
		{
			return flag_stone;
		}
		mrpcs_item_stone_pair* alloc_stone()
		{
			flag_stone = true;
			return &stone;
		}
		const mrpcs_item_stone_pair* get_stone() const
		{
			if (true == flag_stone)
			{
				if (nullptr == p_stone)
				{
					return &stone;
				}
				return p_stone;
			}
			return nullptr;
		}
		void set_stone(mrpcs_item_stone_pair* in_stone)
		{
			if (nullptr == p_stone)
			{
				p_stone = in_stone;
				flag_stone = true;
			}
		}
	public:
		int32_t current_request_count{};
	public:
		int32_t request_item_count{};

	public:
		mrpc_guild_storage_share_request_get_item_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_storage_share_request_get_item_sc, tag)
		{
		}
		mrpc_guild_storage_share_request_get_item_sc() : RpcPacket(mpe_rpc_cmd::guild_storage_share_request_get_item_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &master);
			protocol::SerializeType(pBuffer, &flag_item);
			if (true == flag_item)
			{
				if (nullptr != p_item)
					protocol::SerializeType(pBuffer, p_item);
				else
					protocol::SerializeType(pBuffer, &item);
			}
			protocol::SerializeType(pBuffer, &flag_stone);
			if (true == flag_stone)
			{
				if (nullptr != p_stone)
					protocol::SerializeType(pBuffer, p_stone);
				else
					protocol::SerializeType(pBuffer, &stone);
			}
			protocol::SerializeType(pBuffer, &current_request_count);
			protocol::SerializeType(pBuffer, &request_item_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
