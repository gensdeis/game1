#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_vector.h"

namespace mir3d
{
	class mp_zone_teleport_ai_return_cs : public BasePacket 
	{
	private:
		bool flag_return_pos = false;
		mps_vector return_pos;
		mps_vector* p_return_pos = nullptr;
	public:
		bool has_return_pos() const
		{
			return flag_return_pos;
		}
		mps_vector* alloc_return_pos()
		{
			flag_return_pos = true;
			return &return_pos;
		}
		const mps_vector* get_return_pos() const
		{
			if (true == flag_return_pos)
			{
				if (nullptr == p_return_pos)
				{
					return &return_pos;
				}
				return p_return_pos;
			}
			return nullptr;
		}
		void set_return_pos(mps_vector* in_return_pos)
		{
			if (nullptr == p_return_pos)
			{
				p_return_pos = in_return_pos;
				flag_return_pos = true;
			}
		}
	public:
		int32_t map_id{};

	public:
		mp_zone_teleport_ai_return_cs() : BasePacket(mpe_cmd::zone_teleport_ai_return_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_return_pos);
			if (true == flag_return_pos)
			{
				if (nullptr != p_return_pos)
					protocol::SerializeType(pBuffer, p_return_pos);
				else
					protocol::SerializeType(pBuffer, &return_pos);
			}
			protocol::SerializeType(pBuffer, &map_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_zone_teleport_ai_return_sc : public BasePacket 
	{

	public:
		mp_zone_teleport_ai_return_sc() : BasePacket(mpe_cmd::zone_teleport_ai_return_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
