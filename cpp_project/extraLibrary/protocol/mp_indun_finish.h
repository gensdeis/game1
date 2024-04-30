#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_siege_result_score.h"

namespace mir3d
{
	class mp_indun_finish_cs : public BasePacket 
	{

	public:
		mp_indun_finish_cs() : BasePacket(mpe_cmd::indun_finish_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_indun_finish_sc : public BasePacket 
	{
	public:
		bool result{};
	public:
		int32_t tid{};
	private:
		bool flag_result_score = false;
		mps_siege_result_score result_score;	// 공성전 결과
		mps_siege_result_score* p_result_score = nullptr;
	public:
		bool has_result_score() const
		{
			return flag_result_score;
		}
		mps_siege_result_score* alloc_result_score()
		{
			flag_result_score = true;
			return &result_score;
		}
		const mps_siege_result_score* get_result_score() const
		{
			if (true == flag_result_score)
			{
				if (nullptr == p_result_score)
				{
					return &result_score;
				}
				return p_result_score;
			}
			return nullptr;
		}
		void set_result_score(mps_siege_result_score* in_result_score)
		{
			if (nullptr == p_result_score)
			{
				p_result_score = in_result_score;
				flag_result_score = true;
			}
		}

	public:
		mp_indun_finish_sc() : BasePacket(mpe_cmd::indun_finish_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &flag_result_score);
			if (true == flag_result_score)
			{
				if (nullptr != p_result_score)
					protocol::SerializeType(pBuffer, p_result_score);
				else
					protocol::SerializeType(pBuffer, &result_score);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
