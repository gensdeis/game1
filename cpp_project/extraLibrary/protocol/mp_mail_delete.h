#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_mail_delete_cs : public BasePacket 	// 메일 삭제
	{
	public:
		std::vector<int64_t> muid{};
	public:
		mpe_mail_type mail_type{};

	public:
		mp_mail_delete_cs() : BasePacket(mpe_cmd::mail_delete_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &muid);
			protocol::SerializeEnum(pBuffer, &mail_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_mail_delete_sc : public BasePacket 	// 메일 삭제
	{
	public:
		std::vector<int64_t> delete_muid{};
	public:
		mpe_mail_type mail_type{};
	public:
		mpe_error result_code{};

	public:
		mp_mail_delete_sc() : BasePacket(mpe_cmd::mail_delete_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &delete_muid);
			protocol::SerializeEnum(pBuffer, &mail_type);
			protocol::SerializeEnum(pBuffer, &result_code);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
