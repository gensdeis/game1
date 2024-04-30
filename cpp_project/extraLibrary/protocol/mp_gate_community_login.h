#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_community_login_cs : public BasePacket 	// 채팅 서버 로그인(채팅서버 소켓 연결되고 한번만)
	{
	public:
		int64_t cuid{};

	public:
		mp_gate_community_login_cs() : BasePacket(mpe_cmd::gate_community_login_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_community_login_sc : public BasePacket 	// 채팅 서버 로그인(채팅서버 소켓 연결되고 한번만)
	{

	public:
		mp_gate_community_login_sc() : BasePacket(mpe_cmd::gate_community_login_sc)
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
