#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_dictionary_info.h"

namespace mir3d
{
	class mp_dictionary_bookmark_get_cs : public BasePacket 
	{
	public:
		mpe_dictionary_type type{};
	public:
		std::vector<int32_t> list_dic_id{};

	public:
		mp_dictionary_bookmark_get_cs() : BasePacket(mpe_cmd::dictionary_bookmark_get_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &list_dic_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_dictionary_bookmark_get_sc : public BasePacket 
	{
	public:
		mpe_dictionary_type type{};
	public:
		std::vector<mps_dictionary_info> list{};

	public:
		mp_dictionary_bookmark_get_sc() : BasePacket(mpe_cmd::dictionary_bookmark_get_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
