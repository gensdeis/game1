#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_siege_warfare_alliance_kickout_cs : public BasePacket 	// 문파연합 추방
	{
	public:
		int64_t nuid{};
	public:
		mpe_siege_castle_type castle_type{};	// 입찰 성 type
	public:
		int64_t alliance_guid{};	// 연합 추방할 길드아이디

	public:
		mp_siege_warfare_alliance_kickout_cs() : BasePacket(mpe_cmd::siege_warfare_alliance_kickout_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nuid);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &alliance_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_siege_warfare_alliance_kickout_sc : public BasePacket 	// 문파연합 추방
	{
	public:
		int64_t alliance_guid{};	// 연합 추방된 길드아이디
	public:
		std::string alliance_guild_name{};	// 연합 추방된 길드이름

	public:
		mp_siege_warfare_alliance_kickout_sc() : BasePacket(mpe_cmd::siege_warfare_alliance_kickout_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &alliance_guid);
			protocol::SerializeType(pBuffer, &alliance_guild_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
