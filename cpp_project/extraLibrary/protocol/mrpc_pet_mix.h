#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_pet_info.h"
#include "struct/mps_reward_pet_info.h"
#include "struct/mps_temp_pet.h"
#include "struct/mps_dictionary_info.h"
#include "struct/mps_restore_compose.h"

namespace mir3d
{
	class mrpc_pet_mix_cs : public RpcPacket 	// 펫 합성
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_pet_info> material_pet_list{};	// 재료
	public:
		std::vector<mps_reward_pet_info> list_reward{};	// 합성 펫
	public:
		std::vector<mps_temp_pet> list_temp_pet{};	// 보관함
	public:
		std::vector<mps_dictionary_info> list_dic{};
	private:
		bool flag_restore_info = false;
		mps_restore_compose restore_info;
		mps_restore_compose* p_restore_info = nullptr;
	public:
		bool has_restore_info() const
		{
			return flag_restore_info;
		}
		mps_restore_compose* alloc_restore_info()
		{
			flag_restore_info = true;
			return &restore_info;
		}
		const mps_restore_compose* get_restore_info() const
		{
			if (true == flag_restore_info)
			{
				if (nullptr == p_restore_info)
				{
					return &restore_info;
				}
				return p_restore_info;
			}
			return nullptr;
		}
		void set_restore_info(mps_restore_compose* in_restore_info)
		{
			if (nullptr == p_restore_info)
			{
				p_restore_info = in_restore_info;
				flag_restore_info = true;
			}
		}

	public:
		mrpc_pet_mix_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::pet_mix_cs, tag)
		{
		}
		mrpc_pet_mix_cs() : RpcPacket(mpe_rpc_cmd::pet_mix_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &material_pet_list);
			protocol::SerializeType(pBuffer, &list_reward);
			protocol::SerializeType(pBuffer, &list_temp_pet);
			protocol::SerializeType(pBuffer, &list_dic);
			protocol::SerializeType(pBuffer, &flag_restore_info);
			if (true == flag_restore_info)
			{
				if (nullptr != p_restore_info)
					protocol::SerializeType(pBuffer, p_restore_info);
				else
					protocol::SerializeType(pBuffer, &restore_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_pet_mix_sc : public RpcPacket 	// 펫 합성
	{
	public:
		int64_t key{};

	public:
		mrpc_pet_mix_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::pet_mix_sc, tag)
		{
		}
		mrpc_pet_mix_sc() : RpcPacket(mpe_rpc_cmd::pet_mix_sc)
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
