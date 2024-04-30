#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_global_governance_context.h"

namespace mir3d
{
	class mrpc_global_party_governance_unstaking_cs : public RpcPacket 
	{
	private:
		bool flag_info = false;
		mrpcs_global_governance_context info;
		mrpcs_global_governance_context* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_global_governance_context* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_global_governance_context* get_info() const
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
		void set_info(mrpcs_global_governance_context* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_global_party_governance_unstaking_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_party_governance_unstaking_cs, tag)
		{
		}
		mrpc_global_party_governance_unstaking_cs() : RpcPacket(mpe_rpc_cmd::global_party_governance_unstaking_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_global_party_governance_unstaking_sc : public RpcPacket 
	{
	public:
		int64_t key{};	// 세션 아이디
	public:
		int64_t auid{};	// 계정 아이디
	public:
		int64_t cuid{};	// 캐릭터 아이디
	public:
		std::string amount{};	// 스테이킹량
	public:
		int32_t gid{};	// 서버 아이디
	public:
		mpe_governance_contents_type contents_type{};	// 거버넌스 콘텐츠 타입(0:없음 1:보스 2:비곡점령전 3:공성전 4:파티)

	public:
		mrpc_global_party_governance_unstaking_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_party_governance_unstaking_sc, tag)
		{
		}
		mrpc_global_party_governance_unstaking_sc() : RpcPacket(mpe_rpc_cmd::global_party_governance_unstaking_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &amount);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeEnum(pBuffer, &contents_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
