#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_advertisement_event.h"

namespace mir3d
{
	class mweb_advertisement_event_reward_cs : public WebBasePacket 	// 광고 출석 보상
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int32_t event_id{};
	public:
		uint16_t reward_sequence{};
	public:
		std::string client_guid{};	// WMM Client GUID
	public:
		std::string player_key{};	// WMM Client Key

	public:
		mweb_advertisement_event_reward_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &event_id);
			protocol::SerializeType(pBuffer, &reward_sequence);
			protocol::SerializeType(pBuffer, &client_guid);
			protocol::SerializeType(pBuffer, &player_key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_advertisement_event_reward_sc : public WebBasePacket 	// 광고 출석 보상
	{
	public:
		int32_t result{};
	public:
		int32_t event_id{};
	public:
		uint16_t reward_sequence{};
	private:
		bool flag_advertisement_event = false;
		mps_advertisement_event advertisement_event;
		mps_advertisement_event* p_advertisement_event = nullptr;
	public:
		bool has_advertisement_event() const
		{
			return flag_advertisement_event;
		}
		mps_advertisement_event* alloc_advertisement_event()
		{
			flag_advertisement_event = true;
			return &advertisement_event;
		}
		const mps_advertisement_event* get_advertisement_event() const
		{
			if (true == flag_advertisement_event)
			{
				if (nullptr == p_advertisement_event)
				{
					return &advertisement_event;
				}
				return p_advertisement_event;
			}
			return nullptr;
		}
		void set_advertisement_event(mps_advertisement_event* in_advertisement_event)
		{
			if (nullptr == p_advertisement_event)
			{
				p_advertisement_event = in_advertisement_event;
				flag_advertisement_event = true;
			}
		}
	public:
		int32_t api_code{};	// API CODE

	public:
		mweb_advertisement_event_reward_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &event_id);
			protocol::SerializeType(pBuffer, &reward_sequence);
			protocol::SerializeType(pBuffer, &flag_advertisement_event);
			if (true == flag_advertisement_event)
			{
				if (nullptr != p_advertisement_event)
					protocol::SerializeType(pBuffer, p_advertisement_event);
				else
					protocol::SerializeType(pBuffer, &advertisement_event);
			}
			protocol::SerializeType(pBuffer, &api_code);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
