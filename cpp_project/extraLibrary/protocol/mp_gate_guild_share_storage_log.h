#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_share_storage_log.h"

namespace mir3d
{
	class mp_gate_guild_share_storage_log_cs : public BasePacket 
	{
	public:
		int64_t guid{};
	public:
		int64_t last_time{};

	public:
		mp_gate_guild_share_storage_log_cs() : BasePacket(mpe_cmd::gate_guild_share_storage_log_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &last_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_guild_share_storage_log_sc : public BasePacket 
	{
	public:
		std::vector<mps_guild_share_storage_log> log_list{};
	public:
		int64_t last_time{};

	public:
		mp_gate_guild_share_storage_log_sc() : BasePacket(mpe_cmd::gate_guild_share_storage_log_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &log_list);
			protocol::SerializeType(pBuffer, &last_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
