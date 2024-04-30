#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_comm_message.h"
#include "struct/mrpcs_comm_message.h"

namespace mir3d
{
	class mrpc_community_object_message_cs : public RpcPacket 
	{
	private:
		bool flag_message = false;
		mrpcs_comm_message message;
		mrpcs_comm_message* p_message = nullptr;
	public:
		bool has_message() const
		{
			return flag_message;
		}
		mrpcs_comm_message* alloc_message()
		{
			flag_message = true;
			return &message;
		}
		const mrpcs_comm_message* get_message() const
		{
			if (true == flag_message)
			{
				if (nullptr == p_message)
				{
					return &message;
				}
				return p_message;
			}
			return nullptr;
		}
		void set_message(mrpcs_comm_message* in_message)
		{
			if (nullptr == p_message)
			{
				p_message = in_message;
				flag_message = true;
			}
		}

	public:
		mrpc_community_object_message_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_object_message_cs, tag)
		{
		}
		mrpc_community_object_message_cs() : RpcPacket(mpe_rpc_cmd::community_object_message_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_message);
			if (true == flag_message)
			{
				if (nullptr != p_message)
					protocol::SerializeType(pBuffer, p_message);
				else
					protocol::SerializeType(pBuffer, &message);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_community_object_message_sc : public RpcPacket 
	{
	public:
		int64_t channel_uid{};
	private:
		bool flag_message = false;
		mrpcs_comm_message message;
		mrpcs_comm_message* p_message = nullptr;
	public:
		bool has_message() const
		{
			return flag_message;
		}
		mrpcs_comm_message* alloc_message()
		{
			flag_message = true;
			return &message;
		}
		const mrpcs_comm_message* get_message() const
		{
			if (true == flag_message)
			{
				if (nullptr == p_message)
				{
					return &message;
				}
				return p_message;
			}
			return nullptr;
		}
		void set_message(mrpcs_comm_message* in_message)
		{
			if (nullptr == p_message)
			{
				p_message = in_message;
				flag_message = true;
			}
		}

	public:
		mrpc_community_object_message_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_object_message_sc, tag)
		{
		}
		mrpc_community_object_message_sc() : RpcPacket(mpe_rpc_cmd::community_object_message_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &flag_message);
			if (true == flag_message)
			{
				if (nullptr != p_message)
					protocol::SerializeType(pBuffer, p_message);
				else
					protocol::SerializeType(pBuffer, &message);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
