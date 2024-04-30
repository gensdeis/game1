#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_character_enable 
	{
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		int32_t id{};
	public:
		int32_t level{};
	public:
		bool enable{};

	public:
		mrpcs_character_enable()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &enable);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
