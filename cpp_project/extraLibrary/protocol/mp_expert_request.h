#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods_list.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mp_expert_request_cs : public BasePacket 
	{

	public:
		mp_expert_request_cs() : BasePacket(mpe_cmd::expert_request_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_expert_request_sc : public BasePacket 
	{
	private:
		bool flag_good_list = false;
		mps_update_goods_list good_list;	// "결과 재화 및 전직레벨"
		mps_update_goods_list* p_good_list = nullptr;
	public:
		bool has_good_list() const
		{
			return flag_good_list;
		}
		mps_update_goods_list* alloc_good_list()
		{
			flag_good_list = true;
			return &good_list;
		}
		const mps_update_goods_list* get_good_list() const
		{
			if (true == flag_good_list)
			{
				if (nullptr == p_good_list)
				{
					return &good_list;
				}
				return p_good_list;
			}
			return nullptr;
		}
		void set_good_list(mps_update_goods_list* in_good_list)
		{
			if (nullptr == p_good_list)
			{
				p_good_list = in_good_list;
				flag_good_list = true;
			}
		}
	public:
		std::vector<mps_item_count_update> update_item_counts{};	// "전직후 아이템 수량."
	public:
		int64_t expert_exp{};	// "결과 전직 경험치."

	public:
		mp_expert_request_sc() : BasePacket(mpe_cmd::expert_request_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_good_list);
			if (true == flag_good_list)
			{
				if (nullptr != p_good_list)
					protocol::SerializeType(pBuffer, p_good_list);
				else
					protocol::SerializeType(pBuffer, &good_list);
			}
			protocol::SerializeType(pBuffer, &update_item_counts);
			protocol::SerializeType(pBuffer, &expert_exp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
