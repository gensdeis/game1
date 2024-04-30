#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_pk_record.h"

namespace mir3d
{
	class mrpc_pk_record_add_cs : public RpcPacket 	// pk 기록처리
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_pk_record = false;
		mps_pk_record pk_record;
		mps_pk_record* p_pk_record = nullptr;
	public:
		bool has_pk_record() const
		{
			return flag_pk_record;
		}
		mps_pk_record* alloc_pk_record()
		{
			flag_pk_record = true;
			return &pk_record;
		}
		const mps_pk_record* get_pk_record() const
		{
			if (true == flag_pk_record)
			{
				if (nullptr == p_pk_record)
				{
					return &pk_record;
				}
				return p_pk_record;
			}
			return nullptr;
		}
		void set_pk_record(mps_pk_record* in_pk_record)
		{
			if (nullptr == p_pk_record)
			{
				p_pk_record = in_pk_record;
				flag_pk_record = true;
			}
		}
	public:
		int64_t delete_pk_record_id{};

	public:
		mrpc_pk_record_add_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::pk_record_add_cs, tag)
		{
		}
		mrpc_pk_record_add_cs() : RpcPacket(mpe_rpc_cmd::pk_record_add_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_pk_record);
			if (true == flag_pk_record)
			{
				if (nullptr != p_pk_record)
					protocol::SerializeType(pBuffer, p_pk_record);
				else
					protocol::SerializeType(pBuffer, &pk_record);
			}
			protocol::SerializeType(pBuffer, &delete_pk_record_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_pk_record_add_sc : public RpcPacket 	// pk 기록처리
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};	// "캐릭터uid"
	public:
		int64_t record_id{};	// "pk 기록 uid"
	public:
		uint16_t ch_id{};	// "채널번호"

	public:
		mrpc_pk_record_add_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::pk_record_add_sc, tag)
		{
		}
		mrpc_pk_record_add_sc() : RpcPacket(mpe_rpc_cmd::pk_record_add_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &record_id);
			protocol::SerializeType(pBuffer, &ch_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
