#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_learn_skill_cs : public BasePacket 
	{
	public:
		int32_t skill_id{};

	public:
		mp_guild_learn_skill_cs() : BasePacket(mpe_cmd::guild_learn_skill_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &skill_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_learn_skill_sc : public BasePacket 
	{
	public:
		int32_t old_skill_id{};
	public:
		int32_t new_skill_id{};
	public:
		int32_t guild_gold{};
	public:
		int32_t guild_blackiron{};

	public:
		mp_guild_learn_skill_sc() : BasePacket(mpe_cmd::guild_learn_skill_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &old_skill_id);
			protocol::SerializeType(pBuffer, &new_skill_id);
			protocol::SerializeType(pBuffer, &guild_gold);
			protocol::SerializeType(pBuffer, &guild_blackiron);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
