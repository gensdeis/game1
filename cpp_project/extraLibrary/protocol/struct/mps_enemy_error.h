#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_enemy_error 
	{
	public:
		int64_t uid{};
	public:
		mpe_error error{};
	public:
		mpe_fsm_type fsm{};

	public:
		mps_enemy_error()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeEnum(pBuffer, &error);
			protocol::SerializeEnum(pBuffer, &fsm);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
