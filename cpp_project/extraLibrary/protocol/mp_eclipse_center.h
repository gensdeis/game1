#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_eclipse_center_cs : public BasePacket 
	{
	public:
		int32_t type{};
	public:
		int32_t param1{};
	public:
		int32_t param2{};
	public:
		int32_t param3{};
	public:
		int32_t param4{};

	public:
		mp_eclipse_center_cs() : BasePacket(mpe_cmd::eclipse_center_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &param1);
			protocol::SerializeType(pBuffer, &param2);
			protocol::SerializeType(pBuffer, &param3);
			protocol::SerializeType(pBuffer, &param4);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_eclipse_center_sc : public BasePacket 
	{
	public:
		int32_t result{};

	public:
		mp_eclipse_center_sc() : BasePacket(mpe_cmd::eclipse_center_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
