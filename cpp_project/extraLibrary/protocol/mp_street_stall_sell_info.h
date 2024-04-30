#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_street_stall_fees.h"
#include "struct/mps_street_stall_log.h"

namespace mir3d
{
	class mp_street_stall_sell_info_cs : public BasePacket 	// // 무인상태 - 노점 판매 정보
	{

	public:
		mp_street_stall_sell_info_cs() : BasePacket(mpe_cmd::street_stall_sell_info_cs)
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

	class mp_street_stall_sell_info_sc : public BasePacket 	// // 무인상태 - 노점 판매 정보
	{
	public:
		std::vector<mps_street_stall_fees> total_fees{};	// // 누적 수수료
	public:
		int32_t use_count{};	// // 대행 횟수
	private:
		bool flag_log = false;
		mps_street_stall_log log;
		mps_street_stall_log* p_log = nullptr;
	public:
		bool has_log() const
		{
			return flag_log;
		}
		mps_street_stall_log* alloc_log()
		{
			flag_log = true;
			return &log;
		}
		const mps_street_stall_log* get_log() const
		{
			if (true == flag_log)
			{
				if (nullptr == p_log)
				{
					return &log;
				}
				return p_log;
			}
			return nullptr;
		}
		void set_log(mps_street_stall_log* in_log)
		{
			if (nullptr == p_log)
			{
				p_log = in_log;
				flag_log = true;
			}
		}

	public:
		mp_street_stall_sell_info_sc() : BasePacket(mpe_cmd::street_stall_sell_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &total_fees);
			protocol::SerializeType(pBuffer, &use_count);
			protocol::SerializeType(pBuffer, &flag_log);
			if (true == flag_log)
			{
				if (nullptr != p_log)
					protocol::SerializeType(pBuffer, p_log);
				else
					protocol::SerializeType(pBuffer, &log);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
