#pragma once

namespace mir3d
{
	#define MAKE_SHORT(a, b)		((unsigned short)(((unsigned char)(((unsigned long)(a)) & 0xff)) | ((unsigned short)((unsigned char)(((unsigned long)(b)) & 0xff))) << 8))	
	#define MAKE_INT32(a, b, c, d)	((((int)(a) & 0xff)) | (((int)(b) & 0xff) << 8) | (((int)(c) & 0xff) << 16) | (((int)(d) & 0xff) << 24))	

	const int32_t	MAX_CLIENT_READ_BUFFER_SIZE = 40960;										// 2022.05.28 클라이언트가 보낼 수 있는 최대 패킷 크기	
	const int32_t	MAX_CLIENT_SOCKET_READ_BUFFER_SIZE = MAX_CLIENT_READ_BUFFER_SIZE * 2;

	// const int32_t	MAX_SOCKET_BUFFER_SIZE = 1024 * 1024;								// 2023.02.12 gogoblue74 - 서버용 패킷 버퍼
	const int32_t	MAX_SOCKET_BUFFER_SIZE = 8192 * 36;										// 2023.02.12 gogoblue74 - 서버용 패킷 버퍼
	const int32_t	MAX_SOCKET_READ_BUFFER_SIZE = MAX_SOCKET_BUFFER_SIZE * 2;				// 원형 큐 이기 때문에  원형이어지는 부분에서 카피를 덜 하기 위해 크게 잡는다.	
	const int32_t	SOCKET_BUFFER_CHECK_SIZE = 65535;										// 2023.02.12 크래시 발생되는 패킷을 찾기 위해서 사용

	const int32_t	PACKET_LENGTH_SIZE = 4;
	const int32_t	PACKET_COMMAND_SIZE = 2;
#ifdef _USE_NEW_PACKET_HEADER
	const int32_t	PACKET_CLIENT_TIME_SIZE = 4;
	const int32_t	PACKET_CLIENT_TIME_POS = PACKET_LENGTH_SIZE + PACKET_COMMAND_SIZE;
	const int32_t	PACKET_HEADER_SIZE = PACKET_LENGTH_SIZE + PACKET_COMMAND_SIZE + PACKET_CLIENT_TIME_SIZE;
#else
	const int32_t	PACKET_HEADER_SIZE = PACKET_LENGTH_SIZE + PACKET_COMMAND_SIZE;
#endif	

	const uint64_t	GHOST_SOCKET_TIMEOUT = 60000;

	const int32_t	PACKET_ERROR_SIZE = 4;
	const int32_t	PACKET_TAG_SIZE = 1;
	
	const uint64_t	UPDATE_TIME_HEARTBEAT_CHECK = 2000;			// gate 에서 heartbeat 체크 처리하는 간격
	
	static inline int MakeRpcPacketError(const char* data)
	{
		int32_t error_code;
		std::memcpy(&error_code, data, PACKET_ERROR_SIZE);
		// memcpy(&error_code, data, PACKET_ERROR_SIZE);
		return error_code;
	}

	static inline uint8_t MakeRpcPacketTag(const char* data)
	{
		uint8_t tag;		
		std::memcpy(&tag, &((uint8_t*)data)[PACKET_ERROR_SIZE], PACKET_TAG_SIZE);
		return tag;
	}

}	// namespace mir3d
