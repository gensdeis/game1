#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_lobby_character_create_cs : public WebBasePacket 	// 캐릭터 생성(gate에서 삭제)
	{
	public:
		int64_t auid{};
	public:
		std::string nickname{};
	public:
		std::string access_token{};
	public:
		int32_t id{};
	public:
		uint16_t customzing_data{};
	public:
		mpe_os_type os_type{};

	public:
		mweb_lobby_character_create_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &customzing_data);
			protocol::SerializeEnum(pBuffer, &os_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_lobby_character_create_sc : public WebBasePacket 	// 캐릭터 생성(gate에서 삭제)
	{
	public:
		int32_t result{};
	public:
		std::string nickname{};
	public:
		int32_t id{};
	public:
		int64_t cuid{};
	public:
		uint16_t customzing_data{};

	public:
		mweb_lobby_character_create_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &customzing_data);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
