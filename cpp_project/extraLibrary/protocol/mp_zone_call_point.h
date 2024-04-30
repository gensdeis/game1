#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_vector2d.h"
#include "struct/mps_vector2d.h"

namespace mir3d
{
	class mp_zone_call_point_cs : public BasePacket 
	{
	private:
		bool flag_call_point = false;
		mps_vector2d call_point;
		mps_vector2d* p_call_point = nullptr;
	public:
		bool has_call_point() const
		{
			return flag_call_point;
		}
		mps_vector2d* alloc_call_point()
		{
			flag_call_point = true;
			return &call_point;
		}
		const mps_vector2d* get_call_point() const
		{
			if (true == flag_call_point)
			{
				if (nullptr == p_call_point)
				{
					return &call_point;
				}
				return p_call_point;
			}
			return nullptr;
		}
		void set_call_point(mps_vector2d* in_call_point)
		{
			if (nullptr == p_call_point)
			{
				p_call_point = in_call_point;
				flag_call_point = true;
			}
		}

	public:
		mp_zone_call_point_cs() : BasePacket(mpe_cmd::zone_call_point_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_call_point);
			if (true == flag_call_point)
			{
				if (nullptr != p_call_point)
					protocol::SerializeType(pBuffer, p_call_point);
				else
					protocol::SerializeType(pBuffer, &call_point);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_zone_call_point_sc : public BasePacket 
	{
	private:
		bool flag_call_point = false;
		mps_vector2d call_point;
		mps_vector2d* p_call_point = nullptr;
	public:
		bool has_call_point() const
		{
			return flag_call_point;
		}
		mps_vector2d* alloc_call_point()
		{
			flag_call_point = true;
			return &call_point;
		}
		const mps_vector2d* get_call_point() const
		{
			if (true == flag_call_point)
			{
				if (nullptr == p_call_point)
				{
					return &call_point;
				}
				return p_call_point;
			}
			return nullptr;
		}
		void set_call_point(mps_vector2d* in_call_point)
		{
			if (nullptr == p_call_point)
			{
				p_call_point = in_call_point;
				flag_call_point = true;
			}
		}

	public:
		mp_zone_call_point_sc() : BasePacket(mpe_cmd::zone_call_point_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_call_point);
			if (true == flag_call_point)
			{
				if (nullptr != p_call_point)
					protocol::SerializeType(pBuffer, p_call_point);
				else
					protocol::SerializeType(pBuffer, &call_point);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
