#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_achieve_rate_info.h"

namespace mir3d
{
	class mp_dictionary_achieve_rate_get_cs : public BasePacket 
	{

	public:
		mp_dictionary_achieve_rate_get_cs() : BasePacket(mpe_cmd::dictionary_achieve_rate_get_cs)
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

	class mp_dictionary_achieve_rate_get_sc : public BasePacket 
	{
	public:
		std::vector<mps_achieve_rate_info> info{};

	public:
		mp_dictionary_achieve_rate_get_sc() : BasePacket(mpe_cmd::dictionary_achieve_rate_get_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
