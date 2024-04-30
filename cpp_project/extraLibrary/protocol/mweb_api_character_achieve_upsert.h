#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_achieve_info.h"

namespace mir3d
{
	class mweb_api_character_achieve_upsert_cs : public WebBasePacket 
	{
	public:
		int64_t cuid{};
	public:
		std::vector<mps_achieve_info> list{};

	public:
		mweb_api_character_achieve_upsert_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_api_character_achieve_upsert_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};

	public:
		mweb_api_character_achieve_upsert_sc() : WebBasePacket()
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
