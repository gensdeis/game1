#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_obtain_pet_info.h"
#include "struct/mps_temp_pet.h"
#include "struct/mps_reward_value.h"
#include "struct/mps_obtain_avatar.h"
#include "struct/mps_obtain_reflection.h"
#include "struct/mps_temp_reflection.h"

namespace mir3d
{
	class mp_randombox_open_cs : public BasePacket 
	{
	public:
		int64_t iuid{};	// 랜덤박스
	public:
		std::vector<int32_t> list_tid{};	// 선택형 박스일 경우 사용
	public:
		uint16_t open_count{};	// 랜덤형 박스일 경우 오픈 횟수

	public:
		mp_randombox_open_cs() : BasePacket(mpe_cmd::randombox_open_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &list_tid);
			protocol::SerializeType(pBuffer, &open_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_randombox_open_sc : public BasePacket 
	{
	private:
		bool flag_reward_item = false;
		mps_item_add reward_item;	// 결과 아이템
		mps_item_add* p_reward_item = nullptr;
	public:
		bool has_reward_item() const
		{
			return flag_reward_item;
		}
		mps_item_add* alloc_reward_item()
		{
			flag_reward_item = true;
			return &reward_item;
		}
		const mps_item_add* get_reward_item() const
		{
			if (true == flag_reward_item)
			{
				if (nullptr == p_reward_item)
				{
					return &reward_item;
				}
				return p_reward_item;
			}
			return nullptr;
		}
		void set_reward_item(mps_item_add* in_reward_item)
		{
			if (nullptr == p_reward_item)
			{
				p_reward_item = in_reward_item;
				flag_reward_item = true;
			}
		}
	public:
		std::vector<mps_obtain_pet_info> reward_pet{};	// 결과 펫
	public:
		std::vector<mps_temp_pet> list_temp_pet{};	// 보관함 펫
	public:
		std::vector<mps_reward_value> reward_info{};	// 결과 tid + count(클라필요)
	public:
		std::vector<mps_obtain_avatar> reward_avatar{};	// 결과 아바타
	public:
		std::vector<mps_obtain_reflection> reward_reflection{};	// 획득화신
	public:
		std::vector<mps_temp_reflection> temp_reflection{};	// 임시보관함 화신
	public:
		int32_t inven_size{};	// 인벤 슬롯사이즈

	public:
		mp_randombox_open_sc() : BasePacket(mpe_cmd::randombox_open_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_reward_item);
			if (true == flag_reward_item)
			{
				if (nullptr != p_reward_item)
					protocol::SerializeType(pBuffer, p_reward_item);
				else
					protocol::SerializeType(pBuffer, &reward_item);
			}
			protocol::SerializeType(pBuffer, &reward_pet);
			protocol::SerializeType(pBuffer, &list_temp_pet);
			protocol::SerializeType(pBuffer, &reward_info);
			protocol::SerializeType(pBuffer, &reward_avatar);
			protocol::SerializeType(pBuffer, &reward_reflection);
			protocol::SerializeType(pBuffer, &temp_reflection);
			protocol::SerializeType(pBuffer, &inven_size);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
