#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_castle_town_info.h"

namespace mir3d
{
	class mrpc_castle_town_owner_update_cs : public RpcPacket 	// 장원 주인 업데이트시 정보 변경
	{

	public:
		mrpc_castle_town_owner_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_owner_update_cs, tag)
		{
		}
		mrpc_castle_town_owner_update_cs() : RpcPacket(mpe_rpc_cmd::castle_town_owner_update_cs)
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

	class mrpc_castle_town_owner_update_sc : public RpcPacket 	// 장원 주인 업데이트시 정보 변경
	{
	private:
		bool flag_town_info = false;
		mrpcs_castle_town_info town_info;
		mrpcs_castle_town_info* p_town_info = nullptr;
	public:
		bool has_town_info() const
		{
			return flag_town_info;
		}
		mrpcs_castle_town_info* alloc_town_info()
		{
			flag_town_info = true;
			return &town_info;
		}
		const mrpcs_castle_town_info* get_town_info() const
		{
			if (true == flag_town_info)
			{
				if (nullptr == p_town_info)
				{
					return &town_info;
				}
				return p_town_info;
			}
			return nullptr;
		}
		void set_town_info(mrpcs_castle_town_info* in_town_info)
		{
			if (nullptr == p_town_info)
			{
				p_town_info = in_town_info;
				flag_town_info = true;
			}
		}

	public:
		mrpc_castle_town_owner_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_owner_update_sc, tag)
		{
		}
		mrpc_castle_town_owner_update_sc() : RpcPacket(mpe_rpc_cmd::castle_town_owner_update_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_town_info);
			if (true == flag_town_info)
			{
				if (nullptr != p_town_info)
					protocol::SerializeType(pBuffer, p_town_info);
				else
					protocol::SerializeType(pBuffer, &town_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
