#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_contents_onoff_info.h"

namespace mir3d
{
	class mweb_contents_onoff_info_cs : public WebBasePacket 	//  (gate에서 삭제)
	{
	public:
		std::vector<int32_t> contents_type{};

	public:
		mweb_contents_onoff_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &contents_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_contents_onoff_info_sc : public WebBasePacket 	//  (gate에서 삭제)
	{
	public:
		std::vector<mps_contents_onoff_info> contents_onoff_info_list{};
	public:
		int32_t result{};

	public:
		mweb_contents_onoff_info_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &contents_onoff_info_list);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
