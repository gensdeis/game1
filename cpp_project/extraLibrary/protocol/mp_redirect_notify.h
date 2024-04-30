#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_redirect_notify_cs : public BasePacket 
	{

	public:
		mp_redirect_notify_cs() : BasePacket(mpe_cmd::redirect_notify_cs)
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

	class mp_redirect_notify_sc : public BasePacket 
	{
	public:
		std::string ip{};
	public:
		int32_t port{};
	public:
		int64_t indun_uid{};	// indun uid
	public:
		int64_t uid{};	// account uid
	public:
		int64_t auth_key{};

	public:
		mp_redirect_notify_sc() : BasePacket(mpe_cmd::redirect_notify_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &ip);
			protocol::SerializeType(pBuffer, &port);
			protocol::SerializeType(pBuffer, &indun_uid);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &auth_key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
