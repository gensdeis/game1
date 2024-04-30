#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mgms_patch_target_file 
	{
	public:
		mrpce_service_type server_type{};
	public:
		std::string filename{};

	public:
		mgms_patch_target_file()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &filename);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
