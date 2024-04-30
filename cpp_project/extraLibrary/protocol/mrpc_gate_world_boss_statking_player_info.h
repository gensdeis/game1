#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_boss_governance_server_info_personal_list.h"

namespace mir3d
{
	class mrpc_gate_world_boss_statking_player_info_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};	// 캐릭터 아이디
	public:
		mpe_governance_contents_type cotents_type{};	// 거버넌스 콘텐츠 타입(0:없음 1:보스 2:비곡점령전 3:공성전)
	public:
		std::string user_address{};	// 유저 월렛 주소

	public:
		mrpc_gate_world_boss_statking_player_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_world_boss_statking_player_info_cs, tag)
		{
		}
		mrpc_gate_world_boss_statking_player_info_cs() : RpcPacket(mpe_rpc_cmd::gate_world_boss_statking_player_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &cotents_type);
			protocol::SerializeType(pBuffer, &user_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_world_boss_statking_player_info_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_info = false;
		mps_boss_governance_server_info_personal_list info;	// 유저가 스테이킹한 서버들 목록
		mps_boss_governance_server_info_personal_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_boss_governance_server_info_personal_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_boss_governance_server_info_personal_list* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mps_boss_governance_server_info_personal_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		mpe_governance_contents_type cotents_type{};	// 거버넌스 콘텐츠 타입(0:없음 1:보스 2:비곡점령전 3:공성전)

	public:
		mrpc_gate_world_boss_statking_player_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_world_boss_statking_player_info_sc, tag)
		{
		}
		mrpc_gate_world_boss_statking_player_info_sc() : RpcPacket(mpe_rpc_cmd::gate_world_boss_statking_player_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeEnum(pBuffer, &cotents_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
