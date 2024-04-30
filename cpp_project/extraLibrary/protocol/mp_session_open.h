#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_session_open_cs : public BasePacket 	// 세션 체크 응답
	{

	public:
		mp_session_open_cs() : BasePacket(mpe_cmd::session_open_cs)
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

	class mp_session_open_sc : public BasePacket 	// 세션 체크 응답
	{
	public:
		mpe_error result{};
	public:
		int64_t session_id{};
	public:
		std::string session_uuid{};

	public:
		mp_session_open_sc() : BasePacket(mpe_cmd::session_open_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &session_id);
			protocol::SerializeType(pBuffer, &session_uuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
