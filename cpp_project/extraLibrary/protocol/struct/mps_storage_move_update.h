#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_storage_move_update 
	{
	public:
		int64_t iuid{};
	public:
		int32_t update{};
	public:
		int32_t total{};
	public:
		uint16_t pos{};
	public:
		uint16_t before_pos{};	// 이전위치
	public:
		bool new_flag{};	// 현재 위치에 새로 생성 해야되는 아이템 인지(클라이언트) true 일 경우 무조건 생성

	public:
		mps_storage_move_update()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &update);
			protocol::SerializeType(pBuffer, &total);
			protocol::SerializeType(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &before_pos);
			protocol::SerializeType(pBuffer, &new_flag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
