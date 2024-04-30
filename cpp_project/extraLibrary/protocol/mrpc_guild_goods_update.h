#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods.h"
#include "struct/mps_guild_goods.h"

namespace mir3d
{
	class mrpc_guild_goods_update_cs : public RpcPacket 
	{

	public:
		mrpc_guild_goods_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_goods_update_cs, tag)
		{
		}
		mrpc_guild_goods_update_cs() : RpcPacket(mpe_rpc_cmd::guild_goods_update_cs)
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

	class mrpc_guild_goods_update_sc : public RpcPacket 
	{
	private:
		bool flag_info = false;
		mps_update_goods info;
		mps_update_goods* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_update_goods* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_update_goods* get_info() const
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
		void set_info(mps_update_goods* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		std::vector<int64_t> list_cuid{};
	public:
		std::vector<mps_guild_goods> list_guild_goods{};

	public:
		mrpc_guild_goods_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_goods_update_sc, tag)
		{
		}
		mrpc_guild_goods_update_sc() : RpcPacket(mpe_rpc_cmd::guild_goods_update_sc)
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
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &list_guild_goods);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
