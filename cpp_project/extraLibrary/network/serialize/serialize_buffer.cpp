#include "stdafx_net.h"
#include "serialize_buffer.h"


/////////////////////////////////////////////////////////////////
// SerializeBuffer implementation
/////////////////////////////////////////////////////////////////

namespace mir3d
{
	namespace protocol
	{
		template<int T_SIZE, bool T_FAST> int SerializeBuffer<T_SIZE, T_FAST>::GetBufferPosition() const
		{
			return T_FAST ? (int)(_dest_ptr) : _dest_offset;
		}
		template<int T_SIZE, bool T_FAST> int SerializeBuffer<T_SIZE, T_FAST>::GetRemainingBufferLength() const
		{
			return GetBufferLength() - GetBufferPosition();
		}
		template<int T_SIZE, bool T_FAST> void SerializeBuffer<T_SIZE, T_FAST>::ResetBuffer(int pos /*= 0*/)
		{
			if (pos == 0)
			{
				//전체를 지움
				
				if ((T_FAST))
				{
					_dest_ptr = NULL;
				}
				else
				{
					_dest_offset = 0;
				}
			}
			else
			{
				

				if ((T_FAST))
				{
					//memset(m_destPtr, 0, T_SIZE);
					_dest_ptr = &(_use_buffer + pos);
				}
				else
				{
					_dest_offset = pos;
				}
			}
		}
			   			
		/////////////////////////////////////////////////////////////////
		// UnSerializeBuffer implementation
		/////////////////////////////////////////////////////////////////
		UnSerializeBuffer::UnSerializeBuffer(const uint8_t* pBuffer, int len)
		{
			SetBuffer(pBuffer, len);
		}
		UnSerializeBuffer::~UnSerializeBuffer()
		{
		}
		void UnSerializeBuffer::ResetBuffer(int pos /*= 0*/)
		{
			//assert(pos >= 0 && pos <= _buffer_length);
			if (pos >= 0 && pos <= _buffer_length)
				_buffer_position = _buffer + pos;
			
		}

		void UnSerializeBuffer::SetBuffer(const uint8_t* pBuffer, int len)
		{
			_buffer = pBuffer;
			_buffer_length = len;
			_buffer_position = _buffer;
			_buffer_end = _buffer + _buffer_length;
			_error = false;
			_floating_warning = false;
		}

		void UnSerializeBuffer::ClearBuffer()
		{
			_buffer = NULL;
			_buffer_length = 0;
			_buffer_position = 0;
			_buffer_end = NULL;
			_error = false;
			_floating_warning = false;
		}


		const uint8_t* UnSerializeBuffer::GetBufferPointer() const
		{
			return _buffer;
		}

		int UnSerializeBuffer::GetBufferLength() const
		{
			return _buffer_length;
		}

		int UnSerializeBuffer::GetBufferPosition() const
		{
			return (int)(_buffer_position - _buffer);
		}

		int UnSerializeBuffer::GetRemainingBufferLength() const
		{
			return (int)(_buffer_end - _buffer_position);
		}

	
		void UnSerializeBuffer::SerializeBool(bool* pValue)
		{
			if (_buffer_position + 1 > _buffer_end)
			{
				//assert(0);
				*pValue = false;
				SetError();
				return;
			}
			_buffer_position += UnpackBool(_buffer_position, pValue);
		}

		void UnSerializeBuffer::SerializeFloat(float* pValue)
		{
			if (_buffer_position + 4 > _buffer_end)
			{
				//assert(0);
				*pValue = 0.0f;
				SetError();
				return;
			}
			_buffer_position += UnpackFloat(_buffer_position, pValue);
			// C++11 NaN
			if (std::isnan(*pValue))
			{
				SetFloatingPointWarning();
				return;
			}
		}

		void UnSerializeBuffer::SerializeDouble(double* pValue)
		{
			if (_buffer_position + 8 > _buffer_end)
			{
				//assert(0);
				*pValue = 0.0;
				SetError();
				return;
			}
			_buffer_position += UnpackDouble(_buffer_position, pValue);
			if (std::isnan(*pValue))        // deserializing NAN is an error condition (infinity is ok for now)
			{
				SetFloatingPointWarning();
				return;
			}
		}

		void UnSerializeBuffer::SerializeString(char* pString, uint16_t maxBufferLen)
		{
			uint16_t len = 0;
			Serialize2(&len);
			if ((len < 0) || (len > (int)(_buffer_end - _buffer_position)))
			{
				//assert(0);
				SetError();
				*pString = 0;
				return;
			}

			if (maxBufferLen < len + 1)
			{
				// not enough space in buffer, so read all that we can and skip the rest
				MEMCPY((uint8_t*)pString, _buffer_position, maxBufferLen - 1);
				pString[maxBufferLen - 1] = 0;      // zero terminate
			}
			else
			{
				// space in buffer, so read specified amount
				MEMCPY((uint8_t*)pString, _buffer_position, len);
				pString[len] = 0;
			}
			_buffer_position += len;
		}

#ifdef __UNREAL__
		void UnSerializeBuffer::SerializeString(std::string * pString)
		{
			uint16_t len;
			Serialize2(&len);
			if ((len < 0) || (len > (int)(_buffer_end - _buffer_position)))
			{
				//assert(0);
				SetError();
				return;
			}

			FUTF8ToTCHAR convert((const char*)_buffer_position, len);
			pString->Append(convert.Get(), convert.Length());
			
			_buffer_position += len;
		}
#else
		void UnSerializeBuffer::SerializeString(std::string * pString)
		{
			uint16_t len = 0;
			Serialize2(&len);
			if ((len < 0) || (len > (int)(_buffer_end - _buffer_position)))
			{
				//assert(0);
				SetError();
				return;
			}

			if (0 < len)
				pString->assign((char*)_buffer_position, (size_t)len);

			_buffer_position += len;
		}
#endif
#if !defined(_MSC_VER) || defined(_NATIVE_WCHAR_T_DEFINED)   
		void UnSerializeBuffer::SerializeString(std::wstring * pString)
		{
			uint16_t len = 0;
			Serialize2(&len);
			if ((len < 0) || (len > (int)(_buffer_end - _buffer_position)))
			{
				//assert(0);
				SetError();
				len = (int)(_buffer_end - _buffer_position);

				return;
			}

			pString->reserve(len);
			wchar_t* pRawString = (wchar_t*)pString->data();
			for (int i = 0; i < len; i++)
			{
				Serialize2(&pRawString[i]);
			}

			pRawString[len] = 0;

		}
#endif
		//버퍼에서 data 로 복사
		void UnSerializeBuffer::SerializeBinaryStatic(uint8_t* data, int * dataLen)
		{
			int len;
			Serialize4(&len);

			
			if ((len < 0) || (len > (int)(_buffer_end - _buffer_position)))
			{
				//assert(0);
				SetError();
				return;
			}

			//if (dataMax < len)
			//{
			//	// not enough space in buffer, so read all that we can and skip the rest
			//	MEMCPY(data, _buffer_position, dataMax);
			//	*dataLen = dataMax;
			//}
			//else
			{
				// space in buffer, so read specified amount
				MEMCPY(data, _buffer_position, len);
				*dataLen = len;
			}
			_buffer_position += len;
		}


		//void UnSerializeBuffer::SerializeBinaryReference(const uint8_t * *ppData, int* dataLen)
		//{
		//	int len;
		//	Serialize4(&len);
		//	if ((len < 0) || (len > (int)(_buffer_end - _buffer_position)))
		//	{
		//		//assert(0);
		//		//assert(0);
		//		*ppData = NULL;
		//		*dataLen = 0;
		//		SetError();
		//		return;
		//	}

		//	*ppData = _buffer_position;
		//	*dataLen = len;
		//	_buffer_position += len;
		//}

		void UnSerializeBuffer::SerializeRaw(uint8_t* rawData, int rawLen)
		{
			if (rawLen < 0 || _buffer_position + rawLen > _buffer_end)
			{
				//assert(0);
				SetError();
				return;
			}
			MEMCPY(rawData, _buffer_position, rawLen);
			_buffer_position += rawLen;
		}

		template <typename T> void UnSerializeBuffer::Peek1(T * pValue)
		{
			const uint8_t* hold = _buffer_position;
			Serialize1(pValue);
			_buffer_position = hold;
		}

		template <typename T> void UnSerializeBuffer::Peek2(T * pValue)
		{
			const uint8_t* hold = _buffer_position;
			Serialize2(pValue);
			_buffer_position = hold;
		}

		template <typename T> void UnSerializeBuffer::Peek4(T * pValue)
		{
			const uint8_t* hold = _buffer_position;
			Serialize4(pValue);
			_buffer_position = hold;
		}

		template <typename T> void UnSerializeBuffer::Peek8(T * pValue)
		{
			const uint8_t* hold = _buffer_position;
			Serialize8(pValue);
			_buffer_position = hold;
		}

		void UnSerializeBuffer::PeekBool(bool* pValue)
		{
			const uint8_t* hold = _buffer_position;
			SerializeBool(pValue);
			_buffer_position = hold;
		}

		void UnSerializeBuffer::PeekFloat(float* pValue)
		{
			const uint8_t* hold = _buffer_position;
			SerializeFloat(pValue);
			_buffer_position = hold;
		}

		void UnSerializeBuffer::PeekDouble(double* pValue)
		{
			const uint8_t* hold = _buffer_position;
			SerializeDouble(pValue);
			_buffer_position = hold;
		}

		void UnSerializeBuffer::PeekString(char* pString, uint16_t len)
		{
			const uint8_t* hold = _buffer_position;
			SerializeString(pString, len);
			_buffer_position = hold;
		}

#ifdef __UNREAL__
		void UnSerializeBuffer::PeekString(std::string * pString)
		{
			const unsigned char* hold = _buffer_position;
			SerializeString(pString);
			_buffer_position = hold;
		}
#else
		void UnSerializeBuffer::PeekString(std::string * pString)
		{
			const uint8_t* hold = _buffer_position;
			SerializeString(pString);
			_buffer_position = hold;
		}
#endif

#if !defined(_MSC_VER) || defined(_NATIVE_WCHAR_T_DEFINED)   
		void UnSerializeBuffer::PeekString(std::wstring * pString)
		{
			const uint8_t* hold = _buffer_position;
			SerializeString(pString);
			_buffer_position = hold;
		}
#endif

		void UnSerializeBuffer::PeekRaw(uint8_t* pBytes, int count)
		{
			const uint8_t* hold = _buffer_position;
			SerializeRaw(pBytes, count);
			_buffer_position = hold;
		}

		/*int UnSerializeBuffer::PeekBinaryLength()
		{
			int temp;
			const uint8_t* hold = _buffer_position;
			Serialize4(&temp);
			_buffer_position = hold;
			return temp;
		}*/

		/*int UnSerializeBuffer::PeekStringLength()
		{
			int temp;
			const uint8_t* hold = _buffer_position;
			Serialize4(&temp);
			_buffer_position = hold;
			return temp;
		}*/
	}
}