#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_profesion_update.h"

namespace mir3d
{
	class mp_profesion_upgrade_cs : public BasePacket 
	{
	public:
		int32_t type{};
	public:
		int64_t npc_uid{};

	public:
		mp_profesion_upgrade_cs() : BasePacket(mpe_cmd::profesion_upgrade_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &npc_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_profesion_upgrade_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_profesion_update info;
		mps_profesion_update* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_profesion_update* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_profesion_update* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mps_profesion_update* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_profesion_upgrade_sc() : BasePacket(mpe_cmd::profesion_upgrade_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
