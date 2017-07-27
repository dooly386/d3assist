//---------------------------------------------------------------------------

#ifndef ProtectionAreaManagerFormUnitH
#define ProtectionAreaManagerFormUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TProtectionAreaManagerForm : public TForm
{
__published:	// IDE-managed Components
	TPopupMenu *MainPopupMenu;
	TMenuItem *MenuFitToBackWindow;
	TMenuItem *MenuMaximizeWindow;
	TMenuItem *MenuRestoreWindow;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *MenuCloseWindow;
	TMenuItem *N3;
	TMenuItem *I1;
	TMenuItem *D1;
	TPanel *AreaPanel;
	TPopupMenu *PanelPopupMenu;
	TMenuItem *MenuPlaceArea;
	TMenuItem *MenuClearAllAreas;
	TMenuItem *N4;
	TMenuItem *MenuDeleteLastArea;
	TOpenDialog *OpenDialog;
	TSaveDialog *SaveDialog;
	TMenuItem *N5;
	TMenuItem *MenuLoadAreaFromFile;
	TMenuItem *MenuSaveAreaToFile;
	TMenuItem *MenuDeleteOverlappedArea;
	TMenuItem *MenuLoadFromAreaFile;
	TMenuItem *N6;
	TMenuItem *MenuSaveToAreaFile;
	TMenuItem *MenuClearAndCloseWindow;
	TStatusBar *stBar;
	TCheckBox *cbEnableWithPrgStart;
	void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall MenuMaximizeWindowClick(TObject *Sender);
	void __fastcall MenuRestoreWindowClick(TObject *Sender);
	void __fastcall MenuCloseWindowClick(TObject *Sender);
	void __fastcall MenuFitToBackWindowClick(TObject *Sender);
	void __fastcall I1Click(TObject *Sender);
	void __fastcall D1Click(TObject *Sender);
	void __fastcall AreaPanelMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall AreaPanelMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall AreaPanelMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall MenuClearAllAreasClick(TObject *Sender);
	void __fastcall MenuPlaceAreaClick(TObject *Sender);
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall MenuDeleteLastAreaClick(TObject *Sender);
	void __fastcall MenuSaveAreaToFileClick(TObject *Sender);
	void __fastcall MenuLoadAreaFromFileClick(TObject *Sender);
	void __fastcall MenuDeleteOverlappedAreaClick(TObject *Sender);
	void __fastcall MenuClearAndCloseWindowClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);




private:	// User declarations
	bool bMoveStart;
	bool bAreaPanelMoveStart;
	int SizeWhich;
	int MoveX;
	int MoveY;
public:		// User declarations
	String OpenFileName;

	__fastcall TProtectionAreaManagerForm(TComponent* Owner);
	void LoadFromFile(AnsiString filename);
	void InitForm();
};
void InitProtectionAreaManagerForm();
//---------------------------------------------------------------------------
extern PACKAGE TProtectionAreaManagerForm *ProtectionAreaManagerForm;
//---------------------------------------------------------------------------
#endif
