#pragma once
#include <vector>
#include <string>
#include "mps_lord_statue_info.h"
#include "mps_lord_bless_info.h"

namespace mir3d
{
	class mps_castle_info 	// 성 정보
	{
	public:
		mpe_siege_castle_type castle_type{};	// 성타입
	public:
		int64_t owner_guid{};	// 성주길드
	public:
		int64_t owner_master_cuid{};	// 성주cuid
	public:
		int32_t tax_rate{};	// 세율
	public:
		int64_t siege_date_time{};	// 길드전날짜
	public:
		bool refund_payment{};	// 정산중확인
	public:
		int64_t tax_rate_reg_time{};	// 세율 변경 날짜
	public:
		mpe_castle_tax_distribution tax_distribution{};	// 세율 분배 방식
	public:
		int32_t dungeon_entrance_fee{};	// 던전입장료
	public:
		int32_t dungeon_apply_entrance_fee{};	// 적용될던전입장료
	public:
		int32_t dungeon_entrance_fee_tax{};	// 던전입장료모인세금
	public:
		std::string guild_name{};	// 길드명
	public:
		std::string master_name{};	// 길마명
	public:
		std::vector<uint8_t> guild_mark{};	// 문파문양
	public:
		uint16_t def_count{};	// 수성횟수
	private:
		bool flag_lord_statue_info = false;
		mps_lord_statue_info lord_statue_info;	// 동상정보
		mps_lord_statue_info* p_lord_statue_info = nullptr;
	public:
		bool has_lord_statue_info() const
		{
			return flag_lord_statue_info;
		}
		mps_lord_statue_info* alloc_lord_statue_info()
		{
			flag_lord_statue_info = true;
			return &lord_statue_info;
		}
		const mps_lord_statue_info* get_lord_statue_info() const
		{
			if (true == flag_lord_statue_info)
			{
				if (nullptr == p_lord_statue_info)
				{
					return &lord_statue_info;
				}
				return p_lord_statue_info;
			}
			return nullptr;
		}
		void set_lord_statue_info(mps_lord_statue_info* in_lord_statue_info)
		{
			if (nullptr == p_lord_statue_info)
			{
				p_lord_statue_info = in_lord_statue_info;
				flag_lord_statue_info = true;
			}
		}
	public:
		int32_t master_class{};	// 길마직업
	private:
		bool flag_lord_bless_info = false;
		mps_lord_bless_info lord_bless_info;	// 축복정보
		mps_lord_bless_info* p_lord_bless_info = nullptr;
	public:
		bool has_lord_bless_info() const
		{
			return flag_lord_bless_info;
		}
		mps_lord_bless_info* alloc_lord_bless_info()
		{
			flag_lord_bless_info = true;
			return &lord_bless_info;
		}
		const mps_lord_bless_info* get_lord_bless_info() const
		{
			if (true == flag_lord_bless_info)
			{
				if (nullptr == p_lord_bless_info)
				{
					return &lord_bless_info;
				}
				return p_lord_bless_info;
			}
			return nullptr;
		}
		void set_lord_bless_info(mps_lord_bless_info* in_lord_bless_info)
		{
			if (nullptr == p_lord_bless_info)
			{
				p_lord_bless_info = in_lord_bless_info;
				flag_lord_bless_info = true;
			}
		}

	public:
		mps_castle_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &owner_guid);
			protocol::SerializeType(pBuffer, &owner_master_cuid);
			protocol::SerializeType(pBuffer, &tax_rate);
			protocol::SerializeType(pBuffer, &siege_date_time);
			protocol::SerializeType(pBuffer, &refund_payment);
			protocol::SerializeType(pBuffer, &tax_rate_reg_time);
			protocol::SerializeEnum(pBuffer, &tax_distribution);
			protocol::SerializeType(pBuffer, &dungeon_entrance_fee);
			protocol::SerializeType(pBuffer, &dungeon_apply_entrance_fee);
			protocol::SerializeType(pBuffer, &dungeon_entrance_fee_tax);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &master_name);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &def_count);
			protocol::SerializeType(pBuffer, &flag_lord_statue_info);
			if (true == flag_lord_statue_info)
			{
				if (nullptr != p_lord_statue_info)
					protocol::SerializeType(pBuffer, p_lord_statue_info);
				else
					protocol::SerializeType(pBuffer, &lord_statue_info);
			}
			protocol::SerializeType(pBuffer, &master_class);
			protocol::SerializeType(pBuffer, &flag_lord_bless_info);
			if (true == flag_lord_bless_info)
			{
				if (nullptr != p_lord_bless_info)
					protocol::SerializeType(pBuffer, p_lord_bless_info);
				else
					protocol::SerializeType(pBuffer, &lord_bless_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
