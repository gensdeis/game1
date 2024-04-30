#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_obtain_reflection.h"
#include "struct/mps_reflection.h"
#include "struct/mps_temp_reflection.h"

namespace mir3d
{
	class mp_reflection_mix_cs : public BasePacket 
	{
	public:
		std::vector<int32_t> material_reflection_id{};
	public:
		uint16_t grade{};
	public:
		int32_t count{};

	public:
		mp_reflection_mix_cs() : BasePacket(mpe_cmd::reflection_mix_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &material_reflection_id);
			protocol::SerializeType(pBuffer, &grade);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_reflection_mix_sc : public BasePacket 
	{
	public:
		std::vector<mps_obtain_reflection> reward_reflection{};	// 결과
	public:
		std::vector<mps_reflection> use_reflection{};	// 재료 화신
	public:
		std::vector<mps_temp_reflection> temp_reflection{};	// 임시보관함 화신

	public:
		mp_reflection_mix_sc() : BasePacket(mpe_cmd::reflection_mix_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &reward_reflection);
			protocol::SerializeType(pBuffer, &use_reflection);
			protocol::SerializeType(pBuffer, &temp_reflection);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
