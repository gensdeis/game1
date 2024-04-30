#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_darksteel_storage_darksteel_pay_cs : public BasePacket 	// 비곡창고 흑철지급
	{
	public:
		mpe_darksteel_storage_pay_type type{};
	public:
		std::vector<int64_t> list_uid{};	// 지급 대상들 또는 문파
	public:
		int32_t count{};

	public:
		mp_darksteel_storage_darksteel_pay_cs() : BasePacket(mpe_cmd::darksteel_storage_darksteel_pay_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &list_uid);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_darksteel_storage_darksteel_pay_sc : public BasePacket 	// 비곡창고 흑철지급
	{
	public:
		mpe_error error_code{};

	public:
		mp_darksteel_storage_darksteel_pay_sc() : BasePacket(mpe_cmd::darksteel_storage_darksteel_pay_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &error_code);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
