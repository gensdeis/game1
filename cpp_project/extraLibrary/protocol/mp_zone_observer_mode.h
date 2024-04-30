#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_zone_object_info.h"
#include "struct/mps_zone_object_info.h"

namespace mir3d
{
	class mp_zone_observer_mode_cs : public BasePacket 
	{

	public:
		mp_zone_observer_mode_cs() : BasePacket(mpe_cmd::zone_observer_mode_cs)
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

	class mp_zone_observer_mode_sc : public BasePacket 
	{
	private:
		bool flag_target_player = false;
		mps_zone_object_info target_player;
		mps_zone_object_info* p_target_player = nullptr;
	public:
		bool has_target_player() const
		{
			return flag_target_player;
		}
		mps_zone_object_info* alloc_target_player()
		{
			flag_target_player = true;
			return &target_player;
		}
		const mps_zone_object_info* get_target_player() const
		{
			if (true == flag_target_player)
			{
				if (nullptr == p_target_player)
				{
					return &target_player;
				}
				return p_target_player;
			}
			return nullptr;
		}
		void set_target_player(mps_zone_object_info* in_target_player)
		{
			if (nullptr == p_target_player)
			{
				p_target_player = in_target_player;
				flag_target_player = true;
			}
		}
	public:
		std::vector<mps_zone_object_info> object_info{};

	public:
		mp_zone_observer_mode_sc() : BasePacket(mpe_cmd::zone_observer_mode_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_target_player);
			if (true == flag_target_player)
			{
				if (nullptr != p_target_player)
					protocol::SerializeType(pBuffer, p_target_player);
				else
					protocol::SerializeType(pBuffer, &target_player);
			}
			protocol::SerializeType(pBuffer, &object_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
