#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_zone_info.h"

namespace mir3d
{
	class mrpc_gm_create_bot_cs : public RpcPacket 
	{
	public:
		int32_t count{};
	private:
		bool flag_current_position = false;
		mps_zone_info current_position;
		mps_zone_info* p_current_position = nullptr;
	public:
		bool has_current_position() const
		{
			return flag_current_position;
		}
		mps_zone_info* alloc_current_position()
		{
			flag_current_position = true;
			return &current_position;
		}
		const mps_zone_info* get_current_position() const
		{
			if (true == flag_current_position)
			{
				if (nullptr == p_current_position)
				{
					return &current_position;
				}
				return p_current_position;
			}
			return nullptr;
		}
		void set_current_position(mps_zone_info* in_current_position)
		{
			if (nullptr == p_current_position)
			{
				p_current_position = in_current_position;
				flag_current_position = true;
			}
		}
	public:
		int64_t channel_uid{};
	public:
		std::string game_ip{};
	public:
		int32_t game_port{};

	public:
		mrpc_gm_create_bot_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_create_bot_cs, tag)
		{
		}
		mrpc_gm_create_bot_cs() : RpcPacket(mpe_rpc_cmd::gm_create_bot_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &flag_current_position);
			if (true == flag_current_position)
			{
				if (nullptr != p_current_position)
					protocol::SerializeType(pBuffer, p_current_position);
				else
					protocol::SerializeType(pBuffer, &current_position);
			}
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &game_ip);
			protocol::SerializeType(pBuffer, &game_port);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_create_bot_sc : public RpcPacket 
	{

	public:
		mrpc_gm_create_bot_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_create_bot_sc, tag)
		{
		}
		mrpc_gm_create_bot_sc() : RpcPacket(mpe_rpc_cmd::gm_create_bot_sc)
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
