#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_equipment_awaken_option_confirmed_cs : public BasePacket 
	{
	public:
		int64_t target_iuid{};

	public:
		mp_equipment_awaken_option_confirmed_cs() : BasePacket(mpe_cmd::equipment_awaken_option_confirmed_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_iuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_equipment_awaken_option_confirmed_sc : public BasePacket 
	{
	public:
		int32_t option_confirmed{};	// 결과
	public:
		int64_t target_iuid{};

	public:
		mp_equipment_awaken_option_confirmed_sc() : BasePacket(mpe_cmd::equipment_awaken_option_confirmed_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &option_confirmed);
			protocol::SerializeType(pBuffer, &target_iuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
