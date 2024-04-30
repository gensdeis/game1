#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_castle_town_arsenal_build_cs : public RpcPacket 	// 공성 무기 제작 등록(하달)
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int32_t town_id{};
	public:
		int32_t build_id{};

	public:
		mrpc_castle_town_arsenal_build_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_arsenal_build_cs, tag)
		{
		}
		mrpc_castle_town_arsenal_build_cs() : RpcPacket(mpe_rpc_cmd::castle_town_arsenal_build_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeType(pBuffer, &build_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_castle_town_arsenal_build_sc : public RpcPacket 	// 공성 무기 제작 등록(하달)
	{
	public:
		int64_t key{};
	public:
		int32_t town_id{};
	public:
		int32_t build_id{};
	public:
		int32_t need_build_value{};

	public:
		mrpc_castle_town_arsenal_build_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_arsenal_build_sc, tag)
		{
		}
		mrpc_castle_town_arsenal_build_sc() : RpcPacket(mpe_rpc_cmd::castle_town_arsenal_build_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeType(pBuffer, &build_id);
			protocol::SerializeType(pBuffer, &need_build_value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
