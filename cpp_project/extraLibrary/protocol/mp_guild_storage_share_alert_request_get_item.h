#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_storage_share_request_get_item.h"

namespace mir3d
{
	class mp_guild_storage_share_alert_request_get_item_cs : public BasePacket 	// 문파 공유 창고 아이템 요청 알림
	{

	public:
		mp_guild_storage_share_alert_request_get_item_cs() : BasePacket(mpe_cmd::guild_storage_share_alert_request_get_item_cs)
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

	class mp_guild_storage_share_alert_request_get_item_sc : public BasePacket 	// 문파 공유 창고 아이템 요청 알림
	{
	private:
		bool flag_request = false;
		mps_guild_storage_share_request_get_item request;
		mps_guild_storage_share_request_get_item* p_request = nullptr;
	public:
		bool has_request() const
		{
			return flag_request;
		}
		mps_guild_storage_share_request_get_item* alloc_request()
		{
			flag_request = true;
			return &request;
		}
		const mps_guild_storage_share_request_get_item* get_request() const
		{
			if (true == flag_request)
			{
				if (nullptr == p_request)
				{
					return &request;
				}
				return p_request;
			}
			return nullptr;
		}
		void set_request(mps_guild_storage_share_request_get_item* in_request)
		{
			if (nullptr == p_request)
			{
				p_request = in_request;
				flag_request = true;
			}
		}

	public:
		mp_guild_storage_share_alert_request_get_item_sc() : BasePacket(mpe_cmd::guild_storage_share_alert_request_get_item_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_request);
			if (true == flag_request)
			{
				if (nullptr != p_request)
					protocol::SerializeType(pBuffer, p_request);
				else
					protocol::SerializeType(pBuffer, &request);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
