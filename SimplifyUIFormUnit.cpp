//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SimplifyUIFormUnit.h"
#include "D3AssistantMainUnit.h"
#include "UtilFunctions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSimplifyUIForm *SimplifyUIForm;
//---------------------------------------------------------------------------
__fastcall TSimplifyUIForm::TSimplifyUIForm(TComponent* Owner)
	: TForm(Owner)
{
	for(int i=0;i<ComponentCount;i++)
	{
		TComponent *comp = (TComponent *)Components[i];
		compMap[comp->Name] = comp;
	}

	Left = 0;
	Top = 0;
	checkColor();

	DisableVclStyles(this,"TEdit");


}
void TSimplifyUIForm::checkColor()
{
	for(int i=1;i<=8;i++)
	{
		String keyname = String("edKey")+i;
		String descname = String("edDesc")+i;

		TEdit *tedesc = (TEdit *)D3AssistantMainForm->compMap[descname];
		if(tedesc->Text.Length())
		{
			TEdit *te = (TEdit *)compMap[keyname];
			te->Text = tedesc->Text;
			te->Color = tedesc->Color;
			te->Font = tedesc->Font;
		}
		else
		{
			TEdit *te = (TEdit *)compMap[keyname];
			TEdit *tekey = (TEdit *)D3AssistantMainForm->compMap[keyname];
			te->Text = tekey->Text;
			te->Color = tekey->Color;
			te->Font = tekey->Font;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TSimplifyUIForm::menuRestoreClick(TObject *Sender)
{
	D3AssistantMainForm->UnSimplify();

}
//---------------------------------------------------------------------------
void __fastcall TSimplifyUIForm::FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if(Button==mbLeft)
	{
		bMoveStart = true;
		MoveX = X;
		MoveY = Y;
	}

}
//---------------------------------------------------------------------------
void __fastcall TSimplifyUIForm::FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	if(bMoveStart)
	{
		int dx = X-MoveX;
		int dy = Y-MoveY;
		D3AssistantMainForm->Left += dx;
        D3AssistantMainForm->Top += dy;
    }

}
//---------------------------------------------------------------------------
void __fastcall TSimplifyUIForm::FormMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if(Button==mbLeft)
	{
		bMoveStart = false;;
	}

}
//---------------------------------------------------------------------------
void __fastcall TSimplifyUIForm::Button1Click(TObject *Sender)
{
	D3AssistantMainForm->UnSimplify();

}
//---------------------------------------------------------------------------

