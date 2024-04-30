#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_trigger_story_dungeon_cs : public BasePacket 	// 스토리 던전 트리거
	{
	public:
		int32_t tid{};

	public:
		mp_trigger_story_dungeon_cs() : BasePacket(mpe_cmd::trigger_story_dungeon_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_trigger_story_dungeon_sc : public BasePacket 	// 스토리 던전 트리거
	{
	public:
		int32_t tid{};
	public:
		bool result{};

	public:
		mp_trigger_story_dungeon_sc() : BasePacket(mpe_cmd::trigger_story_dungeon_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
