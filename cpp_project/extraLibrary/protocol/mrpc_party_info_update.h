#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_party_base.h"
#include "struct/mps_party_member_base.h"

namespace mir3d
{
	class mrpc_party_info_update_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t puid{};
	public:
		int64_t cuid{};
	public:
		std::string nickname{};

	public:
		mrpc_party_info_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_info_update_cs, tag)
		{
		}
		mrpc_party_info_update_cs() : RpcPacket(mpe_rpc_cmd::party_info_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_party_info_update_sc : public RpcPacket 
	{
	public:
		int64_t key{};	// "이 응답 사용안함. mrpc_party_info_sc로 응답함"
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
		std::vector<mps_party_member_base> list_member{};

	public:
		mrpc_party_info_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_info_update_sc, tag)
		{
		}
		mrpc_party_info_update_sc() : RpcPacket(mpe_rpc_cmd::party_info_update_sc)
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
			protocol::SerializeType(pBuffer, &list_member);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
