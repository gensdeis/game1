#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_vehicle_expire_cs : public BasePacket 
	{
	public:
		int32_t vehicle_tid{};	// 탈것
	public:
		mpe_vehicle_expire_type type{};	// 만료 타입

	public:
		mp_vehicle_expire_cs() : BasePacket(mpe_cmd::vehicle_expire_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &vehicle_tid);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_vehicle_expire_sc : public BasePacket 
	{
	public:
		int32_t vehicle_tid{};
	public:
		mpe_vehicle_expire_type type{};
	public:
		mpe_error result{};	// 처리 결과
	public:
		int32_t inven_weight{};	// 인벤 무게

	public:
		mp_vehicle_expire_sc() : BasePacket(mpe_cmd::vehicle_expire_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &vehicle_tid);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &inven_weight);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
