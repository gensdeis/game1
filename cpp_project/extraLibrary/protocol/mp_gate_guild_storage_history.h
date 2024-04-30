#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_storage_history.h"

namespace mir3d
{
	class mp_gate_guild_storage_history_cs : public BasePacket 
	{
	public:
		int64_t guid{};
	public:
		int32_t history_type{};

	public:
		mp_gate_guild_storage_history_cs() : BasePacket(mpe_cmd::gate_guild_storage_history_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &history_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_guild_storage_history_sc : public BasePacket 
	{
	public:
		int32_t result{};
	public:
		std::vector<mps_guild_storage_history> history_list{};

	public:
		mp_gate_guild_storage_history_sc() : BasePacket(mpe_cmd::gate_guild_storage_history_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &history_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
