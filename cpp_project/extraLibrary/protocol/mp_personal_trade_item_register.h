#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_personal_trade_item_register_cs : public BasePacket 
	{
	public:
		int64_t ptuid{};	// // 거래 번호
	public:
		int64_t iuid{};
	public:
		int32_t count{};

	public:
		mp_personal_trade_item_register_cs() : BasePacket(mpe_cmd::personal_trade_item_register_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &ptuid);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_personal_trade_item_register_sc : public BasePacket 
	{
	public:
		int64_t uid{};	// // 아이템 등록자 uid
	public:
		int64_t ptuid{};	// // 거래 번호
	private:
		bool flag_trade_info = false;
		mps_item_add trade_info;	// // 거래아이템
		mps_item_add* p_trade_info = nullptr;
	public:
		bool has_trade_info() const
		{
			return flag_trade_info;
		}
		mps_item_add* alloc_trade_info()
		{
			flag_trade_info = true;
			return &trade_info;
		}
		const mps_item_add* get_trade_info() const
		{
			if (true == flag_trade_info)
			{
				if (nullptr == p_trade_info)
				{
					return &trade_info;
				}
				return p_trade_info;
			}
			return nullptr;
		}
		void set_trade_info(mps_item_add* in_trade_info)
		{
			if (nullptr == p_trade_info)
			{
				p_trade_info = in_trade_info;
				flag_trade_info = true;
			}
		}
	private:
		bool flag_inven_info = false;
		mps_item_add inven_info;	// // 인벤 변경 아이템
		mps_item_add* p_inven_info = nullptr;
	public:
		bool has_inven_info() const
		{
			return flag_inven_info;
		}
		mps_item_add* alloc_inven_info()
		{
			flag_inven_info = true;
			return &inven_info;
		}
		const mps_item_add* get_inven_info() const
		{
			if (true == flag_inven_info)
			{
				if (nullptr == p_inven_info)
				{
					return &inven_info;
				}
				return p_inven_info;
			}
			return nullptr;
		}
		void set_inven_info(mps_item_add* in_inven_info)
		{
			if (nullptr == p_inven_info)
			{
				p_inven_info = in_inven_info;
				flag_inven_info = true;
			}
		}

	public:
		mp_personal_trade_item_register_sc() : BasePacket(mpe_cmd::personal_trade_item_register_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &ptuid);
			protocol::SerializeType(pBuffer, &flag_trade_info);
			if (true == flag_trade_info)
			{
				if (nullptr != p_trade_info)
					protocol::SerializeType(pBuffer, p_trade_info);
				else
					protocol::SerializeType(pBuffer, &trade_info);
			}
			protocol::SerializeType(pBuffer, &flag_inven_info);
			if (true == flag_inven_info)
			{
				if (nullptr != p_inven_info)
					protocol::SerializeType(pBuffer, p_inven_info);
				else
					protocol::SerializeType(pBuffer, &inven_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
