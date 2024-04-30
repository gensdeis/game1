#pragma once
#include <vector>
#include <string>
#include "mps_vector.h"

namespace mir3d
{
	class mps_friend_info 
	{
	public:
		int64_t cuid{};
	public:
		int32_t level{};
	public:
		int32_t id{};
	public:
		std::string nickname{};
	public:
		std::string guildname{};
	public:
		int64_t lasttime{};
	public:
		bool connect{};
	public:
		mpe_friend_type friend_type{};
	public:
		int32_t map_id{};
	public:
		uint16_t channel_id{};
	private:
		bool flag_pos = false;
		mps_vector pos;
		mps_vector* p_pos = nullptr;
	public:
		bool has_pos() const
		{
			return flag_pos;
		}
		mps_vector* alloc_pos()
		{
			flag_pos = true;
			return &pos;
		}
		const mps_vector* get_pos() const
		{
			if (true == flag_pos)
			{
				if (nullptr == p_pos)
				{
					return &pos;
				}
				return p_pos;
			}
			return nullptr;
		}
		void set_pos(mps_vector* in_pos)
		{
			if (nullptr == p_pos)
			{
				p_pos = in_pos;
				flag_pos = true;
			}
		}
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		int32_t expert_level{};	// "전직레벨"

	public:
		mps_friend_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &guildname);
			protocol::SerializeType(pBuffer, &lasttime);
			protocol::SerializeType(pBuffer, &connect);
			protocol::SerializeEnum(pBuffer, &friend_type);
			protocol::SerializeType(pBuffer, &map_id);
			protocol::SerializeType(pBuffer, &channel_id);
			protocol::SerializeType(pBuffer, &flag_pos);
			if (true == flag_pos)
			{
				if (nullptr != p_pos)
					protocol::SerializeType(pBuffer, p_pos);
				else
					protocol::SerializeType(pBuffer, &pos);
			}
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
