#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_buff.h"
#include "struct/mps_update_goods.h"

namespace mir3d
{
	class mp_mentor_buff_buy_cs : public BasePacket 
	{
	public:
		int32_t buff_id{};

	public:
		mp_mentor_buff_buy_cs() : BasePacket(mpe_cmd::mentor_buff_buy_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &buff_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_mentor_buff_buy_sc : public BasePacket 
	{
	private:
		bool flag_buff_info = false;
		mps_buff buff_info;
		mps_buff* p_buff_info = nullptr;
	public:
		bool has_buff_info() const
		{
			return flag_buff_info;
		}
		mps_buff* alloc_buff_info()
		{
			flag_buff_info = true;
			return &buff_info;
		}
		const mps_buff* get_buff_info() const
		{
			if (true == flag_buff_info)
			{
				if (nullptr == p_buff_info)
				{
					return &buff_info;
				}
				return p_buff_info;
			}
			return nullptr;
		}
		void set_buff_info(mps_buff* in_buff_info)
		{
			if (nullptr == p_buff_info)
			{
				p_buff_info = in_buff_info;
				flag_buff_info = true;
			}
		}
	private:
		bool flag_update_goods = false;
		mps_update_goods update_goods;
		mps_update_goods* p_update_goods = nullptr;
	public:
		bool has_update_goods() const
		{
			return flag_update_goods;
		}
		mps_update_goods* alloc_update_goods()
		{
			flag_update_goods = true;
			return &update_goods;
		}
		const mps_update_goods* get_update_goods() const
		{
			if (true == flag_update_goods)
			{
				if (nullptr == p_update_goods)
				{
					return &update_goods;
				}
				return p_update_goods;
			}
			return nullptr;
		}
		void set_update_goods(mps_update_goods* in_update_goods)
		{
			if (nullptr == p_update_goods)
			{
				p_update_goods = in_update_goods;
				flag_update_goods = true;
			}
		}

	public:
		mp_mentor_buff_buy_sc() : BasePacket(mpe_cmd::mentor_buff_buy_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_buff_info);
			if (true == flag_buff_info)
			{
				if (nullptr != p_buff_info)
					protocol::SerializeType(pBuffer, p_buff_info);
				else
					protocol::SerializeType(pBuffer, &buff_info);
			}
			protocol::SerializeType(pBuffer, &flag_update_goods);
			if (true == flag_update_goods)
			{
				if (nullptr != p_update_goods)
					protocol::SerializeType(pBuffer, p_update_goods);
				else
					protocol::SerializeType(pBuffer, &update_goods);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
