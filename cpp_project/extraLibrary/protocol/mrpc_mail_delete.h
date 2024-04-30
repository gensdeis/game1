#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_mail_delete_cs : public RpcPacket 	// 메일 삭제
	{
	public:
		int64_t key{};
	public:
		int64_t uid{};
	public:
		mpe_mail_type mail_type{};
	public:
		std::vector<int64_t> list_muid{};

	public:
		mrpc_mail_delete_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mail_delete_cs, tag)
		{
		}
		mrpc_mail_delete_cs() : RpcPacket(mpe_rpc_cmd::mail_delete_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeEnum(pBuffer, &mail_type);
			protocol::SerializeType(pBuffer, &list_muid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_mail_delete_sc : public RpcPacket 	// 메일 삭제
	{
	public:
		int64_t key{};

	public:
		mrpc_mail_delete_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mail_delete_sc, tag)
		{
		}
		mrpc_mail_delete_sc() : RpcPacket(mpe_rpc_cmd::mail_delete_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
