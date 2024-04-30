#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_comm_object 
	{
	public:
		int64_t ouid{};
	public:
		int64_t cuid{};
	public:
		mrpce_server_type server_type{};
	public:
		int32_t server_index{};
	public:
		int32_t zone_id{};
	public:
		float pos_x{};
	public:
		float pos_y{};
	public:
		float pos_z{};
	public:
		int64_t channel_uid{};
	public:
		int64_t end_time{};
	public:
		int64_t run_time{};

	public:
		mrpcs_comm_object()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &ouid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &pos_x);
			protocol::SerializeType(pBuffer, &pos_y);
			protocol::SerializeType(pBuffer, &pos_z);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &end_time);
			protocol::SerializeType(pBuffer, &run_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
