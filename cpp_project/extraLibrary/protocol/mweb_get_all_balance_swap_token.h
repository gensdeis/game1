#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_token_balance.h"

namespace mir3d
{
	class mweb_get_all_balance_swap_token_cs : public WebBasePacket 
	{
	public:
		int64_t auid{};
	public:
		std::string user_address{};

	public:
		mweb_get_all_balance_swap_token_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &user_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_get_all_balance_swap_token_sc : public WebBasePacket 
	{
	public:
		std::vector<mps_token_balance> token_balance{};
	public:
		int32_t result{};

	public:
		mweb_get_all_balance_swap_token_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &token_balance);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
