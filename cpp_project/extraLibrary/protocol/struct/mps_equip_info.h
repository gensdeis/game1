#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_equip_info 
	{
	public:
		int64_t iuid{};	// //서버에서받은값이equip_pos_max면equip->inven으로이동된아이템
	public:
		mpe_equip_pos pos{};	// //클라사용안함.
	public:
		int32_t id{};

	public:
		mps_equip_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeEnum(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
