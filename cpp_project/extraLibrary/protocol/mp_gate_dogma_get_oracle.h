#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_dogma_get_oracle_cs : public BasePacket 	// oracle 정보 조회
	{
	public:
		std::string player_key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};

	public:
		mp_gate_dogma_get_oracle_cs() : BasePacket(mpe_cmd::gate_dogma_get_oracle_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &player_key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_dogma_get_oracle_sc : public BasePacket 	// oracle 정보 조회
	{
	public:
		int32_t result{};
	public:
		int32_t oracle{};

	public:
		mp_gate_dogma_get_oracle_sc() : BasePacket(mpe_cmd::gate_dogma_get_oracle_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &oracle);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
