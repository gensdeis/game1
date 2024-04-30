#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_stat_update.h"

namespace mir3d
{
	class mp_zone_object_update_stat_cs : public BasePacket 
	{

	public:
		mp_zone_object_update_stat_cs() : BasePacket(mpe_cmd::zone_object_update_stat_cs)
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

	class mp_zone_object_update_stat_sc : public BasePacket 
	{
	private:
		bool flag_update_stat_list = false;
		mps_stat_update update_stat_list;
		mps_stat_update* p_update_stat_list = nullptr;
	public:
		bool has_update_stat_list() const
		{
			return flag_update_stat_list;
		}
		mps_stat_update* alloc_update_stat_list()
		{
			flag_update_stat_list = true;
			return &update_stat_list;
		}
		const mps_stat_update* get_update_stat_list() const
		{
			if (true == flag_update_stat_list)
			{
				if (nullptr == p_update_stat_list)
				{
					return &update_stat_list;
				}
				return p_update_stat_list;
			}
			return nullptr;
		}
		void set_update_stat_list(mps_stat_update* in_update_stat_list)
		{
			if (nullptr == p_update_stat_list)
			{
				p_update_stat_list = in_update_stat_list;
				flag_update_stat_list = true;
			}
		}

	public:
		mp_zone_object_update_stat_sc() : BasePacket(mpe_cmd::zone_object_update_stat_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_update_stat_list);
			if (true == flag_update_stat_list)
			{
				if (nullptr != p_update_stat_list)
					protocol::SerializeType(pBuffer, p_update_stat_list);
				else
					protocol::SerializeType(pBuffer, &update_stat_list);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
