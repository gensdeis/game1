#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_request_member.h"

namespace mir3d
{
	class mrpc_guild_alert_join_request_cs : public RpcPacket 	// // 가입요청 알림 패킷
	{

	public:
		mrpc_guild_alert_join_request_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_join_request_cs, tag)
		{
		}
		mrpc_guild_alert_join_request_cs() : RpcPacket(mpe_rpc_cmd::guild_alert_join_request_cs)
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

	class mrpc_guild_alert_join_request_sc : public RpcPacket 	// // 가입요청 알림 패킷
	{
	public:
		std::vector<int64_t> list_member_having_permission{};	// // 가입처리 가능한 멤버리스트
	private:
		bool flag_info = false;
		mps_guild_request_member info;	// // 가입요청한 유저 정보
		mps_guild_request_member* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_guild_request_member* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_guild_request_member* get_info() const
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
		void set_info(mps_guild_request_member* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_guild_alert_join_request_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_join_request_sc, tag)
		{
		}
		mrpc_guild_alert_join_request_sc() : RpcPacket(mpe_rpc_cmd::guild_alert_join_request_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_member_having_permission);
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

}
