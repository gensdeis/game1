#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_castle_town_work_cs : public BasePacket 	// 장원 관련 작업
	{
	public:
		int64_t nuid{};
	public:
		int32_t town_id{};
	public:
		mpe_castle_town_detail_pos house_pos{};	// house 고용 타입
	public:
		mpe_castle_town_work_type work_type{};	// 장원 관련 작업 종류
	public:
		bool direct{};	// 즉시 고용 여부

	public:
		mp_castle_town_work_cs() : BasePacket(mpe_cmd::castle_town_work_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nuid);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeEnum(pBuffer, &house_pos);
			protocol::SerializeEnum(pBuffer, &work_type);
			protocol::SerializeType(pBuffer, &direct);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_castle_town_work_sc : public BasePacket 	// 장원 관련 작업
	{
	public:
		int32_t town_id{};
	public:
		mpe_castle_town_detail_pos house_pos{};	// house 고용 타입
	public:
		mpe_castle_town_work_type work_type{};
	public:
		int64_t end_time{};
	private:
		bool flag_use_item_info = false;
		mps_item_add use_item_info;	// 사용한 아이템 정보
		mps_item_add* p_use_item_info = nullptr;
	public:
		bool has_use_item_info() const
		{
			return flag_use_item_info;
		}
		mps_item_add* alloc_use_item_info()
		{
			flag_use_item_info = true;
			return &use_item_info;
		}
		const mps_item_add* get_use_item_info() const
		{
			if (true == flag_use_item_info)
			{
				if (nullptr == p_use_item_info)
				{
					return &use_item_info;
				}
				return p_use_item_info;
			}
			return nullptr;
		}
		void set_use_item_info(mps_item_add* in_use_item_info)
		{
			if (nullptr == p_use_item_info)
			{
				p_use_item_info = in_use_item_info;
				flag_use_item_info = true;
			}
		}

	public:
		mp_castle_town_work_sc() : BasePacket(mpe_cmd::castle_town_work_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeEnum(pBuffer, &house_pos);
			protocol::SerializeEnum(pBuffer, &work_type);
			protocol::SerializeType(pBuffer, &end_time);
			protocol::SerializeType(pBuffer, &flag_use_item_info);
			if (true == flag_use_item_info)
			{
				if (nullptr != p_use_item_info)
					protocol::SerializeType(pBuffer, p_use_item_info);
				else
					protocol::SerializeType(pBuffer, &use_item_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
