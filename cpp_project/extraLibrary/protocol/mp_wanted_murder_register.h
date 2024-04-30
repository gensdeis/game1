#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_wanted_murder_register_info.h"
#include "struct/mps_update_goods_list.h"

namespace mir3d
{
	class mp_wanted_murder_register_cs : public BasePacket 
	{
	public:
		int64_t target_cuid{};
	public:
		int64_t record_id{};
	public:
		int32_t pay{};
	public:
		int32_t shop_tid{};

	public:
		mp_wanted_murder_register_cs() : BasePacket(mpe_cmd::wanted_murder_register_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &record_id);
			protocol::SerializeType(pBuffer, &pay);
			protocol::SerializeType(pBuffer, &shop_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_wanted_murder_register_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_wanted_murder_register_info info;
		mps_wanted_murder_register_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_wanted_murder_register_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_wanted_murder_register_info* get_info() const
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
		void set_info(mps_wanted_murder_register_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	private:
		bool flag_good_info = false;
		mps_update_goods_list good_info;
		mps_update_goods_list* p_good_info = nullptr;
	public:
		bool has_good_info() const
		{
			return flag_good_info;
		}
		mps_update_goods_list* alloc_good_info()
		{
			flag_good_info = true;
			return &good_info;
		}
		const mps_update_goods_list* get_good_info() const
		{
			if (true == flag_good_info)
			{
				if (nullptr == p_good_info)
				{
					return &good_info;
				}
				return p_good_info;
			}
			return nullptr;
		}
		void set_good_info(mps_update_goods_list* in_good_info)
		{
			if (nullptr == p_good_info)
			{
				p_good_info = in_good_info;
				flag_good_info = true;
			}
		}
	public:
		bool result{};

	public:
		mp_wanted_murder_register_sc() : BasePacket(mpe_cmd::wanted_murder_register_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &flag_good_info);
			if (true == flag_good_info)
			{
				if (nullptr != p_good_info)
					protocol::SerializeType(pBuffer, p_good_info);
				else
					protocol::SerializeType(pBuffer, &good_info);
			}
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
