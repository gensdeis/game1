#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_occupationwar_darksteel_tax_log 
	{
	public:
		int64_t huid{};
	public:
		mpe_occupationwar_map_type map_type{};
	public:
		uint8_t log_type{};
	public:
		int32_t decide_gid{};
	public:
		uint8_t rank{};
	public:
		int32_t sender_gid{};
	public:
		int64_t count{};

	public:
		mrpcs_occupationwar_darksteel_tax_log()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &huid);
			protocol::SerializeEnum(pBuffer, &map_type);
			protocol::SerializeType(pBuffer, &log_type);
			protocol::SerializeType(pBuffer, &decide_gid);
			protocol::SerializeType(pBuffer, &rank);
			protocol::SerializeType(pBuffer, &sender_gid);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
