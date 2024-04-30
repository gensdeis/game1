#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_shipwar_character.h"

namespace mir3d
{
	class mweb_shipwar_result_cs : public WebBasePacket 	// gate에서 삭제
	{
	public:
		int64_t guid{};
	public:
		int64_t battle_uid{};
	public:
		int32_t season_round{};

	public:
		mweb_shipwar_result_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &battle_uid);
			protocol::SerializeType(pBuffer, &season_round);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_shipwar_result_sc : public WebBasePacket 	// gate에서 삭제
	{
	public:
		std::vector<mps_shipwar_character> list_info{};

	public:
		mweb_shipwar_result_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
