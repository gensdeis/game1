#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_town_info.h"

namespace mir3d
{
	class mrpc_town_rental_continuation_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};

	public:
		mrpc_town_rental_continuation_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::town_rental_continuation_cs, tag)
		{
		}
		mrpc_town_rental_continuation_cs() : RpcPacket(mpe_rpc_cmd::town_rental_continuation_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_town_rental_continuation_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	private:
		bool flag_town_info = false;
		mps_guild_town_info town_info;
		mps_guild_town_info* p_town_info = nullptr;
	public:
		bool has_town_info() const
		{
			return flag_town_info;
		}
		mps_guild_town_info* alloc_town_info()
		{
			flag_town_info = true;
			return &town_info;
		}
		const mps_guild_town_info* get_town_info() const
		{
			if (true == flag_town_info)
			{
				if (nullptr == p_town_info)
				{
					return &town_info;
				}
				return p_town_info;
			}
			return nullptr;
		}
		void set_town_info(mps_guild_town_info* in_town_info)
		{
			if (nullptr == p_town_info)
			{
				p_town_info = in_town_info;
				flag_town_info = true;
			}
		}

	public:
		mrpc_town_rental_continuation_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::town_rental_continuation_sc, tag)
		{
		}
		mrpc_town_rental_continuation_sc() : RpcPacket(mpe_rpc_cmd::town_rental_continuation_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &flag_town_info);
			if (true == flag_town_info)
			{
				if (nullptr != p_town_info)
					protocol::SerializeType(pBuffer, p_town_info);
				else
					protocol::SerializeType(pBuffer, &town_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
