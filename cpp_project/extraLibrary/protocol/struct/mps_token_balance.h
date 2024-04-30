#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_token_balance 
	{
	public:
		mpe_token_type token_type{};
	public:
		std::string balance{};

	public:
		mps_token_balance()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &token_type);
			protocol::SerializeType(pBuffer, &balance);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
