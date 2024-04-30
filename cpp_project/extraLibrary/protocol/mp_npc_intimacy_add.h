#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_id.h"

namespace mir3d
{
	class mp_npc_intimacy_add_cs : public BasePacket 
	{
	public:
		int32_t category_id{};
	public:
		int32_t dic_id{};
	public:
		std::vector<mps_item_id> list_item{};
	public:
		int32_t pos{};
	public:
		int64_t npc_uid{};
	public:
		std::vector<int32_t> list_tid{};

	public:
		mp_npc_intimacy_add_cs() : BasePacket(mpe_cmd::npc_intimacy_add_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &category_id);
			protocol::SerializeType(pBuffer, &dic_id);
			protocol::SerializeType(pBuffer, &list_item);
			protocol::SerializeType(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &npc_uid);
			protocol::SerializeType(pBuffer, &list_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_npc_intimacy_add_sc : public BasePacket 
	{

	public:
		mp_npc_intimacy_add_sc() : BasePacket(mpe_cmd::npc_intimacy_add_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
