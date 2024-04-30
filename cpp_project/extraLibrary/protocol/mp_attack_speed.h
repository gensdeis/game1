#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_attack_speed_cs : public BasePacket 
	{

	public:
		mp_attack_speed_cs() : BasePacket(mpe_cmd::attack_speed_cs)
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

	class mp_attack_speed_sc : public BasePacket 
	{
	public:
		int64_t uid{};
	public:
		int32_t skill_id{};
	public:
		int64_t skill_uid{};
	public:
		float atk_speed{};

	public:
		mp_attack_speed_sc() : BasePacket(mpe_cmd::attack_speed_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &skill_id);
			protocol::SerializeType(pBuffer, &skill_uid);
			protocol::SerializeType(pBuffer, &atk_speed);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
