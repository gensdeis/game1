#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_server_group_info 
	{
	public:
		int32_t gid{};
	public:
		uint8_t recommend{};	// 추천서버
	public:
		uint8_t new_server{};	// 신규서버
	public:
		uint8_t create_limit{};	// 캐릭터 생산제한
	public:
		uint8_t show_list{};	// 서버리스트 노출
	public:
		uint8_t connect_limit{};	// 접속 제한
	public:
		uint8_t governance{};	// 거버넌스 참가 여부
	public:
		int32_t game_max_count{};	// 서버 최대 접속자수
	public:
		int32_t lobby_current_count{};	// 로비 현재 접속자수
	public:
		int32_t game_current_count{};	// 서버 현재 접속자수

	public:
		mrpcs_server_group_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &recommend);
			protocol::SerializeType(pBuffer, &new_server);
			protocol::SerializeType(pBuffer, &create_limit);
			protocol::SerializeType(pBuffer, &show_list);
			protocol::SerializeType(pBuffer, &connect_limit);
			protocol::SerializeType(pBuffer, &governance);
			protocol::SerializeType(pBuffer, &game_max_count);
			protocol::SerializeType(pBuffer, &lobby_current_count);
			protocol::SerializeType(pBuffer, &game_current_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
