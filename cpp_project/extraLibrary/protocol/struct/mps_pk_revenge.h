#pragma once
#include <vector>
#include <string>
#include "mps_vector.h"

namespace mir3d
{
	class mps_pk_revenge 
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
		bool result{};	// "true:처치, false "
	public:
		int64_t reg_time{};
	public:
		int32_t tid{};	// 직업아이디
	public:
		int32_t chao_point{};	// 평판포인트
	public:
		int64_t revenge_possible_time{};	// 복수가능시간
	public:
		int64_t delete_time{};	// 삭제시간
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
		mps_pk_revenge()
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
			protocol::SerializeType(pBuffer, &reg_time);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &chao_point);
			protocol::SerializeType(pBuffer, &revenge_possible_time);
			protocol::SerializeType(pBuffer, &delete_time);
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
