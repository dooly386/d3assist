//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SimplifyUIFormUnit.h"
#include "D3AssistantMainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSimplifyUIForm *SimplifyUIForm;
//---------------------------------------------------------------------------
__fastcall TSimplifyUIForm::TSimplifyUIForm(TComponent* Owner)
	: TForm(Owner)
{
	Left = 0;
	Top = 0;
    checkColor();
}
void TSimplifyUIForm::checkColor()
{
	for(int i=0;i<ComponentCount;i++)
	{
		TComponent *comp = Components[i];
		if(comp->ClassNameIs("TEdit"))
		{
			TEdit *te1 = (TEdit *)comp;
			TEdit *te2 = (TEdit *)D3AssistantMainForm->FindComponent(te1->Name);
			te1->Text = te2->Text;
			te1->Color = te2->Color;
			te1->Font = te2->Font;
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
