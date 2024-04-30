#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_ally_request_info.h"
#include "struct/mps_other_guild_info.h"

namespace mir3d
{
	class mrpc_guild_ally_request_regist_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};	// "요청자 cuid"
	public:
		int64_t my_guid{};	// 내 문파 UID
	public:
		int64_t target_guid{};	// 대상 문파 UID
	public:
		bool is_regist{};	// true:등록요청 false:요청취소

	public:
		mrpc_guild_ally_request_regist_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_ally_request_regist_cs, tag)
		{
		}
		mrpc_guild_ally_request_regist_cs() : RpcPacket(mpe_rpc_cmd::guild_ally_request_regist_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &my_guid);
			protocol::SerializeType(pBuffer, &target_guid);
			protocol::SerializeType(pBuffer, &is_regist);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_ally_request_regist_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		bool is_regist{};	// 결과 요청값 그대로 돌려줌
	private:
		bool flag_request_info = false;
		mps_guild_ally_request_info request_info;	// "추가/삭제된 동맹 신청 정보."
		mps_guild_ally_request_info* p_request_info = nullptr;
	public:
		bool has_request_info() const
		{
			return flag_request_info;
		}
		mps_guild_ally_request_info* alloc_request_info()
		{
			flag_request_info = true;
			return &request_info;
		}
		const mps_guild_ally_request_info* get_request_info() const
		{
			if (true == flag_request_info)
			{
				if (nullptr == p_request_info)
				{
					return &request_info;
				}
				return p_request_info;
			}
			return nullptr;
		}
		void set_request_info(mps_guild_ally_request_info* in_request_info)
		{
			if (nullptr == p_request_info)
			{
				p_request_info = in_request_info;
				flag_request_info = true;
			}
		}
	private:
		bool flag_guild_info = false;
		mps_other_guild_info guild_info;	// "동맹 요청한 문파 정보. is_regist가 참 일때만 유효."
		mps_other_guild_info* p_guild_info = nullptr;
	public:
		bool has_guild_info() const
		{
			return flag_guild_info;
		}
		mps_other_guild_info* alloc_guild_info()
		{
			flag_guild_info = true;
			return &guild_info;
		}
		const mps_other_guild_info* get_guild_info() const
		{
			if (true == flag_guild_info)
			{
				if (nullptr == p_guild_info)
				{
					return &guild_info;
				}
				return p_guild_info;
			}
			return nullptr;
		}
		void set_guild_info(mps_other_guild_info* in_guild_info)
		{
			if (nullptr == p_guild_info)
			{
				p_guild_info = in_guild_info;
				flag_guild_info = true;
			}
		}

	public:
		mrpc_guild_ally_request_regist_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_ally_request_regist_sc, tag)
		{
		}
		mrpc_guild_ally_request_regist_sc() : RpcPacket(mpe_rpc_cmd::guild_ally_request_regist_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &is_regist);
			protocol::SerializeType(pBuffer, &flag_request_info);
			if (true == flag_request_info)
			{
				if (nullptr != p_request_info)
					protocol::SerializeType(pBuffer, p_request_info);
				else
					protocol::SerializeType(pBuffer, &request_info);
			}
			protocol::SerializeType(pBuffer, &flag_guild_info);
			if (true == flag_guild_info)
			{
				if (nullptr != p_guild_info)
					protocol::SerializeType(pBuffer, p_guild_info);
				else
					protocol::SerializeType(pBuffer, &guild_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
