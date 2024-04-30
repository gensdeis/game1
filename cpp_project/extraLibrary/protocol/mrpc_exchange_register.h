#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mrpcs_item_stone_pair.h"
#include "struct/mps_item_add.h"
#include "struct/mrpcs_item_stone_pair.h"

namespace mir3d
{
	class mrpc_exchange_register_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int32_t gid{};
	public:
		int32_t price{};
	public:
		uint8_t period{};
	public:
		bool new_item{};
	public:
		uint8_t type{};	// // 0 : normal, 1 : world
	public:
		std::string ip_address{};
	public:
		std::string username{};
	private:
		bool flag_info = false;
		mps_item_add info;
		mps_item_add* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_add* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_add* get_info() const
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
		void set_info(mps_item_add* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	private:
		bool flag_stone_pair = false;
		mrpcs_item_stone_pair stone_pair;	// 용령석 연결 정보
		mrpcs_item_stone_pair* p_stone_pair = nullptr;
	public:
		bool has_stone_pair() const
		{
			return flag_stone_pair;
		}
		mrpcs_item_stone_pair* alloc_stone_pair()
		{
			flag_stone_pair = true;
			return &stone_pair;
		}
		const mrpcs_item_stone_pair* get_stone_pair() const
		{
			if (true == flag_stone_pair)
			{
				if (nullptr == p_stone_pair)
				{
					return &stone_pair;
				}
				return p_stone_pair;
			}
			return nullptr;
		}
		void set_stone_pair(mrpcs_item_stone_pair* in_stone_pair)
		{
			if (nullptr == p_stone_pair)
			{
				p_stone_pair = in_stone_pair;
				flag_stone_pair = true;
			}
		}
	public:
		int64_t socket_access_token{};

	public:
		mrpc_exchange_register_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::exchange_register_cs, tag)
		{
		}
		mrpc_exchange_register_cs() : RpcPacket(mpe_rpc_cmd::exchange_register_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &price);
			protocol::SerializeType(pBuffer, &period);
			protocol::SerializeType(pBuffer, &new_item);
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &ip_address);
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &flag_stone_pair);
			if (true == flag_stone_pair)
			{
				if (nullptr != p_stone_pair)
					protocol::SerializeType(pBuffer, p_stone_pair);
				else
					protocol::SerializeType(pBuffer, &stone_pair);
			}
			protocol::SerializeType(pBuffer, &socket_access_token);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_exchange_register_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t euid{};
	public:
		int64_t cuid{};
	public:
		uint8_t type{};	// // 0 : normal, 1 : world
	private:
		bool flag_info = false;
		mps_item_add info;
		mps_item_add* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_add* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_add* get_info() const
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
		void set_info(mps_item_add* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	private:
		bool flag_stone_pair = false;
		mrpcs_item_stone_pair stone_pair;	// 용령석 연결 정보
		mrpcs_item_stone_pair* p_stone_pair = nullptr;
	public:
		bool has_stone_pair() const
		{
			return flag_stone_pair;
		}
		mrpcs_item_stone_pair* alloc_stone_pair()
		{
			flag_stone_pair = true;
			return &stone_pair;
		}
		const mrpcs_item_stone_pair* get_stone_pair() const
		{
			if (true == flag_stone_pair)
			{
				if (nullptr == p_stone_pair)
				{
					return &stone_pair;
				}
				return p_stone_pair;
			}
			return nullptr;
		}
		void set_stone_pair(mrpcs_item_stone_pair* in_stone_pair)
		{
			if (nullptr == p_stone_pair)
			{
				p_stone_pair = in_stone_pair;
				flag_stone_pair = true;
			}
		}

	public:
		mrpc_exchange_register_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::exchange_register_sc, tag)
		{
		}
		mrpc_exchange_register_sc() : RpcPacket(mpe_rpc_cmd::exchange_register_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &euid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &flag_stone_pair);
			if (true == flag_stone_pair)
			{
				if (nullptr != p_stone_pair)
					protocol::SerializeType(pBuffer, p_stone_pair);
				else
					protocol::SerializeType(pBuffer, &stone_pair);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
