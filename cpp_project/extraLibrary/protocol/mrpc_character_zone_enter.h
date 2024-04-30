#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_vector.h"

namespace mir3d
{
	class mrpc_character_zone_enter_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		uint16_t server_index{};
	public:
		mrpce_server_type server_type{};
	public:
		int64_t auid{};
	public:
		int32_t zone_id{};
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
		uint16_t channel_id{};
	public:
		uint8_t team_index{};
	public:
		int64_t channel_uid{};
	public:
		uint8_t expert_level{};

	public:
		mrpc_character_zone_enter_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::character_zone_enter_cs, tag)
		{
		}
		mrpc_character_zone_enter_cs() : RpcPacket(mpe_rpc_cmd::character_zone_enter_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &flag_pos);
			if (true == flag_pos)
			{
				if (nullptr != p_pos)
					protocol::SerializeType(pBuffer, p_pos);
				else
					protocol::SerializeType(pBuffer, &pos);
			}
			protocol::SerializeType(pBuffer, &channel_id);
			protocol::SerializeType(pBuffer, &team_index);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_character_zone_enter_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};

	public:
		mrpc_character_zone_enter_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::character_zone_enter_sc, tag)
		{
		}
		mrpc_character_zone_enter_sc() : RpcPacket(mpe_rpc_cmd::character_zone_enter_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
