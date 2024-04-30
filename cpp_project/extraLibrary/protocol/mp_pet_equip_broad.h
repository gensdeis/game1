#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_pet_equip_broad_cs : public BasePacket 
	{

	public:
		mp_pet_equip_broad_cs() : BasePacket(mpe_cmd::pet_equip_broad_cs)
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

	class mp_pet_equip_broad_sc : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		int32_t tid{};	// 장착펫아이디 - 0 이면 없음

	public:
		mp_pet_equip_broad_sc() : BasePacket(mpe_cmd::pet_equip_broad_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
