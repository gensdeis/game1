#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_indun_monarch_item_regist_cs : public BasePacket 	// 소환석등록 정보
	{
	public:
		std::vector<int32_t> list_item_id{};

	public:
		mp_indun_monarch_item_regist_cs() : BasePacket(mpe_cmd::indun_monarch_item_regist_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_item_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_indun_monarch_item_regist_sc : public BasePacket 	// 소환석등록 정보
	{
	public:
		std::vector<int32_t> list_item_id{};

	public:
		mp_indun_monarch_item_regist_sc() : BasePacket(mpe_cmd::indun_monarch_item_regist_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_item_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
