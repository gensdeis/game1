#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_skill_list_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};

	public:
		mrpc_guild_skill_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_skill_list_cs, tag)
		{
		}
		mrpc_guild_skill_list_cs() : RpcPacket(mpe_rpc_cmd::guild_skill_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_skill_list_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		std::vector<int32_t> list_guild_skill{};

	public:
		mrpc_guild_skill_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_skill_list_sc, tag)
		{
		}
		mrpc_guild_skill_list_sc() : RpcPacket(mpe_rpc_cmd::guild_skill_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &list_guild_skill);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
