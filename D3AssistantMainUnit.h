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
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
//---------------------------------------------------------------------------
#include <KeyRows.h>
#include <Vcl.MPlayer.hpp>
#include <string>
#include <list>

class TD3AssistantMainForm : public TForm
{
__published:	// IDE-managed Components
	TSaveDialog *SaveDialog;
	TOpenDialog *OpenDialog;
	TTimer *Timer1;
	TTimer *Timer2;
	TTimer *Timer3;
	TTimer *Timer4;
	TTimer *Timer5;
	TTimer *Timer6;
	TTimer *Timer7;
	TTimer *Timer8;
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
	TLabel *Label4;
	TLabel *Label5;
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
	TPopupMenu *PopupMenu1;
	TMenuItem *DeleteRecentlyFileMenu;
	TCheckBox *cbMinimizeWhenStart;
	TMenuItem *DeleteAllRecentlyFileMenu;
	TLabel *Label13;
	TMenuItem *P1;
	TMenuItem *MenuOpenProtectionAreaManager;
	TMenuItem *N5;
	TMenuItem *MenuLoadFromAreaFile;
	TEdit *edImmediatelyKey;
	TEdit *edImmediatelyDelay;
	TLabel *Label14;
	TEdit *edImmediatelyActive;
	TTimer *TimerImmediately;
	TPanel *Panel1;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *edStart;
	TEdit *edStop;
	TButton *btnSave;
	TButton *btnLoad;
	TPanel *StatusPanel;
	TListBox *lbRecentlyFiles;
	TListBox *lbRecentlyFilesFullPath;
	TMenuItem *T1;
	TMenuItem *MenuOpenTTSManager;
	TCheckBox *cbDoNotStart;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *SkinsMenuGroup;
	TMenuItem *MenuSkinDefault;
	TMenuItem *MenuGroupAddOn;
	TTimer *RecordPlayTimer;
	TOpenDialog *OpenDialogMacro;
	TSaveDialog *SaveDialogMacro;
	TMenuItem *MenuDebugWindow;
	TEdit *edInit1;
	TEdit *edInit2;
	TEdit *edInit3;
	TEdit *edInit4;
	TEdit *edInit5;
	TEdit *edInit6;
	TEdit *edInit7;
	TEdit *edInit8;
	TCheckBox *cbMultiKey;
	TTabSheet *TabSheetSequenceKey;
	TLabel *Label3;
	TCheckBox *cbMultiKeyAndMode;
	TLabel *Label7;
	TMenuItem *N8;
	TMenuItem *MenuGroupMediaPlayer;
	TMenuItem *N9;
	TTimer *TimerYoloCursor;
	TTabSheet *YoloControlTabSheet;
	TButton *btnStartYoloMouse;
	TEdit *edCurGrp1;
	TEdit *edCurGrp2;
	TEdit *edCurGrp3;
	TEdit *edCurGrp4;
	TEdit *edCurGrp5;
	TEdit *edCurGrp6;
	TEdit *edCurGrp7;
	TEdit *edCurGrp8;
	TEdit *edYoloName1;
	TEdit *edYoloName2;
	TEdit *edYoloName3;
	TEdit *edYoloName4;
	TEdit *edYoloName5;
	TEdit *edYoloName6;
	TEdit *edYoloName7;
	TEdit *edYoloName8;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TEdit *edYoloLoopInterval;
	TLabel *Label21;
	TEdit *edYoloLoopStart;
	TLabel *Label22;
	TEdit *edYoloLoopStop;
	TLabel *Label23;
	TEdit *edCurId1;
	TEdit *edCurId2;
	TEdit *edCurId3;
	TEdit *edCurId4;
	TEdit *edCurId5;
	TEdit *edCurId6;
	TEdit *edCurId7;
	TEdit *edCurId8;
	TLabel *Label16;
	TEdit *edSpeech1;
	TEdit *edSpeech2;
	TEdit *edSpeech3;
	TEdit *edSpeech4;
	TEdit *edSpeech5;
	TEdit *edSpeech6;
	TEdit *edSpeech7;
	TEdit *edSpeech8;
	TMediaPlayer *mpYolo1;
	TMediaPlayer *mpYolo2;
	TMediaPlayer *mpYolo3;
	TMediaPlayer *mpYolo4;
	TMediaPlayer *mpYolo5;
	TMediaPlayer *mpYolo6;
	TMediaPlayer *mpYolo7;
	TMediaPlayer *mpYolo8;
	TCheckBox *cbAudioWhenStartStop;
	TEdit *edWaveNameStart;
	TEdit *edWaveNameStop;
	TMediaPlayer *mpStart;
	TMediaPlayer *mpStop;
	TLabel *Label17;
	TEdit *edKeyMouseModifier;
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
	void __fastcall MenuOpenProtectionAreaManagerClick(TObject *Sender);
	void __fastcall MenuLoadFromAreaFileClick(TObject *Sender);
	void __fastcall TimerImmediatelyTimer(TObject *Sender);
	void __fastcall MenuOpenTTSManagerClick(TObject *Sender);
	void __fastcall MenuSkinDefaultClick(TObject *Sender);
	void __fastcall MenuDebugWindowClick(TObject *Sender);
	void __fastcall N9Click(TObject *Sender);
	void __fastcall TimerYoloCursorTimer(TObject *Sender);
	void __fastcall edCurGrp1KeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall mpYolo1Click(TObject *Sender, TMPBtnType Button, bool &DoDefault);
	void __fastcall edYoloName1Change(TObject *Sender);
	void __fastcall mpStartClick(TObject *Sender, TMPBtnType Button, bool &DoDefault);
	void __fastcall mpStopClick(TObject *Sender, TMPBtnType Button, bool &DoDefault);
	void __fastcall cbAudioWhenStartStopClick(TObject *Sender);






private:	// User declarations
	bool bModified;
	String OpenFileName;
	std::list<DWORD> editlist;
	HWND targetHwnd;
	TObject *MouseClickObject;
	bool bPause;
	bool bProtWindowFlag;
	bool bLoading;
	int  iForceMode;
	String SkinName;
	int CurrentPlayCount;
	std::map<String,int> keyState;  //0 up, 1 down
    int sleepsec;

	BEGIN_MESSAGE_MAP
	MESSAGE_HANDLER(CM_DIALOGKEY, TMessage, CMDialogKey)
	MESSAGE_HANDLER(WM_ACTIVATEAPP, TWMActivate, WMActivate);
	END_MESSAGE_MAP(TForm);

	void __fastcall CMDialogKey(TMessage &a);
	void __fastcall WMActivate(TWMActivate &Message);

	void LoadEnv();
    void SaveEnv();

	void SaveIni(String filename);
	void LoadIni(String filename);

	void Start();
	void Stop();

	void setBlend();
	void enableRecord(int i);
	void disableRecord(int i);
	void enableEditAll();
	void disableEditAll();

	void PrepareKeyRows();

	void UpdateRecentlyFile(String filename);
	void UpdateRecentlyLb();

	void ProcessMouseDown(String key);
	void ProcessMouseUp(String key);

	bool StartImmediately(String key);
	void StopImmediately(String key);


	int GetActiveKeyState(keyRow &row); // 0 up, 1 down, -1 no key assign
	int GetPauseKeyState(keyRow &row); // 0 up, 1 down, -1 no key assign



	bool IsForegroundWindow(HWND hwnd);

	void StartHook();
	void StopHook();

	void SendToAppKey(keyRow &row,String &key,int opt=0); // opt=0 click, 1=down,2=up

	void StartYoloCycle();
	void StopYoloCycle();
	bool LoadMediaIfExist(TMediaPlayer *mp,String filename);
	void PlayStartMp();
	void PlayStopMp();

	DWORD GetYoloTargetProcessId();
	void CloseAllMedia();
	bool IsUsedMediaFile(String filename);

public:		// User declarations
	bool bStarted;
	bool bRecordStarted;
	bool bPlayStarted;

	void checkColor();


	void PushDownKey(int vcode,int scancode);
	void PushUpKey(int vcode,int scancode);

	void PressKey(int vcode,int scancode);

	void KeyDown(String key);
	void KeyUp(String key);



	void MouseDown(TMouseButton button);
	void MouseUp(TMouseButton button);
	void MouseClick(TMouseButton button);
	void MouseDown(String key);
	void MouseUp(String key);


	void MouseDownX(int btn);
	void MouseUpX(int btn);

	void MouseWheel(int delta);



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
