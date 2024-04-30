#pragma once
#include <vector>
#include <string>
#include "mps_update_goods.h"

namespace mir3d
{
	class mps_exchange_context 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int64_t euid{};
	public:
		int64_t iuid{};
	public:
		int32_t count{};
	public:
		int32_t price{};
	public:
		int32_t gid{};
	private:
		bool flag_good = false;
		mps_update_goods good;	// "mrpc_exchange_buy, mrpc_exchange_gold_withdraw (처리전 최종 good 값)"
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
		mps_exchange_context()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &euid);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &price);
			protocol::SerializeType(pBuffer, &gid);
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
		}
	};
}
