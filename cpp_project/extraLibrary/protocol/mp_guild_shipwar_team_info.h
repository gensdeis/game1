#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_shipwar_team_info_cs : public BasePacket 
	{

	public:
		mp_guild_shipwar_team_info_cs() : BasePacket(mpe_cmd::guild_shipwar_team_info_cs)
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

	class mp_guild_shipwar_team_info_sc : public BasePacket 
	{
	public:
		int64_t guid_A{};
	public:
		std::string guid_name_A{};
	public:
		std::vector<uint8_t> guild_mark_A{};	// 문파 문장
	public:
		uint8_t guid_flag_count_A{};
	public:
		int32_t guild_gid_A{};	// 해당 문파 서버 gid 
	public:
		int64_t guid_B{};
	public:
		std::string guid_name_B{};
	public:
		std::vector<uint8_t> guild_mark_B{};	// 문파 문장
	public:
		uint8_t guid_flag_count_B{};
	public:
		int32_t guild_gid_B{};	// 해당 문파 서버 gid 
	public:
		mpe_shipwar_time_type time_type{};
	public:
		int32_t time_remaining{};
	public:
		uint8_t revival_time_remaining{};
	public:
		std::vector<uint8_t> list_flag{};

	public:
		mp_guild_shipwar_team_info_sc() : BasePacket(mpe_cmd::guild_shipwar_team_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid_A);
			protocol::SerializeType(pBuffer, &guid_name_A);
			protocol::SerializeType(pBuffer, &guild_mark_A);
			protocol::SerializeType(pBuffer, &guid_flag_count_A);
			protocol::SerializeType(pBuffer, &guild_gid_A);
			protocol::SerializeType(pBuffer, &guid_B);
			protocol::SerializeType(pBuffer, &guid_name_B);
			protocol::SerializeType(pBuffer, &guild_mark_B);
			protocol::SerializeType(pBuffer, &guid_flag_count_B);
			protocol::SerializeType(pBuffer, &guild_gid_B);
			protocol::SerializeEnum(pBuffer, &time_type);
			protocol::SerializeType(pBuffer, &time_remaining);
			protocol::SerializeType(pBuffer, &revival_time_remaining);
			protocol::SerializeType(pBuffer, &list_flag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
