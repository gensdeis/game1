#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_session_auth_cs : public BasePacket 
	{
	public:
		int64_t session_id{};
	public:
		std::string session_uuid{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int32_t client_seed{};
	public:
		std::string digest{};

	public:
		mp_session_auth_cs() : BasePacket(mpe_cmd::session_auth_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &session_id);
			protocol::SerializeType(pBuffer, &session_uuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &client_seed);
			protocol::SerializeType(pBuffer, &digest);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_session_auth_sc : public BasePacket 
	{
	public:
		mpe_error result{};

	public:
		mp_session_auth_sc() : BasePacket(mpe_cmd::session_auth_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
