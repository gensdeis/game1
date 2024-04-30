#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_shipwar_situation.h"

namespace mir3d
{
	class mp_guild_shipwar_situation_cs : public BasePacket 
	{
	public:
		bool intro{};

	public:
		mp_guild_shipwar_situation_cs() : BasePacket(mpe_cmd::guild_shipwar_situation_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &intro);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_shipwar_situation_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_guild_shipwar_situation info;
		mps_guild_shipwar_situation* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_guild_shipwar_situation* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_guild_shipwar_situation* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mps_guild_shipwar_situation* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		bool intro{};

	public:
		mp_guild_shipwar_situation_sc() : BasePacket(mpe_cmd::guild_shipwar_situation_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &intro);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
