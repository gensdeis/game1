#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_quest.h"
#include "struct/mps_quest_history.h"
#include "struct/mps_quest.h"

namespace mir3d
{
	class mrpc_gm_quest_accept_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_quest> info{};
	private:
		bool flag_history = false;
		mps_quest_history history;
		mps_quest_history* p_history = nullptr;
	public:
		bool has_history() const
		{
			return flag_history;
		}
		mps_quest_history* alloc_history()
		{
			flag_history = true;
			return &history;
		}
		const mps_quest_history* get_history() const
		{
			if (true == flag_history)
			{
				if (nullptr == p_history)
				{
					return &history;
				}
				return p_history;
			}
			return nullptr;
		}
		void set_history(mps_quest_history* in_history)
		{
			if (nullptr == p_history)
			{
				p_history = in_history;
				flag_history = true;
			}
		}
	public:
		std::vector<uint16_t> delete_list_id{};	// 퀘스트 삭제 목록

	public:
		mrpc_gm_quest_accept_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_quest_accept_cs, tag)
		{
		}
		mrpc_gm_quest_accept_cs() : RpcPacket(mpe_rpc_cmd::gm_quest_accept_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeType(pBuffer, &flag_history);
			if (true == flag_history)
			{
				if (nullptr != p_history)
					protocol::SerializeType(pBuffer, p_history);
				else
					protocol::SerializeType(pBuffer, &history);
			}
			protocol::SerializeType(pBuffer, &delete_list_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_quest_accept_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		std::vector<mps_quest> info{};

	public:
		mrpc_gm_quest_accept_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_quest_accept_sc, tag)
		{
		}
		mrpc_gm_quest_accept_sc() : RpcPacket(mpe_rpc_cmd::gm_quest_accept_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
