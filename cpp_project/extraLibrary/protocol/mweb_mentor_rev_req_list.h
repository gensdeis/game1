#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_mentor.h"
#include "struct/mps_mentor.h"

namespace mir3d
{
	class mweb_mentor_rev_req_list_cs : public WebBasePacket 
	{
	public:
		int64_t cuid{};

	public:
		mweb_mentor_rev_req_list_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_mentor_rev_req_list_sc : public WebBasePacket 
	{
	public:
		std::vector<mps_mentor> list_send_mentor{};
	public:
		std::vector<mps_mentor> list_receive_mentor{};

	public:
		mweb_mentor_rev_req_list_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_send_mentor);
			protocol::SerializeType(pBuffer, &list_receive_mentor);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
