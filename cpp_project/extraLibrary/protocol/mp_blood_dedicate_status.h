#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_blood_dedicate_status_info.h"

namespace mir3d
{
	class mp_blood_dedicate_status_cs : public BasePacket 	// 봉혈 현황 UI
	{
	public:
		int32_t fixed_object_id{};	// 봉혈 오브젝트 아이디

	public:
		mp_blood_dedicate_status_cs() : BasePacket(mpe_cmd::blood_dedicate_status_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &fixed_object_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_blood_dedicate_status_sc : public BasePacket 	// 봉혈 현황 UI
	{
	public:
		std::vector<mps_blood_dedicate_status_info> info{};	// 봉혈 현황 정보

	public:
		mp_blood_dedicate_status_sc() : BasePacket(mpe_cmd::blood_dedicate_status_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
