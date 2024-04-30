#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_event_reward_cs : public WebBasePacket 
	{
	public:
		int64_t cuid{};
	public:
		int32_t event_id{};
	public:
		uint16_t reward_sequence{};
	public:
		bool is_advertisement{};
	public:
		int64_t auid{};

	public:
		mweb_event_reward_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &event_id);
			protocol::SerializeType(pBuffer, &reward_sequence);
			protocol::SerializeType(pBuffer, &is_advertisement);
			protocol::SerializeType(pBuffer, &auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_event_reward_sc : public WebBasePacket 
	{
	public:
		int32_t result{};
	public:
		int32_t event_id{};
	public:
		uint16_t reward_sequence{};

	public:
		mweb_event_reward_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &event_id);
			protocol::SerializeType(pBuffer, &reward_sequence);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
