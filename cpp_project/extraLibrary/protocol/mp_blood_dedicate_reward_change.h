#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_blood_dedicate_reward_change_cs : public BasePacket 	// 봉혈 재화를 통한 보상 교환
	{
	public:
		int64_t cuid{};	// 캐릭터 아이디
	public:
		int32_t fixed_object_id{};	// 봉혈 오브젝트 아이디
	public:
		int32_t id{};	// 테이블 아이디

	public:
		mp_blood_dedicate_reward_change_cs() : BasePacket(mpe_cmd::blood_dedicate_reward_change_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &fixed_object_id);
			protocol::SerializeType(pBuffer, &id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_blood_dedicate_reward_change_sc : public BasePacket 	// 봉혈 재화를 통한 보상 교환
	{
	public:
		int32_t fixed_object_id{};	// 봉혈 오브젝트 아이디
	public:
		int32_t id{};	// 테이블 아이디
	public:
		int32_t daily_change_count{};	// 남은 교환 횟수
	private:
		bool flag_item_add = false;
		mps_item_add item_add;	// 갱신된 아이템 및 굿즈 정보
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
		mpe_error result{};	// 응답 결과(토스트메시지 출력시 사용)

	public:
		mp_blood_dedicate_reward_change_sc() : BasePacket(mpe_cmd::blood_dedicate_reward_change_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &fixed_object_id);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &daily_change_count);
			protocol::SerializeType(pBuffer, &flag_item_add);
			if (true == flag_item_add)
			{
				if (nullptr != p_item_add)
					protocol::SerializeType(pBuffer, p_item_add);
				else
					protocol::SerializeType(pBuffer, &item_add);
			}
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
