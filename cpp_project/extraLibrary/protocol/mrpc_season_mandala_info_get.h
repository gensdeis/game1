#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_season_mandala_info.h"

namespace mir3d
{
	class mrpc_season_mandala_info_get_cs : public RpcPacket 	// 시즌 만다라 시즌정보 요청
	{
	public:
		mrpce_server_type server_type{};	// 패킷을 송신한 서버 타입

	public:
		mrpc_season_mandala_info_get_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::season_mandala_info_get_cs, tag)
		{
		}
		mrpc_season_mandala_info_get_cs() : RpcPacket(mpe_rpc_cmd::season_mandala_info_get_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &server_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_season_mandala_info_get_sc : public RpcPacket 	// 시즌 만다라 시즌정보 요청
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
		mrpc_season_mandala_info_get_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::season_mandala_info_get_sc, tag)
		{
		}
		mrpc_season_mandala_info_get_sc() : RpcPacket(mpe_rpc_cmd::season_mandala_info_get_sc)
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

}
