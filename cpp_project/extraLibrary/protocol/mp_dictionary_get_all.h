#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_dictionary_info.h"
#include "struct/mps_dictionary_count_info.h"

namespace mir3d
{
	class mp_dictionary_get_all_cs : public BasePacket 
	{

	public:
		mp_dictionary_get_all_cs() : BasePacket(mpe_cmd::dictionary_get_all_cs)
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

	class mp_dictionary_get_all_sc : public BasePacket 
	{
	public:
		std::vector<mps_dictionary_info> list{};
	public:
		std::vector<mps_dictionary_count_info> count_info{};

	public:
		mp_dictionary_get_all_sc() : BasePacket(mpe_cmd::dictionary_get_all_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &count_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
