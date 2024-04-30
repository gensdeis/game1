#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_gm_table_patch_cs : public WebBasePacket 
	{
	public:
		std::string access_token{};
	public:
		std::vector<int32_t> list_gid{};
	public:
		std::string file_name{};
	public:
		std::vector<uint8_t> list_patchfile{};

	public:
		mweb_gm_table_patch_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &list_gid);
			protocol::SerializeType(pBuffer, &file_name);
			protocol::SerializeType(pBuffer, &list_patchfile);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_table_patch_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};

	public:
		mweb_gm_table_patch_sc() : WebBasePacket()
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
