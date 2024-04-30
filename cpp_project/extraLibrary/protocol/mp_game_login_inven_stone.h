#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_inventory.h"

namespace mir3d
{
	class mp_game_login_inven_stone_cs : public BasePacket 
	{

	public:
		mp_game_login_inven_stone_cs() : BasePacket(mpe_cmd::game_login_inven_stone_cs)
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

	class mp_game_login_inven_stone_sc : public BasePacket 
	{
	private:
		bool flag_inven_stone = false;
		mps_inventory inven_stone;
		mps_inventory* p_inven_stone = nullptr;
	public:
		bool has_inven_stone() const
		{
			return flag_inven_stone;
		}
		mps_inventory* alloc_inven_stone()
		{
			flag_inven_stone = true;
			return &inven_stone;
		}
		const mps_inventory* get_inven_stone() const
		{
			if (true == flag_inven_stone)
			{
				if (nullptr == p_inven_stone)
				{
					return &inven_stone;
				}
				return p_inven_stone;
			}
			return nullptr;
		}
		void set_inven_stone(mps_inventory* in_inven_stone)
		{
			if (nullptr == p_inven_stone)
			{
				p_inven_stone = in_inven_stone;
				flag_inven_stone = true;
			}
		}

	public:
		mp_game_login_inven_stone_sc() : BasePacket(mpe_cmd::game_login_inven_stone_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_inven_stone);
			if (true == flag_inven_stone)
			{
				if (nullptr != p_inven_stone)
					protocol::SerializeType(pBuffer, p_inven_stone);
				else
					protocol::SerializeType(pBuffer, &inven_stone);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
