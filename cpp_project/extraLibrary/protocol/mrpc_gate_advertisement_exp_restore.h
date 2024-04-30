#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_character_advertisement.h"

namespace mir3d
{
	class mrpc_gate_advertisement_exp_restore_cs : public RpcPacket 	// 광고 경험치 복구
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		uint16_t revive_id{};
	public:
		std::string client_guid{};	// WMM Client GUID
	public:
		std::string player_key{};	// WMM Client Key

	public:
		mrpc_gate_advertisement_exp_restore_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_advertisement_exp_restore_cs, tag)
		{
		}
		mrpc_gate_advertisement_exp_restore_cs() : RpcPacket(mpe_rpc_cmd::gate_advertisement_exp_restore_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &revive_id);
			protocol::SerializeType(pBuffer, &client_guid);
			protocol::SerializeType(pBuffer, &player_key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_advertisement_exp_restore_sc : public RpcPacket 	// 광고 경험치 복구
	{
	public:
		int64_t key{};
	public:
		int32_t result{};
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
	public:
		int32_t api_code{};	// API CODE

	public:
		mrpc_gate_advertisement_exp_restore_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_advertisement_exp_restore_sc, tag)
		{
		}
		mrpc_gate_advertisement_exp_restore_sc() : RpcPacket(mpe_rpc_cmd::gate_advertisement_exp_restore_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &flag_character_advertisement);
			if (true == flag_character_advertisement)
			{
				if (nullptr != p_character_advertisement)
					protocol::SerializeType(pBuffer, p_character_advertisement);
				else
					protocol::SerializeType(pBuffer, &character_advertisement);
			}
			protocol::SerializeType(pBuffer, &api_code);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
