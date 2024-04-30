#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_ally_request_info.h"
#include "struct/mps_other_guild_info.h"

namespace mir3d
{
	class mp_guild_ally_request_regist_cs : public BasePacket 	// 문파 동맹 요청
	{
	public:
		int64_t target_guid{};	// 대상문파 UID
	public:
		bool is_regist{};	// true:등록요청 false:요청취소

	public:
		mp_guild_ally_request_regist_cs() : BasePacket(mpe_cmd::guild_ally_request_regist_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_guid);
			protocol::SerializeType(pBuffer, &is_regist);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_ally_request_regist_sc : public BasePacket 	// 문파 동맹 요청
	{
	public:
		bool is_regist{};	// 보내온값 그대로 넘겨줌
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
		mp_guild_ally_request_regist_sc() : BasePacket(mpe_cmd::guild_ally_request_regist_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
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
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
