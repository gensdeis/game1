#pragma once

#ifdef _WINDOWS

#include <Windows.h>
#include <DbgHelp.h>
#include <string>
#pragma comment(lib, "dbghelp.lib")


namespace mir3d
{
	class CallStack final
	{
	public:
		static const size_t kMaxStackDepth = 16U;

	public:
		explicit CallStack()
		{
			count_ = CaptureStackBackTrace(0, kMaxStackDepth, addresses_, &hash_);
		}

		void* operator[] (const size_t index)const { return addresses_[index]; }

		ULONG GetHash()const { return hash_; }
		size_t GetCount()const { return count_; }

	private:
		void* addresses_[kMaxStackDepth];
		ULONG hash_;
		size_t count_;
	};

	struct SymbolBuffer :public SYMBOL_INFO
	{
		SymbolBuffer()
		{
			// SYMBOL_INFO 구조체에 필요한 정보를 setting
			MaxNameLen = static_cast<ULONG>(kBufferSize);
			SizeOfStruct = sizeof(SYMBOL_INFO);
		}

		static const size_t kBufferSize = 256U;
		char buffer_[kBufferSize];
	};

	class SymbolLookup final
	{
	public:
		SymbolLookup() : handle_(GetCurrentProcess())
		{
			SymInitialize(handle_, nullptr, TRUE);
			SymSetOptions(SYMOPT_LOAD_LINES);
		}

		std::string GetSymbolString(void* address) const
		{
			if (address == nullptr) {
				return "";
			}

			DWORD displacement = 0;
			DWORD64 addr = reinterpret_cast<DWORD64>(address);
			SymbolBuffer symbol;
			char buffer[kStrBufferSize] = { 0, };

			// 주소에 대응하는 심볼의 파일이름 + line을 저장할 객체      
			IMAGEHLP_LINE64 line;
			line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);

			// SymbolBuffer 객체에 address에 대응하는 심볼 이름(함수명) 저장
			SymFromAddr(handle_, addr, 0, &symbol);


			BOOL ret = SymGetLineFromAddr64(handle_, addr, &displacement, &line);
			if (ret) {
				sprintf_s(buffer, kStrBufferSize, "%s(%d) : %s",
					line.FileName, line.LineNumber, symbol.Name);
			}
			else {
				sprintf_s(buffer, kStrBufferSize, "No line info : %s", symbol.Name);
			}

			return std::string(buffer);
		}

	private:
		const static size_t kStrBufferSize = 1024U;
	private:
		HANDLE handle_;
	};


	
} // namespace mir3d

#endif