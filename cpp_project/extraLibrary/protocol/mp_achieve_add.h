#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_achieve_info.h"

namespace mir3d
{
	class mp_achieve_add_cs : public BasePacket 
	{
	public:
		int32_t gid{};	// 업적 그룹아이디
	public:
		int32_t value{};

	public:
		mp_achieve_add_cs() : BasePacket(mpe_cmd::achieve_add_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_achieve_add_sc : public BasePacket 
	{
	private:
		bool flag_achieve_info = false;
		mps_achieve_info achieve_info;	// 업적 정보
		mps_achieve_info* p_achieve_info = nullptr;
	public:
		bool has_achieve_info() const
		{
			return flag_achieve_info;
		}
		mps_achieve_info* alloc_achieve_info()
		{
			flag_achieve_info = true;
			return &achieve_info;
		}
		const mps_achieve_info* get_achieve_info() const
		{
			if (true == flag_achieve_info)
			{
				if (nullptr == p_achieve_info)
				{
					return &achieve_info;
				}
				return p_achieve_info;
			}
			return nullptr;
		}
		void set_achieve_info(mps_achieve_info* in_achieve_info)
		{
			if (nullptr == p_achieve_info)
			{
				p_achieve_info = in_achieve_info;
				flag_achieve_info = true;
			}
		}

	public:
		mp_achieve_add_sc() : BasePacket(mpe_cmd::achieve_add_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_achieve_info);
			if (true == flag_achieve_info)
			{
				if (nullptr != p_achieve_info)
					protocol::SerializeType(pBuffer, p_achieve_info);
				else
					protocol::SerializeType(pBuffer, &achieve_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
