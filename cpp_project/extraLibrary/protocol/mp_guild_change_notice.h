#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_change_notice_cs : public BasePacket 	// 문파 공지 변경
	{
	public:
		std::string notice{};

	public:
		mp_guild_change_notice_cs() : BasePacket(mpe_cmd::guild_change_notice_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &notice);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_change_notice_sc : public BasePacket 	// 문파 공지 변경
	{
	public:
		std::string notice{};
	public:
		int64_t notice_update_time{};

	public:
		mp_guild_change_notice_sc() : BasePacket(mpe_cmd::guild_change_notice_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &notice);
			protocol::SerializeType(pBuffer, &notice_update_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
