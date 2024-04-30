#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_received_mail.h"

namespace mir3d
{
	class mrpc_red_dot_noti_server_cs : public RpcPacket 
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};

	public:
		mrpc_red_dot_noti_server_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::red_dot_noti_server_cs, tag)
		{
		}
		mrpc_red_dot_noti_server_cs() : RpcPacket(mpe_rpc_cmd::red_dot_noti_server_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_red_dot_noti_server_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		std::vector<uint8_t> noti_list{};
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
		mrpc_red_dot_noti_server_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::red_dot_noti_server_sc, tag)
		{
		}
		mrpc_red_dot_noti_server_sc() : RpcPacket(mpe_rpc_cmd::red_dot_noti_server_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &noti_list);
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
