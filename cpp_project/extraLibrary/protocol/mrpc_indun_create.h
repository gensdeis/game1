#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_party_info.h"

namespace mir3d
{
	class mrpc_indun_create_cs : public RpcPacket 	// // cs / sc 구조로 할 수 없다. game / indun 이 같은 프로젝트라 패킷을 분리한다.
	{
	public:
		int64_t cuid{};	// 인던 생성 요청 character_uid
	public:
		int32_t tid{};	// indun table id
	public:
		int32_t party_category{};
	public:
		bool is_new{};	// indun 새로 만들것인가(true) 이미생성된 인던할당받을것인가(false)
	public:
		mpe_indun_enter_type indun_enter_type{};
	public:
		mpe_party_loot loot_type{};	// 파티 바로입장일때 파티의 루팅정보
	public:
		std::vector<int64_t> member{};
	public:
		std::vector<int32_t> list_item_id{};	// // 소환석 아이템 id 목록
	public:
		int64_t guid{};	// 길드던전입장guid
	public:
		int32_t castle_dungeon_entrance_fee{};	// 성관할던전입장료
	private:
		bool flag_group_info = false;
		mps_party_info group_info;
		mps_party_info* p_group_info = nullptr;
	public:
		bool has_group_info() const
		{
			return flag_group_info;
		}
		mps_party_info* alloc_group_info()
		{
			flag_group_info = true;
			return &group_info;
		}
		const mps_party_info* get_group_info() const
		{
			if (true == flag_group_info)
			{
				if (nullptr == p_group_info)
				{
					return &group_info;
				}
				return p_group_info;
			}
			return nullptr;
		}
		void set_group_info(mps_party_info* in_group_info)
		{
			if (nullptr == p_group_info)
			{
				p_group_info = in_group_info;
				flag_group_info = true;
			}
		}

	public:
		mrpc_indun_create_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::indun_create_cs, tag)
		{
		}
		mrpc_indun_create_cs() : RpcPacket(mpe_rpc_cmd::indun_create_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &party_category);
			protocol::SerializeType(pBuffer, &is_new);
			protocol::SerializeEnum(pBuffer, &indun_enter_type);
			protocol::SerializeEnum(pBuffer, &loot_type);
			protocol::SerializeType(pBuffer, &member);
			protocol::SerializeType(pBuffer, &list_item_id);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &castle_dungeon_entrance_fee);
			protocol::SerializeType(pBuffer, &flag_group_info);
			if (true == flag_group_info)
			{
				if (nullptr != p_group_info)
					protocol::SerializeType(pBuffer, p_group_info);
				else
					protocol::SerializeType(pBuffer, &group_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_indun_create_sc : public RpcPacket 	// // cs / sc 구조로 할 수 없다. game / indun 이 같은 프로젝트라 패킷을 분리한다.
	{
	public:
		int64_t cuid{};
	public:
		mpe_error error{};
	public:
		int32_t index{};	// indun server index
	public:
		int64_t indun_uid{};
	public:
		int32_t tid{};	// indun table id
	public:
		std::vector<int64_t> member{};
	public:
		std::vector<int32_t> list_item_id{};	// // 소환석 아이템 id 목록
	public:
		int64_t guid{};	// 길드던전 입장 guid
	public:
		int32_t castle_dungeon_entrance_fee{};	// 성관할던전입장료

	public:
		mrpc_indun_create_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::indun_create_sc, tag)
		{
		}
		mrpc_indun_create_sc() : RpcPacket(mpe_rpc_cmd::indun_create_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &error);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &indun_uid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &member);
			protocol::SerializeType(pBuffer, &list_item_id);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &castle_dungeon_entrance_fee);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
