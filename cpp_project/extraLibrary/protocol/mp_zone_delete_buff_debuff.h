#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_zone_delete_buff_debuff_cs : public BasePacket 
	{

	public:
		mp_zone_delete_buff_debuff_cs() : BasePacket(mpe_cmd::zone_delete_buff_debuff_cs)
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

	class mp_zone_delete_buff_debuff_sc : public BasePacket 
	{
	public:
		int64_t target_uid{};
	public:
		std::vector<int64_t> buff_debuff_uid_list{};

	public:
		mp_zone_delete_buff_debuff_sc() : BasePacket(mpe_cmd::zone_delete_buff_debuff_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_uid);
			protocol::SerializeType(pBuffer, &buff_debuff_uid_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
