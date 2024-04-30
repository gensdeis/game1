#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_check_indun_enter_condition_cs : public BasePacket 
	{
	public:
		int32_t dungeon_group_id{};

	public:
		mp_check_indun_enter_condition_cs() : BasePacket(mpe_cmd::check_indun_enter_condition_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &dungeon_group_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_check_indun_enter_condition_sc : public BasePacket 
	{

	public:
		mp_check_indun_enter_condition_sc() : BasePacket(mpe_cmd::check_indun_enter_condition_sc)
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
