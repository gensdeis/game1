#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_player_equipitem 
	{
	public:
		std::vector<uint16_t> list{};

	public:
		mrpcs_player_equipitem()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
