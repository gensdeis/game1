#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_member.h"

namespace mir3d
{
	class mrpc_guild_member_daily_reset_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		mrpce_guild_reset_type reset_type{};

	public:
		mrpc_guild_member_daily_reset_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_member_daily_reset_cs, tag)
		{
		}
		mrpc_guild_member_daily_reset_cs() : RpcPacket(mpe_rpc_cmd::guild_member_daily_reset_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeEnum(pBuffer, &reset_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_member_daily_reset_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		mpe_error result{};
	private:
		bool flag_my_info = false;
		mps_guild_member my_info;
		mps_guild_member* p_my_info = nullptr;
	public:
		bool has_my_info() const
		{
			return flag_my_info;
		}
		mps_guild_member* alloc_my_info()
		{
			flag_my_info = true;
			return &my_info;
		}
		const mps_guild_member* get_my_info() const
		{
			if (true == flag_my_info)
			{
				if (nullptr == p_my_info)
				{
					return &my_info;
				}
				return p_my_info;
			}
			return nullptr;
		}
		void set_my_info(mps_guild_member* in_my_info)
		{
			if (nullptr == p_my_info)
			{
				p_my_info = in_my_info;
				flag_my_info = true;
			}
		}

	public:
		mrpc_guild_member_daily_reset_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_member_daily_reset_sc, tag)
		{
		}
		mrpc_guild_member_daily_reset_sc() : RpcPacket(mpe_rpc_cmd::guild_member_daily_reset_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &flag_my_info);
			if (true == flag_my_info)
			{
				if (nullptr != p_my_info)
					protocol::SerializeType(pBuffer, p_my_info);
				else
					protocol::SerializeType(pBuffer, &my_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
