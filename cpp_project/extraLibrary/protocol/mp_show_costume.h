#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_show_costume_cs : public BasePacket 
	{
	public:
		uint16_t pos{};	// table::costume_type
	public:
		mpe_costume_show show{};

	public:
		mp_show_costume_cs() : BasePacket(mpe_cmd::show_costume_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &pos);
			protocol::SerializeEnum(pBuffer, &show);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_show_costume_sc : public BasePacket 
	{
	public:
		uint16_t show_costume{};

	public:
		mp_show_costume_sc() : BasePacket(mpe_cmd::show_costume_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &show_costume);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
