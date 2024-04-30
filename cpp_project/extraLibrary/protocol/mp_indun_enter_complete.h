#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_indun_enter_complete_cs : public BasePacket 
	{
	public:
		int64_t iuid{};

	public:
		mp_indun_enter_complete_cs() : BasePacket(mpe_cmd::indun_enter_complete_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_indun_enter_complete_sc : public BasePacket 
	{
	public:
		bool result{};
	public:
		int32_t id{};
	public:
		int32_t stage{};
	public:
		int32_t count{};
	public:
		int32_t guild_dungeon_damage{};

	public:
		mp_indun_enter_complete_sc() : BasePacket(mpe_cmd::indun_enter_complete_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &stage);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &guild_dungeon_damage);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
