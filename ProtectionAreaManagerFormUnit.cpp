//---------------------------------------------------------------------------
#include <list>

#include <vcl.h>
#pragma hdrstop

#include "ProtectionAreaManagerFormUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TProtectionAreaManagerForm *ProtectionAreaManagerForm;

std::list<RECT> gProtArea;

bool InsideProtArea(POINT &pt)
{

	TPoint pt2(pt.x,pt.y);
	pt2 = ProtectionAreaManagerForm->ScreenToClient(pt2);
	std::list<RECT>::iterator it = gProtArea.begin();
	while(it!=gProtArea.end())
	{
		RECT &r = *it;
		if(pt2.x<r.left)
		{
			it++;
			continue;
		}
		if(pt2.x>r.right)
		{
			it++;
			continue;
		}
		if(pt2.y<r.top)
		{
			it++;
			continue;
		}
		if(pt2.y>r.bottom)
		{
			it++;
			continue;
		}

		/*
		AnsiString s;
		s.printf("%d,%d",pt.x,pt.y);
		ProtectionAreaManagerForm->Memo1->Lines->Add(s);
        */

		return true;
	}
	return false;
}
//---------------------------------------------------------------------------
__fastcall TProtectionAreaManagerForm::TProtectionAreaManagerForm(TComponent* Owner)
	: TForm(Owner)
{
	bMoveStart = false;
	bAreaPanelMoveStart = false;

	BoundsRect = Screen->PrimaryMonitor->BoundsRect;
}
//---------------------------------------------------------------------------
void __fastcall TProtectionAreaManagerForm::FormMouseDown(TObject *Sender, TMouseButton Button,
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
void __fastcall TProtectionAreaManagerForm::FormMouseUp(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	if(Button==mbLeft)
	{
		bMoveStart = false;;
	}

}
//---------------------------------------------------------------------------
void __fastcall TProtectionAreaManagerForm::FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	if(bMoveStart)
	{
		int dx = X-MoveX;
		int dy = Y-MoveY;
		Left += dx;
        Top += dy;
    }
}
//---------------------------------------------------------------------------
void __fastcall TProtectionAreaManagerForm::MenuMaximizeWindowClick(TObject *Sender)

{
    WindowState = wsMaximized;
}
//---------------------------------------------------------------------------
void __fastcall TProtectionAreaManagerForm::MenuRestoreWindowClick(TObject *Sender)

{
	WindowState = wsNormal;
}
//---------------------------------------------------------------------------
void __fastcall TProtectionAreaManagerForm::MenuCloseWindowClick(TObject *Sender)

{
    Hide();
}
//---------------------------------------------------------------------------
void __fastcall TProtectionAreaManagerForm::MenuFitToBackWindowClick(TObject *Sender)

{
	POINT p;
//	GetCursorPos(&p);
	p.x = Left-1;
	p.y = Top-1;

	Hide();
	Update();
	HWND hwnd = WindowFromPoint(p);
	Show();
    Update();

	if(hwnd)
	{
		/*
		WINDOWPLACEMENT wp;
		::GetWindowPlacement(hwnd,&wp);
		if(wp.flags&WPF_RESTORETOMAXIMIZED)
		{
			MenuMaximizeWindowClick(Sender);
			return;
		}
        */

		int caph = GetSystemMetrics(SM_CYCAPTION);
		int offsety = GetSystemMetrics(SM_CYSIZEFRAME);
		int offsetx = GetSystemMetrics(SM_CYSIZEFRAME);

		RECT r;
		if(::GetWindowRect(hwnd,&r))
		{
			Left = r.left+offsetx;
			Top = r.top+caph+offsety;
		}
		if(::GetClientRect(hwnd,&r))
		{
			Width = r.right-r.left;
			Height = r.bottom-r.top;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TProtectionAreaManagerForm::I1Click(TObject *Sender)
{
	int a = AlphaBlendValue + 10;
	if(a>255)
	{
		a = 255;
	}
	AlphaBlendValue = a;
}
//---------------------------------------------------------------------------
void __fastcall TProtectionAreaManagerForm::D1Click(TObject *Sender)
{
	int a = AlphaBlendValue - 10;
	if(a<30)
	{
		a = 30;
	}
	AlphaBlendValue = a;

}
//---------------------------------------------------------------------------
void __fastcall TProtectionAreaManagerForm::AreaPanelMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if(Button==mbLeft)
	{

		MoveX = X;
		MoveY = Y;
		bAreaPanelMoveStart = true;

	}
}
//---------------------------------------------------------------------------

void __fastcall TProtectionAreaManagerForm::AreaPanelMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
    bAreaPanelMoveStart = false;
}
//---------------------------------------------------------------------------
void __fastcall TProtectionAreaManagerForm::AreaPanelMouseMove(TObject *Sender, TShiftState Shift,
		  int X, int Y)
{
	if(bAreaPanelMoveStart)
	{
		int dx = X-MoveX;
		int dy = Y-MoveY;
		if(SizeWhich==1)
		{
			AreaPanel->Left += dx;
            AreaPanel->Width -= dx;
			return;
		}
		if(SizeWhich==2)
		{
			AreaPanel->Width += dx;
			MoveX = X;
			return;
		}
		if(SizeWhich==3)
		{
			AreaPanel->Top += dy;
			AreaPanel->Height -= dy;
			return;
		}
		if(SizeWhich==4)
		{
			AreaPanel->Height += dy;
            MoveY = Y;
			return;
		}
		AreaPanel->Left += dx;
		AreaPanel->Top += dy;
		return;
	}

	int gap = 5;
	SizeWhich = 0;
	if(X<gap)
	{
		AreaPanel->Cursor = crSizeWE;
		SizeWhich = 1;
	}
	if(X>AreaPanel->Width-gap)
	{
		AreaPanel->Cursor = crSizeWE;
		SizeWhich = 2;
	}
	if(Y<gap)
	{
		AreaPanel->Cursor = crSizeNS;
		SizeWhich = 3;
	}
	if(Y>AreaPanel->Height-gap)
	{
		AreaPanel->Cursor = crSizeNS;
		SizeWhich = 4;
	}
	if(SizeWhich==0)
	{
		AreaPanel->Cursor = crSizeAll;

    }
}
//---------------------------------------------------------------------------
void __fastcall TProtectionAreaManagerForm::MenuClearAllAreasClick(TObject *Sender)

{
	gProtArea.clear();
	Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TProtectionAreaManagerForm::MenuPlaceAreaClick(TObject *Sender)
{
//
	RECT r;
	r.left = AreaPanel->Left;
	r.top = AreaPanel->Top;
	r.right = AreaPanel->Left+AreaPanel->Width;
	r.bottom = AreaPanel->Top+AreaPanel->Height;
	gProtArea.push_back(r);

	Refresh();

}
//---------------------------------------------------------------------------
void __fastcall TProtectionAreaManagerForm::FormPaint(TObject *Sender)
{
	Canvas->Pen->Width = 5;
	Canvas->Pen->Color = clRed;
	Canvas->Brush->Style = bsClear;

	std::list<RECT>::iterator it = gProtArea.begin();
	while(it!=gProtArea.end())
	{
		RECT r = *it;
		Canvas->Rectangle(r.left,r.top,r.right,r.bottom);
		it++;
	}
}
//---------------------------------------------------------------------------
void __fastcall TProtectionAreaManagerForm::MenuDeleteLastAreaClick(TObject *Sender)

{
	if(gProtArea.size()==0) return;

	gProtArea.pop_back();
	Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TProtectionAreaManagerForm::MenuSaveAreaToFileClick(TObject *Sender)
{
	bool r = SaveDialog->Execute();
	if(r==false) return;
	AnsiString filename = SaveDialog->FileName;


	FILE *fp = fopen(filename.c_str(),"w");
	fprintf(fp,"window %d,%d,%d,%d\n",Left,Top,Width,Height);

	std::list<RECT>::iterator it = gProtArea.begin();
	while(it!=gProtArea.end())
	{
		RECT r = *it;
		fprintf(fp,"%d,%d,%d,%d\n",r.left,r.top,r.right,r.bottom);
		it++;
	}
	fclose(fp);

}
//---------------------------------------------------------------------------
void __fastcall TProtectionAreaManagerForm::MenuLoadAreaFromFileClick(TObject *Sender)

{
	bool r = OpenDialog->Execute();
	if(r==false) return;
	AnsiString filename = OpenDialog->FileName;


	FILE *fp = fopen(filename.c_str(),"r");

	gProtArea.clear();

	std::list<RECT>::iterator it = gProtArea.begin();

	int left,top,right,bottom;
	bool flag = false;
	while(true)
	{
		int a = fscanf(fp,"window %d,%d,%d,%d\n",&left,&top,&right,&bottom);
		if(a==4 && flag==false)
		{
			Left = left;
			Top = top;
			Width = right;
			Height = bottom;
			flag = true;
        }
		a = fscanf(fp,"%d,%d,%d,%d\n",&left,&top,&right,&bottom);
		if(a!=4)
		{
			break;
		}
		RECT r;
		r.left = left;
		r.top = top;
		r.right = right;
		r.bottom = bottom;
		gProtArea.push_back(r);
	}

	fclose(fp);

	if(Visible==false)
	{
        Visible = true;
    }

	Refresh();

}
//---------------------------------------------------------------------------
void __fastcall TProtectionAreaManagerForm::MenuDeleteOverlappedAreaClick(TObject *Sender)

{
	RECT r;
	r.left = AreaPanel->Left;
	r.top = AreaPanel->Top;
	r.right = AreaPanel->Left+AreaPanel->Width;
	r.bottom = AreaPanel->Top+AreaPanel->Height;


	std::list<RECT>::iterator it = gProtArea.begin();

	while(it!=gProtArea.end())
	{
		RECT &r2 = *it;
		if(r2.right<r.left)
		{
			it++;
			continue;
		}
		if(r2.left>r.right)
		{
			it++;
			continue;
		}
		if(r2.top>r.bottom)
		{
			it++;
			continue;
		}
		if(r2.bottom<r.top)
		{
			it++;
			continue;
		}

		gProtArea.erase(it);

		it++;
	}
    Refresh();

}
//---------------------------------------------------------------------------
void __fastcall TProtectionAreaManagerForm::MenuClearAndCloseWindowClick(TObject *Sender)

{
	gProtArea.clear();
	Hide();
}
//---------------------------------------------------------------------------
