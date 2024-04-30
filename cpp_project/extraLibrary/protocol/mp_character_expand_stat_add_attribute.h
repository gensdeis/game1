#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_character_expand_stat_add_attribute_cs : public BasePacket 
	{
	public:
		uint8_t ability_list{};
	public:
		uint8_t ability_value_type{};
	public:
		int32_t ability_param{};
	public:
		float rate{};

	public:
		mp_character_expand_stat_add_attribute_cs() : BasePacket(mpe_cmd::character_expand_stat_add_attribute_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &ability_list);
			protocol::SerializeType(pBuffer, &ability_value_type);
			protocol::SerializeType(pBuffer, &ability_param);
			protocol::SerializeType(pBuffer, &rate);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_character_expand_stat_add_attribute_sc : public BasePacket 
	{

	public:
		mp_character_expand_stat_add_attribute_sc() : BasePacket(mpe_cmd::character_expand_stat_add_attribute_sc)
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
