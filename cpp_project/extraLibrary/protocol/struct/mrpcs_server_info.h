#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_server_info 
	{
	public:
		int32_t id{};	// db id
	public:
		uint16_t channel_id{};	// channel id
	public:
		int64_t channel_uid{};	// channel uid
	public:
		int32_t gid{};
	public:
		int32_t index{};
	public:
		mrpce_server_type server_type{};
	public:
		int32_t table_id{};	// map_id or dungeon_control_table_id
	public:
		uint8_t worker_index{};	// thread index (maptag 의 tag)
	public:
		short max_user_count{};
	public:
		uint8_t enable{};	// 채널 활성화 여부
	public:
		uint8_t enable_channel_add{};	// 채널 증가 가능 여부
	public:
		uint8_t enable_channel_delete{};	// 채널 감소 가능 여부
	public:
		int32_t default_pool_size{};
	public:
		std::string comment{};

	public:
		mrpcs_server_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &channel_id);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &worker_index);
			protocol::SerializeType(pBuffer, &max_user_count);
			protocol::SerializeType(pBuffer, &enable);
			protocol::SerializeType(pBuffer, &enable_channel_add);
			protocol::SerializeType(pBuffer, &enable_channel_delete);
			protocol::SerializeType(pBuffer, &default_pool_size);
			protocol::SerializeType(pBuffer, &comment);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
