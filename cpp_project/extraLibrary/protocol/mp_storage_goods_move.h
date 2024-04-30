#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods.h"
#include "struct/mps_storage_move_goods.h"

namespace mir3d
{
	class mp_storage_goods_move_cs : public BasePacket 
	{
	private:
		bool flag_goods = false;
		mps_update_goods goods;
		mps_update_goods* p_goods = nullptr;
	public:
		bool has_goods() const
		{
			return flag_goods;
		}
		mps_update_goods* alloc_goods()
		{
			flag_goods = true;
			return &goods;
		}
		const mps_update_goods* get_goods() const
		{
			if (true == flag_goods)
			{
				if (nullptr == p_goods)
				{
					return &goods;
				}
				return p_goods;
			}
			return nullptr;
		}
		void set_goods(mps_update_goods* in_goods)
		{
			if (nullptr == p_goods)
			{
				p_goods = in_goods;
				flag_goods = true;
			}
		}
	public:
		mpe_storage_goods_move move_type{};	// 이동 위치 플래그
	public:
		int64_t npc_uid{};	// 창고 npc uid

	public:
		mp_storage_goods_move_cs() : BasePacket(mpe_cmd::storage_goods_move_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_goods);
			if (true == flag_goods)
			{
				if (nullptr != p_goods)
					protocol::SerializeType(pBuffer, p_goods);
				else
					protocol::SerializeType(pBuffer, &goods);
			}
			protocol::SerializeEnum(pBuffer, &move_type);
			protocol::SerializeType(pBuffer, &npc_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_storage_goods_move_sc : public BasePacket 
	{
	public:
		std::vector<mps_storage_move_goods> info{};

	public:
		mp_storage_goods_move_sc() : BasePacket(mpe_cmd::storage_goods_move_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
