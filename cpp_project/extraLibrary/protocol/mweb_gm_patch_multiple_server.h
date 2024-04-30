#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mgms_patch_target_group.h"
#include "struct/mgms_patch_target_file.h"

namespace mir3d
{
	class mweb_gm_patch_multiple_server_cs : public WebBasePacket 
	{
	public:
		std::string access_token{};
	public:
		std::vector<mgms_patch_target_group> list_target_group{};
	public:
		std::vector<mgms_patch_target_file> list_target_file{};

	public:
		mweb_gm_patch_multiple_server_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &list_target_group);
			protocol::SerializeType(pBuffer, &list_target_file);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_patch_multiple_server_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};

	public:
		mweb_gm_patch_multiple_server_sc() : WebBasePacket()
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
