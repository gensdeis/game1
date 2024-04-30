#pragma once
#include <vector>
#include <string>
#include "mps_party_base.h"
#include "mps_party_member.h"

namespace mir3d
{
	class mps_party_info 
	{
	private:
		bool flag_info = false;
		mps_party_base info;
		mps_party_base* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_party_base* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_party_base* get_info() const
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
		void set_info(mps_party_base* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		std::vector<mps_party_member> list{};

	public:
		mps_party_info()
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
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
