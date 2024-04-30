#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_siege_machine.h"

namespace mir3d
{
	class mp_siege_warfare_def_release_machine_cs : public BasePacket 	// 수성병기 해제
	{
	public:
		int64_t nuid{};
	public:
		mpe_siege_castle_type castle_type{};	// 성 type
	private:
		bool flag_machine_info = false;
		mps_siege_machine machine_info;	// 공성무기
		mps_siege_machine* p_machine_info = nullptr;
	public:
		bool has_machine_info() const
		{
			return flag_machine_info;
		}
		mps_siege_machine* alloc_machine_info()
		{
			flag_machine_info = true;
			return &machine_info;
		}
		const mps_siege_machine* get_machine_info() const
		{
			if (true == flag_machine_info)
			{
				if (nullptr == p_machine_info)
				{
					return &machine_info;
				}
				return p_machine_info;
			}
			return nullptr;
		}
		void set_machine_info(mps_siege_machine* in_machine_info)
		{
			if (nullptr == p_machine_info)
			{
				p_machine_info = in_machine_info;
				flag_machine_info = true;
			}
		}

	public:
		mp_siege_warfare_def_release_machine_cs() : BasePacket(mpe_cmd::siege_warfare_def_release_machine_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nuid);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &flag_machine_info);
			if (true == flag_machine_info)
			{
				if (nullptr != p_machine_info)
					protocol::SerializeType(pBuffer, p_machine_info);
				else
					protocol::SerializeType(pBuffer, &machine_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_siege_warfare_def_release_machine_sc : public BasePacket 	// 수성병기 해제
	{

	public:
		mp_siege_warfare_def_release_machine_sc() : BasePacket(mpe_cmd::siege_warfare_def_release_machine_sc)
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

}
