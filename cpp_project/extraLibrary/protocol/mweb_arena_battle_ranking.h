#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_arena_battle_ranking_info.h"
#include "struct/mps_arena_battle_ranking_info.h"

namespace mir3d
{
	class mweb_arena_battle_ranking_cs : public WebBasePacket 	// gate에서 삭제
	{
	public:
		int32_t class_type{};	// enum table 의 class_type (0~3)
	public:
		uint16_t season{};
	public:
		int64_t cuid{};
	public:
		int32_t gid{};

	public:
		mweb_arena_battle_ranking_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &class_type);
			protocol::SerializeType(pBuffer, &season);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_arena_battle_ranking_sc : public WebBasePacket 	// gate에서 삭제
	{
	public:
		std::vector<mps_arena_battle_ranking_info> ranking_info{};
	private:
		bool flag_my_ranking = false;
		mps_arena_battle_ranking_info my_ranking;
		mps_arena_battle_ranking_info* p_my_ranking = nullptr;
	public:
		bool has_my_ranking() const
		{
			return flag_my_ranking;
		}
		mps_arena_battle_ranking_info* alloc_my_ranking()
		{
			flag_my_ranking = true;
			return &my_ranking;
		}
		const mps_arena_battle_ranking_info* get_my_ranking() const
		{
			if (true == flag_my_ranking)
			{
				if (nullptr == p_my_ranking)
				{
					return &my_ranking;
				}
				return p_my_ranking;
			}
			return nullptr;
		}
		void set_my_ranking(mps_arena_battle_ranking_info* in_my_ranking)
		{
			if (nullptr == p_my_ranking)
			{
				p_my_ranking = in_my_ranking;
				flag_my_ranking = true;
			}
		}

	public:
		mweb_arena_battle_ranking_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &ranking_info);
			protocol::SerializeType(pBuffer, &flag_my_ranking);
			if (true == flag_my_ranking)
			{
				if (nullptr != p_my_ranking)
					protocol::SerializeType(pBuffer, p_my_ranking);
				else
					protocol::SerializeType(pBuffer, &my_ranking);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
