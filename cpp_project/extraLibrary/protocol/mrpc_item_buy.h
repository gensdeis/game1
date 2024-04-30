#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mrpcs_castle_tax_value.h"
#include "struct/mps_npc_buy_count.h"

namespace mir3d
{
	class mrpc_item_buy_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_info = false;
		mps_item_add info;
		mps_item_add* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_add* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_add* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mps_item_add* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		int32_t protect_equip{};
	public:
		int32_t zone_id{};
	public:
		int64_t drop_uid{};
	private:
		bool flag_castle_tax = false;
		mrpcs_castle_tax_value castle_tax;
		mrpcs_castle_tax_value* p_castle_tax = nullptr;
	public:
		bool has_castle_tax() const
		{
			return flag_castle_tax;
		}
		mrpcs_castle_tax_value* alloc_castle_tax()
		{
			flag_castle_tax = true;
			return &castle_tax;
		}
		const mrpcs_castle_tax_value* get_castle_tax() const
		{
			if (true == flag_castle_tax)
			{
				if (nullptr == p_castle_tax)
				{
					return &castle_tax;
				}
				return p_castle_tax;
			}
			return nullptr;
		}
		void set_castle_tax(mrpcs_castle_tax_value* in_castle_tax)
		{
			if (nullptr == p_castle_tax)
			{
				p_castle_tax = in_castle_tax;
				flag_castle_tax = true;
			}
		}
	private:
		bool flag_buy_count = false;
		mps_npc_buy_count buy_count;
		mps_npc_buy_count* p_buy_count = nullptr;
	public:
		bool has_buy_count() const
		{
			return flag_buy_count;
		}
		mps_npc_buy_count* alloc_buy_count()
		{
			flag_buy_count = true;
			return &buy_count;
		}
		const mps_npc_buy_count* get_buy_count() const
		{
			if (true == flag_buy_count)
			{
				if (nullptr == p_buy_count)
				{
					return &buy_count;
				}
				return p_buy_count;
			}
			return nullptr;
		}
		void set_buy_count(mps_npc_buy_count* in_buy_count)
		{
			if (nullptr == p_buy_count)
			{
				p_buy_count = in_buy_count;
				flag_buy_count = true;
			}
		}
	public:
		int64_t auid{};

	public:
		mrpc_item_buy_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::item_buy_cs, tag)
		{
		}
		mrpc_item_buy_cs() : RpcPacket(mpe_rpc_cmd::item_buy_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &protect_equip);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &drop_uid);
			protocol::SerializeType(pBuffer, &flag_castle_tax);
			if (true == flag_castle_tax)
			{
				if (nullptr != p_castle_tax)
					protocol::SerializeType(pBuffer, p_castle_tax);
				else
					protocol::SerializeType(pBuffer, &castle_tax);
			}
			protocol::SerializeType(pBuffer, &flag_buy_count);
			if (true == flag_buy_count)
			{
				if (nullptr != p_buy_count)
					protocol::SerializeType(pBuffer, p_buy_count);
				else
					protocol::SerializeType(pBuffer, &buy_count);
			}
			protocol::SerializeType(pBuffer, &auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_item_buy_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t zone_id{};
	public:
		int64_t drop_uid{};

	public:
		mrpc_item_buy_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::item_buy_sc, tag)
		{
		}
		mrpc_item_buy_sc() : RpcPacket(mpe_rpc_cmd::item_buy_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &drop_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
