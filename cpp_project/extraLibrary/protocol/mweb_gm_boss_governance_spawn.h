#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_gm_boss_governance_spawn_cs : public WebBasePacket 
	{
	public:
		int32_t type{};	// 0 : field  1 : world
	public:
		int32_t zone_id{};
	public:
		int32_t monster_id{};

	public:
		mweb_gm_boss_governance_spawn_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &monster_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_boss_governance_spawn_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	public:
		int32_t type{};	// 0 : field  1 : world
	public:
		int32_t zone_id{};
	public:
		int32_t monster_id{};

	public:
		mweb_gm_boss_governance_spawn_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &monster_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
