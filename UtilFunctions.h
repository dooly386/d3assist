//---------------------------------------------------------------------------

#ifndef UtilFunctionsH
#define UtilFunctionsH
//---------------------------------------------------------------------------
void killProcessByName(const char *filename);
void killYolo();
String vk2str(WORD key);
int str2vkey(String s);
String GetFileVersionString(const String &filename);

#endif
