#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_other_guild_info.h"
#include "struct/mps_guild_member.h"

namespace mir3d
{
	class mrpc_guild_ally_detail_info_cs : public RpcPacket 	// "동맹길드문파방문정보"
	{
	public:
		int64_t key{};
	public:
		int64_t ally_guid{};	// "동맹 문파 UID"

	public:
		mrpc_guild_ally_detail_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_ally_detail_info_cs, tag)
		{
		}
		mrpc_guild_ally_detail_info_cs() : RpcPacket(mpe_rpc_cmd::guild_ally_detail_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &ally_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_ally_detail_info_sc : public RpcPacket 	// "동맹길드문파방문정보"
	{
	public:
		int64_t key{};
	private:
		bool flag_guild = false;
		mps_other_guild_info guild;	// "대상길드정보"
		mps_other_guild_info* p_guild = nullptr;
	public:
		bool has_guild() const
		{
			return flag_guild;
		}
		mps_other_guild_info* alloc_guild()
		{
			flag_guild = true;
			return &guild;
		}
		const mps_other_guild_info* get_guild() const
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
		void set_guild(mps_other_guild_info* in_guild)
		{
			if (nullptr == p_guild)
			{
				p_guild = in_guild;
				flag_guild = true;
			}
		}
	public:
		std::vector<mps_guild_member> list_member{};	// "길드멤버 목록"
	public:
		std::vector<int32_t> guild_skill{};	// "길드스킬목록"

	public:
		mrpc_guild_ally_detail_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_ally_detail_info_sc, tag)
		{
		}
		mrpc_guild_ally_detail_info_sc() : RpcPacket(mpe_rpc_cmd::guild_ally_detail_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_guild);
			if (true == flag_guild)
			{
				if (nullptr != p_guild)
					protocol::SerializeType(pBuffer, p_guild);
				else
					protocol::SerializeType(pBuffer, &guild);
			}
			protocol::SerializeType(pBuffer, &list_member);
			protocol::SerializeType(pBuffer, &guild_skill);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
