#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_party_member.h"

namespace mir3d
{
	class mp_party_invite_agree_cs : public BasePacket 
	{
	public:
		int64_t puid{};

	public:
		mp_party_invite_agree_cs() : BasePacket(mpe_cmd::party_invite_agree_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &puid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_party_invite_agree_sc : public BasePacket 
	{
	private:
		bool flag_member = false;
		mps_party_member member;
		mps_party_member* p_member = nullptr;
	public:
		bool has_member() const
		{
			return flag_member;
		}
		mps_party_member* alloc_member()
		{
			flag_member = true;
			return &member;
		}
		const mps_party_member* get_member() const
		{
			if (true == flag_member)
			{
				if (nullptr == p_member)
				{
					return &member;
				}
				return p_member;
			}
			return nullptr;
		}
		void set_member(mps_party_member* in_member)
		{
			if (nullptr == p_member)
			{
				p_member = in_member;
				flag_member = true;
			}
		}

	public:
		mp_party_invite_agree_sc() : BasePacket(mpe_cmd::party_invite_agree_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_member);
			if (true == flag_member)
			{
				if (nullptr != p_member)
					protocol::SerializeType(pBuffer, p_member);
				else
					protocol::SerializeType(pBuffer, &member);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
