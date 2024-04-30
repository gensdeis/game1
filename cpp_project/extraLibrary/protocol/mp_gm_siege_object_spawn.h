#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_siege_machine.h"

namespace mir3d
{
	class mp_gm_siege_object_spawn_cs : public BasePacket 
	{
	public:
		std::vector<mps_siege_machine> list_siege_machine{};
	public:
		std::vector<int32_t> list_siege_static_object{};	// map_object_data_table - id
	public:
		mpe_siege_castle_type siege_castle_type{};

	public:
		mp_gm_siege_object_spawn_cs() : BasePacket(mpe_cmd::gm_siege_object_spawn_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_siege_machine);
			protocol::SerializeType(pBuffer, &list_siege_static_object);
			protocol::SerializeEnum(pBuffer, &siege_castle_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_siege_object_spawn_sc : public BasePacket 
	{

	public:
		mp_gm_siege_object_spawn_sc() : BasePacket(mpe_cmd::gm_siege_object_spawn_sc)
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

}
