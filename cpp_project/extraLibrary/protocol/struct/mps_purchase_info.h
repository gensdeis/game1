#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_purchase_info 
	{
	public:
		int32_t product_id{};
	public:
		int32_t count{};
	public:
		std::string product_name{};	// 상품이름

	public:
		mps_purchase_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &product_id);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &product_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
