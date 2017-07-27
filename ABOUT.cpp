/*
	Programmed by DoYoung Kang
	dooly386@gmail.com
	Copyright(c) dooly386@gmail.com
	2017.7.17
*/

//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "About.h"
#include "D3AssistantMainUnit.h"
//---------------------------------------------------------------------
#pragma link "dxGDIPlusClasses"
#pragma resource "*.dfm"
TAboutBox *AboutBox;
//---------------------------------------------------------------------
String GetFileVersionString(const String &filename);

__fastcall TAboutBox::TAboutBox(TComponent* AOwner)
	: TForm(AOwner)
{
	String ver = GetFileVersionString(Application->ExeName);
	Version->Caption = String("Version : v")+ver;

    FormStyle = D3AssistantMainForm->FormStyle;
}
//--------------------------------------------------------------------- 
