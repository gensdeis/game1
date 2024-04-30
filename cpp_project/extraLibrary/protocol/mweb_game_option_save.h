#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_game_option_save_cs : public WebBasePacket 
	{
	public:
		int64_t cuid{};
	public:
		mpe_clinet_platform platform{};
	public:
		std::vector<uint8_t> option_data{};
	public:
		std::string option_hash{};

	public:
		mweb_game_option_save_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &platform);
			protocol::SerializeType(pBuffer, &option_data);
			protocol::SerializeType(pBuffer, &option_hash);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_game_option_save_sc : public WebBasePacket 
	{

	public:
		mweb_game_option_save_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
