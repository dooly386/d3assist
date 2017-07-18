/*
	Programmed by DoYoung Kang
	dooly386@gmail.com
	Copyright(c) dooly386@gmail.com
	2017.7.17
*/
//---------------------------------------------------------------------------
#include <vcl.h>
#include <map>
#include <list>
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
		strvkeymap["[SPACE]"] = VK_SPACE;
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

		strvkeymap["[ENTER]"] = VK_RETURN;

		strvkeymap["[SHIFT]"] = VK_SHIFT;
		strvkeymap["[CONTROL]"] = VK_CONTROL;
        strvkeymap["[ALT]"] = 0xa4;


	}

	std::map<String,int>::iterator it = strvkeymap.find(s);
	if(it==strvkeymap.end()) return 0;
    return it->second;
}

String vk2str(WORD key)
{
	switch(key)
	{

		case 0xa4: return "[ALT]";
		case VK_SHIFT:
			return "[SHIFT]";
		case VK_CONTROL:
			return "[CONTROL]";
		case VK_SPACE:
			return "[SPACE]";
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
	if(key==VK_ESCAPE)
	{
		return "[ESC]";
	}
	if(key==192)
	{
		return "`";
	}
	if(key==VK_TAB)
	{
		return "[TAB]";
	}
	if(key==VK_DELETE)
	{
		return "[DEL]";
	}
	if(key==VK_INSERT)
	{
		return "[INS]";
	}
	if(key==VK_HOME)
	{
		return "[HOME]";
	}
	if(key==VK_END)
	{
		return "[END]";
	}
	if(key==VK_PRIOR)
	{
		return "[PGUP]";
	}
	if(key==VK_NEXT)
	{
		return "[PGDN]";
	}
	if(key==VK_PAUSE)
	{
		return "[PAUSE]";
	}
	if(key==VK_SPACE)
	{
        return "[SPACE]";
	}
	if(key==VK_RETURN)
	{
        return "[ENTER]";
    }
	return "";

}

char* translate(int vk, int up)
{
	int shift = 0, caps = 0 , ctrl=0;
	/*
	if (up)
	{
		if ((vk == 0x10) || (vk == 0xa0) || (vk == 0xa1)) shift = 0;
		if(vk==0xa2) ctrl = 0;
		return 0;
	} else if ((vk==0x10)||(vk==0xa0)||(vk==0xa1))
	{
		shift=1; return 0;
	}
	shift = 0;

	if(vk==0xa2)
	{
		ctrl = 1;
		return 0;
	}
	*/


	static char buf[16];
	memset(buf, 0, 16);

	switch (vk)
	{
		case VK_BACK: strcpy(buf, "[BS]"); return buf;
		case VK_TAB: strcpy(buf, "[TAB]"); return buf;
		case VK_RETURN: strcpy(buf, "[ENTER]"); return buf;
		case VK_LEFT: strcpy(buf, "[LT]"); return buf;
		case VK_UP: strcpy(buf, "[UP]"); return buf;
		case VK_RIGHT: strcpy(buf, "[RT]"); return buf;
		case VK_DOWN: strcpy(buf, "[DN]"); return buf;
		case VK_ESCAPE: strcpy(buf, "[ESC]"); return buf;
		case VK_DELETE: strcpy(buf,"[DEL]"); return buf;
		case VK_INSERT: strcpy(buf,"[INS]"); return buf;
		case VK_HOME: strcpy(buf,"[HOME]"); return buf;
		case VK_END: strcpy(buf,"[END]"); return buf;
		case VK_PRIOR: strcpy(buf,"[PGUP]"); return buf;
		case VK_NEXT: strcpy(buf,"[PGDN]"); return buf;
		case VK_PAUSE: strcpy(buf,"[PAUSE]"); return buf;
		case VK_SPACE: strcpy(buf,"[SPACE]"); return buf;
		case 0xa0:
		case 0xa1:
		case VK_SHIFT: strcpy(buf,"[SHIFT]"); return buf;
        case 0xa2:
		case VK_CONTROL: strcpy(buf,"[CONTROL]"); return buf;
		case 0xa4: strcpy(buf,"[ALT]"); return buf;

	}


	if (vk > 0x69 && vk < 0x70)
	{
		buf[0] = (char)(vk - 0x40);
	}
	else if (vk > 0x6f && vk < 0x88)
	{
		sprintf(buf, "[F%d]", vk - 0x6f);
	}
	else if (isalpha(vk))
	{
		if (!caps)
			if (shift) { buf[0] = (char)(toupper(vk)); } else { buf[0] = (char)(toupper(vk)); }
		else
			if (!shift) { buf[0] = (char)(toupper(vk)); } else { buf[0] = (char)(toupper(vk)); }
	}
	else
	{
		switch (vk)
		{
			case '1': if (!shift) {buf[0]=(char)vk;} else {buf[0]='!';} break;
			case '2': if (!shift) {buf[0]=(char)vk;} else {buf[0]='@';} break;
			case '3': if (!shift) {buf[0]=(char)vk;} else {buf[0]='#';} break;
			case '4': if (!shift) {buf[0]=(char)vk;} else {buf[0]='$';} break;
			case '5': if (!shift) {buf[0]=(char)vk;} else {buf[0]='%';} break;
			case '6': if (!shift) {buf[0]=(char)vk;} else {buf[0]='^';} break;
			case '7': if (!shift) {buf[0]=(char)vk;} else {buf[0]='&';} break;
			case '8': if (!shift) {buf[0]=(char)vk;} else {buf[0]='*';} break;
			case '9': if (!shift) {buf[0]=(char)vk;} else {buf[0]='(';} break;
			case '0': if (!shift) {buf[0]=(char)vk;} else {buf[0]=')';} break;
			case 0xba: if (!shift) {buf[0]=';';} else {buf[0]=':';} break;
			case 0xbb: if (!shift) {buf[0]='=';} else {buf[0]='+';} break;
			case 0xbc: if (!shift) {buf[0]=',';} else {buf[0]='<';} break;
			case 0xbd: if (!shift) {buf[0]='-';} else {buf[0]='_';} break;
			case 0xbe: if (!shift) {buf[0]='.';} else {buf[0]='>';} break;
			case 0xbf: if (!shift) {buf[0]='/';} else {buf[0]='?';} break;
			case 0xc0: if (!shift) {buf[0]='`';} else {buf[0]='~';} break;
			case 0xdb: if (!shift) {buf[0]='[';} else {buf[0]='{';} break;
			case 0xdc: if (!shift) {buf[0]='\\';} else {buf[0]='|';} break;
			case 0xdd: if (!shift) {buf[0]=']';} else {buf[0]='}';} break;
			case 0xde: if (!shift) {buf[0]='\'';} else {buf[0]='\"';} break;
		}
	}
	/*
	if(ctrl)
	{
		char temp[128];
		strcpy(temp,buf);
		sprintf(buf,"CTRL+%s",temp);
	}
    */
	return buf;
}



void GetAllFileNames(String path,std::list<String> &ret)
{
	TSearchRec rec;
	int attr = 0;
	int r = FindFirst(path,attr,rec);
	while(r==0)
	{
		if(rec.Name!="." && rec.Name!="..")
		{
			String name = ChangeFileExt(rec.Name,"");
			ret.push_back(name);
		}
		r = FindNext(rec);
	}
	FindClose(rec);
}


bool IsValidStyle(String style)
{
	for(int i=0;i<TStyleManager::StyleNames.Length;i++)
	{
		String kkk = TStyleManager::StyleNames[i];
		if(kkk==style)
		{
			return true;
		}
	}
	return false;
}

void SetSkin(String name)
{
	if(name=="Windows")
	{
		TStyleManager::TrySetStyle("Windows");
        return;
    }
	String path = ExtractFilePath(Application->ExeName);
	if(IsValidStyle(name)==false)
	{
		String filename = path+"\\styles2\\"+name+".vsf";
		if(FileExists(filename))
		{
			TStyleManager_TStyleServicesHandle h = TStyleManager::LoadFromFile(filename);

        }
	}
	if(IsValidStyle(name))
	{
		TStyleManager::TrySetStyle(name);
		TStyleManager::SystemHooks = TStyleManager::SystemHooks - (TStyleManager::TSystemHooks() << TStyleManager::TSystemHook::shDialogs);
		TStyleManager::SystemHooks = TStyleManager::SystemHooks >> TStyleManager::TSystemHook::shDialogs;
	}
}

