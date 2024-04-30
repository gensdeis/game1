#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_quest.h"
#include "struct/mps_quest_history.h"

namespace mir3d
{
	class mp_gm_quest_accept_cs : public BasePacket 
	{
	public:
		uint16_t tid{};

	public:
		mp_gm_quest_accept_cs() : BasePacket(mpe_cmd::gm_quest_accept_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_quest_accept_sc : public BasePacket 
	{
	public:
		std::vector<mps_quest> list_quest{};
	public:
		std::vector<uint16_t> delete_tid{};
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
		mp_gm_quest_accept_sc() : BasePacket(mpe_cmd::gm_quest_accept_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_quest);
			protocol::SerializeType(pBuffer, &delete_tid);
			protocol::SerializeType(pBuffer, &flag_history);
			if (true == flag_history)
			{
				if (nullptr != p_history)
					protocol::SerializeType(pBuffer, p_history);
				else
					protocol::SerializeType(pBuffer, &history);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
