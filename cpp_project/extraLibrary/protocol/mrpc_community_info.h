#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_comm_character.h"

namespace mir3d
{
	class mrpc_community_info_cs : public RpcPacket 
	{
	public:
		mrpce_community_update_type update_type{};
	private:
		bool flag_character_info = false;
		mrpcs_comm_character character_info;
		mrpcs_comm_character* p_character_info = nullptr;
	public:
		bool has_character_info() const
		{
			return flag_character_info;
		}
		mrpcs_comm_character* alloc_character_info()
		{
			flag_character_info = true;
			return &character_info;
		}
		const mrpcs_comm_character* get_character_info() const
		{
			if (true == flag_character_info)
			{
				if (nullptr == p_character_info)
				{
					return &character_info;
				}
				return p_character_info;
			}
			return nullptr;
		}
		void set_character_info(mrpcs_comm_character* in_character_info)
		{
			if (nullptr == p_character_info)
			{
				p_character_info = in_character_info;
				flag_character_info = true;
			}
		}

	public:
		mrpc_community_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_info_cs, tag)
		{
		}
		mrpc_community_info_cs() : RpcPacket(mpe_rpc_cmd::community_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &update_type);
			protocol::SerializeType(pBuffer, &flag_character_info);
			if (true == flag_character_info)
			{
				if (nullptr != p_character_info)
					protocol::SerializeType(pBuffer, p_character_info);
				else
					protocol::SerializeType(pBuffer, &character_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_community_info_sc : public RpcPacket 
	{

	public:
		mrpc_community_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_info_sc, tag)
		{
		}
		mrpc_community_info_sc() : RpcPacket(mpe_rpc_cmd::community_info_sc)
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
