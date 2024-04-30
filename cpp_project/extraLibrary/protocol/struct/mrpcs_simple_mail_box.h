#pragma once
#include <vector>
#include <string>
#include "mrpcs_simple_mail.h"
#include "mrpcs_simple_mail.h"
#include "mrpcs_simple_mail.h"

namespace mir3d
{
	class mrpcs_simple_mail_box 
	{
	public:
		std::vector<mrpcs_simple_mail> list_account{};
	public:
		std::vector<mrpcs_simple_mail> list_character{};
	public:
		std::vector<mrpcs_simple_mail> list_server{};

	public:
		mrpcs_simple_mail_box()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list_account);
			protocol::SerializeType(pBuffer, &list_character);
			protocol::SerializeType(pBuffer, &list_server);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
