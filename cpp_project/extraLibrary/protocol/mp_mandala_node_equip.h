#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_mandala_node_info.h"

namespace mir3d
{
	class mp_mandala_node_equip_cs : public BasePacket 
	{
	public:
		int32_t node_id{};
	public:
		int64_t stone_uid{};	// 0인 경우 장착 해제
	public:
		mpe_mandala_type mandala_type{};	// 만다라 타입(1:전투2:장인3:시즌)

	public:
		mp_mandala_node_equip_cs() : BasePacket(mpe_cmd::mandala_node_equip_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &node_id);
			protocol::SerializeType(pBuffer, &stone_uid);
			protocol::SerializeEnum(pBuffer, &mandala_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_mandala_node_equip_sc : public BasePacket 
	{
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
		bool flag_node_info = false;
		mps_mandala_node_info node_info;
		mps_mandala_node_info* p_node_info = nullptr;
	public:
		bool has_node_info() const
		{
			return flag_node_info;
		}
		mps_mandala_node_info* alloc_node_info()
		{
			flag_node_info = true;
			return &node_info;
		}
		const mps_mandala_node_info* get_node_info() const
		{
			if (true == flag_node_info)
			{
				if (nullptr == p_node_info)
				{
					return &node_info;
				}
				return p_node_info;
			}
			return nullptr;
		}
		void set_node_info(mps_mandala_node_info* in_node_info)
		{
			if (nullptr == p_node_info)
			{
				p_node_info = in_node_info;
				flag_node_info = true;
			}
		}
	public:
		mpe_mandala_type mandala_type{};	// 만다라 타입(1:전투2:장인3:시즌)

	public:
		mp_mandala_node_equip_sc() : BasePacket(mpe_cmd::mandala_node_equip_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_item_add);
			if (true == flag_item_add)
			{
				if (nullptr != p_item_add)
					protocol::SerializeType(pBuffer, p_item_add);
				else
					protocol::SerializeType(pBuffer, &item_add);
			}
			protocol::SerializeType(pBuffer, &flag_node_info);
			if (true == flag_node_info)
			{
				if (nullptr != p_node_info)
					protocol::SerializeType(pBuffer, p_node_info);
				else
					protocol::SerializeType(pBuffer, &node_info);
			}
			protocol::SerializeEnum(pBuffer, &mandala_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
