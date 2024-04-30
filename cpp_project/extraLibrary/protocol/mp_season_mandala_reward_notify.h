#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_season_mandala_reward_info.h"

namespace mir3d
{
	class mp_season_mandala_reward_notify_cs : public BasePacket 	// 시즌 만다라 보상정보 전달
	{

	public:
		mp_season_mandala_reward_notify_cs() : BasePacket(mpe_cmd::season_mandala_reward_notify_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_season_mandala_reward_notify_sc : public BasePacket 	// 시즌 만다라 보상정보 전달
	{
	public:
		std::vector<mps_season_mandala_reward_info> list_season_mandala_reward{};	// 시즌 만다라 캐릭터보상 정보리스트

	public:
		mp_season_mandala_reward_notify_sc() : BasePacket(mpe_cmd::season_mandala_reward_notify_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_season_mandala_reward);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
