#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_drop_item_info 
	{
	public:
		int64_t uid{};	// contribution_type이 FirstAttacker면 character uid, ServerAttacker면 gid 소유권이 없으면 0
	public:
		uint8_t contribution_type{};	// 몬스터 소유권 타입, table enum의 ItemPriority 값을 따름
	public:
		int32_t index{};	// 가방정보의아이템index
	public:
		int32_t id{};	// 아이템id
	public:
		int32_t count{};	// 수량
	public:
		int32_t tile_index{};	// 셀 인덱스
	public:
		bool pet_rooting{};	// 영물 획득 가능 여부

	public:
		mps_drop_item_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &contribution_type);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &tile_index);
			protocol::SerializeType(pBuffer, &pet_rooting);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
