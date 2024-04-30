#pragma once
#include <vector>
#include <string>
#include "mps_ranking_history.h"

namespace mir3d
{
	class mps_ranking_info 
	{
	public:
		int64_t cuid{};
	public:
		int32_t id{};	// class id
	public:
		int32_t level{};
	public:
		std::string nickname{};
	public:
		std::string guildname{};
	private:
		bool flag_rank = false;
		mps_ranking_history rank;
		mps_ranking_history* p_rank = nullptr;
	public:
		bool has_rank() const
		{
			return flag_rank;
		}
		mps_ranking_history* alloc_rank()
		{
			flag_rank = true;
			return &rank;
		}
		const mps_ranking_history* get_rank() const
		{
			if (true == flag_rank)
			{
				if (nullptr == p_rank)
				{
					return &rank;
				}
				return p_rank;
			}
			return nullptr;
		}
		void set_rank(mps_ranking_history* in_rank)
		{
			if (nullptr == p_rank)
			{
				p_rank = in_rank;
				flag_rank = true;
			}
		}
	public:
		std::vector<uint8_t> guild_mark{};

	public:
		mps_ranking_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &guildname);
			protocol::SerializeType(pBuffer, &flag_rank);
			if (true == flag_rank)
			{
				if (nullptr != p_rank)
					protocol::SerializeType(pBuffer, p_rank);
				else
					protocol::SerializeType(pBuffer, &rank);
			}
			protocol::SerializeType(pBuffer, &guild_mark);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
