#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item.h"

namespace mir3d
{
	class mweb_global_exchange_item_detail_cs : public WebBasePacket 
	{
	public:
		int32_t exchange_type{};
	public:
		int32_t class_type{};
	public:
		int64_t euid{};
	public:
		mpe_exchange_type type{};

	public:
		mweb_global_exchange_item_detail_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &exchange_type);
			protocol::SerializeType(pBuffer, &class_type);
			protocol::SerializeType(pBuffer, &euid);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_global_exchange_item_detail_sc : public WebBasePacket 
	{
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
		mweb_global_exchange_item_detail_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_item);
			if (true == flag_item)
			{
				if (nullptr != p_item)
					protocol::SerializeType(pBuffer, p_item);
				else
					protocol::SerializeType(pBuffer, &item);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
