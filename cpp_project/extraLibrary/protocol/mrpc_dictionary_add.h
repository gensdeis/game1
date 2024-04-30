#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_dictionary_info.h"
#include "struct/mps_update_goods.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mrpc_dictionary_add_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	public:
		int32_t category{};
	private:
		bool flag_info = false;
		mps_dictionary_info info;
		mps_dictionary_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_dictionary_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_dictionary_info* get_info() const
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
		void set_info(mps_dictionary_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		std::vector<mps_update_goods> update_goods{};	// 사용한 재화
	public:
		std::vector<mps_item_count_update> item_info{};
	public:
		int32_t pet_id{};
	public:
		int32_t keep_value{};
	public:
		int32_t collection_id{};
	public:
		int32_t dic_type_value{};	// 도감 진행률
	public:
		int32_t dic_total_value{};	// 탐험일지 총 진행률

	public:
		mrpc_dictionary_add_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dictionary_add_cs, tag)
		{
		}
		mrpc_dictionary_add_cs() : RpcPacket(mpe_rpc_cmd::dictionary_add_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &category);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &update_goods);
			protocol::SerializeType(pBuffer, &item_info);
			protocol::SerializeType(pBuffer, &pet_id);
			protocol::SerializeType(pBuffer, &keep_value);
			protocol::SerializeType(pBuffer, &collection_id);
			protocol::SerializeType(pBuffer, &dic_type_value);
			protocol::SerializeType(pBuffer, &dic_total_value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_dictionary_add_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_dictionary_add_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::dictionary_add_sc, tag)
		{
		}
		mrpc_dictionary_add_sc() : RpcPacket(mpe_rpc_cmd::dictionary_add_sc)
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
