#pragma once
#include <vector>
#include <string>
#include "mps_lord_bless_buff.h"

namespace mir3d
{
	class mps_lord_bless_info 	// 성주경배정보
	{
	public:
		std::vector<mps_lord_bless_buff> bless_buff{};	// 버프정보
	public:
		int32_t bless_point{};	// 축복포인트
	public:
		std::string lord_message{};	// 성주교령메시지

	public:
		mps_lord_bless_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &bless_buff);
			protocol::SerializeType(pBuffer, &bless_point);
			protocol::SerializeType(pBuffer, &lord_message);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
