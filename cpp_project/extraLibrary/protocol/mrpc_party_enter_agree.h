#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_party_member_base.h"
#include "struct/mps_party_base.h"
#include "struct/mps_party_member_base.h"

namespace mir3d
{
	class mrpc_party_enter_agree_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t target_cuid{};
	public:
		int64_t puid{};

	public:
		mrpc_party_enter_agree_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_enter_agree_cs, tag)
		{
		}
		mrpc_party_enter_agree_cs() : RpcPacket(mpe_rpc_cmd::party_enter_agree_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &puid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_party_enter_agree_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t puid{};
	private:
		bool flag_target_member = false;
		mps_party_member_base target_member;
		mps_party_member_base* p_target_member = nullptr;
	public:
		bool has_target_member() const
		{
			return flag_target_member;
		}
		mps_party_member_base* alloc_target_member()
		{
			flag_target_member = true;
			return &target_member;
		}
		const mps_party_member_base* get_target_member() const
		{
			if (true == flag_target_member)
			{
				if (nullptr == p_target_member)
				{
					return &target_member;
				}
				return p_target_member;
			}
			return nullptr;
		}
		void set_target_member(mps_party_member_base* in_target_member)
		{
			if (nullptr == p_target_member)
			{
				p_target_member = in_target_member;
				flag_target_member = true;
			}
		}
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
		std::vector<mps_party_member_base> member{};

	public:
		mrpc_party_enter_agree_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_enter_agree_sc, tag)
		{
		}
		mrpc_party_enter_agree_sc() : RpcPacket(mpe_rpc_cmd::party_enter_agree_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &flag_target_member);
			if (true == flag_target_member)
			{
				if (nullptr != p_target_member)
					protocol::SerializeType(pBuffer, p_target_member);
				else
					protocol::SerializeType(pBuffer, &target_member);
			}
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &member);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
