#pragma once
#include <vector>
#include <string>
#include "mps_quest_history.h"
#include "mps_quest.h"
#include "mps_quest_reward.h"
#include "mps_repute_quest.h"
#include "mps_achieve_info.h"
#include "mps_quest.h"

namespace mir3d
{
	class mps_questbook 
	{
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
	public:
		std::vector<mps_quest> list_quest{};
	public:
		std::vector<mps_quest_reward> list_quest_reward{};
	public:
		std::vector<mps_repute_quest> list_repute_quest{};
	public:
		std::vector<mps_achieve_info> list_achieve{};
	public:
		std::vector<uint8_t> list_tutorial{};
	public:
		std::vector<mps_quest> list_tutorial_quest{};

	public:
		mps_questbook()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &flag_history);
			if (true == flag_history)
			{
				if (nullptr != p_history)
					protocol::SerializeType(pBuffer, p_history);
				else
					protocol::SerializeType(pBuffer, &history);
			}
			protocol::SerializeType(pBuffer, &list_quest);
			protocol::SerializeType(pBuffer, &list_quest_reward);
			protocol::SerializeType(pBuffer, &list_repute_quest);
			protocol::SerializeType(pBuffer, &list_achieve);
			protocol::SerializeType(pBuffer, &list_tutorial);
			protocol::SerializeType(pBuffer, &list_tutorial_quest);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
