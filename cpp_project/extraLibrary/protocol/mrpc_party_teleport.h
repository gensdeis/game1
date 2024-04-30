#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_vector.h"
#include "struct/mps_party_member_base.h"
#include "struct/mps_vector.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_party_teleport_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t puid{};
	public:
		int64_t cuid{};
	public:
		mpe_party_teleport teleport_type{};
	private:
		bool flag_item_add = false;
		mps_item_add item_add;
		mps_item_add* p_item_add = nullptr;
	public:
		bool has_item_add() const
		{
			return flag_item_add;
		}
		mps_item_add* alloc_item_add()
		{
			flag_item_add = true;
			return &item_add;
		}
		const mps_item_add* get_item_add() const
		{
			if (true == flag_item_add)
			{
				if (nullptr == p_item_add)
				{
					return &item_add;
				}
				return p_item_add;
			}
			return nullptr;
		}
		void set_item_add(mps_item_add* in_item_add)
		{
			if (nullptr == p_item_add)
			{
				p_item_add = in_item_add;
				flag_item_add = true;
			}
		}
	public:
		int32_t owner_server_index{};
	public:
		mrpce_server_type owner_server_type{};
	private:
		bool flag_owner_pos = false;
		mps_vector owner_pos;
		mps_vector* p_owner_pos = nullptr;
	public:
		bool has_owner_pos() const
		{
			return flag_owner_pos;
		}
		mps_vector* alloc_owner_pos()
		{
			flag_owner_pos = true;
			return &owner_pos;
		}
		const mps_vector* get_owner_pos() const
		{
			if (true == flag_owner_pos)
			{
				if (nullptr == p_owner_pos)
				{
					return &owner_pos;
				}
				return p_owner_pos;
			}
			return nullptr;
		}
		void set_owner_pos(mps_vector* in_owner_pos)
		{
			if (nullptr == p_owner_pos)
			{
				p_owner_pos = in_owner_pos;
				flag_owner_pos = true;
			}
		}

	public:
		mrpc_party_teleport_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_teleport_cs, tag)
		{
		}
		mrpc_party_teleport_cs() : RpcPacket(mpe_rpc_cmd::party_teleport_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &teleport_type);
			protocol::SerializeType(pBuffer, &flag_item_add);
			if (true == flag_item_add)
			{
				if (nullptr != p_item_add)
					protocol::SerializeType(pBuffer, p_item_add);
				else
					protocol::SerializeType(pBuffer, &item_add);
			}
			protocol::SerializeType(pBuffer, &owner_server_index);
			protocol::SerializeEnum(pBuffer, &owner_server_type);
			protocol::SerializeType(pBuffer, &flag_owner_pos);
			if (true == flag_owner_pos)
			{
				if (nullptr != p_owner_pos)
					protocol::SerializeType(pBuffer, p_owner_pos);
				else
					protocol::SerializeType(pBuffer, &owner_pos);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_party_teleport_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t puid{};
	public:
		int64_t cuid{};
	public:
		mpe_party_teleport teleport_type{};
	private:
		bool flag_owner = false;
		mps_party_member_base owner;
		mps_party_member_base* p_owner = nullptr;
	public:
		bool has_owner() const
		{
			return flag_owner;
		}
		mps_party_member_base* alloc_owner()
		{
			flag_owner = true;
			return &owner;
		}
		const mps_party_member_base* get_owner() const
		{
			if (true == flag_owner)
			{
				if (nullptr == p_owner)
				{
					return &owner;
				}
				return p_owner;
			}
			return nullptr;
		}
		void set_owner(mps_party_member_base* in_owner)
		{
			if (nullptr == p_owner)
			{
				p_owner = in_owner;
				flag_owner = true;
			}
		}
	private:
		bool flag_owner_pos = false;
		mps_vector owner_pos;
		mps_vector* p_owner_pos = nullptr;
	public:
		bool has_owner_pos() const
		{
			return flag_owner_pos;
		}
		mps_vector* alloc_owner_pos()
		{
			flag_owner_pos = true;
			return &owner_pos;
		}
		const mps_vector* get_owner_pos() const
		{
			if (true == flag_owner_pos)
			{
				if (nullptr == p_owner_pos)
				{
					return &owner_pos;
				}
				return p_owner_pos;
			}
			return nullptr;
		}
		void set_owner_pos(mps_vector* in_owner_pos)
		{
			if (nullptr == p_owner_pos)
			{
				p_owner_pos = in_owner_pos;
				flag_owner_pos = true;
			}
		}
	public:
		int32_t server_index{};
	public:
		mrpce_server_type server_type{};
	private:
		bool flag_item_add = false;
		mps_item_add item_add;
		mps_item_add* p_item_add = nullptr;
	public:
		bool has_item_add() const
		{
			return flag_item_add;
		}
		mps_item_add* alloc_item_add()
		{
			flag_item_add = true;
			return &item_add;
		}
		const mps_item_add* get_item_add() const
		{
			if (true == flag_item_add)
			{
				if (nullptr == p_item_add)
				{
					return &item_add;
				}
				return p_item_add;
			}
			return nullptr;
		}
		void set_item_add(mps_item_add* in_item_add)
		{
			if (nullptr == p_item_add)
			{
				p_item_add = in_item_add;
				flag_item_add = true;
			}
		}
	public:
		uint16_t channel_id{};

	public:
		mrpc_party_teleport_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_teleport_sc, tag)
		{
		}
		mrpc_party_teleport_sc() : RpcPacket(mpe_rpc_cmd::party_teleport_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &teleport_type);
			protocol::SerializeType(pBuffer, &flag_owner);
			if (true == flag_owner)
			{
				if (nullptr != p_owner)
					protocol::SerializeType(pBuffer, p_owner);
				else
					protocol::SerializeType(pBuffer, &owner);
			}
			protocol::SerializeType(pBuffer, &flag_owner_pos);
			if (true == flag_owner_pos)
			{
				if (nullptr != p_owner_pos)
					protocol::SerializeType(pBuffer, p_owner_pos);
				else
					protocol::SerializeType(pBuffer, &owner_pos);
			}
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &flag_item_add);
			if (true == flag_item_add)
			{
				if (nullptr != p_item_add)
					protocol::SerializeType(pBuffer, p_item_add);
				else
					protocol::SerializeType(pBuffer, &item_add);
			}
			protocol::SerializeType(pBuffer, &channel_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
