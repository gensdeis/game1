#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gm_object_skill_start_cs : public BasePacket 
	{
	public:
		int64_t uid{};	// object uid
	public:
		int32_t skill_index{};	// 스킬 슬롯 index

	public:
		mp_gm_object_skill_start_cs() : BasePacket(mpe_cmd::gm_object_skill_start_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &skill_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_object_skill_start_sc : public BasePacket 
	{

	public:
		mp_gm_object_skill_start_sc() : BasePacket(mpe_cmd::gm_object_skill_start_sc)
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
