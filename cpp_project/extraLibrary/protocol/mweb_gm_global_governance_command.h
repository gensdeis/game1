#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_gm_global_governance_command_cs : public WebBasePacket 
	{
	public:
		mpe_governance_contents_type contents_type{};
	public:
		mrpce_global_governance_command_type command_type{};
	public:
		int64_t cuid{};
	public:
		int32_t count{};

	public:
		mweb_gm_global_governance_command_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &contents_type);
			protocol::SerializeEnum(pBuffer, &command_type);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_global_governance_command_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};

	public:
		mweb_gm_global_governance_command_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
