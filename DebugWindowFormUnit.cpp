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
__fastcall TDebugWindowForm::TDebugWindowForm(TComponent* Owner)
	: TForm(Owner)
{
	ApplyMLTS(this);
}
//---------------------------------------------------------------------------
