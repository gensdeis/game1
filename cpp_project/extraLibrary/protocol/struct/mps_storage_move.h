#pragma once
#include <vector>
#include <string>
#include "mps_storage_move_insert.h"
#include "mps_storage_move_update.h"
#include "mps_storage_move_goods.h"

namespace mir3d
{
	class mps_storage_move 
	{
	public:
		std::vector<mps_storage_move_insert> item{};
	public:
		std::vector<mps_storage_move_update> update{};
	public:
		std::vector<mps_storage_move_goods> goods{};

	public:
		mps_storage_move()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &item);
			protocol::SerializeType(pBuffer, &update);
			protocol::SerializeType(pBuffer, &goods);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
