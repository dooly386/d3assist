//---------------------------------------------------------------------------

#ifndef D3AssistantMainUnitH
#define D3AssistantMainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
//---------------------------------------------------------------------------
#include <string>
#include <list>

class TD3AssistantMainForm : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *edStart;
	TEdit *edStop;
	TMemo *Memo1;
	TSaveDialog *SaveDialog;
	TButton *btnSave;
	TButton *btnLoad;
	TOpenDialog *OpenDialog;
	TTimer *Timer1;
	TTimer *Timer2;
	TTimer *Timer3;
	TTimer *Timer4;
	TTimer *Timer5;
	TTimer *Timer6;
	TTimer *Timer7;
	TTimer *Timer8;
	TPanel *StatusPanel;
	TMainMenu *MainMenu;
	TMenuItem *F1;
	TMenuItem *menuNew;
	TMenuItem *menuOpen;
	TMenuItem *menuSave;
	TMenuItem *menuSaveAs;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *menuClose;
	TMenuItem *H1;
	TMenuItem *MenuHelp;
	TMenuItem *MenuHomePage;
	TMenuItem *MenuCheckUpdate;
	TMenuItem *N1;
	TMenuItem *MenuAboutDlg;
	TMenuItem *MenuReleaseNote;
	TStatusBar *stBar;
	TMenuItem *Y1;
	TMenuItem *StartYoloMouseMenu;
	TMenuItem *StopYoloMouseMenu;
	TMenuItem *YoloMouseHomePageMenu;
	TMenuItem *N4;
	TMenuItem *MenuSetYoloMouseTargetProcess;
	TPageControl *PageControl;
	TTabSheet *KeySettingTabSheet;
	TTabSheet *EnvironmentTabSheet;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label7;
	TEdit *edActive1;
	TEdit *edPause1;
	TEdit *edDelay1;
	TEdit *edKey1;
	TEdit *edKey2;
	TEdit *edDelay2;
	TEdit *edPause2;
	TEdit *edActive2;
	TEdit *edActive3;
	TEdit *edPause3;
	TEdit *edDelay3;
	TEdit *edKey3;
	TEdit *edKey4;
	TEdit *edKey5;
	TEdit *edKey6;
	TEdit *edKey7;
	TEdit *edKey8;
	TEdit *edDelay8;
	TEdit *edDelay7;
	TEdit *edDelay6;
	TEdit *edDelay5;
	TEdit *edDelay4;
	TEdit *edPause4;
	TEdit *edPause5;
	TEdit *edPause6;
	TEdit *edPause7;
	TEdit *edPause8;
	TEdit *edActive8;
	TEdit *edActive7;
	TEdit *edActive6;
	TEdit *edActive5;
	TEdit *edActive4;
	TLabel *Label8;
	TTabSheet *TabSheet1;
	TCheckBox *cbStayOnTop;
	TCheckBox *cbOnlyD3;
	TEdit *edOnlyWindow;
	TEdit *edAlphaValue;
	TLabel *Label6;
	TEdit *edStopName1;
	TEdit *edStopKey1;
	TLabel *Label9;
	TLabel *Label10;
	TEdit *edStopName2;
	TEdit *edStopKey2;
	TEdit *edStopName3;
	TEdit *edStopKey3;
	TEdit *edStopName4;
	TEdit *edStopKey4;
	TEdit *edStopName5;
	TEdit *edStopKey5;
	TEdit *edStopName6;
	TEdit *edStopKey6;
	TEdit *edStopName7;
	TEdit *edStopKey7;
	TEdit *edStopName8;
	TEdit *edStopKey8;
	TLabel *Label11;
	TLabel *Label12;
	TEdit *edStopKey9;
	TEdit *edStopName9;
	TEdit *edStopName10;
	TEdit *edStopKey10;
	TEdit *edStopKey11;
	TEdit *edStopName11;
	TEdit *edStopName12;
	TEdit *edStopKey12;
	TEdit *edStopKey13;
	TEdit *edStopName13;
	TEdit *edStopName14;
	TEdit *edStopKey14;
	TEdit *edStopKey15;
	TEdit *edStopName15;
	TEdit *edStopName16;
	TEdit *edStopKey16;
	TLabel *Label15;
	TCheckBox *cbToggle1;
	TCheckBox *cbToggle2;
	TCheckBox *cbToggle3;
	TCheckBox *cbToggle4;
	TCheckBox *cbToggle5;
	TCheckBox *cbToggle6;
	TCheckBox *cbToggle7;
	TCheckBox *cbToggle8;
	TListBox *lbRecentlyFiles;
	TListBox *lbRecentlyFilesFullPath;
	TPopupMenu *PopupMenu1;
	TMenuItem *DeleteRecentlyFileMenu;
	TCheckBox *cbCheckUpdateOnStart;
	TIdHTTP *IdHTTP;
	TMenuItem *DeleteAllRecentlyFileMenu;
	void __fastcall edStartKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall edStartKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall edKey1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall edStartContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled);
	void __fastcall btnSaveClick(TObject *Sender);
	void __fastcall btnLoadClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall cbStayOnTopClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall menuSaveAsClick(TObject *Sender);
	void __fastcall menuNewClick(TObject *Sender);
	void __fastcall edDelay1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall MenuAboutDlgClick(TObject *Sender);
	void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled);
	void __fastcall MenuHelpClick(TObject *Sender);
	void __fastcall MenuHomePageClick(TObject *Sender);
	void __fastcall MenuReleaseNoteClick(TObject *Sender);
	void __fastcall YoloMouseHomePageMenuClick(TObject *Sender);
	void __fastcall StartYoloMouseMenuClick(TObject *Sender);
	void __fastcall StopYoloMouseMenuClick(TObject *Sender);
	void __fastcall MenuSetYoloMouseTargetProcessClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall PageControlChange(TObject *Sender);
	void __fastcall lbRecentlyFilesDblClick(TObject *Sender);
	void __fastcall DeleteRecentlyFileMenuClick(TObject *Sender);
	void __fastcall edStartChange(TObject *Sender);
	void __fastcall cbToggle1Click(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall MenuCheckUpdateClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DeleteAllRecentlyFileMenuClick(TObject *Sender);
	void __fastcall edStopName1Change(TObject *Sender);
	void __fastcall edKey1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);


private:	// User declarations
	bool bModified;
	String OpenFileName;
	bool bStarted;
	std::list<DWORD> editlist;
	HWND targetHwnd;
	TObject *MouseClickObject;
	bool bPause;



	BEGIN_MESSAGE_MAP
	MESSAGE_HANDLER(CM_DIALOGKEY, TMessage, CMDialogKey)
	MESSAGE_HANDLER(WM_ACTIVATEAPP, TWMActivate, WMActivate);
	END_MESSAGE_MAP(TForm);

	void __fastcall CMDialogKey(TMessage &a);
	void __fastcall WMActivate(TWMActivate &Message);

	void SaveIni(String filename);
	void LoadIni(String filename);

	void Start();
	void Stop();

	void setBlend();
	void enableRecord(int i);
	void disableRecord(int i);
	void enableEditAll();
	void disableEditAll();

	void prepareKeyRows();

	void UpdateRecentlyFile(String filename);
	void UpdateRecentlyLb();

	void ProcessMouseDown(String key);
	void ProcessMouseUp(String key);



public:		// User declarations
	void checkColor();

	void PushDownKey(int vcode,int scancode);
	void PushUpKey(int vcode,int scancode);

	void PressKey(int vcode,int scancode);

	void MouseDown(TMouseButton button);
	void MouseUp(TMouseButton button);
	void MouseClick(TMouseButton button);


	void OnKeyDownHook(String key);
	void OnKeyUpHook(String key);

	void OnMouseXButtonDown(int btn);
	void OnMouseXButtonUp(int btn);


	void OnMouseDownHook(int b,WPARAM wParam,LPARAM lParam);
	void OnMouseUpHook(int b,WPARAM wParam,LPARAM lParam);

	bool OnMouseWheelHook(int delta);


	__fastcall TD3AssistantMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TD3AssistantMainForm *D3AssistantMainForm;
//---------------------------------------------------------------------------
#endif
