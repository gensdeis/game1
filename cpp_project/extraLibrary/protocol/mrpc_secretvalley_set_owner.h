#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_secretvalley_set_owner_cs : public RpcPacket 
	{
	public:
		uint8_t valley_type{};
	public:
		mpe_secretvalley_state state{};
	public:
		int64_t owner_guild_uid{};
	public:
		int64_t destory_time{};
	public:
		int64_t mvp_cuid{};
	public:
		std::string mvp_nickname{};

	public:
		mrpc_secretvalley_set_owner_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::secretvalley_set_owner_cs, tag)
		{
		}
		mrpc_secretvalley_set_owner_cs() : RpcPacket(mpe_rpc_cmd::secretvalley_set_owner_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &valley_type);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &owner_guild_uid);
			protocol::SerializeType(pBuffer, &destory_time);
			protocol::SerializeType(pBuffer, &mvp_cuid);
			protocol::SerializeType(pBuffer, &mvp_nickname);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_secretvalley_set_owner_sc : public RpcPacket 
	{

	public:
		mrpc_secretvalley_set_owner_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::secretvalley_set_owner_sc, tag)
		{
		}
		mrpc_secretvalley_set_owner_sc() : RpcPacket(mpe_rpc_cmd::secretvalley_set_owner_sc)
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

}
