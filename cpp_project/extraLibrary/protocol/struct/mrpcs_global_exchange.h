#pragma once
#include <vector>
#include <string>
#include "mps_item.h"

namespace mir3d
{
	class mrpcs_global_exchange 
	{
	public:
		int64_t euid{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int32_t gid{};
	public:
		int32_t tid{};
	public:
		int32_t reinforce{};
	public:
		mrpce_exchange_sell_state sell_state{};
	public:
		int32_t regtime{};
	public:
		int32_t expire{};
	public:
		int32_t exchange_type{};
	public:
		int32_t class_type{};
	public:
		float price{};
	public:
		float tax{};
	public:
		float revenue{};
	public:
		std::string username{};
	public:
		std::string wallet_address{};
	private:
		bool flag_item = false;
		mps_item item;
		mps_item* p_item = nullptr;
	public:
		bool has_item() const
		{
			return flag_item;
		}
		mps_item* alloc_item()
		{
			flag_item = true;
			return &item;
		}
		const mps_item* get_item() const
		{
			if (true == flag_item)
			{
				if (nullptr == p_item)
				{
					return &item;
				}
				return p_item;
			}
			return nullptr;
		}
		void set_item(mps_item* in_item)
		{
			if (nullptr == p_item)
			{
				p_item = in_item;
				flag_item = true;
			}
		}
	public:
		int32_t awaken_step{};

	public:
		mrpcs_global_exchange()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &euid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &reinforce);
			protocol::SerializeEnum(pBuffer, &sell_state);
			protocol::SerializeType(pBuffer, &regtime);
			protocol::SerializeType(pBuffer, &expire);
			protocol::SerializeType(pBuffer, &exchange_type);
			protocol::SerializeType(pBuffer, &class_type);
			protocol::SerializeType(pBuffer, &price);
			protocol::SerializeType(pBuffer, &tax);
			protocol::SerializeType(pBuffer, &revenue);
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &wallet_address);
			protocol::SerializeType(pBuffer, &flag_item);
			if (true == flag_item)
			{
				if (nullptr != p_item)
					protocol::SerializeType(pBuffer, p_item);
				else
					protocol::SerializeType(pBuffer, &item);
			}
			protocol::SerializeType(pBuffer, &awaken_step);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
