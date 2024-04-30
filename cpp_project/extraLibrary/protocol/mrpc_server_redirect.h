#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_db_buff.h"
#include "struct/mps_zone_info.h"

namespace mir3d
{
	class mrpc_server_redirect_cs : public RpcPacket 
	{
	public:
		std::string from_tag{};
	public:
		int64_t channel_uid{};
	public:
		int64_t uid{};
	public:
		std::string username{};
	public:
		int64_t cuid{};
	public:
		mpe_redirect_type redirect_type{};
	public:
		uint8_t indun_prepare_state{};	// 서버 이동 시 상태 유지용 정보
	public:
		int32_t indun_id{};	// 서버 이동 시 상태 유지용 정보
	public:
		int32_t login_time{};
	public:
		std::vector<mps_db_buff> buff_list{};	// 서버 이동 시 옮길 버프정보
	public:
		int32_t special_move_gage{};	// 서버 이동 시 옮길 필살기게이지
	private:
		bool flag_zone = false;
		mps_zone_info zone;	// 서버 이동해서 갈 zone 정보
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
		int32_t gid{};	// 해당 캐릭터의 서버 gid
	public:
		int64_t access_token{};

	public:
		mrpc_server_redirect_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_redirect_cs, tag)
		{
		}
		mrpc_server_redirect_cs() : RpcPacket(mpe_rpc_cmd::server_redirect_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &from_tag);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &redirect_type);
			protocol::SerializeType(pBuffer, &indun_prepare_state);
			protocol::SerializeType(pBuffer, &indun_id);
			protocol::SerializeType(pBuffer, &login_time);
			protocol::SerializeType(pBuffer, &buff_list);
			protocol::SerializeType(pBuffer, &special_move_gage);
			protocol::SerializeType(pBuffer, &flag_zone);
			if (true == flag_zone)
			{
				if (nullptr != p_zone)
					protocol::SerializeType(pBuffer, p_zone);
				else
					protocol::SerializeType(pBuffer, &zone);
			}
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &access_token);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_server_redirect_sc : public RpcPacket 
	{
	public:
		mpe_error error{};
	public:
		int64_t channel_uid{};
	public:
		int64_t uid{};
	public:
		int64_t auth_key{};
	public:
		std::string ip{};
	public:
		int32_t port{};

	public:
		mrpc_server_redirect_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_redirect_sc, tag)
		{
		}
		mrpc_server_redirect_sc() : RpcPacket(mpe_rpc_cmd::server_redirect_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &error);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &auth_key);
			protocol::SerializeType(pBuffer, &ip);
			protocol::SerializeType(pBuffer, &port);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
