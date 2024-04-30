#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_ally_info.h"

namespace mir3d
{
	class mrpc_guild_ally_request_accept_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};	// "수락캐릭터 cuid"
	public:
		int64_t my_guid{};	// 내 문파 UID
	public:
		int64_t target_guid{};	// 동맹 요청 문파 UID

	public:
		mrpc_guild_ally_request_accept_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_ally_request_accept_cs, tag)
		{
		}
		mrpc_guild_ally_request_accept_cs() : RpcPacket(mpe_rpc_cmd::guild_ally_request_accept_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &my_guid);
			protocol::SerializeType(pBuffer, &target_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_ally_request_accept_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_ally = false;
		mps_guild_ally_info ally;	// 동맹길드정보
		mps_guild_ally_info* p_ally = nullptr;
	public:
		bool has_ally() const
		{
			return flag_ally;
		}
		mps_guild_ally_info* alloc_ally()
		{
			flag_ally = true;
			return &ally;
		}
		const mps_guild_ally_info* get_ally() const
		{
			if (true == flag_ally)
			{
				if (nullptr == p_ally)
				{
					return &ally;
				}
				return p_ally;
			}
			return nullptr;
		}
		void set_ally(mps_guild_ally_info* in_ally)
		{
			if (nullptr == p_ally)
			{
				p_ally = in_ally;
				flag_ally = true;
			}
		}

	public:
		mrpc_guild_ally_request_accept_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_ally_request_accept_sc, tag)
		{
		}
		mrpc_guild_ally_request_accept_sc() : RpcPacket(mpe_rpc_cmd::guild_ally_request_accept_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_ally);
			if (true == flag_ally)
			{
				if (nullptr != p_ally)
					protocol::SerializeType(pBuffer, p_ally);
				else
					protocol::SerializeType(pBuffer, &ally);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
