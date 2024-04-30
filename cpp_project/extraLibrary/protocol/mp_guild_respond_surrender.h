#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_respond_surrender_cs : public BasePacket 
	{
	public:
		int64_t target_guid{};
	public:
		bool accept{};

	public:
		mp_guild_respond_surrender_cs() : BasePacket(mpe_cmd::guild_respond_surrender_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_guid);
			protocol::SerializeType(pBuffer, &accept);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_respond_surrender_sc : public BasePacket 
	{
	public:
		int64_t target_guid{};
	public:
		std::string target_guild_name{};
	public:
		bool accept{};
	public:
		int64_t negotiation_gold{};
	public:
		int64_t next_available_start_time{};

	public:
		mp_guild_respond_surrender_sc() : BasePacket(mpe_cmd::guild_respond_surrender_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_guid);
			protocol::SerializeType(pBuffer, &target_guild_name);
			protocol::SerializeType(pBuffer, &accept);
			protocol::SerializeType(pBuffer, &negotiation_gold);
			protocol::SerializeType(pBuffer, &next_available_start_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
