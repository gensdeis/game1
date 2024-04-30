#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_party_member_enter_state 
	{
	public:
		int64_t cuid{};	// "멤버cuid."
	public:
		bool is_ready{};	// "인던입장가능 여부."

	public:
		mps_party_member_enter_state()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &is_ready);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
