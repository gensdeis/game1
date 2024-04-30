#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_temp_pet.h"
#include "struct/mps_obtain_pet_info.h"

namespace mir3d
{
	class mp_temp_pet_get_cs : public BasePacket 
	{

	public:
		mp_temp_pet_get_cs() : BasePacket(mpe_cmd::temp_pet_get_cs)
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

	class mp_temp_pet_get_sc : public BasePacket 
	{
	public:
		std::vector<mps_temp_pet> list{};	// 보관함 펫
	public:
		std::vector<mps_obtain_pet_info> pet_info{};	// 획득 펫
	public:
		std::vector<int64_t> del_uid{};	// 보관함에서 삭제된 uid

	public:
		mp_temp_pet_get_sc() : BasePacket(mpe_cmd::temp_pet_get_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &pet_info);
			protocol::SerializeType(pBuffer, &del_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
