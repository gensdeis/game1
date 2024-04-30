#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_zone_object_return_teleport_cs : public BasePacket 
	{

	public:
		mp_zone_object_return_teleport_cs() : BasePacket(mpe_cmd::zone_object_return_teleport_cs)
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

	class mp_zone_object_return_teleport_sc : public BasePacket 
	{
	public:
		int64_t uid{};	// // 텔레포트 리턴 상태의 오브젝트 uid

	public:
		mp_zone_object_return_teleport_sc() : BasePacket(mpe_cmd::zone_object_return_teleport_sc)
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
