#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_ally_info.h"

namespace mir3d
{
	class mp_guild_ally_request_accept_cs : public BasePacket 	// 문파 동맹 요청 승인
	{
	public:
		int64_t target_guid{};	// 동맹 요청 문파 UID

	public:
		mp_guild_ally_request_accept_cs() : BasePacket(mpe_cmd::guild_ally_request_accept_cs)
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

	class mp_guild_ally_request_accept_sc : public BasePacket 	// 문파 동맹 요청 승인
	{
	private:
		bool flag_ally = false;
		mps_guild_ally_info ally;	// 신청 결과
		mps_guild_ally_info* p_ally = nullptr;
	public:
		bool has_ally() const
		{
			return flag_ally;
		}
		mps_guild_ally_info* alloc_ally()
		{
			flag_ally = true;
			return &ally;
		}
		const mps_guild_ally_info* get_ally() const
		{
			if (true == flag_ally)
			{
				if (nullptr == p_ally)
				{
					return &ally;
				}
				return p_ally;
			}
			return nullptr;
		}
		void set_ally(mps_guild_ally_info* in_ally)
		{
			if (nullptr == p_ally)
			{
				p_ally = in_ally;
				flag_ally = true;
			}
		}

	public:
		mp_guild_ally_request_accept_sc() : BasePacket(mpe_cmd::guild_ally_request_accept_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_ally);
			if (true == flag_ally)
			{
				if (nullptr != p_ally)
					protocol::SerializeType(pBuffer, p_ally);
				else
					protocol::SerializeType(pBuffer, &ally);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
