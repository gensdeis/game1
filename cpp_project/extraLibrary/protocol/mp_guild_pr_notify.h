#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_pr_notify_cs : public BasePacket 
	{

	public:
		mp_guild_pr_notify_cs() : BasePacket(mpe_cmd::guild_pr_notify_cs)
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

	class mp_guild_pr_notify_sc : public BasePacket 
	{
	public:
		int64_t guid{};
	public:
		std::string guild_name{};
	public:
		int32_t member_count{};
	public:
		int32_t max_member_count{};

	public:
		mp_guild_pr_notify_sc() : BasePacket(mpe_cmd::guild_pr_notify_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &member_count);
			protocol::SerializeType(pBuffer, &max_member_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
