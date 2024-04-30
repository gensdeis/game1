#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mgms_table_patch_info.h"

namespace mir3d
{
	class mweb_gm_table_patch_list_cs : public WebBasePacket 
	{
	public:
		std::string access_token{};
	public:
		int32_t date_start{};
	public:
		int32_t date_end{};

	public:
		mweb_gm_table_patch_list_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &date_start);
			protocol::SerializeType(pBuffer, &date_end);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_table_patch_list_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	public:
		std::vector<mgms_table_patch_info> info{};

	public:
		mweb_gm_table_patch_list_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
