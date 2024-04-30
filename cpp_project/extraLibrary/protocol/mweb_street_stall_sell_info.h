#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_street_stall_fees.h"

namespace mir3d
{
	class mweb_street_stall_sell_info_cs : public WebBasePacket 
	{
	public:
		int64_t suid{};	// 상점 uid

	public:
		mweb_street_stall_sell_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &suid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_street_stall_sell_info_sc : public WebBasePacket 
	{
	public:
		std::vector<mps_street_stall_fees> total_fees{};
	public:
		int32_t use_count{};

	public:
		mweb_street_stall_sell_info_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &total_fees);
			protocol::SerializeType(pBuffer, &use_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
