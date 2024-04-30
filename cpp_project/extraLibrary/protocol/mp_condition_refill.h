#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods_list.h"

namespace mir3d
{
	class mp_condition_refill_cs : public BasePacket 	// "// 피로도 회복
	{
	public:
		int64_t npc_uid{};	// // npc uid
	public:
		int32_t refill{};	// // 회복량
	public:
		bool type{};	// "// false : condition, true : conditionbag"

	public:
		mp_condition_refill_cs() : BasePacket(mpe_cmd::condition_refill_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &npc_uid);
			protocol::SerializeType(pBuffer, &refill);
			protocol::SerializeType(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_condition_refill_sc : public BasePacket 	// "// 피로도 회복
	{
	private:
		bool flag_info = false;
		mps_update_goods_list info;	// // 변경된 재화 목록
		mps_update_goods_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_update_goods_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_update_goods_list* get_info() const
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
		void set_info(mps_update_goods_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		bool flag{};	// "// false : 회복, true : 충전"

	public:
		mp_condition_refill_sc() : BasePacket(mpe_cmd::condition_refill_sc)
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
			protocol::SerializeType(pBuffer, &flag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
