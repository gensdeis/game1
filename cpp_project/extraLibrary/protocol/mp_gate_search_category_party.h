#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_party_info.h"

namespace mir3d
{
	class mp_gate_search_category_party_cs : public BasePacket 
	{
	public:
		std::vector<int32_t> category_list{};	// 찾을파티카테고리목록

	public:
		mp_gate_search_category_party_cs() : BasePacket(mpe_cmd::gate_search_category_party_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &category_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_search_category_party_sc : public BasePacket 
	{
	public:
		std::vector<mps_party_info> list_info{};

	public:
		mp_gate_search_category_party_sc() : BasePacket(mpe_cmd::gate_search_category_party_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
