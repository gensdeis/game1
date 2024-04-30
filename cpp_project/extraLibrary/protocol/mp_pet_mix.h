#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_pet_info.h"
#include "struct/mps_reward_pet_info.h"
#include "struct/mps_temp_pet.h"

namespace mir3d
{
	class mp_pet_mix_cs : public BasePacket 	// 펫 합성
	{
	public:
		std::vector<int32_t> material_pet_list{};	// 합성재료
	public:
		int32_t grade{};	// 제작등급
	public:
		int32_t count{};	// 제작개수

	public:
		mp_pet_mix_cs() : BasePacket(mpe_cmd::pet_mix_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &material_pet_list);
			protocol::SerializeType(pBuffer, &grade);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_pet_mix_sc : public BasePacket 	// 펫 합성
	{
	public:
		std::vector<mps_pet_info> material_pet_list{};	// 합성재료 사용후 정보
	public:
		std::vector<mps_reward_pet_info> list_reward_pet{};
	public:
		bool isAll{};	// "true : 전체 합성, false : 1회 합성"
	public:
		std::vector<mps_temp_pet> list_temp_pet{};

	public:
		mp_pet_mix_sc() : BasePacket(mpe_cmd::pet_mix_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &material_pet_list);
			protocol::SerializeType(pBuffer, &list_reward_pet);
			protocol::SerializeType(pBuffer, &isAll);
			protocol::SerializeType(pBuffer, &list_temp_pet);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
