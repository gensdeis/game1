#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_vector.h"
#include "struct/mps_item_count_update.h"
#include "struct/mps_update_goods.h"
#include "struct/mps_update_exp.h"

namespace mir3d
{
	class mp_zone_revive_cs : public BasePacket 
	{
	public:
		mpe_revive revive_type{};
	public:
		int64_t item_uid{};

	public:
		mp_zone_revive_cs() : BasePacket(mpe_cmd::zone_revive_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &revive_type);
			protocol::SerializeType(pBuffer, &item_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_zone_revive_sc : public BasePacket 
	{
	public:
		int32_t hp{};
	public:
		int32_t mp{};
	private:
		bool flag_revive_pos = false;
		mps_vector revive_pos;
		mps_vector* p_revive_pos = nullptr;
	public:
		bool has_revive_pos() const
		{
			return flag_revive_pos;
		}
		mps_vector* alloc_revive_pos()
		{
			flag_revive_pos = true;
			return &revive_pos;
		}
		const mps_vector* get_revive_pos() const
		{
			if (true == flag_revive_pos)
			{
				if (nullptr == p_revive_pos)
				{
					return &revive_pos;
				}
				return p_revive_pos;
			}
			return nullptr;
		}
		void set_revive_pos(mps_vector* in_revive_pos)
		{
			if (nullptr == p_revive_pos)
			{
				p_revive_pos = in_revive_pos;
				flag_revive_pos = true;
			}
		}
	private:
		bool flag_item_info = false;
		mps_item_count_update item_info;
		mps_item_count_update* p_item_info = nullptr;
	public:
		bool has_item_info() const
		{
			return flag_item_info;
		}
		mps_item_count_update* alloc_item_info()
		{
			flag_item_info = true;
			return &item_info;
		}
		const mps_item_count_update* get_item_info() const
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
		void set_item_info(mps_item_count_update* in_item_info)
		{
			if (nullptr == p_item_info)
			{
				p_item_info = in_item_info;
				flag_item_info = true;
			}
		}
	public:
		int64_t uid{};
	public:
		mpe_revive revive_type{};
	public:
		int32_t map_id{};
	public:
		float weight{};
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
	private:
		bool flag_update_exp = false;
		mps_update_exp update_exp;	// long 경험치
		mps_update_exp* p_update_exp = nullptr;
	public:
		bool has_update_exp() const
		{
			return flag_update_exp;
		}
		mps_update_exp* alloc_update_exp()
		{
			flag_update_exp = true;
			return &update_exp;
		}
		const mps_update_exp* get_update_exp() const
		{
			if (true == flag_update_exp)
			{
				if (nullptr == p_update_exp)
				{
					return &update_exp;
				}
				return p_update_exp;
			}
			return nullptr;
		}
		void set_update_exp(mps_update_exp* in_update_exp)
		{
			if (nullptr == p_update_exp)
			{
				p_update_exp = in_update_exp;
				flag_update_exp = true;
			}
		}

	public:
		mp_zone_revive_sc() : BasePacket(mpe_cmd::zone_revive_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &hp);
			protocol::SerializeType(pBuffer, &mp);
			protocol::SerializeType(pBuffer, &flag_revive_pos);
			if (true == flag_revive_pos)
			{
				if (nullptr != p_revive_pos)
					protocol::SerializeType(pBuffer, p_revive_pos);
				else
					protocol::SerializeType(pBuffer, &revive_pos);
			}
			protocol::SerializeType(pBuffer, &flag_item_info);
			if (true == flag_item_info)
			{
				if (nullptr != p_item_info)
					protocol::SerializeType(pBuffer, p_item_info);
				else
					protocol::SerializeType(pBuffer, &item_info);
			}
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeEnum(pBuffer, &revive_type);
			protocol::SerializeType(pBuffer, &map_id);
			protocol::SerializeType(pBuffer, &weight);
			protocol::SerializeType(pBuffer, &flag_update_goods);
			if (true == flag_update_goods)
			{
				if (nullptr != p_update_goods)
					protocol::SerializeType(pBuffer, p_update_goods);
				else
					protocol::SerializeType(pBuffer, &update_goods);
			}
			protocol::SerializeType(pBuffer, &flag_update_exp);
			if (true == flag_update_exp)
			{
				if (nullptr != p_update_exp)
					protocol::SerializeType(pBuffer, p_update_exp);
				else
					protocol::SerializeType(pBuffer, &update_exp);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
