#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_party_base.h"
#include "struct/mps_party_base.h"
#include "struct/mps_party_member_base.h"

namespace mir3d
{
	class mrpc_party_create_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_info = false;
		mps_party_base info;
		mps_party_base* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_party_base* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_party_base* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mps_party_base* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		int64_t cuid{};

	public:
		mrpc_party_create_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_create_cs, tag)
		{
		}
		mrpc_party_create_cs() : RpcPacket(mpe_rpc_cmd::party_create_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_party_create_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_info = false;
		mps_party_base info;
		mps_party_base* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_party_base* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_party_base* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mps_party_base* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
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
		mrpc_party_create_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_create_sc, tag)
		{
		}
		mrpc_party_create_sc() : RpcPacket(mpe_rpc_cmd::party_create_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
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
