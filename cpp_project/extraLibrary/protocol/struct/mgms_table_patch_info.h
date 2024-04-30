#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mgms_table_patch_info 
	{
	public:
		int64_t uid{};
	public:
		int32_t patch_date{};
	public:
		std::string user_name{};
	public:
		int32_t gid{};
	public:
		std::string gname{};
	public:
		std::string file_name{};
	public:
		int32_t state{};

	public:
		mgms_table_patch_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &patch_date);
			protocol::SerializeType(pBuffer, &user_name);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &gname);
			protocol::SerializeType(pBuffer, &file_name);
			protocol::SerializeType(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
