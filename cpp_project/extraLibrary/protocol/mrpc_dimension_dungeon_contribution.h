#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_dimension_dungeon_contribution.h"

namespace mir3d
{
	class mrpc_dimension_dungeon_contribution_cs : public RpcPacket 	// 차원비경 기여도랭킹 정보요청
	{
	public:
		int32_t gid{};	// 서버 아이디

	public:
		mrpc_dimension_dungeon_contribution_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dimension_dungeon_contribution_cs, tag)
		{
		}
		mrpc_dimension_dungeon_contribution_cs() : RpcPacket(mpe_rpc_cmd::dimension_dungeon_contribution_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_dimension_dungeon_contribution_sc : public RpcPacket 	// 차원비경 기여도랭킹 정보요청
	{
	private:
		bool flag_info = false;
		mrpcs_dimension_dungeon_contribution info;	// 기여도랭킹 정보
		mrpcs_dimension_dungeon_contribution* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_dimension_dungeon_contribution* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_dimension_dungeon_contribution* get_info() const
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
		void set_info(mrpcs_dimension_dungeon_contribution* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_dimension_dungeon_contribution_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dimension_dungeon_contribution_sc, tag)
		{
		}
		mrpc_dimension_dungeon_contribution_sc() : RpcPacket(mpe_rpc_cmd::dimension_dungeon_contribution_sc)
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
