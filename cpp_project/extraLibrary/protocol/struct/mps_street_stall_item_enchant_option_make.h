#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_street_stall_item_enchant_option_make 
	{
	public:
		int64_t iuid{};
	public:
		mpe_item_reinforce_position pos{};
	public:
		int32_t lock_slot{};

	public:
		mps_street_stall_item_enchant_option_make()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeEnum(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &lock_slot);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
