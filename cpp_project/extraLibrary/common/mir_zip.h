#pragma once

//#include <pb_game_struct.pb.h>
#ifdef _WINDOWS

#include <windows.h>
#include <tchar.h>

#include <iostream>
#include <fstream>
#endif

#include <string>

#include "./zip/unzip.h"

namespace mir3d
{
	void Decompression(std::string target_file, std::string target_dir)
	{
		HZIP hz = OpenZip(target_file.c_str(), 0);
		if (hz != nullptr)
		{
			SetUnzipBaseDir(hz, target_dir.c_str()); //절대 경로로 압축풀경우
			// SetUnzipTargetDir(hz, target_dir.c_str()); //상대 경로로 압축풀경우

			ZIPENTRY ze;
			GetZipItem(hz, -1, &ze);
			int numitems = ze.index;
			for (int zi = 0; zi < numitems; zi++)
			{
				GetZipItem(hz, zi, &ze);
				UnzipItem(hz, zi, ze.name);
			}
			CloseZip(hz);
		}
	}

}   //namespace mir3d	
