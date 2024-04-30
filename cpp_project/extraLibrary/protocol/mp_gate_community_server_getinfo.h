#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_community_server_getinfo_cs : public BasePacket 
	{

	public:
		mp_gate_community_server_getinfo_cs() : BasePacket(mpe_cmd::gate_community_server_getinfo_cs)
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

	class mp_gate_community_server_getinfo_sc : public BasePacket 
	{
	public:
		std::string community_ip{};	// 채팅서버 정보
	public:
		uint16_t community_port{};	// 채팅서버 정보

	public:
		mp_gate_community_server_getinfo_sc() : BasePacket(mpe_cmd::gate_community_server_getinfo_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &community_ip);
			protocol::SerializeType(pBuffer, &community_port);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
