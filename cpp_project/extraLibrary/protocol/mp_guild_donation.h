#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_guild_donation_cs : public BasePacket 
	{
	public:
		mpe_guild_donation_type donation_type{};

	public:
		mp_guild_donation_cs() : BasePacket(mpe_cmd::guild_donation_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &donation_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_donation_sc : public BasePacket 
	{
	public:
		mpe_error error{};
	private:
		bool flag_update_golds = false;
		mps_item_add update_golds;
		mps_item_add* p_update_golds = nullptr;
	public:
		bool has_update_golds() const
		{
			return flag_update_golds;
		}
		mps_item_add* alloc_update_golds()
		{
			flag_update_golds = true;
			return &update_golds;
		}
		const mps_item_add* get_update_golds() const
		{
			if (true == flag_update_golds)
			{
				if (nullptr == p_update_golds)
				{
					return &update_golds;
				}
				return p_update_golds;
			}
			return nullptr;
		}
		void set_update_golds(mps_item_add* in_update_golds)
		{
			if (nullptr == p_update_golds)
			{
				p_update_golds = in_update_golds;
				flag_update_golds = true;
			}
		}
	public:
		int32_t donation_count{};
	public:
		int32_t available_time{};

	public:
		mp_guild_donation_sc() : BasePacket(mpe_cmd::guild_donation_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &error);
			protocol::SerializeType(pBuffer, &flag_update_golds);
			if (true == flag_update_golds)
			{
				if (nullptr != p_update_golds)
					protocol::SerializeType(pBuffer, p_update_golds);
				else
					protocol::SerializeType(pBuffer, &update_golds);
			}
			protocol::SerializeType(pBuffer, &donation_count);
			protocol::SerializeType(pBuffer, &available_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
