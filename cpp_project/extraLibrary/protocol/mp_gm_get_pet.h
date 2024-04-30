#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_pet_info.h"
#include "struct/mps_temp_pet.h"

namespace mir3d
{
	class mp_gm_get_pet_cs : public BasePacket 
	{
	public:
		int32_t pet_tid{};

	public:
		mp_gm_get_pet_cs() : BasePacket(mpe_cmd::gm_get_pet_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &pet_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_get_pet_sc : public BasePacket 
	{
	public:
		std::vector<mps_pet_info> pet_info{};
	public:
		int32_t inven_size{};
	public:
		std::vector<mps_temp_pet> temp_list{};

	public:
		mp_gm_get_pet_sc() : BasePacket(mpe_cmd::gm_get_pet_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &pet_info);
			protocol::SerializeType(pBuffer, &inven_size);
			protocol::SerializeType(pBuffer, &temp_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
