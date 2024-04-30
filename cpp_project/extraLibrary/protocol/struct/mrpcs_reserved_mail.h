#pragma once
#include <vector>
#include <string>
#include "mps_mail_item.h"

namespace mir3d
{
	class mrpcs_reserved_mail 
	{
	public:
		int32_t seq{};
	public:
		mpe_mail_type mail_type{};
	public:
		std::vector<int32_t> send_server{};
	public:
		int32_t id{};
	public:
		std::string title_text{};
	public:
		std::string notice_text{};
	public:
		int32_t start_date{};
	public:
		int32_t end_date{};
	public:
		std::vector<mps_mail_item> info{};
	public:
		mrpce_reserved_mail_state_type mail_state{};

	public:
		mrpcs_reserved_mail()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &seq);
			protocol::SerializeEnum(pBuffer, &mail_type);
			protocol::SerializeType(pBuffer, &send_server);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &title_text);
			protocol::SerializeType(pBuffer, &notice_text);
			protocol::SerializeType(pBuffer, &start_date);
			protocol::SerializeType(pBuffer, &end_date);
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeEnum(pBuffer, &mail_state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
