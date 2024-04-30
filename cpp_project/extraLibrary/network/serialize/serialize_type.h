#pragma once

namespace mir3d
{
	namespace protocol
	{

		template<typename T_BUFFER> void SerializeType(T_BUFFER* buffer, bool* obj)
		{
			buffer->SerializeBool(obj);
		}

		template<typename T_BUFFER> void SerializeType(T_BUFFER* buffer, float* obj)
		{
			buffer->SerializeFloat(obj);
		}

		template<typename T_BUFFER> void SerializeType(T_BUFFER* buffer, double* obj)
		{
			buffer->SerializeDouble(obj);
		}

		template<typename T_BUFFER> void SerializeType(T_BUFFER* buffer, char* obj)
		{
			buffer->Serialize1(obj);
		}


#if !defined(_MSC_VER) || defined(_NATIVE_WCHAR_T_DEFINED)     
		template<typename T_BUFFER> void SerializeType(T_BUFFER * buffer, wchar_t* obj)
		{
			buffer->Serialize2(obj);
		}
#endif

		template<typename T_BUFFER> void SerializeType(T_BUFFER* buffer, int8_t* obj)
		{
			buffer->Serialize1(obj);
			
		}

		template<typename T_BUFFER> void SerializeType(T_BUFFER* buffer, uint8_t* obj)
		{
			buffer->Serialize1(obj);
		}

		template<typename T_BUFFER> void SerializeType(T_BUFFER* buffer, int16_t* obj)
		{
			buffer->Serialize2(obj);
		}

		template<typename T_BUFFER> void SerializeType(T_BUFFER* buffer, uint16_t* obj)
		{
			buffer->Serialize2(obj);
		}

		template<typename T_BUFFER> void SerializeType(T_BUFFER* buffer, int32_t* obj)
		{

			buffer->Serialize4(obj);

		}

		template<typename T_BUFFER> void SerializeType(T_BUFFER* buffer, uint32_t* obj)
		{
			buffer->Serialize4(obj);
		}

		template<typename T_BUFFER> void SerializeType(T_BUFFER* buffer, int64_t* obj)
		{
			buffer->Serialize8(obj);
		}

		template<typename T_BUFFER> void SerializeType(T_BUFFER* buffer, uint64_t* obj)
		{

			buffer->Serialize8(obj);
		}
		template<typename T_BUFFER> void SerializeVector(T_BUFFER *buffer, uint8_t *obj, uint16_t len)
		{			
			buffer->SerializeRaw(obj, len);
			
		}

		template<typename T_BUFFER, typename T> void SerializeType(T_BUFFER *buffer, T *obj)
		{
#ifdef __UNREAL__
			obj->Serialize_Unreal(buffer);
#else
			if (buffer)
			{
				obj->Serialize(buffer);
				obj->SerializeEnd(buffer,(int16_t)buffer->GetBufferLength());
				//obj->SerializeEnd(buffer, buffer->GetBufferLength());
			}
#endif
		}

		template<typename T_BUFFER, typename T> void SerializeType(T_BUFFER *buffer, const T *obj)
		{
			SerializeType(buffer, const_cast<T *>(obj));
		}

		template<typename T_BUFFER, typename T> void SerializeType(T_BUFFER *buffer, T **ppObj)
		{

			if ((T_BUFFER::cIsWriter))
			{
				
				SerializeType(buffer, *ppObj);
				
			}
			else
			{
			
#ifdef __UNREAL__
					*ppObj = NewObject<T>();
#else
					if(*ppObj == nullptr)
						*ppObj = new T;
#endif
					SerializeType(buffer, *ppObj);
				

			}
		}

		template<typename T_BUFFER, typename T> void SerializeType(T_BUFFER *buffer, const T **ppObj)
		{

			SerializeType(buffer, const_cast<T **>(ppObj));
		}

		//template<typename T_BUFFER, typename T> void SerializeEnd(T_BUFFER* buffer, const int16_t size)
		//{
		//	//memcpy(&buffer[0], &size, sizeof(int16_t));
		//	buffer->SerializeEnd(size);

		//}
#ifdef __UNREAL__

		template<typename T_BUFFER> void SerializeType(T_BUFFER *buffer, FString *obj)
		{
			buffer->SerializeString(obj);
		}

		template<typename T_BUFFER, typename T> void SerializeType(T_BUFFER *buffer, TArray<T *> *container)
		{
			if ((T_BUFFER::cIsWriter))
			{
				uint16_t count = container->Num();
				SerializeType(buffer, &count);

				for (auto itr = container->CreateConstIterator(); itr; ++itr)
				{
					SerializeType(buffer, (*itr));
				}
			}
			else
			{
				container->Empty();
				uint16_t count = 0;
				SerializeType(buffer, &count);

				for (int i = 0; i < count && !buffer->IsError(); i++)
				{
					T *cur = NewObject<T>();
					SerializeType(buffer, cur);

					container->Emplace(cur);
				}
			}
		}
		template<typename T_BUFFER, typename T> void SerializeType(T_BUFFER *buffer, TArray<T> *container)
		{
			if ((T_BUFFER::cIsWriter))
			{
				uint16_t count = container->Num();
				SerializeType(buffer, &count);

				for (auto itr = container->CreateConstIterator(); itr; ++itr)
				{
					SerializeType(buffer, &(*itr));
				}
			}
			else
			{
				container->Empty();
				uint16_t count = 0;
				SerializeType(buffer, &count);

				for (int i = 0; i < count && !buffer->IsError(); i++)
				{
					T cur;
					SerializeType(buffer, &cur);

					container->Emplace(cur);
				}
			}
		}
#else
	
		
		template<typename T_BUFFER> void SerializeType(T_BUFFER *buffer, std::string *obj)
		{
			buffer->SerializeString(obj);
		}
				
		template<typename T_BUFFER> void SerializeType(T_BUFFER *buffer, std::wstring *obj)
		{
			buffer->SerializeString(obj);
		}

		template<typename T_BUFFER, typename T> void SerializeType(T_BUFFER *buffer, std::vector<T *> *container)
		{
			if ((T_BUFFER::cIsWriter))
			{
				uint16_t count = (uint16_t)container->size();
				SerializeType(buffer, &count);


				for (int i= 0 ; i < container->size() && !buffer->IsError(); i++)
				{
					SerializeType(buffer, (*container)[i]);
				}
			}
			else
			{
				container->clear();
				uint16_t count = 0;
				SerializeType(buffer, &count);

				for (int i = 0; i < count && !buffer->IsError(); i++)
				{
					T * cur = new T;
					SerializeType(buffer, cur);

					container->push_back(cur);
				}
			}
		}

		template<typename T_BUFFER, typename T> void SerializeType(T_BUFFER *buffer, std::vector<T> *container)
		{
			if ((T_BUFFER::cIsWriter))
			{
				int size = sizeof(T);
				if (sizeof(uint8_t) == size)
				{
					uint16_t count = (uint16_t)container->size();
					SerializeType(buffer, &count);
					if (count > 0)
					{
						SerializeVector(buffer, (uint8_t *)&(*container)[0], count);
					}
					
				}
				else
				{
					uint16_t count = (uint16_t)container->size();
					SerializeType(buffer, &count);

					for (int i = 0; i < (int)container->size() && !buffer->IsError(); i++)
					{
						SerializeType(buffer, &(*container)[i]);
					}
				}
			}
			else
			{
				int size = sizeof(T);
				// enum vector
				if (sizeof(uint8_t) == size)
				{
					uint16_t count = 0;
				
					SerializeType(buffer, &count);
					if (count > 0)
					{
						container->resize(count);
						SerializeVector(buffer, (uint8_t *)&(*container)[0], count);
					}
				}
				else
				{
					// container->clear();
					uint16_t count = 0;
					SerializeType(buffer, &count);
					
					for (int i = 0; i < count && !buffer->IsError(); i++)
					{
						T  cur;
						SerializeType(buffer, &cur);

						// container->push_back(cur);
						container->emplace_back(cur);
					}
				}
			}
		}

		template<typename T> void AssignVector(std::vector<T>* source, std::vector<T> *target)
		{
			target = source;
		}
#endif

		template <typename T_BUFFER, typename T, int size = sizeof(T)>
		class cSerializeEnum
		{
			//빈 클래스
		};
		template <typename T_BUFFER, typename T>
		class cSerializeEnum<T_BUFFER, T, 1>
		{
		public:
			static void SerializeEnum(T_BUFFER *buffer, T * value) { buffer->Serialize1(value); }
			
		};
		template<typename T_BUFFER, typename T>
		class cSerializeEnum<T_BUFFER, T, 2>
		{
		public:
			static void SerializeEnum(T_BUFFER *buffer, T * value) { buffer->Serialize2(value); }

		};
		template<typename T_BUFFER, typename T>
		class cSerializeEnum<T_BUFFER, T, 4>
		{
		public:
			static void SerializeEnum(T_BUFFER *buffer, T * value) { buffer->Serialize4(value); }

		};
		template<typename T_BUFFER, typename T>
		class cSerializeEnum<T_BUFFER, T, 8>
		{
		public:
			static void SerializeEnum(T_BUFFER *buffer, T * value) { buffer->Serialize8(value); }

		};
		template<typename T_BUFFER, typename T> void SerializeEnum(T_BUFFER *buffer, T *value)
		{
			cSerializeEnum<T_BUFFER, T>::SerializeEnum(buffer, value);
		}
	}
}