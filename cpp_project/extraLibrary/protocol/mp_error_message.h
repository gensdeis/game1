#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_error_message_cs : public BasePacket 	// 에러 체크
	{

	public:
		mp_error_message_cs() : BasePacket(mpe_cmd::error_message_cs)
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

	class mp_error_message_sc : public BasePacket 	// 에러 체크
	{
	public:
		mpe_error error{};
	public:
		mpe_cmd cmd{};
	public:
		bool reload{};
	public:
		int64_t param1{};

	public:
		mp_error_message_sc() : BasePacket(mpe_cmd::error_message_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &error);
			protocol::SerializeEnum(pBuffer, &cmd);
			protocol::SerializeType(pBuffer, &reload);
			protocol::SerializeType(pBuffer, &param1);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
