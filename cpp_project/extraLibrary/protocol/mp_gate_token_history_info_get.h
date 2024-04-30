#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_token_history_info.h"

namespace mir3d
{
	class mp_gate_token_history_info_get_cs : public BasePacket 
	{
	public:
		int64_t auid{};
	public:
		int64_t access_token{};

	public:
		mp_gate_token_history_info_get_cs() : BasePacket(mpe_cmd::gate_token_history_info_get_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &access_token);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_token_history_info_get_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_token_history_info info;
		mps_token_history_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_token_history_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_token_history_info* get_info() const
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
		void set_info(mps_token_history_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_gate_token_history_info_get_sc() : BasePacket(mpe_cmd::gate_token_history_info_get_sc)
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
