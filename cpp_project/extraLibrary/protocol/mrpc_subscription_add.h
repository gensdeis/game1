#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_subscription_info.h"

namespace mir3d
{
	class mrpc_subscription_add_cs : public RpcPacket 	// 구독서비스 아이템 사용으로인한 관련 정보전달
	{
	private:
		bool flag_info = false;
		mrpcs_subscription_info info;	// 구독서비스 정보
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
		int64_t cuid{};	// 캐릭터 아이디
	public:
		int32_t item_id{};	// 사용한 아이템 아이디
	public:
		int32_t last_update_date{};	// 구독서비스 갱신날짜
	public:
		bool post_flag{};	// 응답패킷 전송 플래그

	public:
		mrpc_subscription_add_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::subscription_add_cs, tag)
		{
		}
		mrpc_subscription_add_cs() : RpcPacket(mpe_rpc_cmd::subscription_add_cs)
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
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &item_id);
			protocol::SerializeType(pBuffer, &last_update_date);
			protocol::SerializeType(pBuffer, &post_flag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_subscription_add_sc : public RpcPacket 	// 구독서비스 아이템 사용으로인한 관련 정보전달
	{
	public:
		int64_t cuid{};	// 캐릭터 아이디

	public:
		mrpc_subscription_add_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::subscription_add_sc, tag)
		{
		}
		mrpc_subscription_add_sc() : RpcPacket(mpe_rpc_cmd::subscription_add_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
