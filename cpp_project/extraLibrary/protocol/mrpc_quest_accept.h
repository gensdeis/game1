#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_quest.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mrpc_quest_accept_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_quest> info{};
	public:
		uint16_t last_main_id{};	// 마지막퀘스트
	public:
		int32_t count{};	// *2byte
	public:
		std::vector<uint8_t> data{};
	public:
		int32_t profession_quest_count{};	// *2byte
	public:
		std::vector<uint8_t> profession_quest_data{};
	public:
		int32_t profession_quest_reset_time{};
	private:
		bool flag_update_item = false;
		mps_item_count_update update_item;
		mps_item_count_update* p_update_item = nullptr;
	public:
		bool has_update_item() const
		{
			return flag_update_item;
		}
		mps_item_count_update* alloc_update_item()
		{
			flag_update_item = true;
			return &update_item;
		}
		const mps_item_count_update* get_update_item() const
		{
			if (true == flag_update_item)
			{
				if (nullptr == p_update_item)
				{
					return &update_item;
				}
				return p_update_item;
			}
			return nullptr;
		}
		void set_update_item(mps_item_count_update* in_update_item)
		{
			if (nullptr == p_update_item)
			{
				p_update_item = in_update_item;
				flag_update_item = true;
			}
		}

	public:
		mrpc_quest_accept_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::quest_accept_cs, tag)
		{
		}
		mrpc_quest_accept_cs() : RpcPacket(mpe_rpc_cmd::quest_accept_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeType(pBuffer, &last_main_id);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &data);
			protocol::SerializeType(pBuffer, &profession_quest_count);
			protocol::SerializeType(pBuffer, &profession_quest_data);
			protocol::SerializeType(pBuffer, &profession_quest_reset_time);
			protocol::SerializeType(pBuffer, &flag_update_item);
			if (true == flag_update_item)
			{
				if (nullptr != p_update_item)
					protocol::SerializeType(pBuffer, p_update_item);
				else
					protocol::SerializeType(pBuffer, &update_item);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_quest_accept_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_quest_accept_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::quest_accept_sc, tag)
		{
		}
		mrpc_quest_accept_sc() : RpcPacket(mpe_rpc_cmd::quest_accept_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
