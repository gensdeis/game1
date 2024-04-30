#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_session_type_cs : public BasePacket 	// 세션 타입
	{
	public:
		int32_t session_data{};
	public:
		bool is_dummy{};
	public:
		int64_t auid{};

	public:
		mp_session_type_cs() : BasePacket(mpe_cmd::session_type_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &session_data);
			protocol::SerializeType(pBuffer, &is_dummy);
			protocol::SerializeType(pBuffer, &auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_session_type_sc : public BasePacket 	// 세션 타입
	{

	public:
		mp_session_type_sc() : BasePacket(mpe_cmd::session_type_sc)
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
