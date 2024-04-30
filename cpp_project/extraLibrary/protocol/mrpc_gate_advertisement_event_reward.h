#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_character_advertisement.h"
#include "struct/mps_advertisement_event.h"

namespace mir3d
{
	class mrpc_gate_advertisement_event_reward_cs : public RpcPacket 	// 광고 출석 보상
	{
	public:
		int64_t key{};
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
		mrpc_gate_advertisement_event_reward_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_advertisement_event_reward_cs, tag)
		{
		}
		mrpc_gate_advertisement_event_reward_cs() : RpcPacket(mpe_rpc_cmd::gate_advertisement_event_reward_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &event_id);
			protocol::SerializeType(pBuffer, &reward_sequence);
			protocol::SerializeType(pBuffer, &client_guid);
			protocol::SerializeType(pBuffer, &player_key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_advertisement_event_reward_sc : public RpcPacket 	// 광고 출석 보상
	{
	public:
		int64_t key{};
	public:
		int32_t result{};
	public:
		int32_t event_id{};
	public:
		uint16_t reward_sequence{};
	private:
		bool flag_character_advertisement = false;
		mps_character_advertisement character_advertisement;
		mps_character_advertisement* p_character_advertisement = nullptr;
	public:
		bool has_character_advertisement() const
		{
			return flag_character_advertisement;
		}
		mps_character_advertisement* alloc_character_advertisement()
		{
			flag_character_advertisement = true;
			return &character_advertisement;
		}
		const mps_character_advertisement* get_character_advertisement() const
		{
			if (true == flag_character_advertisement)
			{
				if (nullptr == p_character_advertisement)
				{
					return &character_advertisement;
				}
				return p_character_advertisement;
			}
			return nullptr;
		}
		void set_character_advertisement(mps_character_advertisement* in_character_advertisement)
		{
			if (nullptr == p_character_advertisement)
			{
				p_character_advertisement = in_character_advertisement;
				flag_character_advertisement = true;
			}
		}
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
		mrpc_gate_advertisement_event_reward_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_advertisement_event_reward_sc, tag)
		{
		}
		mrpc_gate_advertisement_event_reward_sc() : RpcPacket(mpe_rpc_cmd::gate_advertisement_event_reward_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &event_id);
			protocol::SerializeType(pBuffer, &reward_sequence);
			protocol::SerializeType(pBuffer, &flag_character_advertisement);
			if (true == flag_character_advertisement)
			{
				if (nullptr != p_character_advertisement)
					protocol::SerializeType(pBuffer, p_character_advertisement);
				else
					protocol::SerializeType(pBuffer, &character_advertisement);
			}
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
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
