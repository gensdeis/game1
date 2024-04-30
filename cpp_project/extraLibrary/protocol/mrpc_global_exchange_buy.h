#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_global_exchange_context.h"

namespace mir3d
{
	class mrpc_global_exchange_buy_cs : public RpcPacket 
	{
	private:
		bool flag_info = false;
		mrpcs_global_exchange_context info;
		mrpcs_global_exchange_context* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_global_exchange_context* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_global_exchange_context* get_info() const
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
		void set_info(mrpcs_global_exchange_context* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		std::string user_wallet{};
	public:
		std::string nonce{};
	public:
		std::string product{};
	public:
		std::string signature{};
	public:
		std::string contract_address{};

	public:
		mrpc_global_exchange_buy_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_exchange_buy_cs, tag)
		{
		}
		mrpc_global_exchange_buy_cs() : RpcPacket(mpe_rpc_cmd::global_exchange_buy_cs)
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
			protocol::SerializeType(pBuffer, &user_wallet);
			protocol::SerializeType(pBuffer, &nonce);
			protocol::SerializeType(pBuffer, &product);
			protocol::SerializeType(pBuffer, &signature);
			protocol::SerializeType(pBuffer, &contract_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_global_exchange_buy_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		mpe_exchange_type type{};

	public:
		mrpc_global_exchange_buy_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_exchange_buy_sc, tag)
		{
		}
		mrpc_global_exchange_buy_sc() : RpcPacket(mpe_rpc_cmd::global_exchange_buy_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
