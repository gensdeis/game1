#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_pet_info.h"
#include "struct/mps_temp_pet.h"
#include "struct/mps_obtain_avatar.h"
#include "struct/mps_obtain_reflection.h"
#include "struct/mps_temp_reflection.h"
#include "struct/mps_dictionary_info.h"

namespace mir3d
{
	class mrpc_randombox_open_cs : public RpcPacket 
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
		mps_item_add info;
		mps_item_add* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_add* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_add* get_info() const
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
		void set_info(mps_item_add* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		std::vector<mps_pet_info> pet_info{};
	public:
		std::vector<mps_temp_pet> list_temp_pet{};
	public:
		std::vector<mps_obtain_avatar> list_avatar{};
	public:
		std::vector<mps_obtain_reflection> list_reflection{};
	public:
		std::vector<mps_temp_reflection> list_temp_reflection{};
	public:
		std::vector<mps_dictionary_info> list_dic{};

	public:
		mrpc_randombox_open_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::randombox_open_cs, tag)
		{
		}
		mrpc_randombox_open_cs() : RpcPacket(mpe_rpc_cmd::randombox_open_cs)
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
			protocol::SerializeType(pBuffer, &pet_info);
			protocol::SerializeType(pBuffer, &list_temp_pet);
			protocol::SerializeType(pBuffer, &list_avatar);
			protocol::SerializeType(pBuffer, &list_reflection);
			protocol::SerializeType(pBuffer, &list_temp_reflection);
			protocol::SerializeType(pBuffer, &list_dic);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_randombox_open_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_randombox_open_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::randombox_open_sc, tag)
		{
		}
		mrpc_randombox_open_sc() : RpcPacket(mpe_rpc_cmd::randombox_open_sc)
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
