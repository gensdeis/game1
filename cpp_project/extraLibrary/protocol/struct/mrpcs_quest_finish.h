#pragma once
#include <vector>
#include <string>
#include "mps_quest_history.h"
#include "mps_item_add.h"

namespace mir3d
{
	class mrpcs_quest_finish 
	{
	public:
		uint16_t id{};
	private:
		bool flag_history = false;
		mps_quest_history history;
		mps_quest_history* p_history = nullptr;
	public:
		bool has_history() const
		{
			return flag_history;
		}
		mps_quest_history* alloc_history()
		{
			flag_history = true;
			return &history;
		}
		const mps_quest_history* get_history() const
		{
			if (true == flag_history)
			{
				if (nullptr == p_history)
				{
					return &history;
				}
				return p_history;
			}
			return nullptr;
		}
		void set_history(mps_quest_history* in_history)
		{
			if (nullptr == p_history)
			{
				p_history = in_history;
				flag_history = true;
			}
		}
	private:
		bool flag_info = false;
		mps_item_add info;
		mps_item_add* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_add* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_add* get_info() const
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
		void set_info(mps_item_add* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		std::vector<uint16_t> delete_list_id{};	// 퀘스트 삭제 목록

	public:
		mrpcs_quest_finish()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &flag_history);
			if (true == flag_history)
			{
				if (nullptr != p_history)
					protocol::SerializeType(pBuffer, p_history);
				else
					protocol::SerializeType(pBuffer, &history);
			}
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &delete_list_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
