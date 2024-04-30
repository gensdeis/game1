#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_mail_open_cs : public RpcPacket 	// 메일 상태 변경
	{
	public:
		int64_t key{};
	public:
		int64_t uid{};
	public:
		mpe_mail_type mail_type{};
	public:
		int64_t muid{};
	public:
		mpe_mail_state state{};

	public:
		mrpc_mail_open_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mail_open_cs, tag)
		{
		}
		mrpc_mail_open_cs() : RpcPacket(mpe_rpc_cmd::mail_open_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeEnum(pBuffer, &mail_type);
			protocol::SerializeType(pBuffer, &muid);
			protocol::SerializeEnum(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_mail_open_sc : public RpcPacket 	// 메일 상태 변경
	{
	public:
		int64_t key{};
	public:
		int64_t muid{};

	public:
		mrpc_mail_open_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mail_open_sc, tag)
		{
		}
		mrpc_mail_open_sc() : RpcPacket(mpe_rpc_cmd::mail_open_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &muid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
