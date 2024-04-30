#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_castle_set_tax_rate_cs : public BasePacket 	// 세율 변경
	{
	public:
		int64_t nuid{};
	public:
		mpe_siege_castle_type castle_type{};	// 세율 변경 성 type
	public:
		int32_t tax_rate{};	// 변경 세율

	public:
		mp_castle_set_tax_rate_cs() : BasePacket(mpe_cmd::castle_set_tax_rate_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nuid);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &tax_rate);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_castle_set_tax_rate_sc : public BasePacket 	// 세율 변경
	{

	public:
		mp_castle_set_tax_rate_sc() : BasePacket(mpe_cmd::castle_set_tax_rate_sc)
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

}
