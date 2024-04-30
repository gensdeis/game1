#pragma once
#include <vector>
#include <string>
#include "mps_boss_governance_server_info_total.h"

namespace mir3d
{
	class mps_governance_server_info_total 	// 거버넌스 서버정보
	{
	private:
		bool flag_info = false;
		mps_boss_governance_server_info_total info;	// 거버넌스 정보
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
		bool on_off{};	// 서버 결정 플래그
	public:
		bool staking_fail{};	// 최소 스테이킹이하로 탈락여부

	public:
		mps_governance_server_info_total()
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
			protocol::SerializeType(pBuffer, &on_off);
			protocol::SerializeType(pBuffer, &staking_fail);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
