#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_mandala_layer_rotate.h"
#include "struct/mps_mandala_layer_info.h"
#include "struct/mps_mandala_node_info.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_mandala_rotation_cs : public BasePacket 
	{
	public:
		std::vector<mps_mandala_layer_rotate> rotate_info{};
	public:
		mpe_mandala_type mandala_type{};	// 만다라 타입(1:전투2:장인3:시즌)

	public:
		mp_mandala_rotation_cs() : BasePacket(mpe_cmd::mandala_rotation_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &rotate_info);
			protocol::SerializeEnum(pBuffer, &mandala_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_mandala_rotation_sc : public BasePacket 
	{
	public:
		std::vector<mps_mandala_layer_info> list_layer{};	// 변경된 레이어 정보
	public:
		std::vector<mps_mandala_node_info> list_node{};	// 변경된 노드 및 활성화 정보
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
		mpe_mandala_type mandala_type{};	// 만다라 타입(1:전투2:장인3:시즌)

	public:
		mp_mandala_rotation_sc() : BasePacket(mpe_cmd::mandala_rotation_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_layer);
			protocol::SerializeType(pBuffer, &list_node);
			protocol::SerializeType(pBuffer, &flag_item_add);
			if (true == flag_item_add)
			{
				if (nullptr != p_item_add)
					protocol::SerializeType(pBuffer, p_item_add);
				else
					protocol::SerializeType(pBuffer, &item_add);
			}
			protocol::SerializeEnum(pBuffer, &mandala_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
