#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_contents_onoff_list.h"

namespace mir3d
{
	class mweb_contents_onoff_list_cs : public WebBasePacket 
	{
	public:
		std::vector<int32_t> list_type{};	// List<mpe_contents_onoff_type>

	public:
		mweb_contents_onoff_list_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_contents_onoff_list_sc : public WebBasePacket 
	{
	public:
		std::vector<mps_contents_onoff_list> list{};
	public:
		int32_t result{};

	public:
		mweb_contents_onoff_list_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
