#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_castle_town_work.h"
#include "struct/mps_item_add.h"
#include "struct/mps_castle_town_building_info.h"

namespace mir3d
{
	class mrpc_castle_town_work_cs : public RpcPacket 	// 장원 작업
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int32_t town_id{};
	public:
		mpe_castle_town_work_type work_type{};	// 작업 타입
	public:
		mpe_castle_town_detail_pos house_pos{};	// 하우스 type
	public:
		bool direct{};	// 바로 적용 여부
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
		mrpc_castle_town_work_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_work_cs, tag)
		{
		}
		mrpc_castle_town_work_cs() : RpcPacket(mpe_rpc_cmd::castle_town_work_cs)
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
			protocol::SerializeEnum(pBuffer, &work_type);
			protocol::SerializeEnum(pBuffer, &house_pos);
			protocol::SerializeType(pBuffer, &direct);
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

	class mrpc_castle_town_work_sc : public RpcPacket 	// 장원 작업
	{
	public:
		int64_t key{};
	public:
		bool direct{};	// 바로 적용 값
	private:
		bool flag_work = false;
		mps_castle_town_work work;
		mps_castle_town_work* p_work = nullptr;
	public:
		bool has_work() const
		{
			return flag_work;
		}
		mps_castle_town_work* alloc_work()
		{
			flag_work = true;
			return &work;
		}
		const mps_castle_town_work* get_work() const
		{
			if (true == flag_work)
			{
				if (nullptr == p_work)
				{
					return &work;
				}
				return p_work;
			}
			return nullptr;
		}
		void set_work(mps_castle_town_work* in_work)
		{
			if (nullptr == p_work)
			{
				p_work = in_work;
				flag_work = true;
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
	private:
		bool flag_building_info = false;
		mps_castle_town_building_info building_info;	// 건물정보
		mps_castle_town_building_info* p_building_info = nullptr;
	public:
		bool has_building_info() const
		{
			return flag_building_info;
		}
		mps_castle_town_building_info* alloc_building_info()
		{
			flag_building_info = true;
			return &building_info;
		}
		const mps_castle_town_building_info* get_building_info() const
		{
			if (true == flag_building_info)
			{
				if (nullptr == p_building_info)
				{
					return &building_info;
				}
				return p_building_info;
			}
			return nullptr;
		}
		void set_building_info(mps_castle_town_building_info* in_building_info)
		{
			if (nullptr == p_building_info)
			{
				p_building_info = in_building_info;
				flag_building_info = true;
			}
		}

	public:
		mrpc_castle_town_work_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_work_sc, tag)
		{
		}
		mrpc_castle_town_work_sc() : RpcPacket(mpe_rpc_cmd::castle_town_work_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &direct);
			protocol::SerializeType(pBuffer, &flag_work);
			if (true == flag_work)
			{
				if (nullptr != p_work)
					protocol::SerializeType(pBuffer, p_work);
				else
					protocol::SerializeType(pBuffer, &work);
			}
			protocol::SerializeType(pBuffer, &flag_use_item_info);
			if (true == flag_use_item_info)
			{
				if (nullptr != p_use_item_info)
					protocol::SerializeType(pBuffer, p_use_item_info);
				else
					protocol::SerializeType(pBuffer, &use_item_info);
			}
			protocol::SerializeType(pBuffer, &flag_building_info);
			if (true == flag_building_info)
			{
				if (nullptr != p_building_info)
					protocol::SerializeType(pBuffer, p_building_info);
				else
					protocol::SerializeType(pBuffer, &building_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
