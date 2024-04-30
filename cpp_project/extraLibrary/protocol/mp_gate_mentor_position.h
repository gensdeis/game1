#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_vector.h"

namespace mir3d
{
	class mp_gate_mentor_position_cs : public BasePacket 
	{
	public:
		int64_t cuid{};

	public:
		mp_gate_mentor_position_cs() : BasePacket(mpe_cmd::gate_mentor_position_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_mentor_position_sc : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		int32_t id{};
	public:
		bool connect{};
	public:
		std::string guild_name{};
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		int32_t level{};
	public:
		std::string nickname{};
	public:
		int64_t last_online_time{};
	public:
		int32_t map_id{};
	public:
		uint16_t channel_id{};
	private:
		bool flag_pos = false;
		mps_vector pos;
		mps_vector* p_pos = nullptr;
	public:
		bool has_pos() const
		{
			return flag_pos;
		}
		mps_vector* alloc_pos()
		{
			flag_pos = true;
			return &pos;
		}
		const mps_vector* get_pos() const
		{
			if (true == flag_pos)
			{
				if (nullptr == p_pos)
				{
					return &pos;
				}
				return p_pos;
			}
			return nullptr;
		}
		void set_pos(mps_vector* in_pos)
		{
			if (nullptr == p_pos)
			{
				p_pos = in_pos;
				flag_pos = true;
			}
		}

	public:
		mp_gate_mentor_position_sc() : BasePacket(mpe_cmd::gate_mentor_position_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &connect);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &last_online_time);
			protocol::SerializeType(pBuffer, &map_id);
			protocol::SerializeType(pBuffer, &channel_id);
			protocol::SerializeType(pBuffer, &flag_pos);
			if (true == flag_pos)
			{
				if (nullptr != p_pos)
					protocol::SerializeType(pBuffer, p_pos);
				else
					protocol::SerializeType(pBuffer, &pos);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
