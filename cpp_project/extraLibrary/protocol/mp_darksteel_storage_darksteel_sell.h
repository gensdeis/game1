#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_darksteel_storage_darksteel_sell_cs : public BasePacket 	// 비곡창고 흑철판매
	{
	public:
		int64_t count{};

	public:
		mp_darksteel_storage_darksteel_sell_cs() : BasePacket(mpe_cmd::darksteel_storage_darksteel_sell_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_darksteel_storage_darksteel_sell_sc : public BasePacket 	// 비곡창고 흑철판매
	{
	public:
		int64_t count{};

	public:
		mp_darksteel_storage_darksteel_sell_sc() : BasePacket(mpe_cmd::darksteel_storage_darksteel_sell_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
