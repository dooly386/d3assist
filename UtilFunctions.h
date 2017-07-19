//---------------------------------------------------------------------------

#ifndef UtilFunctionsH
#define UtilFunctionsH
//---------------------------------------------------------------------------
void killProcessByName(const char *filename);
void killYolo();
String vk2str(WORD key);
int str2vkey(String s);
String GetFileVersionString(const String &filename);
void GetAllFileNames(String path,std::list<String> &ret);
bool IsValidStyle(String style);
void SetSkin(String name);
bool IsKeyPressed(int key);//    // key = 'A' ,,, VK_SHIFT ...

#endif
