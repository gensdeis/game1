#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_inven_size_change_cs : public BasePacket 
	{

	public:
		mp_inven_size_change_cs() : BasePacket(mpe_cmd::inven_size_change_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_inven_size_change_sc : public BasePacket 
	{
	public:
		int32_t equipstone_inven_size{};
	public:
		int32_t inven_size{};

	public:
		mp_inven_size_change_sc() : BasePacket(mpe_cmd::inven_size_change_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &equipstone_inven_size);
			protocol::SerializeType(pBuffer, &inven_size);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
