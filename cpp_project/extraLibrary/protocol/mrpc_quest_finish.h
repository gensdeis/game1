#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_quest_finish.h"
#include "struct/mps_profesion.h"

namespace mir3d
{
	class mrpc_quest_finish_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::string username{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	private:
		bool flag_info = false;
		mrpcs_quest_finish info;
		mrpcs_quest_finish* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_quest_finish* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_quest_finish* get_info() const
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
		void set_info(mrpcs_quest_finish* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	private:
		bool flag_profesion = false;
		mps_profesion profesion;	// 승급 퀘스트 보상
		mps_profesion* p_profesion = nullptr;
	public:
		bool has_profesion() const
		{
			return flag_profesion;
		}
		mps_profesion* alloc_profesion()
		{
			flag_profesion = true;
			return &profesion;
		}
		const mps_profesion* get_profesion() const
		{
			if (true == flag_profesion)
			{
				if (nullptr == p_profesion)
				{
					return &profesion;
				}
				return p_profesion;
			}
			return nullptr;
		}
		void set_profesion(mps_profesion* in_profesion)
		{
			if (nullptr == p_profesion)
			{
				p_profesion = in_profesion;
				flag_profesion = true;
			}
		}

	public:
		mrpc_quest_finish_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::quest_finish_cs, tag)
		{
		}
		mrpc_quest_finish_cs() : RpcPacket(mpe_rpc_cmd::quest_finish_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &username);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &flag_profesion);
			if (true == flag_profesion)
			{
				if (nullptr != p_profesion)
					protocol::SerializeType(pBuffer, p_profesion);
				else
					protocol::SerializeType(pBuffer, &profesion);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_quest_finish_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_quest_finish_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::quest_finish_sc, tag)
		{
		}
		mrpc_quest_finish_sc() : RpcPacket(mpe_rpc_cmd::quest_finish_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
