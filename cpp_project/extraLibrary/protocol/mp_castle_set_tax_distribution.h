#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_castle_set_tax_distribution_cs : public BasePacket 	// 세금 분배 방식 변경
	{
	public:
		int64_t nuid{};
	public:
		mpe_siege_castle_type castle_type{};	// 세율 변경 성 type
	public:
		mpe_castle_tax_distribution tax_distribution{};	// 분배방식

	public:
		mp_castle_set_tax_distribution_cs() : BasePacket(mpe_cmd::castle_set_tax_distribution_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nuid);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeEnum(pBuffer, &tax_distribution);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_castle_set_tax_distribution_sc : public BasePacket 	// 세금 분배 방식 변경
	{

	public:
		mp_castle_set_tax_distribution_sc() : BasePacket(mpe_cmd::castle_set_tax_distribution_sc)
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
