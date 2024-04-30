#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_token_info 
	{
	public:
		mpe_token_type token_type{};
	public:
		std::string chain{};
	public:
		std::string contract{};
	public:
		std::string contract_address{};

	public:
		mps_token_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &token_type);
			protocol::SerializeType(pBuffer, &chain);
			protocol::SerializeType(pBuffer, &contract);
			protocol::SerializeType(pBuffer, &contract_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
