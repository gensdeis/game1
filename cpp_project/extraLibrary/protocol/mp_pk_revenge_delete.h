#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_pk_revenge_delete_cs : public BasePacket 	// pk 복수 삭제
	{
	public:
		int64_t record_id{};	// pk 복수 record_id

	public:
		mp_pk_revenge_delete_cs() : BasePacket(mpe_cmd::pk_revenge_delete_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &record_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_pk_revenge_delete_sc : public BasePacket 	// pk 복수 삭제
	{
	public:
		int64_t record_id{};

	public:
		mp_pk_revenge_delete_sc() : BasePacket(mpe_cmd::pk_revenge_delete_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &record_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
