#pragma once
#include <vector>
#include <string>
#include "mps_character.h"

namespace mir3d
{
	class mps_enter_character 
	{
	public:
		int64_t auid{};
	public:
		std::string username{};
	public:
		int32_t index{};
	private:
		bool flag_info = false;
		mps_character info;
		mps_character* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_character* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_character* get_info() const
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
		void set_info(mps_character* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mps_enter_character()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &index);
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
