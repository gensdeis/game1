#pragma once

#include "serialize_packer.h"

#ifdef __UNREAL__
#define MEMCPY FMemory::Memcpy
#else
#define MEMCPY std::memcpy
#endif
//

#define SERIALIZE_SIZE_1	1
#define SERIALIZE_SIZE_2	2
#define SERIALIZE_SIZE_4	4
#define SERIALIZE_SIZE_8	8

namespace mir3d
{
	namespace protocol
	{		

		template<int T_SIZE, bool T_FAST = false>
		class SerializeBuffer
		{
		private:
			SerializeBuffer(const SerializeBuffer&) = delete;
			SerializeBuffer& operator=(const SerializeBuffer&) = delete;
			SerializeBuffer(SerializeBuffer&&) = delete;
			SerializeBuffer& operator=(SerializeBuffer&&) = delete;

		public:
			enum { cIsWriter = 1 };

			SerializeBuffer(int maximumSpace = MAX_SOCKET_BUFFER_SIZE)
			{
				_error = false;
				_floating_warning = false;
				_use_size = 0;
				if ((T_FAST))
				{
					_dest_ptr = NULL;
					Prepare(T_SIZE);
				}
				else
				{
					_dest_offset = 0;
				}
			}
			~SerializeBuffer()
			{
			}

			inline void Reset(void)
			{
				_dest_ptr = &_use_buffer[0];
				_error = false;
				_floating_warning = false;
				_use_size = 0;				
				_error_serialize_size = 0;
				_packet_cmd = 0;
			}

			void SetError(const int32_t& size)
			{ 
				if (0 == _error_serialize_size)
					_error_serialize_size = _use_size + size;
				else
					_error_serialize_size += size;

				_error = true; 
			}
			bool IsError(void)						const			{ return _error; }
			void SetFloatingPointWarning(void)						{ _floating_warning = true; }
			bool IsFloatingPointWarning(void)		const			{ return _floating_warning; }
			const uint8_t* GetBufferPointer(void)	const			{ return _use_buffer; }
			uint8_t* GetBufferPointer_Mutable(void)					{ return _use_buffer; }
			int32_t GetErrorSerializeSize(void)						{ return _error_serialize_size; }
			void SetSerializeCommand(const uint16_t& command)		{ _packet_cmd = command; }
			uint16_t GetSerializeCommand(void)						{ return _packet_cmd; }
			int32_t GetBufferLength() const
			{
				if ((T_FAST))
				{
					int32_t nLen = 0;
					if (_dest_ptr != NULL)
					{
						nLen = ((int32_t)(_dest_ptr - _use_buffer));
					}					
					return nLen;
				}
				else
				{					 
					return (int32_t)_use_size;
				}
			}

			int32_t GetRemainingBufferLength(void)	const;  // 버퍼 길이에서 현재 위치를 뺀값 을 반환 얼마나 남았냐?
			int32_t GetBufferPosition(void)			const;  // returns current write-offset within the buffer
			void ResetBuffer(int pos = 0);					// clears the buffer from pos onward (pos is inclusive). 0 clears the entire buffer			

#ifdef _DELETE
			void SetExternalBuffer(const uint8_t * externalBuffer, int size)
			{
				std::memcpy(_dest_ptr, externalBuffer, size);
				_dest_ptr += size;
				_use_size += 1;
			}
#endif

			template<typename T> inline void Serialize1(const T* pValue)
			{
				if ((T_FAST))
				{
#ifdef _USE_PACKET_SERIALIZE_CHECK
					if (false == IsError() && nullptr != _dest_ptr)
					{
						if (MAX_SOCKET_BUFFER_SIZE < (_use_size + SERIALIZE_SIZE_1))
						{
							SetError(SERIALIZE_SIZE_1);
						}
						else
						{
							_dest_ptr += Pack8(_dest_ptr, *pValue);
							_use_size += SERIALIZE_SIZE_1;
						}
					}
#else
					if (_dest_ptr != NULL)
					{
						//assert(_dest_ptr != NULL);      // must call Prepare on fast-buffer before using it
						_dest_ptr += Pack8(_dest_ptr, *pValue);
						_use_size += SERIALIZE_SIZE_1;
					}
#endif			
				}
				else
				{
					uint8_t buf[SERIALIZE_SIZE_1];
					Pack8(buf, *pValue);
					InternalWrite(buf, SERIALIZE_SIZE_1);
				}
			}

			template<typename T> inline void Serialize2(const T * pValue)
			{
				if ((T_FAST))
				{
#ifdef _USE_PACKET_SERIALIZE_CHECK
					if (false == IsError() && nullptr != _dest_ptr)
					{
						if (MAX_SOCKET_BUFFER_SIZE < (_use_size + SERIALIZE_SIZE_2))
						{
							SetError(SERIALIZE_SIZE_2);
						}
						else
						{
							_dest_ptr += Pack16(_dest_ptr, *pValue);
							_use_size += SERIALIZE_SIZE_2;
						}
					}
#else
					if (_dest_ptr != NULL)
					{
						//assert(_dest_ptr != NULL);      // must call Prepare on fast-buffer before using it
						_dest_ptr += Pack16(_dest_ptr, *pValue);
						_use_size += SERIALIZE_SIZE_2;
					}
#endif
				}
				else
				{
					uint8_t buf[SERIALIZE_SIZE_2];
					Pack16(buf, *pValue);
					InternalWrite(buf, SERIALIZE_SIZE_2);
				}
			}

			template<typename T> inline void Serialize4(const T * pValue)
			{
				if ((T_FAST))
				{
#ifdef _USE_PACKET_SERIALIZE_CHECK
					if (false == IsError() && nullptr != _dest_ptr)
					{
						if (MAX_SOCKET_BUFFER_SIZE < (_use_size + SERIALIZE_SIZE_4))
						{
							SetError(SERIALIZE_SIZE_4);
						}
						else
						{
							_dest_ptr += Pack32(_dest_ptr, *pValue);
							_use_size += SERIALIZE_SIZE_4;
						}
					}
#else
					if (_dest_ptr != NULL)
					{
						//assert(_dest_ptr != NULL);      // must call Prepare on fast-buffer before using it
						_dest_ptr += Pack32(_dest_ptr, *pValue);
						_use_size += SERIALIZE_SIZE_4;
					}
#endif
				}
				else
				{
					uint8_t buf[SERIALIZE_SIZE_4];
					Pack32(buf, *pValue);
					InternalWrite(buf, SERIALIZE_SIZE_4);
				}
			}

			template<typename T> inline void Serialize8(const T * pValue)
			{
				if ((T_FAST))
				{
#ifdef _USE_PACKET_SERIALIZE_CHECK
					if (false == IsError() && nullptr != _dest_ptr)
					{
						if (MAX_SOCKET_BUFFER_SIZE < (_use_size + SERIALIZE_SIZE_8))
						{
							SetError(SERIALIZE_SIZE_8);
						}
						else
						{
							_dest_ptr += Pack64(_dest_ptr, *pValue);
							_use_size += SERIALIZE_SIZE_8;
						}
					}
#else
					if (_dest_ptr != NULL)
					{
						//assert(_dest_ptr != NULL);      // must call Prepare on fast-buffer before using it
						_dest_ptr += Pack64(_dest_ptr, *pValue);
						_use_size += SERIALIZE_SIZE_8;
					}
#endif
				}
				else
				{
					uint8_t buf[SERIALIZE_SIZE_8];
					Pack64(buf, *pValue);
					InternalWrite(buf, SERIALIZE_SIZE_8);
				}
			}
			inline void SerializeBool(const bool* pValue)
			{
				if ((T_FAST))
				{
#ifdef _USE_PACKET_SERIALIZE_CHECK
					if (false == IsError() && nullptr != _dest_ptr)
					{
						if (MAX_SOCKET_BUFFER_SIZE < (_use_size + SERIALIZE_SIZE_1))
						{
							SetError(SERIALIZE_SIZE_1);
						}
						else
						{
							_dest_ptr += PackBool(_dest_ptr, *pValue);
							_use_size += SERIALIZE_SIZE_1;
						}
					}
#else
					if (_dest_ptr != NULL)
					{
						//assert(_dest_ptr != NULL);      // must call Prepare on fast-buffer before using it
						_dest_ptr += PackBool(_dest_ptr, *pValue);
						_use_size += SERIALIZE_SIZE_1;
					}
#endif
				}
				else
				{
					uint8_t buf[SERIALIZE_SIZE_1];
					PackBool(buf, *pValue);
					InternalWrite(buf, SERIALIZE_SIZE_1);
				}
			}

			void SerializeString(char * pString, uint16_t maxBufferLen)                     // reads/writes 4-uint8_t-length and string
			{				
#ifdef _USE_PACKET_SERIALIZE_CHECK
				if (false == IsError() && nullptr != _dest_ptr)
				{
					if (MAX_SOCKET_BUFFER_SIZE < (_use_size + maxBufferLen))
					{
						SetError(maxBufferLen);
					}
					else
					{
						Serialize2(&maxBufferLen);
						InternalWrite((const uint8_t*)pString, maxBufferLen);
					}
				}
#else
				Serialize2(&maxBufferLen);
				InternalWrite((const uint8_t*)pString, maxBufferLen);
#endif
			}
			inline void SerializeFloat(const float* pValue)
			{
				if ((T_FAST))
				{
#ifdef _USE_PACKET_SERIALIZE_CHECK
					if (false == IsError() && nullptr != _dest_ptr)
					{
						if (MAX_SOCKET_BUFFER_SIZE < (_use_size + SERIALIZE_SIZE_4))
						{
							SetError(SERIALIZE_SIZE_4);
						}
						else
						{
							_dest_ptr += PackFloat(_dest_ptr, *pValue);
							_use_size += SERIALIZE_SIZE_4;
						}
					}
#else
					if (_dest_ptr != NULL)
					{
						//assert(_dest_ptr != NULL);     //버퍼 준비를 해야함
						_dest_ptr += PackFloat(_dest_ptr, *pValue);
						_use_size += SERIALIZE_SIZE_4;
					}
#endif
				}
				else
				{
					uint8_t buf[SERIALIZE_SIZE_4];
					PackFloat(buf, *pValue);
					InternalWrite(buf, SERIALIZE_SIZE_4);
				}
			}
			inline void SerializeDouble(const double* pValue)
			{
				if ((T_FAST))
				{
#ifdef _USE_PACKET_SERIALIZE_CHECK
					if (false == IsError() && nullptr != _dest_ptr)
					{
						if (MAX_SOCKET_BUFFER_SIZE < (_use_size + SERIALIZE_SIZE_8))
						{
							SetError(SERIALIZE_SIZE_8);
						}
						else
						{
							_dest_ptr += PackDouble(_dest_ptr, *pValue);
							_use_size += SERIALIZE_SIZE_8;
						}
					}
#else
					if (_dest_ptr != NULL)
					{
						//assert(_dest_ptr != NULL);
						_dest_ptr += PackDouble(_dest_ptr, *pValue);
						_use_size += SERIALIZE_SIZE_8;
					}
#endif
				}
				else
				{
					uint8_t buf[SERIALIZE_SIZE_8];
					PackDouble(buf, *pValue);
					InternalWrite(buf, SERIALIZE_SIZE_8);
				}
			}

#ifdef __UNREAL__
			void SerializeString(const std::string * pString)
			{

				//int length = pString->Len();
				//Serialize4(&length);

				FTCHARToUTF8 convert(pString->GetCharArray().GetData(), pString->Len());
				uint16_t length = (uint16_t)convert.Length();
				Serialize2(&length);
				InternalWrite((const uint8_t*)convert.Get(), length);
				//InternalWrite((const uint8_t*)FTCHARToUTF8(**pString, length).Get(), length);
				//InternalWrite((const uint8_t*)TCHAR_TO_UTF8(**pString),length);
			}
#else
			void SerializeString(const std::string * pString)
			{				
#ifdef _USE_PACKET_SERIALIZE_CHECK
				if (false == IsError() && nullptr != _dest_ptr)
				{
					uint16_t length = (uint16_t)pString->length();
					if (MAX_SOCKET_BUFFER_SIZE < (_use_size + length))
					{
						SetError(length);
					}
					else
					{
						Serialize2(&length);
						InternalWrite((const uint8_t*)pString->c_str(), length);
					}
				}
#else
				uint16_t length = (uint16_t)pString->length();
				Serialize2(&length);
				InternalWrite((const uint8_t*)pString->c_str(), length);
#endif	// _USE_PACKET_SERIALIZE_CHECK
			}

#endif	// __UNREAL__
#if !defined(_MSC_VER) || defined(_NATIVE_WCHAR_T_DEFINED)   
			void SerializeString(const std::wstring * pString)
			{
				uint16_t length = (uint16_t)pString->length();
				Serialize2(&length);

				for (int i = 0; i < length; i++)
				{
					wchar_t v = pString->at(i);
					Serialize2(&v);
				}
			}
#endif
			// void SerializeBinaryStatic(const uint8_t* data, const int * dataLen)
			void SerializeBinaryStatic(const uint8_t* data, const int32_t& dataLen)
			{
#ifdef _USE_PACKET_SERIALIZE_CHECK
				if (false == IsError() && nullptr != _dest_ptr)
				{
					if (MAX_SOCKET_BUFFER_SIZE < (_use_size + dataLen))
					{
						SetError(dataLen);
					}
					else
					{
						Serialize2(dataLen);
						InternalWrite(data, dataLen);
					}
				}
#else
				Serialize2(dataLen);
				InternalWrite(data, dataLen);
#endif
			}

			void SerializeRaw(const uint8_t* rawData, int rawLen)                              // reads/writes binary-data length 읽지않음
			{
#ifdef _USE_PACKET_SERIALIZE_CHECK
				if (false == IsError())
				{
					if (MAX_SOCKET_BUFFER_SIZE < (_use_size + rawLen))
					{
						SetError(rawLen);
					}
					else
					{
						InternalWrite(rawData, rawLen);
					}
			}
#else
				InternalWrite(rawData, rawLen);
#endif
			}

			inline void SerializeEnd(const int16_t size)  
			{
				if ((T_FAST))
				{
					if (_dest_ptr != NULL)
					{
						std::memcpy(&_use_buffer[0], &size, sizeof(int16_t));
					}
				}
			
			}
			// T_FAST 가 참일때 사용 되고 버퍼를 count 만큼 할당
			//count 실제 serialize 된 것보다 크고 GetBufferLehgth() 를 통해 실제 size 를 가져옴
			//bool Prepare(int count);                    // prepares
			bool Prepare(int count)
			{
				if (count > MAX_SOCKET_BUFFER_SIZE)
				{
					return false;
				}

				if ((T_FAST))
				{
					if (nullptr == _dest_ptr)
					{
						_dest_ptr = _use_buffer;
					}
					else
					{
						return false;
					}
				}
				else
				{
					memset(_use_buffer, 0, count);
				}
				return true;
			}

			inline void InternalWrite(const uint8_t * data, const int32_t& dataLen)
			{
#ifdef __UNREAL__
				if ((T_FAST))
				{
					MEMCPY(_dest_ptr, data, dataLen);
					_dest_ptr += dataLen;
					_use_size += dataLen;
				}
				else
				{

					int len = FMath::Min((int)(_maximum_space - _use_size), dataLen);
					MEMCPY(&_use_buffer[_dest_offset], data, len);
					_dest_offset += len;
				}
#else
				if ((T_FAST))
				{
#ifdef _USE_PACKET_SERIALIZE_CHECK
					if (false == IsError())
					{
						if (MAX_SOCKET_BUFFER_SIZE < (_use_size + dataLen))
						{
							SetError(dataLen);
						}
						else
						{
							MEMCPY(_dest_ptr, data, dataLen);
							_dest_ptr += dataLen;
							_use_size += dataLen;
						}
					}
#else
					MEMCPY(_dest_ptr, data, dataLen);
					_dest_ptr += dataLen;
					_use_size += dataLen;
#endif
				}
				else
				{
					int len = std::min((int)(MAX_SOCKET_BUFFER_SIZE - _use_size), dataLen);
					std::copy(data, data + len, &_use_buffer[0] + _dest_offset);
					_dest_offset += len;
				}
#endif
			}
			
		protected:
			uint8_t		_use_buffer[T_SIZE] = { 0 };
			bool		_error{};
			bool		_floating_warning{};
			int32_t		_use_size{};
			int32_t		_error_serialize_size{};			
			uint16_t	_packet_cmd;
			union
			{
				uint8_t*	_dest_ptr;
				int32_t		_dest_offset;
			};
		};

		class UnSerializeBuffer
		{
		private:
			UnSerializeBuffer(const UnSerializeBuffer&) = delete;
			UnSerializeBuffer& operator=(const UnSerializeBuffer&) = delete;
			UnSerializeBuffer(UnSerializeBuffer&&) = delete;
			UnSerializeBuffer& operator=(UnSerializeBuffer&&) = delete;
			// UTIL_DECLARE_NOCOPY(UnSerializeBuffer);

		public:
			enum { cIsWriter = 0 };

			UnSerializeBuffer(const uint8_t* pBuffer = NULL, int len = 0);
			~UnSerializeBuffer();

			const uint8_t* GetBufferPointer() const;
			int GetBufferLength() const;
			int GetBufferPosition() const;

			int GetRemainingBufferLength() const;
			void ResetBuffer(int pos = 0);                                         // starts the buffer over again at pos

			void SetBuffer(const uint8_t* pBuffer, int len);                    // assigns it a new buffer and resets to beginning
			void ClearBuffer();														// clears the assigned buffer

			template<typename T>inline void Serialize1(T * pValue)
			{
				if (_buffer_position + 1 > _buffer_end)
				{
					//assert(0);
					*pValue = (T)0;
					SetError();
					return;
				}
				_buffer_position += Unpack8(_buffer_position, pValue);
			}

			template<typename T>inline void Serialize2(T * pValue)
			{
				if (_buffer_position + 2 > _buffer_end)
				{
					//assert(0);
					*pValue = (T)0;
					SetError();
					return;
				}
				_buffer_position += Unpack16(_buffer_position, pValue);
			}

			template<typename T>inline void Serialize4(T * pValue)
			{
				if (_buffer_position + 4 > _buffer_end)
				{
					//assert(0);
					*pValue = (T)0;
					SetError();
					return;
				}
				_buffer_position += Unpack32(_buffer_position, pValue);
			}

			template<typename T>inline void Serialize8(T * pValue)
			{
				if (_buffer_position + 8 > _buffer_end)
				{
					//assert(0);
					*pValue = (T)0;
					SetError();
					return;
				}
				_buffer_position += Unpack64(_buffer_position, pValue);
			}
			void SerializeBool(bool* pValue);                                      // reads/writes in 1 uint8_t always
			void SerializeFloat(float* pValue);                                    // reads/writes in 4 unsigned chars always
			void SerializeDouble(double* pValue);                                  // reads/writes in 8 unsigned chars always
			
			void SerializeString(char* pString, uint16_t maxBufferLen);
#ifdef __UNREAL__
			void SerializeString(std::string* pString);								// reads/writes 4-uint8_t-length and string
#else
			void SerializeString(std::string* pString);								// reads/writes 4-uint8_t-length and string
#endif
			
#if !defined(_MSC_VER) || defined(_NATIVE_WCHAR_T_DEFINED)   
			void SerializeString(std::wstring* pString);							// reads/writes 4-uint8_t-length and string
#endif
			void SerializeBinaryStatic(uint8_t* data, int * dataLen);				// reads/writes 4-uint8_t-length and binary-data. See implementation for more details.
		

			void SerializeRaw(uint8_t* rawData, int rawLen);						// reads/writes binary-data only of length specified

			// 하나씩 꺼내오는 데 사용 꺼내면 없어짐
			template <typename T> void Peek1(T* pValue);
			template <typename T> void Peek2(T* pValue);
			template <typename T> void Peek4(T* pValue);
			template <typename T> void Peek8(T* pValue);
			void PeekBool(bool* pValue);
			void PeekFloat(float* pValue);
			void PeekDouble(double* pValue);
			void PeekString( char* pString, uint16_t len);
			inline void SerializeEnd(const int16_t size) {}
#ifdef __UNREAL__
			void PeekString(std::string* pString);
#else
			void PeekString(std::string* pString);
#endif

#if !defined(_MSC_VER) || defined(_NATIVE_WCHAR_T_DEFINED)   
			void PeekString(std::wstring* pString);
#endif
			void PeekRaw(uint8_t* pBytes, int count);

			void SetError() { _error = true; _buffer_position = _buffer_end; }
			bool IsError() const { return _error; }
			void SetFloatingPointWarning() { _floating_warning = true; }
			bool IsFloatingPointWarning() const { return _floating_warning; }
			
			void SetSerializeCommand(uint16_t command)	{ _packet_cmd = command; }
			uint16_t GetSerializeCommand(void)			{ return _packet_cmd; }

		protected:
			const uint8_t*	_buffer;
			int32_t			_buffer_length{};
			const uint8_t*	_buffer_position;
			const uint8_t*	_buffer_end;
			bool			_error{};
			bool			_floating_warning;
			uint16_t		_packet_cmd{};
		};

		// convenience typedefs
		typedef SerializeBuffer<MAX_SOCKET_BUFFER_SIZE, true> SerializeBufferNative;
		typedef UnSerializeBuffer UnSerializeBufferNative;

		template<typename T>inline bool UnSerializeNative(const uint8_t * data, int dataLen, T * obj)
		{
			UnSerializeBuffer buffer(data, dataLen);
			SerializeType(&buffer, obj);
			return(!buffer.IsError());
		}

	}  // namespace
}
