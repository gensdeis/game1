#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_other_guild_info.h"

namespace mir3d
{
	class mp_guild_recommend_cs : public BasePacket 
	{

	public:
		mp_guild_recommend_cs() : BasePacket(mpe_cmd::guild_recommend_cs)
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

	class mp_guild_recommend_sc : public BasePacket 
	{
	public:
		std::vector<mps_other_guild_info> list_guild{};
	public:
		std::vector<int64_t> list_request_guid{};

	public:
		mp_guild_recommend_sc() : BasePacket(mpe_cmd::guild_recommend_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_guild);
			protocol::SerializeType(pBuffer, &list_request_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
