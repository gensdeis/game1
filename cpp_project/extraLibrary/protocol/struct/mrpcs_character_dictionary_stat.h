#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_character_dictionary_stat 
	{
	public:
		int32_t pdef{};
	public:
		int32_t mdef{};
	public:
		int32_t accuracy{};
	public:
		int32_t atk{};
	public:
		int32_t def_penetrate_rate{};
	public:
		int32_t def_penetrate_value{};
	public:
		int32_t cc_resist{};
	public:
		int32_t cc_rate{};
	public:
		int32_t hp_max{};
	public:
		int32_t mp_max{};
	public:
		int32_t force_max{};

	public:
		mrpcs_character_dictionary_stat()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &pdef);
			protocol::SerializeType(pBuffer, &mdef);
			protocol::SerializeType(pBuffer, &accuracy);
			protocol::SerializeType(pBuffer, &atk);
			protocol::SerializeType(pBuffer, &def_penetrate_rate);
			protocol::SerializeType(pBuffer, &def_penetrate_value);
			protocol::SerializeType(pBuffer, &cc_resist);
			protocol::SerializeType(pBuffer, &cc_rate);
			protocol::SerializeType(pBuffer, &hp_max);
			protocol::SerializeType(pBuffer, &mp_max);
			protocol::SerializeType(pBuffer, &force_max);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
