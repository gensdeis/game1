#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_boss_dungeon_record.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_boss_dungeon_clear_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_record = false;
		mps_boss_dungeon_record record;	// 총 클리어 시간
		mps_boss_dungeon_record* p_record = nullptr;
	public:
		bool has_record() const
		{
			return flag_record;
		}
		mps_boss_dungeon_record* alloc_record()
		{
			flag_record = true;
			return &record;
		}
		const mps_boss_dungeon_record* get_record() const
		{
			if (true == flag_record)
			{
				if (nullptr == p_record)
				{
					return &record;
				}
				return p_record;
			}
			return nullptr;
		}
		void set_record(mps_boss_dungeon_record* in_record)
		{
			if (nullptr == p_record)
			{
				p_record = in_record;
				flag_record = true;
			}
		}
	private:
		bool flag_info = false;
		mps_item_add info;
		mps_item_add* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_add* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_add* get_info() const
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
		void set_info(mps_item_add* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		int64_t clear_update_time{};	// 던전 종료시간 (unixtime)
	public:
		bool new_record{};

	public:
		mrpc_boss_dungeon_clear_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::boss_dungeon_clear_cs, tag)
		{
		}
		mrpc_boss_dungeon_clear_cs() : RpcPacket(mpe_rpc_cmd::boss_dungeon_clear_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_record);
			if (true == flag_record)
			{
				if (nullptr != p_record)
					protocol::SerializeType(pBuffer, p_record);
				else
					protocol::SerializeType(pBuffer, &record);
			}
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &clear_update_time);
			protocol::SerializeType(pBuffer, &new_record);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_boss_dungeon_clear_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_boss_dungeon_clear_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::boss_dungeon_clear_sc, tag)
		{
		}
		mrpc_boss_dungeon_clear_sc() : RpcPacket(mpe_rpc_cmd::boss_dungeon_clear_sc)
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
