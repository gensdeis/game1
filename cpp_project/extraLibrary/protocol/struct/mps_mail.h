#pragma once
#include <vector>
#include <string>
#include "mps_mail_item.h"

namespace mir3d
{
	class mps_mail 
	{
	public:
		int64_t muid{};
	public:
		mpe_mail_state state{};
	public:
		int32_t id{};
	public:
		int64_t expir_date{};
	public:
		int64_t reg_date{};
	public:
		std::string title_text{};
	public:
		std::string contents_text{};
	public:
		std::vector<mps_mail_item> info{};

	public:
		mps_mail()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &muid);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &expir_date);
			protocol::SerializeType(pBuffer, &reg_date);
			protocol::SerializeType(pBuffer, &title_text);
			protocol::SerializeType(pBuffer, &contents_text);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
