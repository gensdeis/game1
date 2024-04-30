#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_storage_history 
	{
	public:
		int64_t huid{};
	public:
		int64_t guid{};
	public:
		int32_t stringID{};
	public:
		int32_t history_type{};
	public:
		std::string param_str{};
	public:
		std::string goods_str{};
	public:
		std::string item_str{};
	public:
		int32_t regDateTime{};

	public:
		mps_guild_storage_history()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &huid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &stringID);
			protocol::SerializeType(pBuffer, &history_type);
			protocol::SerializeType(pBuffer, &param_str);
			protocol::SerializeType(pBuffer, &goods_str);
			protocol::SerializeType(pBuffer, &item_str);
			protocol::SerializeType(pBuffer, &regDateTime);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
