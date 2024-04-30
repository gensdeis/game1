#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild.h"
#include "struct/mps_item_add.h"
#include "struct/mps_guild_member.h"

namespace mir3d
{
	class mp_guild_create_cs : public BasePacket 
	{
	public:
		std::string guild_name{};	// 길드명
	public:
		mpe_guild_join_type join_type{};	// 가입타입
	public:
		int32_t join_level{};	// 가입제한레벨
	public:
		std::string introdution{};	// 길드소개
	public:
		std::vector<uint8_t> guild_mark{};	// 문파 문양 정보

	public:
		mp_guild_create_cs() : BasePacket(mpe_cmd::guild_create_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeEnum(pBuffer, &join_type);
			protocol::SerializeType(pBuffer, &join_level);
			protocol::SerializeType(pBuffer, &introdution);
			protocol::SerializeType(pBuffer, &guild_mark);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_create_sc : public BasePacket 
	{
	public:
		mpe_error error{};
	private:
		bool flag_guild = false;
		mps_guild guild;	// 길드정보
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
	private:
		bool flag_use_item = false;
		mps_item_add use_item;
		mps_item_add* p_use_item = nullptr;
	public:
		bool has_use_item() const
		{
			return flag_use_item;
		}
		mps_item_add* alloc_use_item()
		{
			flag_use_item = true;
			return &use_item;
		}
		const mps_item_add* get_use_item() const
		{
			if (true == flag_use_item)
			{
				if (nullptr == p_use_item)
				{
					return &use_item;
				}
				return p_use_item;
			}
			return nullptr;
		}
		void set_use_item(mps_item_add* in_use_item)
		{
			if (nullptr == p_use_item)
			{
				p_use_item = in_use_item;
				flag_use_item = true;
			}
		}
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
		int64_t available_time{};

	public:
		mp_guild_create_sc() : BasePacket(mpe_cmd::guild_create_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &error);
			protocol::SerializeType(pBuffer, &flag_guild);
			if (true == flag_guild)
			{
				if (nullptr != p_guild)
					protocol::SerializeType(pBuffer, p_guild);
				else
					protocol::SerializeType(pBuffer, &guild);
			}
			protocol::SerializeType(pBuffer, &flag_use_item);
			if (true == flag_use_item)
			{
				if (nullptr != p_use_item)
					protocol::SerializeType(pBuffer, p_use_item);
				else
					protocol::SerializeType(pBuffer, &use_item);
			}
			protocol::SerializeType(pBuffer, &flag_my_info);
			if (true == flag_my_info)
			{
				if (nullptr != p_my_info)
					protocol::SerializeType(pBuffer, p_my_info);
				else
					protocol::SerializeType(pBuffer, &my_info);
			}
			protocol::SerializeType(pBuffer, &available_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
