#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_available_font.h"

namespace mir3d
{
	class mweb_get_available_font_list_cs : public WebBasePacket 	// (gate에서 삭제)
	{
	public:
		int32_t param{};

	public:
		mweb_get_available_font_list_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &param);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_get_available_font_list_sc : public WebBasePacket 	// (gate에서 삭제)
	{
	public:
		std::vector<mps_available_font> list{};

	public:
		mweb_get_available_font_list_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
