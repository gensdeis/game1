#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_siege_machine.h"

namespace mir3d
{
	class mweb_siege_warfare_atk_machine_info_cs : public WebBasePacket 
	{
	public:
		mpe_siege_castle_type castle_type{};	// 성타입
	public:
		int64_t guid{};	// 길드아이디

	public:
		mweb_siege_warfare_atk_machine_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_siege_warfare_atk_machine_info_sc : public WebBasePacket 
	{
	public:
		std::vector<mps_siege_machine> machine_info{};	// 공성무기

	public:
		mweb_siege_warfare_atk_machine_info_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &machine_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
