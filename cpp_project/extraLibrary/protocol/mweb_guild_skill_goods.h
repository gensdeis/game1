#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_goods_info.h"
#include "struct/mps_item_id.h"

namespace mir3d
{
	class mweb_guild_skill_goods_cs : public WebBasePacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int32_t tid{};

	public:
		mweb_guild_skill_goods_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_guild_skill_goods_sc : public WebBasePacket 
	{
	public:
		int32_t result{};
	public:
		std::vector<mps_guild_goods_info> goods_info{};
	public:
		std::vector<mps_item_id> list_item{};

	public:
		mweb_guild_skill_goods_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &goods_info);
			protocol::SerializeType(pBuffer, &list_item);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
