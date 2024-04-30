#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_profesion_update.h"
#include "struct/mps_make_item.h"

namespace mir3d
{
	class mp_profesion_make_cs : public BasePacket 	// // outgame - profesion
	{
	public:
		int32_t recipe_id{};
	public:
		int32_t count{};
	public:
		int64_t npc_uid{};
	public:
		std::vector<int32_t> list_tid{};

	public:
		mp_profesion_make_cs() : BasePacket(mpe_cmd::profesion_make_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &recipe_id);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &npc_uid);
			protocol::SerializeType(pBuffer, &list_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_profesion_make_sc : public BasePacket 	// // outgame - profesion
	{
	private:
		bool flag_info = false;
		mps_profesion_update info;
		mps_profesion_update* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_profesion_update* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_profesion_update* get_info() const
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
		void set_info(mps_profesion_update* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		mpe_recipe_type recipe_type{};
	private:
		bool flag_make_item = false;
		mps_make_item make_item;
		mps_make_item* p_make_item = nullptr;
	public:
		bool has_make_item() const
		{
			return flag_make_item;
		}
		mps_make_item* alloc_make_item()
		{
			flag_make_item = true;
			return &make_item;
		}
		const mps_make_item* get_make_item() const
		{
			if (true == flag_make_item)
			{
				if (nullptr == p_make_item)
				{
					return &make_item;
				}
				return p_make_item;
			}
			return nullptr;
		}
		void set_make_item(mps_make_item* in_make_item)
		{
			if (nullptr == p_make_item)
			{
				p_make_item = in_make_item;
				flag_make_item = true;
			}
		}

	public:
		mp_profesion_make_sc() : BasePacket(mpe_cmd::profesion_make_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeEnum(pBuffer, &recipe_type);
			protocol::SerializeType(pBuffer, &flag_make_item);
			if (true == flag_make_item)
			{
				if (nullptr != p_make_item)
					protocol::SerializeType(pBuffer, p_make_item);
				else
					protocol::SerializeType(pBuffer, &make_item);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
