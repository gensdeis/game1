#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_pk_revenge.h"

namespace mir3d
{
	class mp_pk_revenge_add_cs : public BasePacket 	// pk 복수 등록
	{
	public:
		int64_t record_id{};	// pk 복수 record_id

	public:
		mp_pk_revenge_add_cs() : BasePacket(mpe_cmd::pk_revenge_add_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &record_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_pk_revenge_add_sc : public BasePacket 	// pk 복수 등록
	{
	private:
		bool flag_pk_revenge = false;
		mps_pk_revenge pk_revenge;
		mps_pk_revenge* p_pk_revenge = nullptr;
	public:
		bool has_pk_revenge() const
		{
			return flag_pk_revenge;
		}
		mps_pk_revenge* alloc_pk_revenge()
		{
			flag_pk_revenge = true;
			return &pk_revenge;
		}
		const mps_pk_revenge* get_pk_revenge() const
		{
			if (true == flag_pk_revenge)
			{
				if (nullptr == p_pk_revenge)
				{
					return &pk_revenge;
				}
				return p_pk_revenge;
			}
			return nullptr;
		}
		void set_pk_revenge(mps_pk_revenge* in_pk_revenge)
		{
			if (nullptr == p_pk_revenge)
			{
				p_pk_revenge = in_pk_revenge;
				flag_pk_revenge = true;
			}
		}

	public:
		mp_pk_revenge_add_sc() : BasePacket(mpe_cmd::pk_revenge_add_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_pk_revenge);
			if (true == flag_pk_revenge)
			{
				if (nullptr != p_pk_revenge)
					protocol::SerializeType(pBuffer, p_pk_revenge);
				else
					protocol::SerializeType(pBuffer, &pk_revenge);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
