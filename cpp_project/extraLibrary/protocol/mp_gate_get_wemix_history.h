#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_wemix_shop_history.h"

namespace mir3d
{
	class mp_gate_get_wemix_history_cs : public BasePacket 	// 위믹스 상점 내역 조회
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};

	public:
		mp_gate_get_wemix_history_cs() : BasePacket(mpe_cmd::gate_get_wemix_history_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_get_wemix_history_sc : public BasePacket 	// 위믹스 상점 내역 조회
	{
	public:
		std::vector<mps_wemix_shop_history> shop_history{};

	public:
		mp_gate_get_wemix_history_sc() : BasePacket(mpe_cmd::gate_get_wemix_history_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &shop_history);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
