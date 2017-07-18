//---------------------------------------------------------------------------

#ifndef TTSManagerFormUnitH
#define TTSManagerFormUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
#include "SpeechLib_OCX.h"
#include "SpeechLib_TLB.h"

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
	TButton *btnSaveToFile;
	TButton *btnLoadFromFile;
	TEdit *stBar;
	TOpenDialog *OpenDialog;
	TSaveDialog *SaveDialog;
	TButton *btnStop;
	TCheckBox *cbRepeat;
	TButton *btnHide;
	TButton *btnClose;
	void __fastcall btnTTSTestClick(TObject *Sender);
	void __fastcall btnPlayMemoClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btnTTSTagManualClick(TObject *Sender);
	void __fastcall edKeyKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall edKeyKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall edKeyMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall btnSaveToFileClick(TObject *Sender);
	void __fastcall btnLoadFromFileClick(TObject *Sender);
	void __fastcall btnStopClick(TObject *Sender);
	void __fastcall btnCloseClick(TObject *Sender);
	void __fastcall btnHideClick(TObject *Sender);
private:	// User declarations
	Speechlib_tlb::TSpVoice *SpVoice1;
    String OpenFileName;
	String SpeakString;
	TObject *MouseClickObject;

	void ReleaseVoiceModule();
	void PrepareVoiceModule();


	void __fastcall OnVoiceEndStream(System::TObject * Sender,long StreamNumber,VARIANT StreamPosition);
	void __fastcall OnVoiceSentence(System::TObject * Sender,long StreamNumber/*[in]*/,
		VARIANT StreamPosition/*[in]*/,long CharacterPosition/*[in]*/,long Length/*[in]*/);
	void __fastcall  OnWord(System::TObject * Sender,
												   long StreamNumber/*[in]*/,
												   VARIANT StreamPosition/*[in]*/,
												   long CharacterPosition/*[in]*/,
												   long Length/*[in]*/);

public:		// User declarations
	void SaveEnv();
	void LoadEnv();

	void SaveToFile(String filename);
	void LoadFromFile(String filename);

	bool Enabled();
	String GetKey();
	void Play();
	void Stop();
	void Speak();

	__fastcall TTTSManagerForm(TComponent* Owner);
};

TTTSManagerForm * CreateNewTTSForm();
void SendKeyToTTS(String key);
void StopAllTTS();

//---------------------------------------------------------------------------
extern PACKAGE TTTSManagerForm *TTSManagerForm;
//---------------------------------------------------------------------------
#endif
