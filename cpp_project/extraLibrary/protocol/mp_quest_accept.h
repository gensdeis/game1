#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_quest.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mp_quest_accept_cs : public BasePacket 
	{
	public:
		uint16_t id{};
	public:
		bool skip_quest{};
	public:
		int64_t iuid{};

	public:
		mp_quest_accept_cs() : BasePacket(mpe_cmd::quest_accept_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &skip_quest);
			protocol::SerializeType(pBuffer, &iuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_quest_accept_sc : public BasePacket 
	{
	public:
		std::vector<mps_quest> list_quest{};
	private:
		bool flag_update_item = false;
		mps_item_count_update update_item;
		mps_item_count_update* p_update_item = nullptr;
	public:
		bool has_update_item() const
		{
			return flag_update_item;
		}
		mps_item_count_update* alloc_update_item()
		{
			flag_update_item = true;
			return &update_item;
		}
		const mps_item_count_update* get_update_item() const
		{
			if (true == flag_update_item)
			{
				if (nullptr == p_update_item)
				{
					return &update_item;
				}
				return p_update_item;
			}
			return nullptr;
		}
		void set_update_item(mps_item_count_update* in_update_item)
		{
			if (nullptr == p_update_item)
			{
				p_update_item = in_update_item;
				flag_update_item = true;
			}
		}

	public:
		mp_quest_accept_sc() : BasePacket(mpe_cmd::quest_accept_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_quest);
			protocol::SerializeType(pBuffer, &flag_update_item);
			if (true == flag_update_item)
			{
				if (nullptr != p_update_item)
					protocol::SerializeType(pBuffer, p_update_item);
				else
					protocol::SerializeType(pBuffer, &update_item);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
