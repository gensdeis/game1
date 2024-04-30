#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_token_history 
	{
	public:
		int64_t huid{};
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		mpe_token_history_type log_type{};
	public:
		mpe_token_history_case log_case{};
	public:
		float token_count{};
	public:
		uint16_t gid{};
	public:
		int32_t tid{};
	public:
		uint16_t item_count{};
	public:
		bool is_receipt{};
	public:
		int32_t reg_datetime{};

	public:
		mps_token_history()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &huid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeEnum(pBuffer, &log_type);
			protocol::SerializeEnum(pBuffer, &log_case);
			protocol::SerializeType(pBuffer, &token_count);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &item_count);
			protocol::SerializeType(pBuffer, &is_receipt);
			protocol::SerializeType(pBuffer, &reg_datetime);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
