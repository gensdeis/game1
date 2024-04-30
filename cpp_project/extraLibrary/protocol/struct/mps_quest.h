#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_quest 	// 현재진행중인퀘스트
	{
	public:
		uint16_t id{};
	public:
		mpe_quest_state state{};	// [default=qs_none];
	public:
		int32_t object_count{};
	public:
		int32_t area_id{};
	public:
		uint8_t sequence{};

	public:
		mps_quest()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &object_count);
			protocol::SerializeType(pBuffer, &area_id);
			protocol::SerializeType(pBuffer, &sequence);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
