#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_subscription_info.h"

namespace mir3d
{
	class mrpc_gm_api_character_subscription_update_cs : public RpcPacket 	// MPBS통한 구독정보 업데이트
	{

	public:
		mrpc_gm_api_character_subscription_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_api_character_subscription_update_cs, tag)
		{
		}
		mrpc_gm_api_character_subscription_update_cs() : RpcPacket(mpe_rpc_cmd::gm_api_character_subscription_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_api_character_subscription_update_sc : public RpcPacket 	// MPBS통한 구독정보 업데이트
	{
	public:
		int64_t cuid{};	// 캐릭터 아이디
	private:
		bool flag_info = false;
		mrpcs_subscription_info info;	// 구독 서비스 정보
		mrpcs_subscription_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_subscription_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_subscription_info* get_info() const
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
		void set_info(mrpcs_subscription_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_gm_api_character_subscription_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_api_character_subscription_update_sc, tag)
		{
		}
		mrpc_gm_api_character_subscription_update_sc() : RpcPacket(mpe_rpc_cmd::gm_api_character_subscription_update_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
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
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
