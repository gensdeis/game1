#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_inventory.h"

namespace mir3d
{
	class mp_game_login_inven_cs : public BasePacket 
	{

	public:
		mp_game_login_inven_cs() : BasePacket(mpe_cmd::game_login_inven_cs)
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

	class mp_game_login_inven_sc : public BasePacket 
	{
	private:
		bool flag_inven = false;
		mps_inventory inven;
		mps_inventory* p_inven = nullptr;
	public:
		bool has_inven() const
		{
			return flag_inven;
		}
		mps_inventory* alloc_inven()
		{
			flag_inven = true;
			return &inven;
		}
		const mps_inventory* get_inven() const
		{
			if (true == flag_inven)
			{
				if (nullptr == p_inven)
				{
					return &inven;
				}
				return p_inven;
			}
			return nullptr;
		}
		void set_inven(mps_inventory* in_inven)
		{
			if (nullptr == p_inven)
			{
				p_inven = in_inven;
				flag_inven = true;
			}
		}

	public:
		mp_game_login_inven_sc() : BasePacket(mpe_cmd::game_login_inven_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_inven);
			if (true == flag_inven)
			{
				if (nullptr != p_inven)
					protocol::SerializeType(pBuffer, p_inven);
				else
					protocol::SerializeType(pBuffer, &inven);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
