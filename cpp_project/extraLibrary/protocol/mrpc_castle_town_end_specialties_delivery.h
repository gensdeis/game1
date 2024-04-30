#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_castle_town_character_specialties_work.h"

namespace mir3d
{
	class mrpc_castle_town_end_specialties_delivery_cs : public RpcPacket 
	{

	public:
		mrpc_castle_town_end_specialties_delivery_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_end_specialties_delivery_cs, tag)
		{
		}
		mrpc_castle_town_end_specialties_delivery_cs() : RpcPacket(mpe_rpc_cmd::castle_town_end_specialties_delivery_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_castle_town_end_specialties_delivery_sc : public RpcPacket 
	{
	public:
		int64_t guid{};
	private:
		bool flag_town_specialties_work = false;
		mps_castle_town_character_specialties_work town_specialties_work;
		mps_castle_town_character_specialties_work* p_town_specialties_work = nullptr;
	public:
		bool has_town_specialties_work() const
		{
			return flag_town_specialties_work;
		}
		mps_castle_town_character_specialties_work* alloc_town_specialties_work()
		{
			flag_town_specialties_work = true;
			return &town_specialties_work;
		}
		const mps_castle_town_character_specialties_work* get_town_specialties_work() const
		{
			if (true == flag_town_specialties_work)
			{
				if (nullptr == p_town_specialties_work)
				{
					return &town_specialties_work;
				}
				return p_town_specialties_work;
			}
			return nullptr;
		}
		void set_town_specialties_work(mps_castle_town_character_specialties_work* in_town_specialties_work)
		{
			if (nullptr == p_town_specialties_work)
			{
				p_town_specialties_work = in_town_specialties_work;
				flag_town_specialties_work = true;
			}
		}

	public:
		mrpc_castle_town_end_specialties_delivery_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_end_specialties_delivery_sc, tag)
		{
		}
		mrpc_castle_town_end_specialties_delivery_sc() : RpcPacket(mpe_rpc_cmd::castle_town_end_specialties_delivery_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &flag_town_specialties_work);
			if (true == flag_town_specialties_work)
			{
				if (nullptr != p_town_specialties_work)
					protocol::SerializeType(pBuffer, p_town_specialties_work);
				else
					protocol::SerializeType(pBuffer, &town_specialties_work);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
