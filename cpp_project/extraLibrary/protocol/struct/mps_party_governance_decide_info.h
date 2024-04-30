#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_party_governance_decide_info 
	{
	public:
		int64_t cuid{};	// 캐릭터 아이디
	public:
		int32_t rank{};	// 순위
	public:
		std::string nickname{};	// 캐릭터 이름
	public:
		int32_t gid{};	// 서버 아이디
	public:
		std::string amount{};	// 스테이킹량

	public:
		mps_party_governance_decide_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &rank);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &amount);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
