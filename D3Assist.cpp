/*
	Programmed by DoYoung Kang
	dooly386@gmail.com
	Copyright(c) dooly386@gmail.com
	2017.7.17
*/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("ProtectionAreaManagerFormUnit.cpp", ProtectionAreaManagerForm);
USEFORM("TTSManagerFormUnit.cpp", TTSManagerForm);
USEFORM("ABOUT.cpp", AboutBox);
USEFORM("D3AssistantMainUnit.cpp", D3AssistantMainForm);
USEFORM("MediaPlayerFormUnit.cpp", MediaPlayerForm);
USEFORM("DebugWindowFormUnit.cpp", DebugWindowForm);
USEFORM("SimplifyUIFormUnit.cpp", SimplifyUIForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TD3AssistantMainForm), &D3AssistantMainForm);
		Application->CreateForm(__classid(TAboutBox), &AboutBox);
		Application->CreateForm(__classid(TProtectionAreaManagerForm), &ProtectionAreaManagerForm);
		Application->CreateForm(__classid(TDebugWindowForm), &DebugWindowForm);
		Application->CreateForm(__classid(TSimplifyUIForm), &SimplifyUIForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
