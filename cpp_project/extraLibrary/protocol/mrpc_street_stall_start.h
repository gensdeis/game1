#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_zone_info.h"
#include "struct/mps_item_add.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_street_stall_start_cs : public RpcPacket 	// // 개인 노점 생성 저장
	{
	public:
		int64_t suid{};	// // 개인 노점 uid
	public:
		int64_t cuid{};
	public:
		int32_t tid{};
	public:
		int32_t profesion_table_id{};
	public:
		std::string street_stall_title{};
	private:
		bool flag_position = false;
		mps_zone_info position;	// // 개인 노점 위치
		mps_zone_info* p_position = nullptr;
	public:
		bool has_position() const
		{
			return flag_position;
		}
		mps_zone_info* alloc_position()
		{
			flag_position = true;
			return &position;
		}
		const mps_zone_info* get_position() const
		{
			if (true == flag_position)
			{
				if (nullptr == p_position)
				{
					return &position;
				}
				return p_position;
			}
			return nullptr;
		}
		void set_position(mps_zone_info* in_position)
		{
			if (nullptr == p_position)
			{
				p_position = in_position;
				flag_position = true;
			}
		}
	public:
		int32_t use_count{};	// // 거래 가능 count
	public:
		int64_t life_time{};
	public:
		mrpce_server_type server_type{};
	public:
		int32_t server_index{};
	public:
		int64_t channel_uid{};
	public:
		uint16_t channel_id{};
	private:
		bool flag_item_info = false;
		mps_item_add item_info;
		mps_item_add* p_item_info = nullptr;
	public:
		bool has_item_info() const
		{
			return flag_item_info;
		}
		mps_item_add* alloc_item_info()
		{
			flag_item_info = true;
			return &item_info;
		}
		const mps_item_add* get_item_info() const
		{
			if (true == flag_item_info)
			{
				if (nullptr == p_item_info)
				{
					return &item_info;
				}
				return p_item_info;
			}
			return nullptr;
		}
		void set_item_info(mps_item_add* in_item_info)
		{
			if (nullptr == p_item_info)
			{
				p_item_info = in_item_info;
				flag_item_info = true;
			}
		}

	public:
		mrpc_street_stall_start_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::street_stall_start_cs, tag)
		{
		}
		mrpc_street_stall_start_cs() : RpcPacket(mpe_rpc_cmd::street_stall_start_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &suid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &profesion_table_id);
			protocol::SerializeType(pBuffer, &street_stall_title);
			protocol::SerializeType(pBuffer, &flag_position);
			if (true == flag_position)
			{
				if (nullptr != p_position)
					protocol::SerializeType(pBuffer, p_position);
				else
					protocol::SerializeType(pBuffer, &position);
			}
			protocol::SerializeType(pBuffer, &use_count);
			protocol::SerializeType(pBuffer, &life_time);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &channel_id);
			protocol::SerializeType(pBuffer, &flag_item_info);
			if (true == flag_item_info)
			{
				if (nullptr != p_item_info)
					protocol::SerializeType(pBuffer, p_item_info);
				else
					protocol::SerializeType(pBuffer, &item_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_street_stall_start_sc : public RpcPacket 	// // 개인 노점 생성 저장
	{
	public:
		int64_t suid{};
	public:
		int64_t cuid{};
	private:
		bool flag_item_info = false;
		mps_item_add item_info;
		mps_item_add* p_item_info = nullptr;
	public:
		bool has_item_info() const
		{
			return flag_item_info;
		}
		mps_item_add* alloc_item_info()
		{
			flag_item_info = true;
			return &item_info;
		}
		const mps_item_add* get_item_info() const
		{
			if (true == flag_item_info)
			{
				if (nullptr == p_item_info)
				{
					return &item_info;
				}
				return p_item_info;
			}
			return nullptr;
		}
		void set_item_info(mps_item_add* in_item_info)
		{
			if (nullptr == p_item_info)
			{
				p_item_info = in_item_info;
				flag_item_info = true;
			}
		}

	public:
		mrpc_street_stall_start_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::street_stall_start_sc, tag)
		{
		}
		mrpc_street_stall_start_sc() : RpcPacket(mpe_rpc_cmd::street_stall_start_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &suid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_item_info);
			if (true == flag_item_info)
			{
				if (nullptr != p_item_info)
					protocol::SerializeType(pBuffer, p_item_info);
				else
					protocol::SerializeType(pBuffer, &item_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
