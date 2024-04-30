#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_castle_town_info.h"

namespace mir3d
{
	class mrpc_castle_town_all_info_cs : public RpcPacket 	// 장원 정보
	{

	public:
		mrpc_castle_town_all_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_all_info_cs, tag)
		{
		}
		mrpc_castle_town_all_info_cs() : RpcPacket(mpe_rpc_cmd::castle_town_all_info_cs)
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

	class mrpc_castle_town_all_info_sc : public RpcPacket 	// 장원 정보
	{
	public:
		std::vector<mrpcs_castle_town_info> info{};

	public:
		mrpc_castle_town_all_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_all_info_sc, tag)
		{
		}
		mrpc_castle_town_all_info_sc() : RpcPacket(mpe_rpc_cmd::castle_town_all_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
