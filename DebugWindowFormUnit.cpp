//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DebugWindowFormUnit.h"
#include "MLTS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDebugWindowForm *DebugWindowForm;
//---------------------------------------------------------------------------

void DBG(String s)
{
	if(DebugWindowForm->Visible==false) return;

	DebugWindowForm->Memo1->Lines->BeginUpdate();
	DebugWindowForm->Memo1->Lines->Add(s);
	DebugWindowForm->Memo1->SelStart = DebugWindowForm->Memo1->GetTextLen();
	DebugWindowForm->Memo1->SelLength = 0;
	DebugWindowForm->Memo1->Lines->EndUpdate();

}


__fastcall TDebugWindowForm::TDebugWindowForm(TComponent* Owner)
	: TForm(Owner)
{
	ApplyMLTS(this);
}
//---------------------------------------------------------------------------
