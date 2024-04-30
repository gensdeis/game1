#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_castle_view_owner_info 	// 성주 정보
	{
	public:
		mpe_siege_castle_type castle_type{};	// 성타입
	public:
		int64_t guid{};	// 길드아이디
	public:
		std::string name{};	// 길드이름
	public:
		int64_t cuid{};	// 문파장아이디
	public:
		std::string nickname{};	// 문파장이름
	public:
		int32_t tax_rate{};	// 세율
	public:
		int32_t tax_value{};	// 누적세금
	public:
		uint16_t def_count{};	// 수성횟수
	public:
		std::vector<uint8_t> guild_mark{};	// 문파문양
	public:
		int32_t master_class{};	// 길마직업
	public:
		int32_t guild_level{};	// 문파레벨
	public:
		int32_t member_count{};	// 문파원 수
	public:
		int32_t entrance_fee{};	// 던전 입장료

	public:
		mps_castle_view_owner_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &tax_rate);
			protocol::SerializeType(pBuffer, &tax_value);
			protocol::SerializeType(pBuffer, &def_count);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &master_class);
			protocol::SerializeType(pBuffer, &guild_level);
			protocol::SerializeType(pBuffer, &member_count);
			protocol::SerializeType(pBuffer, &entrance_fee);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
