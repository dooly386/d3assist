//---------------------------------------------------------------------------

#ifndef UtilFunctionsH
#define UtilFunctionsH
//---------------------------------------------------------------------------
#include <map>
#include <set>
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
String ParsingKeys(String s,std::set<String> &r);

#endif
