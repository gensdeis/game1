#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_seasonpass.h"
#include "struct/mps_update_goods.h"

namespace mir3d
{
	class mrpc_seasonpass_unlock_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_seasonpass = false;
		mps_seasonpass seasonpass;
		mps_seasonpass* p_seasonpass = nullptr;
	public:
		bool has_seasonpass() const
		{
			return flag_seasonpass;
		}
		mps_seasonpass* alloc_seasonpass()
		{
			flag_seasonpass = true;
			return &seasonpass;
		}
		const mps_seasonpass* get_seasonpass() const
		{
			if (true == flag_seasonpass)
			{
				if (nullptr == p_seasonpass)
				{
					return &seasonpass;
				}
				return p_seasonpass;
			}
			return nullptr;
		}
		void set_seasonpass(mps_seasonpass* in_seasonpass)
		{
			if (nullptr == p_seasonpass)
			{
				p_seasonpass = in_seasonpass;
				flag_seasonpass = true;
			}
		}
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
		mrpc_seasonpass_unlock_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::seasonpass_unlock_cs, tag)
		{
		}
		mrpc_seasonpass_unlock_cs() : RpcPacket(mpe_rpc_cmd::seasonpass_unlock_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_seasonpass);
			if (true == flag_seasonpass)
			{
				if (nullptr != p_seasonpass)
					protocol::SerializeType(pBuffer, p_seasonpass);
				else
					protocol::SerializeType(pBuffer, &seasonpass);
			}
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

	class mrpc_seasonpass_unlock_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_seasonpass_unlock_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::seasonpass_unlock_sc, tag)
		{
		}
		mrpc_seasonpass_unlock_sc() : RpcPacket(mpe_rpc_cmd::seasonpass_unlock_sc)
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
