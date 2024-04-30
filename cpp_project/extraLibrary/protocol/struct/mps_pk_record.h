#pragma once
#include <vector>
#include <string>
#include "mps_item_id.h"
#include "mps_vector.h"

namespace mir3d
{
	class mps_pk_record 
	{
	public:
		int64_t record_id{};
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		int32_t level{};
	public:
		bool result{};	// "true:처치, false 사망"
	public:
		bool reg_revenge{};	// 복수등록 여부
	public:
		int64_t reg_time{};
	public:
		std::vector<mps_item_id> lose_item{};	// 잃은 아이템
	public:
		int32_t lose_gold{};	// 잃은 골드
	public:
		int32_t tid{};	// 직업아이디
	public:
		int32_t chao_point{};
	public:
		bool wanted_murder_result{};	// 현상수배결과
	public:
		int32_t expert_level{};	// "전직레벨"
	public:
		int64_t guid{};	// "문파uid"
	public:
		uint16_t ch_id{};	// "채널id"
	public:
		int32_t zone_id{};	// "pk발생 zoneid"
	private:
		bool flag_pos = false;
		mps_vector pos;	// "pk발생 좌표"
		mps_vector* p_pos = nullptr;
	public:
		bool has_pos() const
		{
			return flag_pos;
		}
		mps_vector* alloc_pos()
		{
			flag_pos = true;
			return &pos;
		}
		const mps_vector* get_pos() const
		{
			if (true == flag_pos)
			{
				if (nullptr == p_pos)
				{
					return &pos;
				}
				return p_pos;
			}
			return nullptr;
		}
		void set_pos(mps_vector* in_pos)
		{
			if (nullptr == p_pos)
			{
				p_pos = in_pos;
				flag_pos = true;
			}
		}
	public:
		std::vector<uint8_t> guild_mark{};	// "문파 마크"
	public:
		std::string guild_name{};	// "문파 이름"

	public:
		mps_pk_record()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &record_id);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &reg_revenge);
			protocol::SerializeType(pBuffer, &reg_time);
			protocol::SerializeType(pBuffer, &lose_item);
			protocol::SerializeType(pBuffer, &lose_gold);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &chao_point);
			protocol::SerializeType(pBuffer, &wanted_murder_result);
			protocol::SerializeType(pBuffer, &expert_level);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &ch_id);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &flag_pos);
			if (true == flag_pos)
			{
				if (nullptr != p_pos)
					protocol::SerializeType(pBuffer, p_pos);
				else
					protocol::SerializeType(pBuffer, &pos);
			}
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &guild_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
