#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_get_contract_address_cs : public BasePacket 	// contract server 정보 요청ㅇ
	{

	public:
		mp_get_contract_address_cs() : BasePacket(mpe_cmd::get_contract_address_cs)
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

	class mp_get_contract_address_sc : public BasePacket 	// contract server 정보 요청ㅇ
	{
	public:
		std::string conteact_address{};

	public:
		mp_get_contract_address_sc() : BasePacket(mpe_cmd::get_contract_address_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &conteact_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
