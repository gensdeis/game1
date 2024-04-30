#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_street_stall_pr_cs : public BasePacket 
	{

	public:
		mp_street_stall_pr_cs() : BasePacket(mpe_cmd::street_stall_pr_cs)
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

	class mp_street_stall_pr_sc : public BasePacket 
	{
	public:
		int32_t map_id{};
	public:
		int32_t channel_id{};
	public:
		std::string character_name{};
	public:
		std::string street_stall_title{};

	public:
		mp_street_stall_pr_sc() : BasePacket(mpe_cmd::street_stall_pr_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &map_id);
			protocol::SerializeType(pBuffer, &channel_id);
			protocol::SerializeType(pBuffer, &character_name);
			protocol::SerializeType(pBuffer, &street_stall_title);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
