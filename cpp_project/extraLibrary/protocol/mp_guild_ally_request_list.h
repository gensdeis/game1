#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_ally_request_info.h"
#include "struct/mps_other_guild_info.h"

namespace mir3d
{
	class mp_guild_ally_request_list_cs : public BasePacket 	// 문파 동맹 요청 신청한/받은 목록
	{
	public:
		int64_t my_guid{};	// 내 문파 UID

	public:
		mp_guild_ally_request_list_cs() : BasePacket(mpe_cmd::guild_ally_request_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &my_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_ally_request_list_sc : public BasePacket 	// 문파 동맹 요청 신청한/받은 목록
	{
	public:
		std::vector<mps_guild_ally_request_info> list{};	// 동맹 신청/받은 목록
	public:
		std::vector<mps_other_guild_info> other_guild_list{};	// 동맹 신청/받은 타 길드정보

	public:
		mp_guild_ally_request_list_sc() : BasePacket(mpe_cmd::guild_ally_request_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &other_guild_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
