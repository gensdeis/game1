#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild.h"
#include "struct/mps_guild_member.h"

namespace mir3d
{
	class mp_guild_invite_accept_cs : public BasePacket 
	{
	public:
		int64_t guid{};

	public:
		mp_guild_invite_accept_cs() : BasePacket(mpe_cmd::guild_invite_accept_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_invite_accept_sc : public BasePacket 
	{
	private:
		bool flag_guild = false;
		mps_guild guild;
		mps_guild* p_guild = nullptr;
	public:
		bool has_guild() const
		{
			return flag_guild;
		}
		mps_guild* alloc_guild()
		{
			flag_guild = true;
			return &guild;
		}
		const mps_guild* get_guild() const
		{
			if (true == flag_guild)
			{
				if (nullptr == p_guild)
				{
					return &guild;
				}
				return p_guild;
			}
			return nullptr;
		}
		void set_guild(mps_guild* in_guild)
		{
			if (nullptr == p_guild)
			{
				p_guild = in_guild;
				flag_guild = true;
			}
		}
	public:
		std::vector<int32_t> list_guild_skill{};
	private:
		bool flag_my_info = false;
		mps_guild_member my_info;
		mps_guild_member* p_my_info = nullptr;
	public:
		bool has_my_info() const
		{
			return flag_my_info;
		}
		mps_guild_member* alloc_my_info()
		{
			flag_my_info = true;
			return &my_info;
		}
		const mps_guild_member* get_my_info() const
		{
			if (true == flag_my_info)
			{
				if (nullptr == p_my_info)
				{
					return &my_info;
				}
				return p_my_info;
			}
			return nullptr;
		}
		void set_my_info(mps_guild_member* in_my_info)
		{
			if (nullptr == p_my_info)
			{
				p_my_info = in_my_info;
				flag_my_info = true;
			}
		}
	public:
		bool result{};

	public:
		mp_guild_invite_accept_sc() : BasePacket(mpe_cmd::guild_invite_accept_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_guild);
			if (true == flag_guild)
			{
				if (nullptr != p_guild)
					protocol::SerializeType(pBuffer, p_guild);
				else
					protocol::SerializeType(pBuffer, &guild);
			}
			protocol::SerializeType(pBuffer, &list_guild_skill);
			protocol::SerializeType(pBuffer, &flag_my_info);
			if (true == flag_my_info)
			{
				if (nullptr != p_my_info)
					protocol::SerializeType(pBuffer, p_my_info);
				else
					protocol::SerializeType(pBuffer, &my_info);
			}
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
