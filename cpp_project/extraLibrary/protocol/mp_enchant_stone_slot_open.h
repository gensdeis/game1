#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_enchant_stone_slot_open_cs : public BasePacket 
	{
	public:
		int64_t iuid{};	// 슬롯을 오픈할 대상 아이템
	public:
		mpe_item_reinforce_position pos{};	// 대상 아이템 착용 여부
	public:
		int64_t use_iuid{};	// 슬롯 오픈에 사용할 아이템

	public:
		mp_enchant_stone_slot_open_cs() : BasePacket(mpe_cmd::enchant_stone_slot_open_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeEnum(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &use_iuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_enchant_stone_slot_open_sc : public BasePacket 
	{
	public:
		int64_t iuid{};	// 슬롯 개방 대상 아이템
	public:
		int32_t index{};	// 슬롯 인덱스 ( -1 일 경우 오픈 실패 )
	private:
		bool flag_info = false;
		mps_item_add info;	// 사용된 아이템 
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
		mp_enchant_stone_slot_open_sc() : BasePacket(mpe_cmd::enchant_stone_slot_open_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
