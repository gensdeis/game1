#pragma once

#ifdef _WINDOWS

#include <string>
#include <Windows.h>

namespace mir3d
{
	struct CrashInfo
	{
		DWORD threadId = 0;
		PEXCEPTION_POINTERS pException = nullptr;
	};

	class Dump
	{
	public:
		static void Initialize();

	private:
		static long __stdcall CreateDumpThread(PEXCEPTION_POINTERS pException);

		static void CreateDump(CrashInfo* pCrashInfo);
		static const std::string MakeDumpFileName();
	};
}

#endif
