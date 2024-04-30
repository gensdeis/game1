#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_zone_treasure_box_open_cs : public BasePacket 
	{
	public:
		int64_t iuid{};	// 보물 상자 uid
	public:
		mpe_object_collect_flag flag{};	// 상태
	public:
		std::vector<int32_t> list_tid{};

	public:
		mp_zone_treasure_box_open_cs() : BasePacket(mpe_cmd::zone_treasure_box_open_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeEnum(pBuffer, &flag);
			protocol::SerializeType(pBuffer, &list_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_zone_treasure_box_open_sc : public BasePacket 
	{
	public:
		int64_t cuid{};	// 캐릭터 uid
	public:
		int64_t iuid{};	// 보물 상자 uid
	public:
		mpe_object_collect_flag flag{};	// 상태
	public:
		mpe_character_action action{};	// 액션 상태
	public:
		float weight{};
	private:
		bool flag_info = false;
		mps_item_add info;	// 아이템 업데이트 정보
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
		std::string open_character_name{};

	public:
		mp_zone_treasure_box_open_sc() : BasePacket(mpe_cmd::zone_treasure_box_open_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeEnum(pBuffer, &flag);
			protocol::SerializeEnum(pBuffer, &action);
			protocol::SerializeType(pBuffer, &weight);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &open_character_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
