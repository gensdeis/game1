#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_global_exchange_pre_register_cs : public RpcPacket 	// database 처리
	{
	public:
		int64_t key{};
	public:
		int64_t ruid{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int32_t gid{};
	public:
		float price{};
	public:
		bool new_item{};
	public:
		std::string ip_address{};
	public:
		std::string wallet_address{};
	public:
		mpe_exchange_type type{};
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
	public:
		int64_t socket_access_token{};

	public:
		mrpc_global_exchange_pre_register_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_exchange_pre_register_cs, tag)
		{
		}
		mrpc_global_exchange_pre_register_cs() : RpcPacket(mpe_rpc_cmd::global_exchange_pre_register_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &ruid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &price);
			protocol::SerializeType(pBuffer, &new_item);
			protocol::SerializeType(pBuffer, &ip_address);
			protocol::SerializeType(pBuffer, &wallet_address);
			protocol::SerializeEnum(pBuffer, &type);
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

	class mrpc_global_exchange_pre_register_sc : public RpcPacket 	// database 처리
	{
	public:
		int64_t key{};
	public:
		int64_t ruid{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int32_t gid{};
	public:
		float price{};
	public:
		bool new_item{};
	public:
		std::string ip_address{};
	public:
		std::string wallet_address{};
	public:
		mpe_exchange_type type{};
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
	public:
		int64_t guid{};
	public:
		uint8_t character_tid{};
	public:
		int32_t character_level{};
	public:
		int32_t character_power{};
	public:
		std::string username{};
	public:
		std::string nickname{};
	public:
		std::string guildname{};

	public:
		mrpc_global_exchange_pre_register_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_exchange_pre_register_sc, tag)
		{
		}
		mrpc_global_exchange_pre_register_sc() : RpcPacket(mpe_rpc_cmd::global_exchange_pre_register_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &ruid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &price);
			protocol::SerializeType(pBuffer, &new_item);
			protocol::SerializeType(pBuffer, &ip_address);
			protocol::SerializeType(pBuffer, &wallet_address);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &character_tid);
			protocol::SerializeType(pBuffer, &character_level);
			protocol::SerializeType(pBuffer, &character_power);
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &guildname);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
