#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_party_invite_request_cs : public BasePacket 
	{
	public:
		int64_t cuid{};

	public:
		mp_party_invite_request_cs() : BasePacket(mpe_cmd::party_invite_request_cs)
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

	class mp_party_invite_request_sc : public BasePacket 
	{
	public:
		int64_t puid{};
	public:
		int64_t owner_cuid{};
	public:
		std::string owner_nickname{};
	public:
		int32_t category{};

	public:
		mp_party_invite_request_sc() : BasePacket(mpe_cmd::party_invite_request_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &owner_cuid);
			protocol::SerializeType(pBuffer, &owner_nickname);
			protocol::SerializeType(pBuffer, &category);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
