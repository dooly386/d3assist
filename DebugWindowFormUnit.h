//---------------------------------------------------------------------------

#ifndef DebugWindowFormUnitH
#define DebugWindowFormUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TDebugWindowForm : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TPanel *Panel1;
	TCheckBox *cbKbdEvent;
	TCheckBox *cbMouseEvent;
private:	// User declarations
public:		// User declarations
	__fastcall TDebugWindowForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDebugWindowForm *DebugWindowForm;
//---------------------------------------------------------------------------
#endif
