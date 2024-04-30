#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_avatar_info 
	{
	public:
		int32_t avatar_id{};	// avatar table id
	public:
		uint8_t class_type{};	// enum table class type
	public:
		int32_t hp{};	// player info 껄 써도 되고 여기꺼를 써도 된다 / 나중에 안쓰면 삭제 예정, 
	public:
		int32_t mp{};	// player info 껄 써도 되고 여기꺼를 써도 된다 / 나중에 안쓰면 삭제 예정
	public:
		int32_t mhp{};	// player info 껄 써도 되고 여기꺼를 써도 된다 / 나중에 안쓰면 삭제 예정
	public:
		int32_t mmp{};	// player info 껄 써도 되고 여기꺼를 써도 된다 / 나중에 안쓰면 삭제 예정
	public:
		float atk_speed{};	// player info 껄 써도 되고 여기꺼를 써도 된다 / 나중에 안쓰면 삭제 예정
	public:
		float run_speed{};	// player info 껄 써도 되고 여기꺼를 써도 된다 / 나중에 안쓰면 삭제 예정
	public:
		int32_t expire_time{};	// 변신 완료 시간

	public:
		mps_avatar_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &avatar_id);
			protocol::SerializeType(pBuffer, &class_type);
			protocol::SerializeType(pBuffer, &hp);
			protocol::SerializeType(pBuffer, &mp);
			protocol::SerializeType(pBuffer, &mhp);
			protocol::SerializeType(pBuffer, &mmp);
			protocol::SerializeType(pBuffer, &atk_speed);
			protocol::SerializeType(pBuffer, &run_speed);
			protocol::SerializeType(pBuffer, &expire_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
