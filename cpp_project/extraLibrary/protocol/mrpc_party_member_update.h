#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_party_member_base.h"

namespace mir3d
{
	class mrpc_party_member_update_cs : public RpcPacket 
	{

	public:
		mrpc_party_member_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_member_update_cs, tag)
		{
		}
		mrpc_party_member_update_cs() : RpcPacket(mpe_rpc_cmd::party_member_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_party_member_update_sc : public RpcPacket 
	{
	private:
		bool flag_member = false;
		mps_party_member_base member;
		mps_party_member_base* p_member = nullptr;
	public:
		bool has_member() const
		{
			return flag_member;
		}
		mps_party_member_base* alloc_member()
		{
			flag_member = true;
			return &member;
		}
		const mps_party_member_base* get_member() const
		{
			if (true == flag_member)
			{
				if (nullptr == p_member)
				{
					return &member;
				}
				return p_member;
			}
			return nullptr;
		}
		void set_member(mps_party_member_base* in_member)
		{
			if (nullptr == p_member)
			{
				p_member = in_member;
				flag_member = true;
			}
		}

	public:
		mrpc_party_member_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_member_update_sc, tag)
		{
		}
		mrpc_party_member_update_sc() : RpcPacket(mpe_rpc_cmd::party_member_update_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_member);
			if (true == flag_member)
			{
				if (nullptr != p_member)
					protocol::SerializeType(pBuffer, p_member);
				else
					protocol::SerializeType(pBuffer, &member);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
