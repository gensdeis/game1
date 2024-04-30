#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_vector.h"
#include "struct/mps_map_discovery.h"

namespace mir3d
{
	class mp_map_discovery_update_cs : public BasePacket 	// outgame - map discovery
	{
	public:
		int32_t map_id{};
	public:
		int32_t area_id{};
	private:
		bool flag_current_pos = false;
		mps_vector current_pos;
		mps_vector* p_current_pos = nullptr;
	public:
		bool has_current_pos() const
		{
			return flag_current_pos;
		}
		mps_vector* alloc_current_pos()
		{
			flag_current_pos = true;
			return &current_pos;
		}
		const mps_vector* get_current_pos() const
		{
			if (true == flag_current_pos)
			{
				if (nullptr == p_current_pos)
				{
					return &current_pos;
				}
				return p_current_pos;
			}
			return nullptr;
		}
		void set_current_pos(mps_vector* in_current_pos)
		{
			if (nullptr == p_current_pos)
			{
				p_current_pos = in_current_pos;
				flag_current_pos = true;
			}
		}

	public:
		mp_map_discovery_update_cs() : BasePacket(mpe_cmd::map_discovery_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &map_id);
			protocol::SerializeType(pBuffer, &area_id);
			protocol::SerializeType(pBuffer, &flag_current_pos);
			if (true == flag_current_pos)
			{
				if (nullptr != p_current_pos)
					protocol::SerializeType(pBuffer, p_current_pos);
				else
					protocol::SerializeType(pBuffer, &current_pos);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_map_discovery_update_sc : public BasePacket 	// outgame - map discovery
	{
	private:
		bool flag_area_info = false;
		mps_map_discovery area_info;
		mps_map_discovery* p_area_info = nullptr;
	public:
		bool has_area_info() const
		{
			return flag_area_info;
		}
		mps_map_discovery* alloc_area_info()
		{
			flag_area_info = true;
			return &area_info;
		}
		const mps_map_discovery* get_area_info() const
		{
			if (true == flag_area_info)
			{
				if (nullptr == p_area_info)
				{
					return &area_info;
				}
				return p_area_info;
			}
			return nullptr;
		}
		void set_area_info(mps_map_discovery* in_area_info)
		{
			if (nullptr == p_area_info)
			{
				p_area_info = in_area_info;
				flag_area_info = true;
			}
		}

	public:
		mp_map_discovery_update_sc() : BasePacket(mpe_cmd::map_discovery_update_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_area_info);
			if (true == flag_area_info)
			{
				if (nullptr != p_area_info)
					protocol::SerializeType(pBuffer, p_area_info);
				else
					protocol::SerializeType(pBuffer, &area_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
