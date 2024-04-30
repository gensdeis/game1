#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_guildshipwar_season_reward_cs : public WebBasePacket 	// gate에서 삭제
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};

	public:
		mweb_guildshipwar_season_reward_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_guildshipwar_season_reward_sc : public WebBasePacket 	// gate에서 삭제
	{
	public:
		bool isReward{};
	public:
		bool is_new_season{};
	public:
		int32_t season{};	// 현재시즌
	public:
		int32_t rank{};	// 이전시즌 순위
	public:
		int32_t league{};	// 이전시즌 리그

	public:
		mweb_guildshipwar_season_reward_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &isReward);
			protocol::SerializeType(pBuffer, &is_new_season);
			protocol::SerializeType(pBuffer, &season);
			protocol::SerializeType(pBuffer, &rank);
			protocol::SerializeType(pBuffer, &league);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
