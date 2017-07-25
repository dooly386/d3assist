//---------------------------------------------------------------------------

#ifndef SimplifyUIFormUnitH
#define SimplifyUIFormUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TSimplifyUIForm : public TForm
{
__published:	// IDE-managed Components
	TPopupMenu *PopupMenu1;
	TMenuItem *menuRestore;
	TEdit *edKey1;
	TEdit *edKey2;
	TEdit *edKey3;
	TEdit *edKey4;
	TEdit *edKey5;
	TEdit *edKey6;
	TEdit *edKey7;
	TEdit *edKey8;
	void __fastcall menuRestoreClick(TObject *Sender);
	void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);

private:	// User declarations
	bool bMoveStart;
	int MoveX;
	int MoveY;
public:		// User declarations
	__fastcall TSimplifyUIForm(TComponent* Owner);

	void checkColor();
};
//---------------------------------------------------------------------------
extern PACKAGE TSimplifyUIForm *SimplifyUIForm;
//---------------------------------------------------------------------------
#endif
