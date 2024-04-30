#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_account_ticket_item 
	{
	public:
		int32_t item{};
	public:
		int32_t use_count{};
	public:
		int32_t use_datetime{};
	public:
		int32_t max_use_count{};

	public:
		mrpcs_account_ticket_item()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &item);
			protocol::SerializeType(pBuffer, &use_count);
			protocol::SerializeType(pBuffer, &use_datetime);
			protocol::SerializeType(pBuffer, &max_use_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
