#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_war.h"

namespace mir3d
{
	class mp_guild_start_war_cs : public BasePacket 
	{
	public:
		int64_t target_guid{};

	public:
		mp_guild_start_war_cs() : BasePacket(mpe_cmd::guild_start_war_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_start_war_sc : public BasePacket 
	{
	private:
		bool flag_war = false;
		mps_guild_war war;
		mps_guild_war* p_war = nullptr;
	public:
		bool has_war() const
		{
			return flag_war;
		}
		mps_guild_war* alloc_war()
		{
			flag_war = true;
			return &war;
		}
		const mps_guild_war* get_war() const
		{
			if (true == flag_war)
			{
				if (nullptr == p_war)
				{
					return &war;
				}
				return p_war;
			}
			return nullptr;
		}
		void set_war(mps_guild_war* in_war)
		{
			if (nullptr == p_war)
			{
				p_war = in_war;
				flag_war = true;
			}
		}

	public:
		mp_guild_start_war_sc() : BasePacket(mpe_cmd::guild_start_war_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_war);
			if (true == flag_war)
			{
				if (nullptr != p_war)
					protocol::SerializeType(pBuffer, p_war);
				else
					protocol::SerializeType(pBuffer, &war);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
