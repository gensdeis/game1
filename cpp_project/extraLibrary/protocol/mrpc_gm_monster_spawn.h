#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_vector.h"

namespace mir3d
{
	class mrpc_gm_monster_spawn_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t map_id{};
	public:
		int32_t monster_id{};
	public:
		int32_t count{};
	public:
		bool dummy{};
	private:
		bool flag_pos = false;
		mps_vector pos;
		mps_vector* p_pos = nullptr;
	public:
		bool has_pos() const
		{
			return flag_pos;
		}
		mps_vector* alloc_pos()
		{
			flag_pos = true;
			return &pos;
		}
		const mps_vector* get_pos() const
		{
			if (true == flag_pos)
			{
				if (nullptr == p_pos)
				{
					return &pos;
				}
				return p_pos;
			}
			return nullptr;
		}
		void set_pos(mps_vector* in_pos)
		{
			if (nullptr == p_pos)
			{
				p_pos = in_pos;
				flag_pos = true;
			}
		}
	public:
		int32_t range{};

	public:
		mrpc_gm_monster_spawn_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_monster_spawn_cs, tag)
		{
		}
		mrpc_gm_monster_spawn_cs() : RpcPacket(mpe_rpc_cmd::gm_monster_spawn_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &map_id);
			protocol::SerializeType(pBuffer, &monster_id);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &dummy);
			protocol::SerializeType(pBuffer, &flag_pos);
			if (true == flag_pos)
			{
				if (nullptr != p_pos)
					protocol::SerializeType(pBuffer, p_pos);
				else
					protocol::SerializeType(pBuffer, &pos);
			}
			protocol::SerializeType(pBuffer, &range);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_monster_spawn_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_gm_monster_spawn_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_monster_spawn_sc, tag)
		{
		}
		mrpc_gm_monster_spawn_sc() : RpcPacket(mpe_rpc_cmd::gm_monster_spawn_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
