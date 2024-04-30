#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_mail.h"
#include "struct/mps_received_mail.h"

namespace mir3d
{
	class mrpc_gate_mail_list_cs : public RpcPacket 	// 메일 목록 가져오기
	{
	public:
		int64_t key{};
	public:
		int64_t uid{};
	public:
		mpe_mail_type mail_type{};

	public:
		mrpc_gate_mail_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_mail_list_cs, tag)
		{
		}
		mrpc_gate_mail_list_cs() : RpcPacket(mpe_rpc_cmd::gate_mail_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeEnum(pBuffer, &mail_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_mail_list_sc : public RpcPacket 	// 메일 목록 가져오기
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_mail> list_mail{};
	public:
		mpe_mail_type mail_type{};
	private:
		bool flag_mail = false;
		mps_received_mail mail;
		mps_received_mail* p_mail = nullptr;
	public:
		bool has_mail() const
		{
			return flag_mail;
		}
		mps_received_mail* alloc_mail()
		{
			flag_mail = true;
			return &mail;
		}
		const mps_received_mail* get_mail() const
		{
			if (true == flag_mail)
			{
				if (nullptr == p_mail)
				{
					return &mail;
				}
				return p_mail;
			}
			return nullptr;
		}
		void set_mail(mps_received_mail* in_mail)
		{
			if (nullptr == p_mail)
			{
				p_mail = in_mail;
				flag_mail = true;
			}
		}

	public:
		mrpc_gate_mail_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_mail_list_sc, tag)
		{
		}
		mrpc_gate_mail_list_sc() : RpcPacket(mpe_rpc_cmd::gate_mail_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &list_mail);
			protocol::SerializeEnum(pBuffer, &mail_type);
			protocol::SerializeType(pBuffer, &flag_mail);
			if (true == flag_mail)
			{
				if (nullptr != p_mail)
					protocol::SerializeType(pBuffer, p_mail);
				else
					protocol::SerializeType(pBuffer, &mail);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
