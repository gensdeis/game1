#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_vector.h"

namespace mir3d
{
	class mp_party_teleport_cs : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		mpe_party_teleport teleport_type{};

	public:
		mp_party_teleport_cs() : BasePacket(mpe_cmd::party_teleport_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &teleport_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_party_teleport_sc : public BasePacket 
	{
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
		int32_t owner_zone_id{};
	public:
		uint16_t owner_channel_id{};

	public:
		mp_party_teleport_sc() : BasePacket(mpe_cmd::party_teleport_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
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
			protocol::SerializeType(pBuffer, &flag_owner_pos);
			if (true == flag_owner_pos)
			{
				if (nullptr != p_owner_pos)
					protocol::SerializeType(pBuffer, p_owner_pos);
				else
					protocol::SerializeType(pBuffer, &owner_pos);
			}
			protocol::SerializeType(pBuffer, &owner_zone_id);
			protocol::SerializeType(pBuffer, &owner_channel_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
