//---------------------------------------------------------------------------

#ifndef UtilFunctionsH
#define UtilFunctionsH
//---------------------------------------------------------------------------
#include <map>
#include <set>

#define USESENDINPUT

void KillProcessByName(const char *filename);
void KillYolo();
String vk2str(WORD key);
int str2vkey(String s);
String GetFileVersionString(const String &filename);
void GetAllFileNames(String path,std::list<String> &ret);
bool IsValidStyle(String style);
void SetSkin(String name);
bool IsKeyPressed(int key);//    // key = 'A' ,,, VK_SHIFT ...
void DBG(String s);
String ParsingKeys(String s,std::list<String> &r);
String ParsingKeys(String s,std::set<String> &r,std::set<String> &andr);
String ParsingKeys(String s,std::list<String> &r,std::list<String> &andr);

ULONG GetPidByProcessName(const char *processname);
HWND GetWinHandleByPid(ULONG pid);
HWND GetWinHandleByProcessName(const char *procname);

String GetInstallPath();
String GetYoloMediaPath();
String GetYoloMediaFileByName(String name);

bool CheckYoloMouseReady();
HWND GetYoloHandle();
void __stdcall SetForegroundWindowForce(HWND hWnd);

void DisableVclStyles(TControl *Control,const String ClassToIgnore);

void MouseDown(TMouseButton button);
void MouseUp(TMouseButton button);

void MouseDownX(int btn);
void MouseUpX(int btn);

void MouseWheel(int delta);
void MouseClick(TMouseButton button);

void PushDownKey(int vcode,int scancode);
void PushUpKey(int vcode,int scancode);
void PressKey(int vcode,int scancode);

int GetKeyState(const String &key);


#endif
