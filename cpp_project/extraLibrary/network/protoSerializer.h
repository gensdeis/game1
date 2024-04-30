#pragma once

#include <memory>
//#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <common/mirapi.h>
#include <common/define.h>

namespace mir3d
{
	class protoSerializer
	{
	public:
		//static bool Serialize(const MirMessage& message, char* buffer, uint16_t& size)
		//{
		//	size = message.ByteSize() + PACKET_HEADER_SIZE;
		//	if (MAX_WRITE_BUFFER_LEN <= size)
		//	{
		//		LOG(ERROR) << "protoSerializer.Serialize() big size packet send, size : " << size << ", packet : " << message.msgtype();
		//	}
		//	memcpy(buffer, &size, PACKET_HEADER_SIZE);
		//	return message.SerializeToArray(&buffer[PACKET_HEADER_SIZE], size - PACKET_HEADER_SIZE);
		//}

		//static bool Serialize(const std::shared_ptr<MirMessage>& message, char* buffer, uint16_t& size)
		//{
		//	size = message->ByteSize() + PACKET_HEADER_SIZE;
		//	if (MAX_WRITE_BUFFER_LEN <= size)
		//	{
		//		LOG(ERROR) << "protoSerializer.Serialize() big size packet send, size : " << size << ", packet : " << message->msgtype();
		//	}
		//	memcpy(buffer, &size, PACKET_HEADER_SIZE);
		//	return message->SerializeToArray(&buffer[PACKET_HEADER_SIZE], size - PACKET_HEADER_SIZE);
		//}

		static std::shared_ptr<char> Deserialize(const char* buffer, const uint16_t size)
		{
			std::shared_ptr<char> message(new char[size]);
			
					
			//memcpy(message.operator=, &buffer[PACKET_HEADER_SIZE], size - PACKET_HEADER_SIZE);
			if (false == message)
			{
				return nullptr;
			}

			return message;
		}
	};

}	// namespace mir3d
