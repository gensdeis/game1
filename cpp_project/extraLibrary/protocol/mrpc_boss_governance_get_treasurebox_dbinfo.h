#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_boss_governance_treasurebox.h"

namespace mir3d
{
	class mrpc_boss_governance_get_treasurebox_dbinfo_cs : public RpcPacket 	// 보스거버넌스 보물상자 추가확률 정보
	{
	public:
		int32_t gid{};	// 서버 아이디

	public:
		mrpc_boss_governance_get_treasurebox_dbinfo_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::boss_governance_get_treasurebox_dbinfo_cs, tag)
		{
		}
		mrpc_boss_governance_get_treasurebox_dbinfo_cs() : RpcPacket(mpe_rpc_cmd::boss_governance_get_treasurebox_dbinfo_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_boss_governance_get_treasurebox_dbinfo_sc : public RpcPacket 	// 보스거버넌스 보물상자 추가확률 정보
	{
	private:
		bool flag_info = false;
		mrpcs_boss_governance_treasurebox info;	// 보스거버넌스 보물상자 추가확률 정보
		mrpcs_boss_governance_treasurebox* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_boss_governance_treasurebox* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_boss_governance_treasurebox* get_info() const
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
		void set_info(mrpcs_boss_governance_treasurebox* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		bool on_off{};	// 혜택유무

	public:
		mrpc_boss_governance_get_treasurebox_dbinfo_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::boss_governance_get_treasurebox_dbinfo_sc, tag)
		{
		}
		mrpc_boss_governance_get_treasurebox_dbinfo_sc() : RpcPacket(mpe_rpc_cmd::boss_governance_get_treasurebox_dbinfo_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &on_off);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
