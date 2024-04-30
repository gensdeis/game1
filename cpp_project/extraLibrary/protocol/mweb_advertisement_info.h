#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_advertisement.h"
#include "struct/mps_character_advertisement.h"

namespace mir3d
{
	class mweb_advertisement_info_cs : public WebBasePacket 	// 광고 정보
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};

	public:
		mweb_advertisement_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_advertisement_info_sc : public WebBasePacket 	// 광고 정보
	{
	public:
		int32_t result{};
	private:
		bool flag_advertisement = false;
		mps_advertisement advertisement;
		mps_advertisement* p_advertisement = nullptr;
	public:
		bool has_advertisement() const
		{
			return flag_advertisement;
		}
		mps_advertisement* alloc_advertisement()
		{
			flag_advertisement = true;
			return &advertisement;
		}
		const mps_advertisement* get_advertisement() const
		{
			if (true == flag_advertisement)
			{
				if (nullptr == p_advertisement)
				{
					return &advertisement;
				}
				return p_advertisement;
			}
			return nullptr;
		}
		void set_advertisement(mps_advertisement* in_advertisement)
		{
			if (nullptr == p_advertisement)
			{
				p_advertisement = in_advertisement;
				flag_advertisement = true;
			}
		}
	private:
		bool flag_character_advertisement = false;
		mps_character_advertisement character_advertisement;
		mps_character_advertisement* p_character_advertisement = nullptr;
	public:
		bool has_character_advertisement() const
		{
			return flag_character_advertisement;
		}
		mps_character_advertisement* alloc_character_advertisement()
		{
			flag_character_advertisement = true;
			return &character_advertisement;
		}
		const mps_character_advertisement* get_character_advertisement() const
		{
			if (true == flag_character_advertisement)
			{
				if (nullptr == p_character_advertisement)
				{
					return &character_advertisement;
				}
				return p_character_advertisement;
			}
			return nullptr;
		}
		void set_character_advertisement(mps_character_advertisement* in_character_advertisement)
		{
			if (nullptr == p_character_advertisement)
			{
				p_character_advertisement = in_character_advertisement;
				flag_character_advertisement = true;
			}
		}

	public:
		mweb_advertisement_info_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &flag_advertisement);
			if (true == flag_advertisement)
			{
				if (nullptr != p_advertisement)
					protocol::SerializeType(pBuffer, p_advertisement);
				else
					protocol::SerializeType(pBuffer, &advertisement);
			}
			protocol::SerializeType(pBuffer, &flag_character_advertisement);
			if (true == flag_character_advertisement)
			{
				if (nullptr != p_character_advertisement)
					protocol::SerializeType(pBuffer, p_character_advertisement);
				else
					protocol::SerializeType(pBuffer, &character_advertisement);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
