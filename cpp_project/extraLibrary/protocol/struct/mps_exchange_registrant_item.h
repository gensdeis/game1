#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_exchange_registrant_item 
	{
	public:
		int64_t euid{};
	public:
		int64_t iuid{};
	public:
		int32_t id{};	// 아이템아이디
	public:
		int32_t sell_state{};	// 판매상태=>0:등록대기1:판매중,2:판매완료,3:등록만료,4:회수
	public:
		int32_t expire{};
	public:
		int32_t reinforce{};
	public:
		int32_t price{};	// 등록가격
	public:
		int32_t count{};	// 개수
	public:
		int32_t tax{};	// 수수료
	public:
		int32_t stax{};	// 특별수수료
	public:
		int32_t gold{};	// 정산금액
	public:
		int32_t awaken_step{};	// 각성 단계

	public:
		mps_exchange_registrant_item()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &euid);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &sell_state);
			protocol::SerializeType(pBuffer, &expire);
			protocol::SerializeType(pBuffer, &reinforce);
			protocol::SerializeType(pBuffer, &price);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &tax);
			protocol::SerializeType(pBuffer, &stax);
			protocol::SerializeType(pBuffer, &gold);
			protocol::SerializeType(pBuffer, &awaken_step);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
