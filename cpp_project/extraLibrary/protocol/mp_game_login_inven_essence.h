#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_inventory.h"

namespace mir3d
{
	class mp_game_login_inven_essence_cs : public BasePacket 
	{

	public:
		mp_game_login_inven_essence_cs() : BasePacket(mpe_cmd::game_login_inven_essence_cs)
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

	class mp_game_login_inven_essence_sc : public BasePacket 
	{
	private:
		bool flag_inven_essence = false;
		mps_inventory inven_essence;
		mps_inventory* p_inven_essence = nullptr;
	public:
		bool has_inven_essence() const
		{
			return flag_inven_essence;
		}
		mps_inventory* alloc_inven_essence()
		{
			flag_inven_essence = true;
			return &inven_essence;
		}
		const mps_inventory* get_inven_essence() const
		{
			if (true == flag_inven_essence)
			{
				if (nullptr == p_inven_essence)
				{
					return &inven_essence;
				}
				return p_inven_essence;
			}
			return nullptr;
		}
		void set_inven_essence(mps_inventory* in_inven_essence)
		{
			if (nullptr == p_inven_essence)
			{
				p_inven_essence = in_inven_essence;
				flag_inven_essence = true;
			}
		}

	public:
		mp_game_login_inven_essence_sc() : BasePacket(mpe_cmd::game_login_inven_essence_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_inven_essence);
			if (true == flag_inven_essence)
			{
				if (nullptr != p_inven_essence)
					protocol::SerializeType(pBuffer, p_inven_essence);
				else
					protocol::SerializeType(pBuffer, &inven_essence);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
