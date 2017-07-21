//---------------------------------------------------------------------------
#include <list>

#include <vcl.h>
#pragma hdrstop

#include "MediaPlayerFormUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMediaPlayerForm *MediaPlayerForm;
//---------------------------------------------------------------------------
std::list<TMediaPlayerForm *> mediaplayerforms;

TMediaPlayerForm * CreateMediaPlayerForm(TComponent *owner)
{
	TMediaPlayerForm *form = new TMediaPlayerForm(owner);
	mediaplayerforms.push_back(form);
	return form;
}


__fastcall TMediaPlayerForm::TMediaPlayerForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMediaPlayerForm::Button1Click(TObject *Sender)
{
	MediaPlayer1->Open();

	HWND hwnd = FindWindow(0,"디아블로 III");
	if(hwnd)
	{
        ::SetParent(Handle,hwnd);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMediaPlayerForm::FormResize(TObject *Sender)
{
	MediaPlayer1->DisplayRect = this->ClientRect;

}
//---------------------------------------------------------------------------
void __fastcall TMediaPlayerForm::FormClose(TObject *Sender, TCloseAction &Action)

{
	MediaPlayer1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TMediaPlayerForm::Button2Click(TObject *Sender)
{
	AlphaBlend = true;
}
//---------------------------------------------------------------------------
