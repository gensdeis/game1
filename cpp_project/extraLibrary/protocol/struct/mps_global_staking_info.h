#pragma once
#include <vector>
#include <string>
#include "mps_boss_governance_server_info_total.h"

namespace mir3d
{
	class mps_global_staking_info 
	{
	private:
		bool flag_info = false;
		mps_boss_governance_server_info_total info;	// 서버별 스테이킹된 정보
		mps_boss_governance_server_info_total* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_boss_governance_server_info_total* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_boss_governance_server_info_total* get_info() const
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
		void set_info(mps_boss_governance_server_info_total* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		int32_t sector_id{};	// Contract에서 사용하는 게임서버 인덱스

	public:
		mps_global_staking_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &sector_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
