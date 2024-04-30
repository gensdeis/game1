#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_pet_release_summon_broad_cs : public BasePacket 	// 펫 소환해제 브로드 캐스팅(포만감0일때 클라에서 주는것)
	{

	public:
		mp_pet_release_summon_broad_cs() : BasePacket(mpe_cmd::pet_release_summon_broad_cs)
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

	class mp_pet_release_summon_broad_sc : public BasePacket 	// 펫 소환해제 브로드 캐스팅(포만감0일때 클라에서 주는것)
	{
	public:
		int64_t cuid{};

	public:
		mp_pet_release_summon_broad_sc() : BasePacket(mpe_cmd::pet_release_summon_broad_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
