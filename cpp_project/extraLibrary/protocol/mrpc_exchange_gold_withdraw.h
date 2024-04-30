#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_exchange_context.h"
#include "struct/mps_update_goods.h"

namespace mir3d
{
	class mrpc_exchange_gold_withdraw_cs : public RpcPacket 
	{
	private:
		bool flag_info = false;
		mrpcs_exchange_context info;
		mrpcs_exchange_context* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_exchange_context* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_exchange_context* get_info() const
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
		void set_info(mrpcs_exchange_context* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		int64_t socket_access_token{};

	public:
		mrpc_exchange_gold_withdraw_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::exchange_gold_withdraw_cs, tag)
		{
		}
		mrpc_exchange_gold_withdraw_cs() : RpcPacket(mpe_rpc_cmd::exchange_gold_withdraw_cs)
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
			protocol::SerializeType(pBuffer, &socket_access_token);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_exchange_gold_withdraw_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		uint8_t type{};	// // 0 : normal, 1 : world
	private:
		bool flag_good = false;
		mps_update_goods good;
		mps_update_goods* p_good = nullptr;
	public:
		bool has_good() const
		{
			return flag_good;
		}
		mps_update_goods* alloc_good()
		{
			flag_good = true;
			return &good;
		}
		const mps_update_goods* get_good() const
		{
			if (true == flag_good)
			{
				if (nullptr == p_good)
				{
					return &good;
				}
				return p_good;
			}
			return nullptr;
		}
		void set_good(mps_update_goods* in_good)
		{
			if (nullptr == p_good)
			{
				p_good = in_good;
				flag_good = true;
			}
		}

	public:
		mrpc_exchange_gold_withdraw_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::exchange_gold_withdraw_sc, tag)
		{
		}
		mrpc_exchange_gold_withdraw_sc() : RpcPacket(mpe_rpc_cmd::exchange_gold_withdraw_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &flag_good);
			if (true == flag_good)
			{
				if (nullptr != p_good)
					protocol::SerializeType(pBuffer, p_good);
				else
					protocol::SerializeType(pBuffer, &good);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
