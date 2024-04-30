#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_mentor.h"
#include "struct/mps_mentor.h"

namespace mir3d
{
	class mweb_mentor_list_cs : public WebBasePacket 
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		mpe_mentor_type mentor_type{};

	public:
		mweb_mentor_list_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &mentor_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_mentor_list_sc : public WebBasePacket 
	{
	public:
		std::vector<mps_mentor> list_mentor{};
	public:
		std::vector<mps_mentor> list_mentee{};
	public:
		int64_t mentor_reg_date{};

	public:
		mweb_mentor_list_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_mentor);
			protocol::SerializeType(pBuffer, &list_mentee);
			protocol::SerializeType(pBuffer, &mentor_reg_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
