#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_game_setup.h"

namespace mir3d
{
	class mweb_game_setup_select_cs : public WebBasePacket 
	{
	public:
		int64_t cuid{};

	public:
		mweb_game_setup_select_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_game_setup_select_sc : public WebBasePacket 
	{
	private:
		bool flag_game_setup = false;
		mps_game_setup game_setup;
		mps_game_setup* p_game_setup = nullptr;
	public:
		bool has_game_setup() const
		{
			return flag_game_setup;
		}
		mps_game_setup* alloc_game_setup()
		{
			flag_game_setup = true;
			return &game_setup;
		}
		const mps_game_setup* get_game_setup() const
		{
			if (true == flag_game_setup)
			{
				if (nullptr == p_game_setup)
				{
					return &game_setup;
				}
				return p_game_setup;
			}
			return nullptr;
		}
		void set_game_setup(mps_game_setup* in_game_setup)
		{
			if (nullptr == p_game_setup)
			{
				p_game_setup = in_game_setup;
				flag_game_setup = true;
			}
		}

	public:
		mweb_game_setup_select_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_game_setup);
			if (true == flag_game_setup)
			{
				if (nullptr != p_game_setup)
					protocol::SerializeType(pBuffer, p_game_setup);
				else
					protocol::SerializeType(pBuffer, &game_setup);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
