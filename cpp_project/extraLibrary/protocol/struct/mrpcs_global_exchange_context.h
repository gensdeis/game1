#pragma once
#include <vector>
#include <string>
#include "mrpcs_dual_long.h"
#include "mps_item_add.h"

namespace mir3d
{
	class mrpcs_global_exchange_context 
	{
	public:
		int64_t key{};
	public:
		uint8_t tag_{};
	public:
		int64_t ruid{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int64_t euid{};
	public:
		int64_t iuid{};
	public:
		int64_t guid{};
	public:
		int64_t contract_uid{};
	public:
		std::vector<mrpcs_dual_long> list_uid{};
	public:
		int32_t count{};
	public:
		float price{};
	public:
		int32_t server_gid{};
	public:
		int32_t server_index{};
	public:
		mrpce_server_type server_type{};
	public:
		bool new_item{};
	public:
		mpe_error contract_error_code{};
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
		std::string ip_address{};
	public:
		std::string nonce{};
	public:
		std::string product{};
	public:
		std::string signature{};
	public:
		std::string contract_address{};
	public:
		std::string register_wallet_address{};
	public:
		std::string buyer_wallet_address{};
	public:
		mpe_exchange_type exchange_type{};
	private:
		bool flag_item_info = false;
		mps_item_add item_info;
		mps_item_add* p_item_info = nullptr;
	public:
		bool has_item_info() const
		{
			return flag_item_info;
		}
		mps_item_add* alloc_item_info()
		{
			flag_item_info = true;
			return &item_info;
		}
		const mps_item_add* get_item_info() const
		{
			if (true == flag_item_info)
			{
				if (nullptr == p_item_info)
				{
					return &item_info;
				}
				return p_item_info;
			}
			return nullptr;
		}
		void set_item_info(mps_item_add* in_item_info)
		{
			if (nullptr == p_item_info)
			{
				p_item_info = in_item_info;
				flag_item_info = true;
			}
		}

	public:
		mrpcs_global_exchange_context()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &tag_);
			protocol::SerializeType(pBuffer, &ruid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &euid);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &contract_uid);
			protocol::SerializeType(pBuffer, &list_uid);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &price);
			protocol::SerializeType(pBuffer, &server_gid);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &new_item);
			protocol::SerializeEnum(pBuffer, &contract_error_code);
			protocol::SerializeType(pBuffer, &character_tid);
			protocol::SerializeType(pBuffer, &character_level);
			protocol::SerializeType(pBuffer, &character_power);
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &guildname);
			protocol::SerializeType(pBuffer, &ip_address);
			protocol::SerializeType(pBuffer, &nonce);
			protocol::SerializeType(pBuffer, &product);
			protocol::SerializeType(pBuffer, &signature);
			protocol::SerializeType(pBuffer, &contract_address);
			protocol::SerializeType(pBuffer, &register_wallet_address);
			protocol::SerializeType(pBuffer, &buyer_wallet_address);
			protocol::SerializeEnum(pBuffer, &exchange_type);
			protocol::SerializeType(pBuffer, &flag_item_info);
			if (true == flag_item_info)
			{
				if (nullptr != p_item_info)
					protocol::SerializeType(pBuffer, p_item_info);
				else
					protocol::SerializeType(pBuffer, &item_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
