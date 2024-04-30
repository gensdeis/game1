#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_buff.h"
#include "struct/mps_buff.h"

namespace mir3d
{
	class mp_mentor_buff_cs : public BasePacket 
	{
	public:
		bool online{};
	public:
		int64_t cuid{};
	private:
		bool flag_buff_info = false;
		mps_buff buff_info;
		mps_buff* p_buff_info = nullptr;
	public:
		bool has_buff_info() const
		{
			return flag_buff_info;
		}
		mps_buff* alloc_buff_info()
		{
			flag_buff_info = true;
			return &buff_info;
		}
		const mps_buff* get_buff_info() const
		{
			if (true == flag_buff_info)
			{
				if (nullptr == p_buff_info)
				{
					return &buff_info;
				}
				return p_buff_info;
			}
			return nullptr;
		}
		void set_buff_info(mps_buff* in_buff_info)
		{
			if (nullptr == p_buff_info)
			{
				p_buff_info = in_buff_info;
				flag_buff_info = true;
			}
		}

	public:
		mp_mentor_buff_cs() : BasePacket(mpe_cmd::mentor_buff_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &online);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_buff_info);
			if (true == flag_buff_info)
			{
				if (nullptr != p_buff_info)
					protocol::SerializeType(pBuffer, p_buff_info);
				else
					protocol::SerializeType(pBuffer, &buff_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_mentor_buff_sc : public BasePacket 
	{
	public:
		bool online{};
	public:
		int64_t cuid{};
	private:
		bool flag_buff_info = false;
		mps_buff buff_info;
		mps_buff* p_buff_info = nullptr;
	public:
		bool has_buff_info() const
		{
			return flag_buff_info;
		}
		mps_buff* alloc_buff_info()
		{
			flag_buff_info = true;
			return &buff_info;
		}
		const mps_buff* get_buff_info() const
		{
			if (true == flag_buff_info)
			{
				if (nullptr == p_buff_info)
				{
					return &buff_info;
				}
				return p_buff_info;
			}
			return nullptr;
		}
		void set_buff_info(mps_buff* in_buff_info)
		{
			if (nullptr == p_buff_info)
			{
				p_buff_info = in_buff_info;
				flag_buff_info = true;
			}
		}

	public:
		mp_mentor_buff_sc() : BasePacket(mpe_cmd::mentor_buff_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &online);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_buff_info);
			if (true == flag_buff_info)
			{
				if (nullptr != p_buff_info)
					protocol::SerializeType(pBuffer, p_buff_info);
				else
					protocol::SerializeType(pBuffer, &buff_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
