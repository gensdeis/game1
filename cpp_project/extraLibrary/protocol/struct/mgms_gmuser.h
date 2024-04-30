#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mgms_gmuser 
	{
	public:
		std::string id{};
	public:
		std::string pass{};
	public:
		mgme_login_type login_type{};
	public:
		mgme_authority_type authority{};
	public:
		int32_t reg_date{};

	public:
		mgms_gmuser()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &pass);
			protocol::SerializeEnum(pBuffer, &login_type);
			protocol::SerializeEnum(pBuffer, &authority);
			protocol::SerializeType(pBuffer, &reg_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
