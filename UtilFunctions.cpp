/*
	Programmed by DoYoung Kang
	dooly386@gmail.com
	Copyright(c) dooly386@gmail.com
	2017.7.17
*/
//---------------------------------------------------------------------------
#include <vcl.h>
#include <map>
#include <Tlhelp32.h>

#pragma hdrstop

#include "UtilFunctions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

String GetFileVersionString(const String &filename)
{
	char *FFileVersionInfoData;
	AnsiString exename = filename;
	DWORD DummyDWORD;
	int FileVersionInfoSize = GetFileVersionInfoSize(exename.c_str(),&DummyDWORD);
	if(FileVersionInfoSize==0)
	{
		return "";
	}
	FFileVersionInfoData = new char[FileVersionInfoSize];
	GetFileVersionInfo(exename.c_str(),0,FileVersionInfoSize,FFileVersionInfoData);

	LPVOID Buffer;
	unsigned int BufferLength;
	VerQueryValue(FFileVersionInfoData,"\\",&Buffer,&BufferLength);
	VS_FIXEDFILEINFO FFixedFileInfo;
	memmove(&FFixedFileInfo,Buffer,BufferLength);
	int major = HIWORD(FFixedFileInfo.dwFileVersionMS);
	int minor = LOWORD(FFixedFileInfo.dwFileVersionMS);
	int release = HIWORD(FFixedFileInfo.dwFileVersionLS);
	int build = LOWORD(FFixedFileInfo.dwFileVersionLS);

	delete[] FFileVersionInfoData;
	FFileVersionInfoData = NULL;

	AnsiString a;
	a = AnsiString(major)+"."+AnsiString(minor)+"."+AnsiString(release)+"."+AnsiString(build);
	return a;
}

void killProcessByName(const char *filename)
{
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
	PROCESSENTRY32 pEntry;
	pEntry.dwSize = sizeof (pEntry);
	BOOL hRes = Process32First(hSnapShot, &pEntry);
	while (hRes)
	{
		if (strcmp(pEntry.szExeFile, filename) == 0)
		{
			HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
										  (DWORD) pEntry.th32ProcessID);
			if (hProcess != NULL)
			{
				TerminateProcess(hProcess, 0);
				CloseHandle(hProcess);
			}
		}
		hRes = Process32Next(hSnapShot, &pEntry);
	}
	CloseHandle(hSnapShot);
}

void killYolo()
{
#ifdef _WIN64
	killProcessByName("YoloMouse64.exe");
#else
	killProcessByName("YoloMouse32.exe");
#endif

}

std::map<String,int> strvkeymap;
int str2vkey(String s)
{
	if(strvkeymap.size()==0)
	{
		strvkeymap["[F1]"] = VK_F1;
		strvkeymap["[F2]"] = VK_F2;
		strvkeymap["[F3]"] = VK_F3;
		strvkeymap["[F4]"] = VK_F4;
		strvkeymap["[F5]"] = VK_F5;
		strvkeymap["[F6]"] = VK_F6;
		strvkeymap["[F7]"] = VK_F7;
		strvkeymap["[F8]"] = VK_F8;
		strvkeymap["[F9]"] = VK_F9;
		strvkeymap["[F10]"] = VK_F10;
		strvkeymap["[F11]"] = VK_F11;
		strvkeymap["[F12]"] = VK_F12;

		strvkeymap["[ESC]"] = VK_ESCAPE;
		strvkeymap["[TAB]"] = VK_TAB;
		strvkeymap["[DEL]"] = VK_DELETE;
		strvkeymap["[INS]"] = VK_INSERT;
		strvkeymap["[HOME]"] = VK_HOME;
		strvkeymap["[END]"] = VK_END;
		strvkeymap["[PGUP]"] = VK_PRIOR;
		strvkeymap["[PGDN]"] = VK_NEXT;
		strvkeymap["[PAUSE]"] = VK_PAUSE;
    }

	std::map<String,int>::iterator it = strvkeymap.find(s);
	if(it==strvkeymap.end()) return 0;
    return it->second;
}

String vk2str(WORD key)
{
	switch(key)
	{
		case VK_F1:
			return "[F1]";
		case VK_F2:
			return "[F2]";
		case VK_F3:
			return "[F3]";
		case VK_F4:
			return "[F4]";
		case VK_F5:
			return "[F5]";
		case VK_F6:
			return "[F6]";
		case VK_F7:
			return "[F7]";
		case VK_F8:
			return "[F8]";
		case VK_F9:
			return "[F9]";
		case VK_F10:
			return "[F10]";
		case VK_F11:
			return "[F11]";
		case VK_F12:
			return "[F12]";
		case '1':
			return "1";
		case '2':
			return "2";
		case '3':
			return "3";
		case '4':
			return "4";
		case '5':
			return "5";
		case '6':
			return "6";
		case '7':
			return "7";
		case '8':
			return "8";
		case '9':
			return "9";
		case '0':
			return "0";
	}

	if(key>=65 && key<=90)
	{
		return (char)(65 +(key-65));
	}
	if(key==27)
	{
		return "[ESC]";
	}
	if(key==192)
	{
		return "`";
	}
	if(key==9)
	{
		return "[TAB]";
	}
	if(key==46)
	{
		return "[DEL]";
	}
	if(key==45)
	{
		return "[INS]";
	}
	if(key==36)
	{
		return "[HOME]";
	}
	if(key==35)
	{
		return "[END]";
	}
	if(key==33)
	{
		return "[PGUP]";
	}
	if(key==34)
	{
		return "[PGDN]";
	}
	if(key==19)
	{
		return "[PAUSE]";
    }
	return "";

}


