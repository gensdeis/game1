#pragma once
#include <vector>
#include <string>
#include "mrpcs_boss_governance_treasurebox.h"

namespace mir3d
{
	class mrpcs_boss_governance_server_decide_process 	// 보스 거버넌스 결정 후처리 정보
	{
	private:
		bool flag_info = false;
		mrpcs_boss_governance_treasurebox info;	// 보스거버넌스 보물상자 추가확률 정보
		mrpcs_boss_governance_treasurebox* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_boss_governance_treasurebox* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_boss_governance_treasurebox* get_info() const
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
		void set_info(mrpcs_boss_governance_treasurebox* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		bool on_off{};	// 혜택 서버여부(false:미혜택/true:혜택)
	public:
		int32_t gid{};	// 서버 아이디

	public:
		mrpcs_boss_governance_server_decide_process()
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
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
