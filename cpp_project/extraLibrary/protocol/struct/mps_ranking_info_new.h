#pragma once
#include <vector>
#include <string>
#include "mps_ranking_history_new.h"

namespace mir3d
{
	class mps_ranking_info_new 
	{
	public:
		int64_t cuid{};
	public:
		int32_t gid{};	// 서버 gid
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
		mps_ranking_history_new rank;
		mps_ranking_history_new* p_rank = nullptr;
	public:
		bool has_rank() const
		{
			return flag_rank;
		}
		mps_ranking_history_new* alloc_rank()
		{
			flag_rank = true;
			return &rank;
		}
		const mps_ranking_history_new* get_rank() const
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
		void set_rank(mps_ranking_history_new* in_rank)
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
		int32_t expert_level{};	// "전직레벨"

	public:
		mps_ranking_info_new()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &gid);
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
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
