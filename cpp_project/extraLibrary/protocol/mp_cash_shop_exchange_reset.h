#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_cash_exchange_product.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_cash_shop_exchange_reset_cs : public BasePacket 
	{
	public:
		uint16_t sell_category_id{};	// 교환소 타입
	public:
		mpe_cash_exchange_type reset_type{};

	public:
		mp_cash_shop_exchange_reset_cs() : BasePacket(mpe_cmd::cash_shop_exchange_reset_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &sell_category_id);
			protocol::SerializeEnum(pBuffer, &reset_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_cash_shop_exchange_reset_sc : public BasePacket 
	{
	public:
		std::vector<mps_cash_exchange_product> product{};	// 리셋된 상품 정보
	private:
		bool flag_item_add = false;
		mps_item_add item_add;	// 소비 아이템 or 재화
		mps_item_add* p_item_add = nullptr;
	public:
		bool has_item_add() const
		{
			return flag_item_add;
		}
		mps_item_add* alloc_item_add()
		{
			flag_item_add = true;
			return &item_add;
		}
		const mps_item_add* get_item_add() const
		{
			if (true == flag_item_add)
			{
				if (nullptr == p_item_add)
				{
					return &item_add;
				}
				return p_item_add;
			}
			return nullptr;
		}
		void set_item_add(mps_item_add* in_item_add)
		{
			if (nullptr == p_item_add)
			{
				p_item_add = in_item_add;
				flag_item_add = true;
			}
		}
	public:
		mpe_error result{};	// 일일 리셋시 갱신 결과

	public:
		mp_cash_shop_exchange_reset_sc() : BasePacket(mpe_cmd::cash_shop_exchange_reset_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &product);
			protocol::SerializeType(pBuffer, &flag_item_add);
			if (true == flag_item_add)
			{
				if (nullptr != p_item_add)
					protocol::SerializeType(pBuffer, p_item_add);
				else
					protocol::SerializeType(pBuffer, &item_add);
			}
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
