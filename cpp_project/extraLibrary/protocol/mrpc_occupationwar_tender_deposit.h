#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_occupationwar_tender_deposit_cs : public RpcPacket 	// 흑철상자 개인 입금
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_info = false;
		mps_item_add info;
		mps_item_add* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_add* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_add* get_info() const
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
		void set_info(mps_item_add* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		int32_t update_count{};
	public:
		int32_t week_number{};
	public:
		int32_t zone_id{};

	public:
		mrpc_occupationwar_tender_deposit_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::occupationwar_tender_deposit_cs, tag)
		{
		}
		mrpc_occupationwar_tender_deposit_cs() : RpcPacket(mpe_rpc_cmd::occupationwar_tender_deposit_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &update_count);
			protocol::SerializeType(pBuffer, &week_number);
			protocol::SerializeType(pBuffer, &zone_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_occupationwar_tender_deposit_sc : public RpcPacket 	// 흑철상자 개인 입금
	{
	public:
		int64_t key{};	// 실패시 게임서버로 리턴, 성공시
	public:
		int32_t gid{};
	public:
		int32_t update_count{};
	public:
		int64_t totoal_server{};

	public:
		mrpc_occupationwar_tender_deposit_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::occupationwar_tender_deposit_sc, tag)
		{
		}
		mrpc_occupationwar_tender_deposit_sc() : RpcPacket(mpe_rpc_cmd::occupationwar_tender_deposit_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &update_count);
			protocol::SerializeType(pBuffer, &totoal_server);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
