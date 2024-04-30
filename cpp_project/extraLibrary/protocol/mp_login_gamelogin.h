#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_server_info.h"

namespace mir3d
{
	class mp_login_gamelogin_cs : public BasePacket 	// 로비 서버 접속
	{
	public:
		int64_t auid{};

	public:
		mp_login_gamelogin_cs() : BasePacket(mpe_cmd::login_gamelogin_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_login_gamelogin_sc : public BasePacket 	// 로비 서버 접속
	{
	public:
		int32_t result{};
	public:
		int32_t awaiter_count{};
	public:
		bool quicklogin{};
	private:
		bool flag_server_info = false;
		mps_server_info server_info;
		mps_server_info* p_server_info = nullptr;
	public:
		bool has_server_info() const
		{
			return flag_server_info;
		}
		mps_server_info* alloc_server_info()
		{
			flag_server_info = true;
			return &server_info;
		}
		const mps_server_info* get_server_info() const
		{
			if (true == flag_server_info)
			{
				if (nullptr == p_server_info)
				{
					return &server_info;
				}
				return p_server_info;
			}
			return nullptr;
		}
		void set_server_info(mps_server_info* in_server_info)
		{
			if (nullptr == p_server_info)
			{
				p_server_info = in_server_info;
				flag_server_info = true;
			}
		}
	public:
		std::string board_url_info{};

	public:
		mp_login_gamelogin_sc() : BasePacket(mpe_cmd::login_gamelogin_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &awaiter_count);
			protocol::SerializeType(pBuffer, &quicklogin);
			protocol::SerializeType(pBuffer, &flag_server_info);
			if (true == flag_server_info)
			{
				if (nullptr != p_server_info)
					protocol::SerializeType(pBuffer, p_server_info);
				else
					protocol::SerializeType(pBuffer, &server_info);
			}
			protocol::SerializeType(pBuffer, &board_url_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
