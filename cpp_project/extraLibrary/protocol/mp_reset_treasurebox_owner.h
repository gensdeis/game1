#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_reset_treasurebox_owner_cs : public BasePacket 
	{

	public:
		mp_reset_treasurebox_owner_cs() : BasePacket(mpe_cmd::reset_treasurebox_owner_cs)
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

	class mp_reset_treasurebox_owner_sc : public BasePacket 
	{
	public:
		int64_t uid{};

	public:
		mp_reset_treasurebox_owner_sc() : BasePacket(mpe_cmd::reset_treasurebox_owner_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
