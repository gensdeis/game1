#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_global_staking_info_list.h"
#include "struct/mps_governance_server_info_total.h"

namespace mir3d
{
	class mp_gate_world_boss_statking_board_info_cs : public BasePacket 
	{
	public:
		mpe_governance_contents_type cotents_type{};	// 거버넌스 콘텐츠 타입(0:없음 1:보스 2:비곡점령전 3:공성전)

	public:
		mp_gate_world_boss_statking_board_info_cs() : BasePacket(mpe_cmd::gate_world_boss_statking_board_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &cotents_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_world_boss_statking_board_info_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_global_staking_info_list info;	// 월드 스테이킹 목록
		mps_global_staking_info_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_global_staking_info_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_global_staking_info_list* get_info() const
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
		void set_info(mps_global_staking_info_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		std::vector<mps_governance_server_info_total> info_last_week{};	// 이전 주 월드 스테이킹 목록
	public:
		int32_t left_time{};	// 남은 시간 (UTC+0기준)
	public:
		int32_t agenda_id{};	// contract에서 사용하는 월드 key 값
	public:
		mpe_governance_contents_type contents_type{};	// 콘텐츠 타입(0:none 1:보스 2:비곡점령전 3:공성전)

	public:
		mp_gate_world_boss_statking_board_info_sc() : BasePacket(mpe_cmd::gate_world_boss_statking_board_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &info_last_week);
			protocol::SerializeType(pBuffer, &left_time);
			protocol::SerializeType(pBuffer, &agenda_id);
			protocol::SerializeEnum(pBuffer, &contents_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
