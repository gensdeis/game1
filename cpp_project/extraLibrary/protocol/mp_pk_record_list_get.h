#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_pk_record.h"
#include "struct/mps_pk_revenge.h"

namespace mir3d
{
	class mp_pk_record_list_get_cs : public BasePacket 
	{

	public:
		mp_pk_record_list_get_cs() : BasePacket(mpe_cmd::pk_record_list_get_cs)
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

	class mp_pk_record_list_get_sc : public BasePacket 
	{
	public:
		std::vector<mps_pk_record> list_pk_record{};
	public:
		std::vector<mps_pk_revenge> list_pk_revenge{};

	public:
		mp_pk_record_list_get_sc() : BasePacket(mpe_cmd::pk_record_list_get_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_pk_record);
			protocol::SerializeType(pBuffer, &list_pk_revenge);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
