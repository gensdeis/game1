#pragma once
#include <vector>
#include <string>
#include "mps_boss_governance_summon_onoff.h"

namespace mir3d
{
	class mrpcs_boss_governance_summon_info 	// 보스출현 redis정보
	{
	private:
		bool flag_info = false;
		mps_boss_governance_summon_onoff info;	// 보스출현 on/off 정보
		mps_boss_governance_summon_onoff* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_boss_governance_summon_onoff* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_boss_governance_summon_onoff* get_info() const
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
		void set_info(mps_boss_governance_summon_onoff* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpcs_boss_governance_summon_info()
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
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
