#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_temp_reflection.h"
#include "struct/mps_obtain_reflection.h"

namespace mir3d
{
	class mp_temp_reflection_get_cs : public BasePacket 
	{

	public:
		mp_temp_reflection_get_cs() : BasePacket(mpe_cmd::temp_reflection_get_cs)
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

	class mp_temp_reflection_get_sc : public BasePacket 
	{
	public:
		std::vector<mps_temp_reflection> list_temp{};	// 보관함 목록
	public:
		std::vector<mps_obtain_reflection> list_reflection{};	// 획득 목록

	public:
		mp_temp_reflection_get_sc() : BasePacket(mpe_cmd::temp_reflection_get_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_temp);
			protocol::SerializeType(pBuffer, &list_reflection);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
