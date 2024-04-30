#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_season_mandala_info.h"

namespace mir3d
{
	class mrpc_season_mandala_info_update_cs : public RpcPacket 	// 시즌 만다라 시즌정보 갱신
	{
	private:
		bool flag_info = false;
		mps_season_mandala_info info;	// 시즌 정보
		mps_season_mandala_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_season_mandala_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_season_mandala_info* get_info() const
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
		void set_info(mps_season_mandala_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_season_mandala_info_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::season_mandala_info_update_cs, tag)
		{
		}
		mrpc_season_mandala_info_update_cs() : RpcPacket(mpe_rpc_cmd::season_mandala_info_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_season_mandala_info_update_sc : public RpcPacket 	// 시즌 만다라 시즌정보 갱신
	{
	public:
		int32_t map_tag{};	// zone 스레드 인덱스
	public:
		int32_t season_id{};	// 시즌 아이디(close상태면 종료된 시즌 아이디, open이면 진행중 시즌아이디)
	public:
		mpe_season_mandala_state state{};	// 시즌 오픈 상태(1:진행중2:종료)

	public:
		mrpc_season_mandala_info_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::season_mandala_info_update_sc, tag)
		{
		}
		mrpc_season_mandala_info_update_sc() : RpcPacket(mpe_rpc_cmd::season_mandala_info_update_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &map_tag);
			protocol::SerializeType(pBuffer, &season_id);
			protocol::SerializeEnum(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
