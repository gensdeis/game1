#pragma once
#include <vector>
#include <string>
#include "mps_mail.h"

namespace mir3d
{
	class mps_received_mail 
	{
	public:
		mpe_mail_type mail_type{};
	public:
		std::vector<mps_mail> list_mail{};
	public:
		std::vector<int64_t> list_delete_muid{};

	public:
		mps_received_mail()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &mail_type);
			protocol::SerializeType(pBuffer, &list_mail);
			protocol::SerializeType(pBuffer, &list_delete_muid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
