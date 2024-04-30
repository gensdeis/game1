#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_obtain_avatar.h"
#include "struct/mps_avatar.h"

namespace mir3d
{
	class mp_avatar_mix_cs : public BasePacket 
	{
	public:
		std::vector<int32_t> material_avatar_id{};
	public:
		uint16_t grade{};
	public:
		int32_t count{};

	public:
		mp_avatar_mix_cs() : BasePacket(mpe_cmd::avatar_mix_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &material_avatar_id);
			protocol::SerializeType(pBuffer, &grade);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_avatar_mix_sc : public BasePacket 
	{
	public:
		std::vector<mps_obtain_avatar> reward_avatar{};	// 결과
	public:
		std::vector<mps_avatar> use_avatar{};	// 재료 아바타

	public:
		mp_avatar_mix_sc() : BasePacket(mpe_cmd::avatar_mix_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &reward_avatar);
			protocol::SerializeType(pBuffer, &use_avatar);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
