#pragma once
#include <vector>
#include <string>
#include "mps_mail_item.h"

namespace mir3d
{
	class mrpcs_mail 
	{
	public:
		int64_t uid{};
	public:
		int64_t muid{};
	public:
		mpe_mail_type mail_type{};
	public:
		mpe_mail_state state{};
	public:
		int32_t id{};
	public:
		int64_t expir_date{};
	public:
		std::string title_text{};
	public:
		std::string contents_text{};
	public:
		std::vector<mps_mail_item> info{};

	public:
		mrpcs_mail()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &muid);
			protocol::SerializeEnum(pBuffer, &mail_type);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &expir_date);
			protocol::SerializeType(pBuffer, &title_text);
			protocol::SerializeType(pBuffer, &contents_text);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
