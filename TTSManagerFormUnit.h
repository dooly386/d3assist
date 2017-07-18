//---------------------------------------------------------------------------

#ifndef TTSManagerFormUnitH
#define TTSManagerFormUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TTTSManagerForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *edTTSTest;
	TButton *btnTTSTest;
	TMemo *moTTS;
	TButton *btnPlayMemo;
	TEdit *edKey;
	TLabel *Label2;
	TCheckBox *cbEnable;
	TButton *btnTTSTagManual;
	void __fastcall btnTTSTestClick(TObject *Sender);
	void __fastcall btnPlayMemoClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btnTTSTagManualClick(TObject *Sender);
	void __fastcall edKeyKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall edKeyKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall edKeyMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
private:	// User declarations
	TObject *MouseClickObject;
public:		// User declarations
	void SaveEnv();
	void LoadEnv();

	bool Enabled();
	String GetKey();
	void Play();

	__fastcall TTTSManagerForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTTSManagerForm *TTSManagerForm;
//---------------------------------------------------------------------------
#endif
