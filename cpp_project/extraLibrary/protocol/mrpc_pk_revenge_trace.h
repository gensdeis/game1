#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_count_update.h"
#include "struct/mps_vector.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mrpc_pk_revenge_trace_cs : public RpcPacket 	// pk 복수 유저 찾기
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t target_cuid{};
	private:
		bool flag_info = false;
		mps_item_count_update info;
		mps_item_count_update* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_count_update* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_count_update* get_info() const
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
		void set_info(mps_item_count_update* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		int64_t record_id{};

	public:
		mrpc_pk_revenge_trace_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::pk_revenge_trace_cs, tag)
		{
		}
		mrpc_pk_revenge_trace_cs() : RpcPacket(mpe_rpc_cmd::pk_revenge_trace_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &record_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_pk_revenge_trace_sc : public RpcPacket 	// pk 복수 유저 찾기
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t target_cuid{};
	public:
		mpe_pk_revenge_trace trace_result{};
	public:
		int32_t zone_id{};
	private:
		bool flag_pos = false;
		mps_vector pos;
		mps_vector* p_pos = nullptr;
	public:
		bool has_pos() const
		{
			return flag_pos;
		}
		mps_vector* alloc_pos()
		{
			flag_pos = true;
			return &pos;
		}
		const mps_vector* get_pos() const
		{
			if (true == flag_pos)
			{
				if (nullptr == p_pos)
				{
					return &pos;
				}
				return p_pos;
			}
			return nullptr;
		}
		void set_pos(mps_vector* in_pos)
		{
			if (nullptr == p_pos)
			{
				p_pos = in_pos;
				flag_pos = true;
			}
		}
	private:
		bool flag_info = false;
		mps_item_count_update info;
		mps_item_count_update* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_count_update* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_count_update* get_info() const
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
		void set_info(mps_item_count_update* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		int64_t record_id{};
	public:
		uint16_t channel_id{};

	public:
		mrpc_pk_revenge_trace_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::pk_revenge_trace_sc, tag)
		{
		}
		mrpc_pk_revenge_trace_sc() : RpcPacket(mpe_rpc_cmd::pk_revenge_trace_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeEnum(pBuffer, &trace_result);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &flag_pos);
			if (true == flag_pos)
			{
				if (nullptr != p_pos)
					protocol::SerializeType(pBuffer, p_pos);
				else
					protocol::SerializeType(pBuffer, &pos);
			}
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &record_id);
			protocol::SerializeType(pBuffer, &channel_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
