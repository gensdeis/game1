#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_dictionary_info.h"

namespace mir3d
{
	class mp_gm_dictionary_add_cs : public BasePacket 
	{
	public:
		mpe_dictionary_type type{};

	public:
		mp_gm_dictionary_add_cs() : BasePacket(mpe_cmd::gm_dictionary_add_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_dictionary_add_sc : public BasePacket 
	{
	public:
		std::vector<mps_dictionary_info> list{};

	public:
		mp_gm_dictionary_add_sc() : BasePacket(mpe_cmd::gm_dictionary_add_sc)
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
