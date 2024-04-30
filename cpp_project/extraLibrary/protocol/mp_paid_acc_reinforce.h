#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_paid_acc_reinforce_request_data.h"
#include "struct/mps_paid_acc_reinforce_result_data.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_paid_acc_reinforce_cs : public BasePacket 
	{
	public:
		std::vector<mps_paid_acc_reinforce_request_data> list_acc{};	// "강화 장신구 목록"
	public:
		bool is_bless_material{};	// "소모될 강화석 축복인지 여부. false:일반(거래가능/불가) true:축복(거래가능/불가)"

	public:
		mp_paid_acc_reinforce_cs() : BasePacket(mpe_cmd::paid_acc_reinforce_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_acc);
			protocol::SerializeType(pBuffer, &is_bless_material);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_paid_acc_reinforce_sc : public BasePacket 
	{
	public:
		std::vector<mps_paid_acc_reinforce_result_data> list_result{};	// "강화 결과 목록."
	private:
		bool flag_info = false;
		mps_item_add info;	// "소모된 아이템 정보"
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
		mpe_error last_result{};	// "마지막 에러 정보"

	public:
		mp_paid_acc_reinforce_sc() : BasePacket(mpe_cmd::paid_acc_reinforce_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_result);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeEnum(pBuffer, &last_result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
