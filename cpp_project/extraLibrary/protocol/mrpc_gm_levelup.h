#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods.h"

namespace mir3d
{
	class mrpc_gm_levelup_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_goods = false;
		mps_update_goods goods;
		mps_update_goods* p_goods = nullptr;
	public:
		bool has_goods() const
		{
			return flag_goods;
		}
		mps_update_goods* alloc_goods()
		{
			flag_goods = true;
			return &goods;
		}
		const mps_update_goods* get_goods() const
		{
			if (true == flag_goods)
			{
				if (nullptr == p_goods)
				{
					return &goods;
				}
				return p_goods;
			}
			return nullptr;
		}
		void set_goods(mps_update_goods* in_goods)
		{
			if (nullptr == p_goods)
			{
				p_goods = in_goods;
				flag_goods = true;
			}
		}

	public:
		mrpc_gm_levelup_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_levelup_cs, tag)
		{
		}
		mrpc_gm_levelup_cs() : RpcPacket(mpe_rpc_cmd::gm_levelup_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_goods);
			if (true == flag_goods)
			{
				if (nullptr != p_goods)
					protocol::SerializeType(pBuffer, p_goods);
				else
					protocol::SerializeType(pBuffer, &goods);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_levelup_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_gm_levelup_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_levelup_sc, tag)
		{
		}
		mrpc_gm_levelup_sc() : RpcPacket(mpe_rpc_cmd::gm_levelup_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
