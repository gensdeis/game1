#pragma once
#include <vector>
#include <string>
#include "mps_buff.h"
#include "mps_party_member_base.h"

namespace mir3d
{
	class mps_party_member 
	{
	public:
		int32_t power{};
	public:
		int32_t hp_max{};
	public:
		int32_t mp_max{};
	public:
		int32_t hp{};
	public:
		int32_t mp{};
	public:
		std::vector<mps_buff> buff_info{};
	private:
		bool flag_info = false;
		mps_party_member_base info;
		mps_party_member_base* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_party_member_base* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_party_member_base* get_info() const
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
		void set_info(mps_party_member_base* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mps_party_member()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &power);
			protocol::SerializeType(pBuffer, &hp_max);
			protocol::SerializeType(pBuffer, &mp_max);
			protocol::SerializeType(pBuffer, &hp);
			protocol::SerializeType(pBuffer, &mp);
			protocol::SerializeType(pBuffer, &buff_info);
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
