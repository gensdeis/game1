#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_castle_town_arsenal_build_donate_cs : public RpcPacket 	// 공성 무기 제작 기부
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
		mrpc_castle_town_arsenal_build_donate_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_arsenal_build_donate_cs, tag)
		{
		}
		mrpc_castle_town_arsenal_build_donate_cs() : RpcPacket(mpe_rpc_cmd::castle_town_arsenal_build_donate_cs)
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

	class mrpc_castle_town_arsenal_build_donate_sc : public RpcPacket 	// 공성 무기 제작 기부
	{
	public:
		int64_t key{};
	public:
		int32_t town_id{};
	public:
		int32_t build_value{};
	public:
		int32_t build_user_count{};
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
		mrpc_castle_town_arsenal_build_donate_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_town_arsenal_build_donate_sc, tag)
		{
		}
		mrpc_castle_town_arsenal_build_donate_sc() : RpcPacket(mpe_rpc_cmd::castle_town_arsenal_build_donate_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeType(pBuffer, &build_value);
			protocol::SerializeType(pBuffer, &build_user_count);
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

}
