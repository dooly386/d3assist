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
#include <set>
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

ULONG ProcIDFromWnd(HWND hwnd) // 윈도우 핸들로 프로세스 아이디 얻기
{
    ULONG idProc;
    GetWindowThreadProcessId( hwnd, &idProc );
    return idProc;
}

HWND GetWinHandleByPid(ULONG pid)
{
	HWND tempHwnd = FindWindow(NULL,NULL); // 최상위 윈도우 핸들 찾기

    while( tempHwnd != NULL )
    {
       // 최상위 핸들인지 체크, 버튼 등도 핸들을 가질 수 있으므로 무시하기 위해
       if( GetParent(tempHwnd) == NULL )
       if( pid == ProcIDFromWnd(tempHwnd) )
           return tempHwnd;
       tempHwnd = GetWindow(tempHwnd, GW_HWNDNEXT); // 다음 윈도우 핸들 찾기
    }
    return NULL;
}

ULONG GetProcIDYolo()
{
	char filename[256];
#ifdef _WIN64
	strcpy(filename,"YoloMouse64.exe");
#else
	strcpy(filename,"YoloMouse32.exe");
#endif

	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
	PROCESSENTRY32 pEntry;
	pEntry.dwSize = sizeof (pEntry);
	BOOL hRes = Process32First(hSnapShot, &pEntry);
	while (hRes)
	{
		if (strcmp(pEntry.szExeFile, filename) == 0)
		{
			CloseHandle(hSnapShot);
			return pEntry.th32ProcessID;
			/*
			HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
										  (DWORD) pEntry.th32ProcessID);
			if (hProcess != NULL)
			{
				TerminateProcess(hProcess, 0);
				CloseHandle(hProcess);
			}
            */
		}
		hRes = Process32Next(hSnapShot, &pEntry);
	}
	CloseHandle(hSnapShot);
	return 0;

}
void KillProcessByName(const char *filename)
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


void KillYolo()
{
	ULONG pid = GetProcIDYolo();
	if(pid==0) return;

	HWND hwnd = GetWinHandleByPid(pid);
	if(hwnd==0) return;

	SendMessage(hwnd,WM_COMMAND,1000,0L);
}

ULONG GetPidByProcessName(const char *processname)
{
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
	PROCESSENTRY32 pEntry;
	pEntry.dwSize = sizeof (pEntry);
	BOOL hRes = Process32First(hSnapShot, &pEntry);
	while (hRes)
	{
		if (strcmp(pEntry.szExeFile, processname) == 0)
		{
			HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
										  (DWORD) pEntry.th32ProcessID);
			if (hProcess != NULL)
			{
				CloseHandle(hProcess);
				CloseHandle(hSnapShot);
				return pEntry.th32ProcessID;
			}
		}
		hRes = Process32Next(hSnapShot, &pEntry);
	}
	CloseHandle(hSnapShot);
	return 0;
}

HWND GetWinHandleByProcessName(const char *procname)
{
	ULONG pid = GetPidByProcessName(procname);
	if(pid==0) return 0;
	HWND hwnd = GetWinHandleByPid(pid);
	return hwnd;

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
		strvkeymap["[BACK]"] = VK_BACK;

		strvkeymap["[LEFT]"] = VK_LEFT;
		strvkeymap["[UP]"] = VK_UP;
		strvkeymap["[RIGHT]"] = VK_RIGHT;
		strvkeymap["[DOWN]"] = VK_DOWN;

		strvkeymap["[NUMLOCK]"] = VK_NUMLOCK;

		strvkeymap["[0]"] = 0x60;
		strvkeymap["[1]"] = 0x61;
		strvkeymap["[2]"] = 0x62;
		strvkeymap["[3]"] = 0x63;
		strvkeymap["[4]"] = 0x64;
		strvkeymap["[5]"] = 0x65;
		strvkeymap["[6]"] = 0x66;
		strvkeymap["[7]"] = 0x67;
		strvkeymap["[8]"] = 0x68;
		strvkeymap["[9]"] = 0x69;

		strvkeymap["[+]"] = 0x6b;
		strvkeymap["[-]"] = 0x6d;

		strvkeymap["[=]"] = 0xbb;
	}

	std::map<String,int>::iterator it = strvkeymap.find(s);
	if(it==strvkeymap.end()) return 0;
    return it->second;
}

String vk2str(WORD key)
{
	switch(key)
	{
		case 0x08:
			return "[BACK]";
		case 0xdc:
		case 0x5c:
			return "\\";
		case 0xdb:
		case 0x5b:
			return "[";
		case 0xdd:
		case 0x5d:
			return "]";

		case 0xbc:
		case 0x2c:
			return ",";

		case 0xbe:
		case 0x2e:
			return ".";

		case 0xbf:
		case 0x2f:
			return "/";

		case 0xba:
		case 0x2a:
			return ";";

		case 0xde:
			return "'";

		case 0x25:
			return "[LEFT]";
		case 0x26:
			return "[UP]";
		case 0x27:
			return "[RIGHT]";
		case 0x28:
			return "[DOWN]";

		case 0x90:
			return "[NUMLOCK]";

		case 0x60:
			return "[0]";
		case 0x61:
			return "[1]";
		case 0x62:
			return "[2]";
		case 0x63:
			return "[3]";
		case 0x64:
			return "[4]";
		case 0x65:
			return "[5]";
		case 0x66:
			return "[6]";
		case 0x67:
			return "[7]";
		case 0x68:
			return "[8]";
		case 0x69:
			return "[9]";
		case 0x6b:
			return "[+]";

		case 0x6d:
		case 0xbd:
			return "[-]";

		case 0xbb:
			return "[=]";


		case 0x12:
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
		case VK_BACK: strcpy(buf, "[BKSP]"); return buf;
		case VK_TAB: strcpy(buf, "[TAB]"); return buf;
		case VK_RETURN: strcpy(buf, "[ENTER]"); return buf;
		case VK_LEFT: strcpy(buf, "[LEFT]"); return buf;
		case VK_UP: strcpy(buf, "[UP]"); return buf;
		case VK_RIGHT: strcpy(buf, "[RIGHT]"); return buf;
		case VK_DOWN: strcpy(buf, "[DOWN]"); return buf;
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
		case 0x60: strcpy(buf,"[0]"); return buf;
		case 0x61: strcpy(buf,"[1]"); return buf;
		case 0x62: strcpy(buf,"[2]"); return buf;
		case 0x63: strcpy(buf,"[3]"); return buf;
		case 0x64: strcpy(buf,"[4]"); return buf;
		case 0x65: strcpy(buf,"[5]"); return buf;
		case 0x66: strcpy(buf,"[6]"); return buf;
		case 0x67: strcpy(buf,"[7]"); return buf;
		case 0x68: strcpy(buf,"[8]"); return buf;
		case 0x69: strcpy(buf,"[9]"); return buf;
		case 0x90: strcpy(buf,"[NUMLOCK]"); return buf;

		case 0x6b: strcpy(buf,"[+]"); return buf;

		case 0xbd:
		case 0x6d: strcpy(buf,"[-]"); return buf;

		case 0xbb: strcpy(buf,"[=]"); return buf;
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
		//TStyleManager::SystemHooks = TStyleManager::SystemHooks - (TStyleManager::TSystemHooks() << TStyleManager::TSystemHook::shDialogs);
		//TStyleManager::SystemHooks = TStyleManager::SystemHooks >> TStyleManager::TSystemHook::shDialogs;
	}
}


BYTE state[256];

#define KEY_PRESSED(key) (state[key] & 0x80)

bool IsKeyPressed(int key)    // key = 'A' ,,, VK_SHIFT ...
{
	GetKeyboardState(state);
	return KEY_PRESSED(key);
}

String ParsingKeys(String s,std::list<String> &r)
{
	if(s.Length()==0) return "";

	TStringList *t = new TStringList;
	t->Delimiter = L'|';
	t->DelimitedText = s;
	if(t->Count==1)
	{
		delete t;
		return s;
	}

	for(int i=1;i<t->Count;i++)
	{
		r.push_back(t->Strings[i]);
	}
	String rs = t->Strings[0];
	delete t;
	return rs;

}
String ParsingKeys(String s,std::set<String> &r,std::set<String> &andr)
{
	if(s.Length()==0) return "";
	if(s.Pos("&"))
	{
		TStringList *t = new TStringList;
		t->Delimiter = L'&';
		t->DelimitedText = s;
		if(t->Count==1)
		{
			delete t;
			return s;
		}

		for(int i=1;i<t->Count;i++)
		{
			andr.insert(t->Strings[i]);
		}
		String rs = t->Strings[0];
		delete t;
		return rs;

	}



	TStringList *t = new TStringList;
	t->Delimiter = L'|';
	t->DelimitedText = s;
	if(t->Count==1)
	{
		delete t;
		return s;
	}

	for(int i=1;i<t->Count;i++)
	{
		r.insert(t->Strings[i]);
	}
	String rs = t->Strings[0];
	delete t;
	return rs;

}

String ParsingKeys(String s,std::list<String> &r,std::list<String> &andr)
{
	if(s.Length()==0) return "";
	if(s.Pos("&"))
	{
		TStringList *t = new TStringList;
		t->Delimiter = L'&';
		t->DelimitedText = s;
		if(t->Count==1)
		{
			delete t;
			return s;
		}

		for(int i=1;i<t->Count;i++)
		{
			andr.push_back(t->Strings[i]);
		}
		String rs = t->Strings[0];
		delete t;
		return rs;

	}



	TStringList *t = new TStringList;
	t->Delimiter = L'|';
	t->DelimitedText = s;
	if(t->Count==1)
	{
		delete t;
		return s;
	}

	for(int i=1;i<t->Count;i++)
	{
		r.push_back(t->Strings[i]);
	}
	String rs = t->Strings[0];
	delete t;
	return rs;

}



String GetInstallPath()
{
	return ExtractFilePath(Application->ExeName);
}

String GetYoloMediaPath()
{
	String path = GetInstallPath()+"tts";
	return path;
}

String GetYoloMediaFileByName(String name)
{
	String filename = GetYoloMediaPath()+"\\"+name+".wav";
	return filename;
}


bool CheckYoloMouseReady()
{
#ifndef _WIN64
	if(GetWinHandleByProcessName("YoloMouse32.exe")==0)
	{
		return false;
	}
#else
	if(GetWinHandleByProcessName("YoloMouse64.exe")==0)
	{
		return false;
	}
#endif
	return true;
}


HWND GetYoloHandle()
{

#ifndef _WIN64
	HWND hwnd = GetWinHandleByProcessName("YoloMouse32.exe");
#else
	HWND hwnd = GetWinHandleByProcessName("YoloMouse64.exe");
#endif
	return hwnd;
}

void __stdcall SetForegroundWindowForce(HWND hWnd)
{
 HWND hForeground;
 DWORD id, foreground_id;
 hForeground = GetForegroundWindow();
 if (hForeground == hWnd) return;
 foreground_id = GetWindowThreadProcessId(hForeground, NULL);
 id = GetWindowThreadProcessId(hWnd, NULL);
 if (AttachThreadInput(id, foreground_id, TRUE))
 {
  SetForegroundWindow(hWnd);
  BringWindowToTop(hWnd);
  AttachThreadInput(id, foreground_id, FALSE);
 }
}


void DisableVclStyles(TControl *Control,const String ClassToIgnore)
{

	if(Control==0) return;
	if(Control->ClassNameIs(ClassToIgnore))
	{
        Control->StyleElements = (TStyleElements)0;
    }
	if(Control->InheritsFrom(__classid(TWinControl)))
	{
		TWinControl *wc = (TWinControl *)Control;
		for(int i=0;i<wc->ControlCount;i++)
		{
			DisableVclStyles(wc->Controls[i],ClassToIgnore);
		}
	}

}


extern bool bKeyboardFromCode;
extern bool bMouseFromCode;

void MouseDown(TMouseButton button)
{

	bMouseFromCode = true;

#ifndef USESENDINPUT
	if(button==mbLeft)
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		bMouseFromCode = false;
	}
	else
	if(button==mbRight)
	{
		mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
		bMouseFromCode = false;
	}
	else
	if(button==mbMiddle)
	{
		mouse_event(MOUSEEVENTF_MIDDLEDOWN,0,0,0,0);
		bMouseFromCode = false;
	}
#else
  INPUT    input;
	::ZeroMemory(&input, sizeof(input));

	if(button==mbLeft)
	{
		input.type      = INPUT_MOUSE;
		input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
		::SendInput(1,&input,sizeof(INPUT));
	}
	else
	if(button==mbRight)
	{
		input.type      = INPUT_MOUSE;
		input.mi.dwFlags  = MOUSEEVENTF_RIGHTDOWN;
		::SendInput(1,&input,sizeof(INPUT));

	}
	else
	if(button==mbMiddle)
	{
		input.type      = INPUT_MOUSE;
		input.mi.dwFlags  = MOUSEEVENTF_MIDDLEDOWN;
		::SendInput(1,&input,sizeof(INPUT));

	}


#endif

	bMouseFromCode = false;

//	if(sleepsec) Sleep(sleepsec);

}

void MouseUp(TMouseButton button)
{
	bMouseFromCode = true;

#ifndef USESENDINPUT
	if(button==mbLeft)
	{
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
		bMouseFromCode = false;
	}
	else
	if(button==mbRight)
	{
		mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
		bMouseFromCode = false;
	}
	else
	if(button==mbMiddle)
	{
		mouse_event(MOUSEEVENTF_MIDDLEUP,0,0,0,0);
		bMouseFromCode = false;
	}
#else
	INPUT    input;
	::ZeroMemory(&input, sizeof(input));

	if(button==mbLeft)
	{
		input.type      = INPUT_MOUSE;
		input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
		::SendInput(1,&input,sizeof(INPUT));
	}
	else
	if(button==mbRight)
	{
		input.type      = INPUT_MOUSE;
		input.mi.dwFlags  = MOUSEEVENTF_RIGHTUP;
		::SendInput(1,&input,sizeof(INPUT));

	}
	else
	if(button==mbMiddle)
	{
		input.type      = INPUT_MOUSE;
		input.mi.dwFlags  = MOUSEEVENTF_MIDDLEUP;
		::SendInput(1,&input,sizeof(INPUT));

	}


#endif

	bMouseFromCode = false;
}


void MouseDownX(int btn)
{
	/*
	MOUSEINPUT input;
	::ZeroMemory(&input, sizeof(input));
	input.mouseData = btn;
	input.dwFlags =  MOUSEEVENTF_XDOWN;
	::SendInput(1,(INPUT *)&input,sizeof(MOUSEINPUT));
	*/
	bKeyboardFromCode = true;

	INPUT    input;
	::ZeroMemory(&input, sizeof(input));

	input.type      = INPUT_MOUSE;
	input.mi.dwFlags  = MOUSEEVENTF_XDOWN;
	input.mi.mouseData = btn;
	::SendInput(1,&input,sizeof(INPUT));

	bKeyboardFromCode = false;


}


void MouseUpX(int btn)
{
	bKeyboardFromCode = true;
	INPUT    input;
	::ZeroMemory(&input, sizeof(input));

	input.type      = INPUT_MOUSE;
	input.mi.dwFlags  = MOUSEEVENTF_XUP;
	input.mi.mouseData = btn;
	::SendInput(1,&input,sizeof(INPUT));

	bKeyboardFromCode = false;
}

void MouseWheel(int delta)
{
	bKeyboardFromCode = true;

	INPUT    input;
	::ZeroMemory(&input, sizeof(input));

	input.type      = INPUT_MOUSE;
	input.mi.dwFlags  = MOUSEEVENTF_WHEEL;
	input.mi.mouseData = delta;
	::SendInput(1,&input,sizeof(INPUT));

	bKeyboardFromCode = false;
}


void MouseClick(TMouseButton button)
{

	bMouseFromCode = true;
#ifndef USESENDINPUT
	if(button==mbLeft)
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	}else
	if(button==mbRight)
	{
		mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
		mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	}else
	if(button==mbMiddle)
	{
		mouse_event(MOUSEEVENTF_MIDDLEDOWN,0,0,0,0);
		mouse_event(MOUSEEVENTF_MIDDLEUP,0,0,0,0);
	}
#else
	MouseDown(button);
	MouseUp(button);
#endif

	bMouseFromCode = false;
}

void PushDownKey(int vcode,int scancode)
{
	bKeyboardFromCode = true;
#ifndef USESENDINPUT
	keybd_event(vcode,scancode,0,0);
#else
	INPUT input;
	::ZeroMemory(&input, sizeof(input));
	input.type = INPUT_KEYBOARD;
	input.ki.wVk  = vcode;
	//  input.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &input, sizeof(INPUT));
#endif
	bKeyboardFromCode = false;

}

void PushUpKey(int vcode,int scancode)
{
	bKeyboardFromCode = true;
#ifndef USESENDINPUT
	keybd_event(vcode,scancode,KEYEVENTF_KEYUP,0);
#else
	INPUT input;
	::ZeroMemory(&input, sizeof(input));
	input.type = INPUT_KEYBOARD;
	input.ki.wVk  = vcode;
	input.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &input, sizeof(INPUT));
#endif
	bKeyboardFromCode = false;
}

void PressKey(int vcode,int scancode)
{
	bKeyboardFromCode = true;
#ifndef USESENDINPUT
	keybd_event(vcode,scancode,0,0);
	keybd_event(vcode,scancode,KEYEVENTF_KEYUP,0);
#else
	PushDownKey(vcode,scancode);
	PushUpKey(vcode,scancode);

	/*
	INPUT input[2];
	::ZeroMemory(input, sizeof(input));
	input[0].type = input[1].type = INPUT_KEYBOARD;
	input[0].ki.wVk  = input[1].ki.wVk = vcode;;
	input[1].ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(2, input, sizeof(INPUT));
}	*/
#endif
	bKeyboardFromCode = false;
}

