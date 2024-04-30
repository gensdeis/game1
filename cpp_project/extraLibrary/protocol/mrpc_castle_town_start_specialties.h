#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_castle_town_character_specialties_work.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_castle_town_start_specialties_cs : public RpcPacket 	// 장원 특산품 시작
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int32_t town_id{};
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
	private:
		bool flag_use_item_info = false;
		mps_item_add use_item_info;	// 사용한 아이템 정보
		mps_item_add* p_use_item_info = nullptr;
	public:
		bool has_use_item_info() const
		{
			return flag_use_item_info;
		}
		mps_item_add* alloc_use_item_info()
		{
			flag_use_item_info = true;
			return &use_item_info;
		}
		const mps_item_add* get_use_item_info() const
		{
			if (true == flag_use_item_info)
			{
				if (nullptr == p_use_item_info)
				{
					return &use_item_info;
				}
				return p_use_item_info;
			}
			return nullptr;
		}
		void set_use_item_info(mps_item_add* in_use_item_info)
		{
			if (nullptr == p_use_item_info)
			{
				p_use_item_info = in_use_item_info;
				flag_use_item_info = true;
			}
		}

	public:
		mrpc_castle_town_start_specialties_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_start_specialties_cs, tag)
		{
		}
		mrpc_castle_town_start_specialties_cs() : RpcPacket(mpe_rpc_cmd::castle_town_start_specialties_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeType(pBuffer, &flag_town_specialties_work);
			if (true == flag_town_specialties_work)
			{
				if (nullptr != p_town_specialties_work)
					protocol::SerializeType(pBuffer, p_town_specialties_work);
				else
					protocol::SerializeType(pBuffer, &town_specialties_work);
			}
			protocol::SerializeType(pBuffer, &flag_use_item_info);
			if (true == flag_use_item_info)
			{
				if (nullptr != p_use_item_info)
					protocol::SerializeType(pBuffer, p_use_item_info);
				else
					protocol::SerializeType(pBuffer, &use_item_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_castle_town_start_specialties_sc : public RpcPacket 	// 장원 특산품 시작
	{
	public:
		int64_t key{};

	public:
		mrpc_castle_town_start_specialties_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_start_specialties_sc, tag)
		{
		}
		mrpc_castle_town_start_specialties_sc() : RpcPacket(mpe_rpc_cmd::castle_town_start_specialties_sc)
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
