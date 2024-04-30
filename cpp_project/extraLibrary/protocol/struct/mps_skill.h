#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_skill 
	{
	public:
		int32_t id{};
	public:
		int32_t level{};
	public:
		int32_t exp{};
	public:
		mpe_db_skill_type type{};

	public:
		mps_skill()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &exp);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
