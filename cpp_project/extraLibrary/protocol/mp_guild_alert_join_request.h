#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_request_member.h"

namespace mir3d
{
	class mp_guild_alert_join_request_cs : public BasePacket 	// // 가입요청 알림 패킷
	{

	public:
		mp_guild_alert_join_request_cs() : BasePacket(mpe_cmd::guild_alert_join_request_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_alert_join_request_sc : public BasePacket 	// // 가입요청 알림 패킷
	{
	private:
		bool flag_info = false;
		mps_guild_request_member info;	// // 가입요청한 유저 정보
		mps_guild_request_member* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_guild_request_member* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_guild_request_member* get_info() const
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
		void set_info(mps_guild_request_member* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_guild_alert_join_request_sc() : BasePacket(mpe_cmd::guild_alert_join_request_sc)
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
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
