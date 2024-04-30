#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_occupationwar_guild_info.h"

namespace mir3d
{
	class mp_occupationwar_guild_info_cs : public BasePacket 	// 비곡점령전 비곡주 문파정보
	{

	public:
		mp_occupationwar_guild_info_cs() : BasePacket(mpe_cmd::occupationwar_guild_info_cs)
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

	class mp_occupationwar_guild_info_sc : public BasePacket 	// 비곡점령전 비곡주 문파정보
	{
	public:
		std::vector<mps_occupationwar_guild_info> list{};

	public:
		mp_occupationwar_guild_info_sc() : BasePacket(mpe_cmd::occupationwar_guild_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
