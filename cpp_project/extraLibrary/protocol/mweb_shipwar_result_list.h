#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_shipwar_character_season_info.h"

namespace mir3d
{
	class mweb_shipwar_result_list_cs : public WebBasePacket 	// gate에서 삭제
	{
	public:
		int64_t guid{};

	public:
		mweb_shipwar_result_list_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_shipwar_result_list_sc : public WebBasePacket 	// gate에서 삭제
	{
	public:
		std::vector<mps_shipwar_character_season_info> season_info{};

	public:
		mweb_shipwar_result_list_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &season_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
