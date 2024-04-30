#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_street_stall_sell_info 
	{
	public:
		int64_t suid{};
	public:
		int64_t cuid{};
	public:
		int32_t use_count{};
	public:
		int32_t fees_gold{};
	public:
		int32_t fees_goldingot{};
	public:
		int32_t fees_black_iron{};

	public:
		mrpcs_street_stall_sell_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &suid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &use_count);
			protocol::SerializeType(pBuffer, &fees_gold);
			protocol::SerializeType(pBuffer, &fees_goldingot);
			protocol::SerializeType(pBuffer, &fees_black_iron);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
