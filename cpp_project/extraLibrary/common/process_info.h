#pragma once

#ifdef _WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#endif

namespace mir3d
{
	unsigned long GetSelfPid(void)
	{
#ifdef _WINDOWS
		return GetCurrentProcessId();
#else
		return getpid();
#endif
	}

}   //namespace mir3d	
