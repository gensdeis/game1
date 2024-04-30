#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_item.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_guild_item_donation_cs : public RpcPacket 	// 문파 재료 창고에 아이템 기부
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int32_t donation_item_id{};	// 기부할 아이템id
	private:
		bool flag_donation_item = false;
		mps_item_add donation_item;	// 기부할 아이템
		mps_item_add* p_donation_item = nullptr;
	public:
		bool has_donation_item() const
		{
			return flag_donation_item;
		}
		mps_item_add* alloc_donation_item()
		{
			flag_donation_item = true;
			return &donation_item;
		}
		const mps_item_add* get_donation_item() const
		{
			if (true == flag_donation_item)
			{
				if (nullptr == p_donation_item)
				{
					return &donation_item;
				}
				return p_donation_item;
			}
			return nullptr;
		}
		void set_donation_item(mps_item_add* in_donation_item)
		{
			if (nullptr == p_donation_item)
			{
				p_donation_item = in_donation_item;
				flag_donation_item = true;
			}
		}

	public:
		mrpc_guild_item_donation_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_item_donation_cs, tag)
		{
		}
		mrpc_guild_item_donation_cs() : RpcPacket(mpe_rpc_cmd::guild_item_donation_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &donation_item_id);
			protocol::SerializeType(pBuffer, &flag_donation_item);
			if (true == flag_donation_item)
			{
				if (nullptr != p_donation_item)
					protocol::SerializeType(pBuffer, p_donation_item);
				else
					protocol::SerializeType(pBuffer, &donation_item);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_item_donation_sc : public RpcPacket 	// 문파 재료 창고에 아이템 기부
	{
	public:
		int64_t cuid{};
	private:
		bool flag_update_storage_item = false;
		mps_item update_storage_item;	// 창고에 추가된 아이템
		mps_item* p_update_storage_item = nullptr;
	public:
		bool has_update_storage_item() const
		{
			return flag_update_storage_item;
		}
		mps_item* alloc_update_storage_item()
		{
			flag_update_storage_item = true;
			return &update_storage_item;
		}
		const mps_item* get_update_storage_item() const
		{
			if (true == flag_update_storage_item)
			{
				if (nullptr == p_update_storage_item)
				{
					return &update_storage_item;
				}
				return p_update_storage_item;
			}
			return nullptr;
		}
		void set_update_storage_item(mps_item* in_update_storage_item)
		{
			if (nullptr == p_update_storage_item)
			{
				p_update_storage_item = in_update_storage_item;
				flag_update_storage_item = true;
			}
		}
	private:
		bool flag_update_user_item = false;
		mps_item_add update_user_item;	// 받은 공헌도 및 기부한 아이템
		mps_item_add* p_update_user_item = nullptr;
	public:
		bool has_update_user_item() const
		{
			return flag_update_user_item;
		}
		mps_item_add* alloc_update_user_item()
		{
			flag_update_user_item = true;
			return &update_user_item;
		}
		const mps_item_add* get_update_user_item() const
		{
			if (true == flag_update_user_item)
			{
				if (nullptr == p_update_user_item)
				{
					return &update_user_item;
				}
				return p_update_user_item;
			}
			return nullptr;
		}
		void set_update_user_item(mps_item_add* in_update_user_item)
		{
			if (nullptr == p_update_user_item)
			{
				p_update_user_item = in_update_user_item;
				flag_update_user_item = true;
			}
		}
	public:
		uint8_t item_donation_count{};

	public:
		mrpc_guild_item_donation_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_item_donation_sc, tag)
		{
		}
		mrpc_guild_item_donation_sc() : RpcPacket(mpe_rpc_cmd::guild_item_donation_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_update_storage_item);
			if (true == flag_update_storage_item)
			{
				if (nullptr != p_update_storage_item)
					protocol::SerializeType(pBuffer, p_update_storage_item);
				else
					protocol::SerializeType(pBuffer, &update_storage_item);
			}
			protocol::SerializeType(pBuffer, &flag_update_user_item);
			if (true == flag_update_user_item)
			{
				if (nullptr != p_update_user_item)
					protocol::SerializeType(pBuffer, p_update_user_item);
				else
					protocol::SerializeType(pBuffer, &update_user_item);
			}
			protocol::SerializeType(pBuffer, &item_donation_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
