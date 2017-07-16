//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "About.h"
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
}
//--------------------------------------------------------------------- 
