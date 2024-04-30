#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods.h"

namespace mir3d
{
	class mrpc_repute_quest_finish_count_reset_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_info = false;
		mps_update_goods info;
		mps_update_goods* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_update_goods* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_update_goods* get_info() const
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
		void set_info(mps_update_goods* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		int32_t repute_quest_last_daily_reset_time{};
	public:
		int32_t repute_quest_daily_reset_count{};

	public:
		mrpc_repute_quest_finish_count_reset_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::repute_quest_finish_count_reset_cs, tag)
		{
		}
		mrpc_repute_quest_finish_count_reset_cs() : RpcPacket(mpe_rpc_cmd::repute_quest_finish_count_reset_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &repute_quest_last_daily_reset_time);
			protocol::SerializeType(pBuffer, &repute_quest_daily_reset_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_repute_quest_finish_count_reset_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_repute_quest_finish_count_reset_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::repute_quest_finish_count_reset_sc, tag)
		{
		}
		mrpc_repute_quest_finish_count_reset_sc() : RpcPacket(mpe_rpc_cmd::repute_quest_finish_count_reset_sc)
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
