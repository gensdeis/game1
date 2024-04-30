#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_gameitem_update.h"
#include "struct/mps_profesion.h"
#include "struct/mps_decrement_item_durability.h"
#include "struct/mrpcs_castle_town_specialties_work.h"

namespace mir3d
{
	class mrpc_zone_fish_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t flag{};
	public:
		int32_t result{};
	private:
		bool flag_info = false;
		mps_gameitem_update info;	// 아이템 갱신
		mps_gameitem_update* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_gameitem_update* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_gameitem_update* get_info() const
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
		void set_info(mps_gameitem_update* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	private:
		bool flag_profesion = false;
		mps_profesion profesion;	// 대가정보 갱신
		mps_profesion* p_profesion = nullptr;
	public:
		bool has_profesion() const
		{
			return flag_profesion;
		}
		mps_profesion* alloc_profesion()
		{
			flag_profesion = true;
			return &profesion;
		}
		const mps_profesion* get_profesion() const
		{
			if (true == flag_profesion)
			{
				if (nullptr == p_profesion)
				{
					return &profesion;
				}
				return p_profesion;
			}
			return nullptr;
		}
		void set_profesion(mps_profesion* in_profesion)
		{
			if (nullptr == p_profesion)
			{
				p_profesion = in_profesion;
				flag_profesion = true;
			}
		}
	private:
		bool flag_durability = false;
		mps_decrement_item_durability durability;	// 내구도 정보
		mps_decrement_item_durability* p_durability = nullptr;
	public:
		bool has_durability() const
		{
			return flag_durability;
		}
		mps_decrement_item_durability* alloc_durability()
		{
			flag_durability = true;
			return &durability;
		}
		const mps_decrement_item_durability* get_durability() const
		{
			if (true == flag_durability)
			{
				if (nullptr == p_durability)
				{
					return &durability;
				}
				return p_durability;
			}
			return nullptr;
		}
		void set_durability(mps_decrement_item_durability* in_durability)
		{
			if (nullptr == p_durability)
			{
				p_durability = in_durability;
				flag_durability = true;
			}
		}
	private:
		bool flag_specialties_work = false;
		mrpcs_castle_town_specialties_work specialties_work;	// 장원 특산품
		mrpcs_castle_town_specialties_work* p_specialties_work = nullptr;
	public:
		bool has_specialties_work() const
		{
			return flag_specialties_work;
		}
		mrpcs_castle_town_specialties_work* alloc_specialties_work()
		{
			flag_specialties_work = true;
			return &specialties_work;
		}
		const mrpcs_castle_town_specialties_work* get_specialties_work() const
		{
			if (true == flag_specialties_work)
			{
				if (nullptr == p_specialties_work)
				{
					return &specialties_work;
				}
				return p_specialties_work;
			}
			return nullptr;
		}
		void set_specialties_work(mrpcs_castle_town_specialties_work* in_specialties_work)
		{
			if (nullptr == p_specialties_work)
			{
				p_specialties_work = in_specialties_work;
				flag_specialties_work = true;
			}
		}

	public:
		mrpc_zone_fish_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::zone_fish_cs, tag)
		{
		}
		mrpc_zone_fish_cs() : RpcPacket(mpe_rpc_cmd::zone_fish_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &flag_profesion);
			if (true == flag_profesion)
			{
				if (nullptr != p_profesion)
					protocol::SerializeType(pBuffer, p_profesion);
				else
					protocol::SerializeType(pBuffer, &profesion);
			}
			protocol::SerializeType(pBuffer, &flag_durability);
			if (true == flag_durability)
			{
				if (nullptr != p_durability)
					protocol::SerializeType(pBuffer, p_durability);
				else
					protocol::SerializeType(pBuffer, &durability);
			}
			protocol::SerializeType(pBuffer, &flag_specialties_work);
			if (true == flag_specialties_work)
			{
				if (nullptr != p_specialties_work)
					protocol::SerializeType(pBuffer, p_specialties_work);
				else
					protocol::SerializeType(pBuffer, &specialties_work);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_zone_fish_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_zone_fish_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::zone_fish_sc, tag)
		{
		}
		mrpc_zone_fish_sc() : RpcPacket(mpe_rpc_cmd::zone_fish_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
