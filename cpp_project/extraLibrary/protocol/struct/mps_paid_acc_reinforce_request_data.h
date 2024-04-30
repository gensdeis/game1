#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_paid_acc_reinforce_request_data 
	{
	public:
		int64_t iuid{};	// "아이템 uid"
	public:
		mpe_item_reinforce_position flag{};	// "착용 위치 정보"

	public:
		mps_paid_acc_reinforce_request_data()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeEnum(pBuffer, &flag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
