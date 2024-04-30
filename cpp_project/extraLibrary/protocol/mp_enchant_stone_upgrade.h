#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_enchant_stone_upgrade_cs : public BasePacket 
	{
	public:
		int64_t uid{};	// "강화 대상( 인벤-> 용령석, 장착->장비uid)"
	public:
		int64_t use_uid{};	// 재료로 사용할 용령석
	public:
		int32_t index{};	// 슬롯 인덱스(인벤일 경우 -1)

	public:
		mp_enchant_stone_upgrade_cs() : BasePacket(mpe_cmd::enchant_stone_upgrade_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &use_uid);
			protocol::SerializeType(pBuffer, &index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_enchant_stone_upgrade_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_item_add info;	// "사용한 아이템, 재화"
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
		int64_t uid{};	// "강화 대상( 인벤-> 용령석, 장착->장비uid)"
	public:
		int32_t grade{};	// 용령석 강화수치
	public:
		mpe_upgrade_state upgrade_result{};	// 강화 결과
	public:
		int32_t index{};	// 슬롯 인덱스(인벤일 경우 -1)

	public:
		mp_enchant_stone_upgrade_sc() : BasePacket(mpe_cmd::enchant_stone_upgrade_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &grade);
			protocol::SerializeEnum(pBuffer, &upgrade_result);
			protocol::SerializeType(pBuffer, &index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
