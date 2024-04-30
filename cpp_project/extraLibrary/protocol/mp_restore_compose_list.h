#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_restore_compose.h"

namespace mir3d
{
	class mp_restore_compose_list_cs : public BasePacket 	// 합성 실패 이력 조회 (일괄조회)
	{

	public:
		mp_restore_compose_list_cs() : BasePacket(mpe_cmd::restore_compose_list_cs)
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

	class mp_restore_compose_list_sc : public BasePacket 	// 합성 실패 이력 조회 (일괄조회)
	{
	public:
		std::vector<mps_restore_compose> list{};	// 복구 정보 리스트 (화신/영물 타입별 grade와 복구여부)

	public:
		mp_restore_compose_list_sc() : BasePacket(mpe_cmd::restore_compose_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
