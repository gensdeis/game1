#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_dungeon.h"

namespace mir3d
{
	class mrpc_indun_play_count_cs : public RpcPacket 
	{
	private:
		bool flag_info = false;
		mps_dungeon info;
		mps_dungeon* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_dungeon* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_dungeon* get_info() const
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
		void set_info(mps_dungeon* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		int64_t cuid{};

	public:
		mrpc_indun_play_count_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::indun_play_count_cs, tag)
		{
		}
		mrpc_indun_play_count_cs() : RpcPacket(mpe_rpc_cmd::indun_play_count_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_indun_play_count_sc : public RpcPacket 
	{

	public:
		mrpc_indun_play_count_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::indun_play_count_sc, tag)
		{
		}
		mrpc_indun_play_count_sc() : RpcPacket(mpe_rpc_cmd::indun_play_count_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
