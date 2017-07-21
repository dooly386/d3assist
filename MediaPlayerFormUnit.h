//---------------------------------------------------------------------------

#ifndef MediaPlayerFormUnitH
#define MediaPlayerFormUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.MPlayer.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMediaPlayerForm : public TForm
{
__published:	// IDE-managed Components
	TMediaPlayer *MediaPlayer1;
	TPanel *Panel1;
	TButton *Button1;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMediaPlayerForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMediaPlayerForm *MediaPlayerForm;
//---------------------------------------------------------------------------
TMediaPlayerForm * CreateMediaPlayerForm(TComponent *owner);
#endif
