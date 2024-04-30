#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_search_custom_cs : public BasePacket 
	{
	public:
		std::string guild_name{};

	public:
		mp_guild_search_custom_cs() : BasePacket(mpe_cmd::guild_search_custom_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guild_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_search_custom_sc : public BasePacket 
	{
	public:
		int64_t guid{};
	public:
		std::string guild_name{};
	public:
		std::string master_name{};
	public:
		int32_t member_count{};
	public:
		int32_t master_level{};
	public:
		int32_t max_member_count{};
	public:
		uint8_t master_class{};
	public:
		int32_t master_expert_level{};	// "전직레벨"

	public:
		mp_guild_search_custom_sc() : BasePacket(mpe_cmd::guild_search_custom_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &master_name);
			protocol::SerializeType(pBuffer, &member_count);
			protocol::SerializeType(pBuffer, &master_level);
			protocol::SerializeType(pBuffer, &max_member_count);
			protocol::SerializeType(pBuffer, &master_class);
			protocol::SerializeType(pBuffer, &master_expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
