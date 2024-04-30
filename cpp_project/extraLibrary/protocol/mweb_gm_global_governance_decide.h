#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_gm_global_governance_decide_cs : public WebBasePacket 
	{
	public:
		int32_t type{};

	public:
		mweb_gm_global_governance_decide_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_global_governance_decide_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	public:
		int32_t type{};
	public:
		std::vector<int32_t> list_success{};
	public:
		std::vector<int32_t> list_failed{};

	public:
		mweb_gm_global_governance_decide_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &list_success);
			protocol::SerializeType(pBuffer, &list_failed);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
