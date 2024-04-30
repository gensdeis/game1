#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_move_story_dungeon_cs : public BasePacket 	// 스토리 던전에서 이동 패킷
	{
	public:
		int64_t uid{};	// 이동 object uid
	public:
		int32_t move_cell{};	// 이동 타일
	public:
		mpe_direction direction{};	// 이동방향

	public:
		mp_move_story_dungeon_cs() : BasePacket(mpe_cmd::move_story_dungeon_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &move_cell);
			protocol::SerializeEnum(pBuffer, &direction);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_move_story_dungeon_sc : public BasePacket 	// 스토리 던전에서 이동 패킷
	{

	public:
		mp_move_story_dungeon_sc() : BasePacket(mpe_cmd::move_story_dungeon_sc)
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

}
