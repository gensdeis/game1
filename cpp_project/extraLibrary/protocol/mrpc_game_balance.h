#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_zone_info.h"
#include "struct/mps_zone_info.h"
#include "struct/mrpcs_config_address.h"

namespace mir3d
{
	class mrpc_game_balance_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	private:
		bool flag_zone = false;
		mps_zone_info zone;
		mps_zone_info* p_zone = nullptr;
	public:
		bool has_zone() const
		{
			return flag_zone;
		}
		mps_zone_info* alloc_zone()
		{
			flag_zone = true;
			return &zone;
		}
		const mps_zone_info* get_zone() const
		{
			if (true == flag_zone)
			{
				if (nullptr == p_zone)
				{
					return &zone;
				}
				return p_zone;
			}
			return nullptr;
		}
		void set_zone(mps_zone_info* in_zone)
		{
			if (nullptr == p_zone)
			{
				p_zone = in_zone;
				flag_zone = true;
			}
		}
	public:
		uint16_t channel_id{};
	public:
		uint8_t is_force{};	// (0:체크)(1:무조건)(2:채널이동)
	public:
		uint8_t is_first_redirect{};	// game_login:redirect_reqeust 에서 맵못찾을때
	public:
		int32_t server_index{};
	public:
		int64_t guid{};
	public:
		mrpce_server_type server_type{};	// game or indun
	public:
		int32_t gid{};
	public:
		int64_t uid{};
	public:
		bool source_redirect{};
	public:
		mrpce_server_type source_server_type{};
	public:
		int32_t source_server_index{};

	public:
		mrpc_game_balance_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::game_balance_cs, tag)
		{
		}
		mrpc_game_balance_cs() : RpcPacket(mpe_rpc_cmd::game_balance_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &flag_zone);
			if (true == flag_zone)
			{
				if (nullptr != p_zone)
					protocol::SerializeType(pBuffer, p_zone);
				else
					protocol::SerializeType(pBuffer, &zone);
			}
			protocol::SerializeType(pBuffer, &channel_id);
			protocol::SerializeType(pBuffer, &is_force);
			protocol::SerializeType(pBuffer, &is_first_redirect);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &source_redirect);
			protocol::SerializeEnum(pBuffer, &source_server_type);
			protocol::SerializeType(pBuffer, &source_server_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_game_balance_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_zone = false;
		mps_zone_info zone;
		mps_zone_info* p_zone = nullptr;
	public:
		bool has_zone() const
		{
			return flag_zone;
		}
		mps_zone_info* alloc_zone()
		{
			flag_zone = true;
			return &zone;
		}
		const mps_zone_info* get_zone() const
		{
			if (true == flag_zone)
			{
				if (nullptr == p_zone)
				{
					return &zone;
				}
				return p_zone;
			}
			return nullptr;
		}
		void set_zone(mps_zone_info* in_zone)
		{
			if (nullptr == p_zone)
			{
				p_zone = in_zone;
				flag_zone = true;
			}
		}
	public:
		mrpce_server_type dest_server_type{};
	public:
		int32_t dest_server_index{};
	public:
		int64_t channel_uid{};
	public:
		uint8_t is_first_redirect{};	// game_login:redirect_reqeust 에서 맵못찾을때
	private:
		bool flag_world_game_info = false;
		mrpcs_config_address world_game_info;
		mrpcs_config_address* p_world_game_info = nullptr;
	public:
		bool has_world_game_info() const
		{
			return flag_world_game_info;
		}
		mrpcs_config_address* alloc_world_game_info()
		{
			flag_world_game_info = true;
			return &world_game_info;
		}
		const mrpcs_config_address* get_world_game_info() const
		{
			if (true == flag_world_game_info)
			{
				if (nullptr == p_world_game_info)
				{
					return &world_game_info;
				}
				return p_world_game_info;
			}
			return nullptr;
		}
		void set_world_game_info(mrpcs_config_address* in_world_game_info)
		{
			if (nullptr == p_world_game_info)
			{
				p_world_game_info = in_world_game_info;
				flag_world_game_info = true;
			}
		}
	public:
		int64_t uid{};

	public:
		mrpc_game_balance_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::game_balance_sc, tag)
		{
		}
		mrpc_game_balance_sc() : RpcPacket(mpe_rpc_cmd::game_balance_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_zone);
			if (true == flag_zone)
			{
				if (nullptr != p_zone)
					protocol::SerializeType(pBuffer, p_zone);
				else
					protocol::SerializeType(pBuffer, &zone);
			}
			protocol::SerializeEnum(pBuffer, &dest_server_type);
			protocol::SerializeType(pBuffer, &dest_server_index);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &is_first_redirect);
			protocol::SerializeType(pBuffer, &flag_world_game_info);
			if (true == flag_world_game_info)
			{
				if (nullptr != p_world_game_info)
					protocol::SerializeType(pBuffer, p_world_game_info);
				else
					protocol::SerializeType(pBuffer, &world_game_info);
			}
			protocol::SerializeType(pBuffer, &uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
