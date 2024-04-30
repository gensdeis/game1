#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_pickup.h"

namespace mir3d
{
	class mp_zone_dropitem_remove_cs : public BasePacket 	//  아이템 루팅 broadcast용
	{

	public:
		mp_zone_dropitem_remove_cs() : BasePacket(mpe_cmd::zone_dropitem_remove_cs)
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

	class mp_zone_dropitem_remove_sc : public BasePacket 	//  아이템 루팅 broadcast용
	{
	public:
		std::vector<mps_item_pickup> info{};	// 루팅된 아이템 정보
	public:
		int64_t uid{};	// 캐릭터 uid
	public:
		bool is_pet{};	// 팻 : true 캐릭터 : false

	public:
		mp_zone_dropitem_remove_sc() : BasePacket(mpe_cmd::zone_dropitem_remove_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &is_pet);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
