#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_castle_owner_info_cs : public BasePacket 
	{

	public:
		mp_castle_owner_info_cs() : BasePacket(mpe_cmd::castle_owner_info_cs)
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

	class mp_castle_owner_info_sc : public BasePacket 
	{
	public:
		int32_t map_id{};
	public:
		int32_t castle_id{};
	public:
		int64_t owner_guid{};
	public:
		int32_t tax_rate{};
	public:
		std::string guild_name{};	// 문파명
	public:
		std::string master_name{};	// 문파장명
	public:
		uint16_t def_count{};	// 수성횟수
	public:
		std::vector<uint8_t> guild_mark{};	// 문파문양
	public:
		int32_t master_class{};

	public:
		mp_castle_owner_info_sc() : BasePacket(mpe_cmd::castle_owner_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &map_id);
			protocol::SerializeType(pBuffer, &castle_id);
			protocol::SerializeType(pBuffer, &owner_guid);
			protocol::SerializeType(pBuffer, &tax_rate);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &master_name);
			protocol::SerializeType(pBuffer, &def_count);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &master_class);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
