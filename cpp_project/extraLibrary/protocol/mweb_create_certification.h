#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_create_certification_cs : public WebBasePacket 
	{
	public:
		std::string username{};	// 계정정보
	public:
		std::string password{};
	public:
		std::string name{};	// 실명
	public:
		std::string id_card{};	// 주민번호

	public:
		mweb_create_certification_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &password);
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &id_card);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_create_certification_sc : public WebBasePacket 
	{
	public:
		int32_t result{};
	public:
		mpe_adult_grade grade{};	// 성년등급

	public:
		mweb_create_certification_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeEnum(pBuffer, &grade);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
