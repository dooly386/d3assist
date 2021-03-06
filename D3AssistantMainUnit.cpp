//---------------------------------------------------------------------------
/*
	Programmed by DoYoung Kang
	dooly386@gmail.com
	Copyright(c) dooly386@gmail.com
	2017.7.17
*/
#include <map>
#include <set>
#include <stdio.h>
#include <vcl.h>
#include <IniFiles.hpp>
#include <Tlhelp32.h>
#include <Vcl.MPlayer.hpp>
#include <Vcl.ExtCtrls.hpp>
#pragma hdrstop

#include "D3AssistantMainUnit.h"
#include "UtilFunctions.h"
#include "ABOUT.h"
#include "CallbackFunctions.h"
#include "KeyRows.h"
#include "ProtectionAreaManagerFormUnit.h"
#include "SpeechLib_TLB.h"
#include "SpeechLib_OCX.h"
#include "TTSManagerFormUnit.h"
#include "DebugWindowFormUnit.h"
#include "MediaPlayerFormUnit.h"
#include "SimplifyUIFormUnit.h"
#include "MLTS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TD3AssistantMainForm *D3AssistantMainForm;
//---------------------------------------------------------------------------

//HKEY_CURRENT_USER\Control Panel\Desktop\LowLevelHooksTimeout

extern std::map<String,int> keyState;  //0 up, 1 down
std::list<evtq> eventq;
extern bool bUseSendQueue;
double StopwatchTime = 0;





HHOOK g_hKeyHook=0;
HHOOK g_hMouseHook=0;
String gSelectedLanguage="English";


__fastcall TD3AssistantMainForm::TD3AssistantMainForm(TComponent* Owner)
	: TForm(Owner)
{
	bModified = false;
	bPause = false;
	targetHwnd = 0;
	OpenFileName = "";
	bStarted = false;
	MouseClickObject = 0;
	bLoading = false;
	bRecordStarted = false;
	bPlayStarted = false;
	sleepsec = 0;


	for(int i=0;i<ComponentCount;i++)
	{
		TComponent *comp = (TComponent *)Components[i];
		if(comp->ClassNameIs("TEdit") && (comp->Tag==1 || comp->Tag==2))
		{
			editlist.push_back((DWORD)comp);
		}

		if(comp->ClassNameIs("TMediaPlayer"))
		{
			TMediaPlayer *mp = (TMediaPlayer *)comp;
			mp->Shareable = false;
		}

		compMap[comp->Name] = comp;
	}

	//--------------------------------------------------------------------------
	PrepareKeyRows();
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	// set version caption
	String ver = GetFileVersionString(Application->ExeName);
	Caption = String("D3Assist v")+ver;

#ifdef _WIN64
	Caption = Caption + " x64";
#else
	Caption = Caption + " win32";
#endif
	//--------------------------------------------------------------------------


	PageControl->TabIndex = 0;

	InitProtectionAreaManagerForm();


	LoadEnv();
	UpdateRecentlyLb();
	StartHook();


	{
		std::list<String> files;
		GetAllFileNames(GetInstallPath()+"styles2\\*.vsf",files);

		std::list<String>::iterator it = files.begin();
		while(it!=files.end())
		{
			TMenuItem *p = new TMenuItem(this);
			p->OnClick = MenuSkinDefault->OnClick;
			p->Caption = *it;
			SkinsMenuGroup->Add(p);
			it++;
		}
	}

	{
		std::list<String> files;
		GetAllFileNames(GetInstallPath()+"lang\\*.ini",files);

		std::list<String>::iterator it = files.begin();
		while(it!=files.end())
		{
			TMenuItem *p = new TMenuItem(this);
			p->OnClick = menuLanguage->OnClick;
			p->Caption = *it;
			MenuGroupLanguage->Add(p);
			it++;
		}
	}





	DisableVclStyles(this,"TEdit");

	SetSkin(SkinName);

	String langfilename = GetInstallPath()+"lang\\"+gSelectedLanguage+".ini";
	InitMLTS(langfilename);
	ApplyMLTS(this);


	if(cbStartWithAssist->Checked)
	{
		StartYoloMouseMenuClick(0);
	}


}



void TD3AssistantMainForm::CloseAllMedia()
{
	for(int i=0;i<ComponentCount;i++)
	{
		TComponent *comp = (TComponent *)Components[i];
		if(comp->ClassNameIs("TMediaPlayer"))
		{
			TMediaPlayer *mp = (TMediaPlayer *)comp;
			if(mp->Mode==mpOpen)
			{
				mp->Close();
                mp->FileName = "";
			}
		}
	}


}

bool TD3AssistantMainForm::IsUsedMediaFile(String filename)
{
	for(int i=0;i<ComponentCount;i++)
	{
		TComponent *comp = (TComponent *)Components[i];
		if(comp->ClassNameIs("TMediaPlayer"))
		{
			TMediaPlayer *mp = (TMediaPlayer *)comp;
			if(mp->FileName==filename) return true;
		}
	}
	return false;
}

void TD3AssistantMainForm::StartHook()
{
	if(g_hKeyHook) return;
	//--------------------------------------------------------------------------
	// start hook keyboard and mouse
	HINSTANCE app = GetModuleHandle(NULL);
	g_hKeyHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, app, 0);
	g_hMouseHook = SetWindowsHookEx(WH_MOUSE_LL, LowLevelMouseProc, app, 0);


	//--------------------------------------------------------------------------

}

void TD3AssistantMainForm::StopHook()
{
	if(g_hKeyHook)
	{
		UnhookWindowsHookEx(g_hKeyHook);
	}
	if(g_hMouseHook)
	{
		UnhookWindowsHookEx(g_hMouseHook);
	}
	g_hKeyHook = 0;
	g_hMouseHook = 0;
}



void TD3AssistantMainForm::LoadEnv()
{
	//--------------------------------------------------------------------------
	CloseAllMedia();
	//--------------------------------------------------------------------------
	// load configuration ini
	String filename = ChangeFileExt(Application->ExeName,".ini");
	if(FileExists(filename))
	{
		TIniFile *ini = new TIniFile(filename);
		String openfilename = ini->ReadString("Setup","OpenFileName","");

		if(ini->ValueExists("Setup","AlphaValue"))
		{
			edAlphaValue->Text = ini->ReadString("Setup","AlphaValue","255");

		}
		if(edAlphaValue->Text.Length()==0)
		{
			edAlphaValue->Text = 255;
		}

		if(ini->ValueExists("Setup","OnlyD3"))
		{
			cbOnlyD3->Checked = ini->ReadBool("Setup","OnlyD3",false);

		}
		if(ini->ValueExists("Setup","OnlyWindowCaption"))
		{
			edOnlyWindow->Text = ini->ReadString("Setup","OnlyWindowCaption","��ƺ��� III");
		}
		if(ini->ValueExists("Setup","MinimizeWhenStart"))
		{
			cbMinimizeWhenStart->Checked = ini->ReadBool("Setup","MinimizeWhenStart",false);
		}
		if(ini->ValueExists("Setup","SkinName"))
		{
			SkinName = ini->ReadString("Setup","SkinName","Windows");
		}
		cbAudioWhenStartStop->Checked = ini->ReadBool("Setup","cbAudioWhenStartStop",false);
		edWaveNameStart->Text = ini->ReadString("Setup","edWaveNameStart","");
		edWaveNameStop->Text = ini->ReadString("Setup","edWaveNameStop","");

		{
			String mediafilename = GetYoloMediaFileByName(edWaveNameStart->Text);
			if(LoadMediaIfExist(mpStart,mediafilename) && IsUsedMediaFile(mediafilename)==false)
			{

				mpStart->FileName = mediafilename;
				mpStart->Open();
			}
		}

		{
			String mediafilename = GetYoloMediaFileByName(edWaveNameStop->Text);
			if(LoadMediaIfExist(mpStop,mediafilename) && IsUsedMediaFile(mediafilename)==false)
			{
				mpStop->FileName = mediafilename;
				mpStop->Open();
			}
		}

		if(ini->ValueExists("Setup","Left"))
		{
			Left = ini->ReadInteger("Setup","Left",Left);
			Top = ini->ReadInteger("Setup","Top",Top);
			Width = ini->ReadInteger("Setup","Width",Width);
			Height = ini->ReadInteger("Setup","Height",Height);
		}
		bool b = false;
		for(int i=0;i<Screen->MonitorCount;i++)
		{
			if(Screen->Monitors[i]->BoundsRect.PtInRect(TPoint(Left,Top)))
			{
				b = true;
			}
		}
		if(b==false)
		{
			Left = 0;
            Top = 0;
        }


        cbStayOnTop->Checked = ini->ReadBool("Setup","cbStayOnTop",false);

		edKeyMouseModifier->Text = ini->ReadString("Setup","edKeyMouseModifier","0");
		gSelectedLanguage = ini->ReadString("Setup","gSelectedLanguage",gSelectedLanguage);
		cbStartWithAssist->Checked = ini->ReadBool("Setup","cbStartWithAssist",false);

		ProtectionAreaManagerForm->cbEnableWithPrgStart->Checked = ini->ReadBool("Setup","ProtectionAreaManagerForm.cbEnableWithPrgStart",false);
		ProtectionAreaManagerForm->OpenFileName = ini->ReadString("Setup","ProtectionAreaManagerForm.OpenFileName","");
		cbMediaOnly->Checked = ini->ReadBool("Setup","cbMediaOnly",false);

		delete ini;
		LoadIni(openfilename);
	}
	//--------------------------------------------------------------------------

}
void TD3AssistantMainForm::SaveEnv()
{
	String filename = ChangeFileExt(Application->ExeName,".ini");

	TIniFile *ini = new TIniFile(filename);
	ini->WriteString("Setup","OpenFileName",OpenFileName);
	ini->WriteString("Setup","AlphaValue",edAlphaValue->Text);
	ini->WriteBool("Setup","OnlyD3",cbOnlyD3->Checked);
	ini->WriteString("Setup","OnlyWindowCaption",edOnlyWindow->Text);
	ini->WriteBool("Setup","MinimizeWhenStart",cbMinimizeWhenStart->Checked);
	ini->WriteString("Setup","SkinName",SkinName);
	ini->WriteBool("Setup","cbAudioWhenStartStop",cbAudioWhenStartStop->Checked);
	ini->WriteString("Setup","edWaveNameStart",edWaveNameStart->Text);
	ini->WriteString("Setup","edWaveNameStop",edWaveNameStop->Text);

	ini->WriteInteger("Setup","Left",Left);
	ini->WriteInteger("Setup","Top",Top);
	ini->WriteInteger("Setup","Width",Width);
	ini->WriteInteger("Setup","Height",Height);
	ini->WriteString("Setup","edKeyMouseModifier",edKeyMouseModifier->Text);
	ini->WriteBool("Setup","cbStayOnTop",cbStayOnTop->Checked);
	ini->WriteString("Setup","gSelectedLanguage",gSelectedLanguage);
	ini->WriteBool("Setup","cbStartWithAssist",cbStartWithAssist->Checked);
	ini->WriteBool("Setup","ProtectionAreaManagerForm.cbEnableWithPrgStart",ProtectionAreaManagerForm->cbEnableWithPrgStart->Checked);
	ini->WriteString("Setup","ProtectionAreaManagerForm.OpenFileName",ProtectionAreaManagerForm->OpenFileName);
	ini->WriteBool("Setup","cbMediaOnly",cbMediaOnly->Checked);
	delete ini;

}

void TD3AssistantMainForm::PrepareKeyRows()
{
	keyTimerMap.clear();
	keyPauseMap.clear();
	keyActiveMap.clear();
	keyHoldMap.clear();

	keyStopMap.clear();

	TEdit *ed;
	for(int i=0;i<8;i++)
	{
		String keyname = String("edKey")+(i+1);
		String initname = String("edInit")+(i+1);
		String delayname = String("edDelay")+(i+1);
		String poname = String("edPause")+(i+1);
		String activekey = String("edActive")+(i+1);
		String timername = String("Timer")+(i+1);
		String togglename = String("cbToggle")+(i+1);
		String descname = String("edDesc")+(i+1);

		keyRows[i].clear();

		keyRows[i].edkey = (TEdit *)FindComponent(keyname);

		keyRows[i].key = ParsingKeys(keyRows[i].edkey->Text,keyRows[i].keys,keyRows[i].keysand);


		keyRows[i].edinit = (TEdit *)FindComponent(initname);
		if(keyRows[i].edinit->Text.Length())
		{
			keyRows[i].initial = keyRows[i].edinit->Text.ToInt();
		}
		else
		{
			keyRows[i].initial = 0;
		}

		keyRows[i].eddelay = (TEdit *)FindComponent(delayname);
		if(keyRows[i].eddelay->Text.Length())
		{
			keyRows[i].interval = keyRows[i].eddelay->Text.ToInt();
			if(keyRows[i].interval<60)
			{
                keyRows[i].interval = 60;
            }
		}
		else
		{
			keyRows[i].interval = 0;
		}
		if(keyRows[i].key.Length()==0)
		{
			keyRows[i].interval = 0;
        }

		keyRows[i].edpause = (TEdit *)FindComponent(poname);
		keyRows[i].pausekey = ParsingKeys(keyRows[i].edpause->Text,keyRows[i].pausekeys,keyRows[i].pausekeysand);

		keyRows[i].edactive = (TEdit *)FindComponent(activekey);
		keyRows[i].activekey = keyRows[i].edactive->Text;
		keyRows[i].activekey = ParsingKeys(keyRows[i].edactive->Text,keyRows[i].activekeys,keyRows[i].activekeysand);

		keyRows[i].timer = (TTimer *)FindComponent(timername);

		keyRows[i].toggle = (TCheckBox *)FindComponent(togglename);
		keyRows[i].pushdown = false;

		keyRows[i].eddesc = (TEdit *)FindComponent(descname);


	}

	for(int i=0;i<16;i++)
	{
		String name = String("edStopName")+(i+1);
		String key = String("edStopKey")+(i+1);
		keyStopRows[i].edname = (TEdit *)FindComponent(name);
		keyStopRows[i].edkey = (TEdit *)FindComponent(key);
		keyStopRows[i].name = keyStopRows[i].edname->Text;
		keyStopRows[i].key = keyStopRows[i].edkey->Text;

		if(keyStopRows[i].name.Length())
		{
			keyStopRows[i].type = 0;
			char c = *keyStopRows[i].name.LastChar();
			if(c=='+')
			{
				keyStopRows[i].type = 1;
			}
			if(c=='-')
			{
				keyStopRows[i].type = 2;
			}
			if(keyStopRows[i].key.Length())
			{
				keyStopMap[keyStopRows[i].key] = keyStopRows+i;
			}
        }
	}


	for(int i=0;i<8;i++)
	{
		keyRow *row = (keyRows+i);
		keyTimerMap[row->timer] = row;
	}


}

bool TD3AssistantMainForm::IsForegroundWindow(HWND hwnd)
{
    return GetForegroundWindow()==hwnd;
}

void TD3AssistantMainForm::setBlend()
{
	if(bStarted==false)
	{
		AlphaBlend = false;
		return;
    }
	int alpha = edAlphaValue->Text.ToInt();
	if(alpha<255 && alpha>=0)
	{
		AlphaBlendValue = alpha;

		if(GetForegroundWindow()==Handle)
		{
			AlphaBlend = false;
		}
		else
		{
			AlphaBlend = true;

		}
	}
	else
	{
		AlphaBlend = false;
	}

}
void TD3AssistantMainForm::enableRecord(int i)
{
	keyRows[i].edkey->Enabled = true;
	keyRows[i].eddelay->Enabled = true;
	keyRows[i].edpause->Enabled = true;
	keyRows[i].edactive->Enabled = true;
	keyRows[i].toggle->Enabled = true;
	keyRows[i].edinit->Enabled = true;


}

void TD3AssistantMainForm::disableRecord(int i)
{
	keyRows[i].edkey->Enabled = false;
	keyRows[i].eddelay->Enabled = false;
	keyRows[i].edpause->Enabled = false;
	keyRows[i].edactive->Enabled = false;
	keyRows[i].toggle->Enabled = false;
	keyRows[i].edinit->Enabled = false;

}

void TD3AssistantMainForm::checkColor()
{
	for(int i=0;i<8;i++)
	{
		bool bold = false;
		bool italic = false;
		bool strikeout = false;

		keyRow &row = keyRows[i];
		TColor color = clWindow;
		if(row.timer->Enabled)
		{
			color = clLime;
			bold = true;
			if(row.toggle->Checked)
			{
				color = clYellow;
				italic = true;
			}
		}
		else
		{
			if(row.enabled)
			{
				color = clLtGray;
				italic = true;
				strikeout = true;
			}
		}

		if(bPause && row.enabled)
		{
			color = clLtGray;
			italic = true;
			strikeout = true;
		}

		row.edkey->Color = color;
		row.eddelay->Color = color;
		row.edpause->Color = color;
		row.edactive->Color = color;
		row.edinit->Color = color;
		row.eddesc->Color = color;

		if(bold)
		{
			row.edkey->Font->Style = row.edkey->Font->Style << fsBold;
			row.eddelay->Font->Style = row.eddelay->Font->Style << fsBold;
			row.edpause->Font->Style = row.edpause->Font->Style << fsBold;
			row.edactive->Font->Style = row.edactive->Font->Style << fsBold;
			row.edinit->Font->Style = row.edinit->Font->Style << fsBold;
			row.eddesc->Font->Style = row.eddesc->Font->Style << fsBold;
		}
		else
		{
			row.edkey->Font->Style = row.edkey->Font->Style >> fsBold;
			row.eddelay->Font->Style = row.eddelay->Font->Style >> fsBold;
			row.edpause->Font->Style = row.edpause->Font->Style >> fsBold;
			row.edactive->Font->Style = row.edactive->Font->Style >> fsBold;
			row.edinit->Font->Style = row.edinit->Font->Style >> fsBold;
			row.eddesc->Font->Style = row.eddesc->Font->Style >> fsBold;
		}
		if(italic)
		{
			row.edkey->Font->Style = row.edkey->Font->Style << fsItalic;
			row.eddelay->Font->Style = row.eddelay->Font->Style << fsItalic;
			row.edpause->Font->Style = row.edpause->Font->Style << fsItalic;
			row.edactive->Font->Style = row.edactive->Font->Style << fsItalic;
			row.edinit->Font->Style = row.edinit->Font->Style << fsItalic;
			row.eddesc->Font->Style = row.eddesc->Font->Style << fsItalic;
		}
		else
		{
			row.edkey->Font->Style = row.edkey->Font->Style >> fsItalic;
			row.eddelay->Font->Style = row.eddelay->Font->Style >> fsItalic;
			row.edpause->Font->Style = row.edpause->Font->Style >> fsItalic;
			row.edactive->Font->Style = row.edactive->Font->Style >> fsItalic;
			row.edinit->Font->Style = row.edinit->Font->Style >> fsItalic;
			row.eddesc->Font->Style = row.eddesc->Font->Style >> fsItalic;
		}

		if(strikeout)
		{
			row.edkey->Font->Style = row.edkey->Font->Style << fsStrikeOut;
			row.eddelay->Font->Style = row.eddelay->Font->Style << fsStrikeOut;
			row.edpause->Font->Style = row.edpause->Font->Style << fsStrikeOut;
			row.edactive->Font->Style = row.edactive->Font->Style << fsStrikeOut;
			row.edinit->Font->Style = row.edinit->Font->Style << fsStrikeOut;
			row.eddesc->Font->Style = row.eddesc->Font->Style << fsStrikeOut;
		}
		else
		{
			row.edkey->Font->Style = row.edkey->Font->Style >> fsStrikeOut;
			row.eddelay->Font->Style = row.eddelay->Font->Style >> fsStrikeOut;
			row.edpause->Font->Style = row.edpause->Font->Style >> fsStrikeOut;
			row.edactive->Font->Style = row.edactive->Font->Style >> fsStrikeOut;
			row.edinit->Font->Style = row.edinit->Font->Style >> fsStrikeOut;
			row.eddesc->Font->Style = row.eddesc->Font->Style >> fsStrikeOut;
		}


	}

	if(SimplifyUIForm->Visible)
	{
		SimplifyUIForm->checkColor();
	}

    Update();
}


void TD3AssistantMainForm::enableEditAll()
{
	for(int i=0;i<8;i++)
	{
		enableRecord(i);
	}

	for(int i=0;i<16;i++)
	{
		keyStopRows[i].edname->Enabled = true;
		keyStopRows[i].edkey->Enabled = true;
	}

	edImmediatelyKey->Enabled = true;
	edImmediatelyDelay->Enabled = true;
	edImmediatelyActive->Enabled = true;

	edStart->Enabled = true;
	edStop->Enabled = true;

}
void TD3AssistantMainForm::disableEditAll()
{
	for(int i=0;i<8;i++)
	{
		disableRecord(i);
	}

	for(int i=0;i<16;i++)
	{
		keyStopRows[i].edname->Enabled = false;
		keyStopRows[i].edkey->Enabled = false;
	}

	edImmediatelyKey->Enabled = false;
	edImmediatelyDelay->Enabled = false;
	edImmediatelyActive->Enabled = false;

	edStart->Enabled = false;
	edStop->Enabled = false;
}


void __fastcall TD3AssistantMainForm::CMDialogKey(TMessage &a)
{
	// prevent tab stop in window form
	if(a.WParam==VK_TAB)
	{
		a.Result = 0;
	}
}

void TD3AssistantMainForm::UpdateRecentlyFile(String filename)
{
	String rfilename = ChangeFileExt(Application->ExeName,".files");
	TStringList *strs = new TStringList;
	if(FileExists(rfilename))
	{
		strs->LoadFromFile(rfilename);
	}

	if(strs->IndexOf(filename)<0)
	{
		strs->Add(filename);
		strs->SaveToFile(rfilename);
	}
	delete strs;

	UpdateRecentlyLb();
}

void TD3AssistantMainForm::UpdateRecentlyLb()
{
	String rfilename = ChangeFileExt(Application->ExeName,".files");
	lbRecentlyFiles->Items->Clear();
	lbRecentlyFilesFullPath->Items->Clear();

	TStringList *strs = new TStringList;
	if(FileExists(rfilename))
	{
		strs->LoadFromFile(rfilename);
	}
	for(int i=0;i<strs->Count;i++)
	{
		String filename = strs->Strings[i];
		if(FileExists(filename))
		{
			String fname = ExtractFileName(filename);
			fname = ChangeFileExt(fname,"");

			lbRecentlyFiles->Items->Add(fname);
			lbRecentlyFilesFullPath->Items->Add(filename);
		}
	}
	delete strs;

}

void TD3AssistantMainForm::SaveIni(String filename)
{
//    PrepareKeyRows();

	TIniFile *ini = new TIniFile(filename);
	std::list<DWORD>::iterator it = editlist.begin();
	while(it!=editlist.end())
	{
		TEdit *ed = (TEdit *)*it;
		String name = ed->Name;
		String value = ed->Text;
		ini->WriteString("Items",name,value);
		it++;
	}

	for(int i=0;i<8;i++)
	{
		bool b = keyRows[i].toggle->Checked;
		ini->WriteBool("Items",keyRows[i].toggle->Name,b);
	}


	for(int i=1;i<=8;i++)
	{
		String name = String("edSpeech")+String(i);
		TEdit *te = (TEdit *)FindComponent(name);
		ini->WriteString("Items",name,te->Text);
	}

	for(int i=1;i<=8;i++)
	{
		String name = String("edDesc")+String(i);
		TEdit *te = (TEdit *)FindComponent(name);
		ini->WriteString("Items",name,te->Text);
	}


	delete ini;

	OpenFileName = filename;
	stBar->Text = OpenFileName;

	UpdateRecentlyFile(filename);

	bModified = false;
	stBar->Text = String("Saved ")+filename;



}
void TD3AssistantMainForm::LoadIni(String filename)
{

	if(FileExists(filename)==false) return;
	CloseAllMedia();

	bLoading = true;

	TIniFile *ini = new TIniFile(filename);
	std::list<DWORD>::iterator it = editlist.begin();
	while(it!=editlist.end())
	{
		TEdit *ed = (TEdit *)*it;
		String name = ed->Name;
		String value = ed->Text;
		if(ini->ValueExists("Items",name))
		{
			ed->Text = ini->ReadString("Items",name,"");
		}
		else
		{
			ed->Text = "";
		}
		it++;
	}
	for(int i=0;i<8;i++)
	{
		if(ini->ValueExists("Items",keyRows[i].toggle->Name))
		{
			keyRows[i].toggle->Checked = ini->ReadBool("Items",keyRows[i].toggle->Name,false);
		}
	}
	for(int i=1;i<=8;i++)
	{
		String name = String("edSpeech")+String(i);
		TEdit *ed = (TEdit *)FindComponent(name);
		ed->Text = ini->ReadString("Items",name,"");

		if(ed->Text.Length())
		{
			String mediafilename = GetYoloMediaFileByName(ed->Text);
			if(FileExists(mediafilename))
			{
				String name = String("mpYolo")+i;
				TMediaPlayer *mp = (TMediaPlayer *)FindComponent(name);
				mp->FileName = mediafilename;
				mp->Open();
			}
			else
			{
				String name = String("mpYolo")+i;
				TMediaPlayer *mp = (TMediaPlayer *)FindComponent(name);
				mp->Close();
			}
		}
		else
		{
			String name = String("mpYolo")+i;
			TMediaPlayer *mp = (TMediaPlayer *)FindComponent(name);
			mp->Close();

		}

	}

	for(int i=0;i<8;i++)
	{
		String name = String("edDesc")+String(i);
		TEdit *te = (TEdit *)FindComponent(name);
		te->Text = ini->ReadString("Items",name,"");
	}

	delete ini;

	OpenFileName = filename;
	UpdateRecentlyFile(OpenFileName);

	bModified = false;

	stBar->Text = String("Load ")+filename;

	bLoading = false;

	PrepareKeyRows();

}
//---------------------------------------------------------------------------
void __fastcall TD3AssistantMainForm::edStartKeyPress(TObject *Sender, System::WideChar &Key)

{
	Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TD3AssistantMainForm::edStartKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{

	if(MouseClickObject==Sender)
	{
		if(ActiveControl==Sender && ActiveControl->Tag==1)
		{
			String str = vk2str(Key);
			TEdit *te = (TEdit *)ActiveControl;
			if(str=="[ESC]")
			{
				if(te->Text.Length())
				{
					bModified=true;
					te->Text = "";

				}
			}
			else
			{
				char delimiter = '|';

				if(te->Name.SubString(1,8)=="edActive" || te->Name.SubString(1,7)=="edPause" || te->Name.SubString(1,5)=="edKey")
				{
					if(cbMultiKeyAndMode->Checked)
					{
						delimiter = '&';
					}
				}
				if(str.Length())
				{
					if(te->Text.Length()==0 || cbMultiKey->Checked==false)
					{
						te->Text = str;
					}
					else
					{
						te->Text = te->Text+String(delimiter)+str;
						if(delimiter=='&')
						{
							te->Text = StringReplace(te->Text,"|","&",TReplaceFlags() << rfReplaceAll);
						}
						if(delimiter=='|')
						{
							te->Text = StringReplace(te->Text,"&","|",TReplaceFlags() << rfReplaceAll);
						}


                    }
				}
			}
		}
	}

	Key = 0;
	ActiveControl = 0;
	MouseClickObject = 0;
}
//---------------------------------------------------------------------------
void __fastcall TD3AssistantMainForm::edKey1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if(Sender==edImmediatelyKey || Sender==edImmediatelyActive || Sender==edStart || Sender==edStop)
	{
        cbMultiKey->Checked = false;
    }
	if(ActiveControl==0) return;

	if(MouseClickObject==Sender)
	{
		TComponent *comp = (TComponent *)Sender;
		if(ActiveControl==Sender && comp->Tag==1)
		{
			TEdit *te = (TEdit *)Sender;
			char delimiter = '|';

			if(te->Name.SubString(1,8)=="edActive" || te->Name.SubString(1,7)=="edPause" || te->Name.SubString(1,5)=="edKey")
			{
				if(cbMultiKeyAndMode->Checked)
				{
					delimiter = '&';
				}
			}

			if(Button==mbLeft)
			{
				if(te->Text.Length()==0 || cbMultiKey->Checked==false)
				{
					te->Text = "[mbLeft]";
				}
				else
				{
					te->Text = te->Text+String(delimiter)+"[mbLeft]";

				}
			}
			if(Button==mbRight)
			{
				if(te->Text.Length()==0 || cbMultiKey->Checked==false)
				{
					te->Text = "[mbRight]";
				}
				else
				{
					te->Text = te->Text+String(delimiter)+"[mbRight]";

				}
			}
			if(Button==mbMiddle)
			{
				if(te->Text.Length()==0 || cbMultiKey->Checked==false)
				{
					te->Text = "[mbMiddle]";
				}
				else
				{
					te->Text = te->Text+String(delimiter)+"[mbMiddle]";

				}
			}

			if(delimiter=='&')
			{
				te->Text = StringReplace(te->Text,"|","&",TReplaceFlags() << rfReplaceAll);
			}
			if(delimiter=='|')
			{
				te->Text = StringReplace(te->Text,"&","|",TReplaceFlags() << rfReplaceAll);
			}


			MouseClickObject = 0;
			ActiveControl = 0;
			return;
		}
		ActiveControl = 0;

	}


	MouseClickObject = Sender;
}
//---------------------------------------------------------------------------
void __fastcall TD3AssistantMainForm::edStartContextPopup(TObject *Sender, TPoint &MousePos,
          bool &Handled)
{
    Handled = true;
}
//---------------------------------------------------------------------------
void __fastcall TD3AssistantMainForm::btnSaveClick(TObject *Sender)
{
	ActiveControl = 0;

	if(OpenFileName.Length())
	{
		SaveIni(OpenFileName);
		return;
	}
	bool r = SaveDialog->Execute();
	if(r==false) return;
	String filename = SaveDialog->FileName;

	SaveIni(filename);
	ActiveControl = 0;


}
//---------------------------------------------------------------------------
void __fastcall TD3AssistantMainForm::btnLoadClick(TObject *Sender)
{
	if(bModified)
	{
		int r = MessageDlg(MLTS("Some field(s) modified, do you want to continue?"),mtConfirmation,TMsgDlgButtons()<<mbYes<<mbNo,0);
		if(r==IDNO)
		{
			return;
		}

    }
	bool r = OpenDialog->Execute();
	if(r==false)
	{
		ActiveControl = 0;
		return;
	}
	String filename = OpenDialog->FileName;

	LoadIni(filename);
	ActiveControl = 0;
}
//---------------------------------------------------------------------------
void TD3AssistantMainForm::Start()
{
	if(cbDoNotStart->Checked) return;


	if(edKeyMouseModifier->Text.Length())
	{
        sleepsec = edKeyMouseModifier->Text.ToInt();
	}
	else
	{
        sleepsec = 0;
    }

	bProtWindowFlag = ProtectionAreaManagerForm->Visible;
	if(ProtectionAreaManagerForm->Visible)
	{
		ProtectionAreaManagerForm->Visible = false;
	}

    PageControl->ActivePage = KeySettingTabSheet;

	if(ActiveControl)
	{
		TComponent *comp = (TComponent *)ActiveControl;
		if(comp->Tag==1)
		{
			ActiveControl = 0;
			MouseClickObject = 0;
			return;
		}

	}

	MouseClickObject = 0;

	if(bStarted || bPause)
	{
		Stop();
	}


	bStarted = true;
	bPause = false;

	targetHwnd = 0;

	PrepareKeyRows();
	keyState.clear();
	eventq.clear();

	for(int i=0;i<8;i++)
	{
		keyRow &row = keyRows[i];
		if(row.key.Length() && row.interval>0)
		{
			if(row.initial)
			{
				row.timer->Interval = row.initial;
			}
			else
			{
				row.timer->Interval = mininterval;
			}
			row.enabled = true;
		}
	}

	keyPauseMap.clear();
	keyActiveMap.clear();
	keyHoldMap.clear();

	for(int i=0;i<8;i++)
	{
		keyRow &row = keyRows[i];
		if(row.enabled==false) continue;
		if(row.timer->Interval==0) continue;

		if(row.toggle->Checked)
		{
            keyHoldMap.push_back(&row);
        }

		if(row.pausekey.Length())
		{
			keyPauseMap[row.pausekey].push_back(&row);

			{
				std::set<String>::iterator it = row.pausekeys.begin();
				while(it!=row.pausekeys.end())
				{
					keyPauseMap[*it].push_back(&row);
					it++;
				}
			}

			{
				std::set<String>::iterator it = row.pausekeysand.begin();
				while(it!=row.pausekeysand.end())
				{
					keyPauseMap[*it].push_back(&row);
					it++;
				}
			}

		}

		if(row.activekey.Length())
		{
			keyActiveMap[row.activekey].push_back(&row);

			{
				std::set<String>::iterator it = row.activekeys.begin();
				while(it!=row.activekeys.end())
				{
					keyActiveMap[*it].push_back(&row);
					it++;
				}
			}
			{
				std::set<String>::iterator it = row.activekeysand.begin();
				while(it!=row.activekeysand.end())
				{
					keyActiveMap[*it].push_back(&row);
					it++;
				}
			}

		}
	}



	for(int i=0;i<8;i++)
	{
		keyRow &row = keyRows[i];
		if(row.enabled==false) continue;
		if(row.timer->Interval==0) continue;

		if(row.activekey.Length()==0)
		{
			row.timer->Enabled = true;
		}

	}


	StatusPanel->Caption = MLTS("Start");
	StatusPanel->Color = clLime;

	disableEditAll();
	checkColor();
	setBlend();

	if(cbMinimizeWhenStart->Checked)
	{
        WindowState = wsMinimized;
    }

	StopwatchTimer->Enabled = true;

}
void TD3AssistantMainForm::Stop()
{
	StopwatchTime = 0;
    StopwatchTimer->Enabled = false;

	if(WindowState==wsMinimized)
	{
        WindowState = wsNormal;
    }
	if(ActiveControl)
	{
		TComponent *comp = (TComponent *)ActiveControl;
		if(comp->Tag==1)
		{
			ActiveControl = 0;
			MouseClickObject = 0;
			return;
		}

	}

	if(bStarted)
	{
		ProtectionAreaManagerForm->Visible = bProtWindowFlag;
        bProtWindowFlag = false;
	}

	for(int i=0;i<8;i++)
	{
		keyRows[i].SendToAppKey(2);
		keyRows[i].timer->Enabled = false;
		keyRows[i].enabled = false;
	}

	bStarted = false;
	bPause = false;

	targetHwnd = 0;

	StopAllTTS();

	StatusPanel->Caption = MLTS("Stop");
	StatusPanel->Color = clLtGray;

	enableEditAll();
	checkColor();
	setBlend();

	ActiveControl = 0;
	MouseClickObject = 0;
	keyState.clear();
	eventq.clear();



}

bool TD3AssistantMainForm::StartImmediately(String key)
{
	if(cbDoNotStart->Checked) return false;
	if(IsForegroundWindow(Handle)) return false;
	if(key==edImmediatelyActive->Text)
	{
		if(edImmediatelyDelay->Text.Length())
		{
			disableEditAll();
			TimerImmediately->Interval = edImmediatelyDelay->Text.ToInt();
			TimerImmediately->Enabled = true;

			edImmediatelyKey->Color = clLime;
			edImmediatelyDelay->Color = clLime;
			edImmediatelyActive->Color = clLime;
			targetHwnd = 0;
            return true;

		}

	}
	return false;

}

void TD3AssistantMainForm::StopImmediately(String key)
{
	if(key==edImmediatelyActive->Text)
	{
		TimerImmediately->Enabled = false;
		enableEditAll();

		edImmediatelyKey->Color = clWindow;
		edImmediatelyDelay->Color = clWindow;
		edImmediatelyActive->Color = clWindow;
		targetHwnd = 0;

	}

}

int TD3AssistantMainForm::GetActiveKeyState(keyRow &row)
{
	if(row.activekey.Length()==0) return -1;

	if(row.activekeysand.size())
	{
		if(keyState[row.activekey]==0) return 0;
		std::set<String>::iterator it = row.activekeysand.begin();
		while(it!=row.activekeysand.end())
		{
			if(keyState[*it]==0) return 0;
			it++;
		}
		return 1;

	}


	if(keyState[row.activekey]==1) return 1;
	std::set<String>::iterator it = row.activekeys.begin();
	while(it!=row.activekeys.end())
	{
		if(keyState[*it]==1) return 1;
		it++;
	}

	return 0;
}

int TD3AssistantMainForm::GetPauseKeyState(keyRow &row)
{
	if(row.pausekey.Length()==0) return -1;


	if(row.pausekeysand.size())
	{
		if(keyState[row.pausekey]==0) return 0;
		std::set<String>::iterator it = row.pausekeysand.begin();
		while(it!=row.pausekeysand.end())
		{
			if(keyState[*it]==0) return 0;
			it++;
		}
		return 1;

	}

	if(keyState[row.pausekey]==1) return 1;
	std::set<String>::iterator it = row.pausekeys.begin();
	while(it!=row.pausekeys.end())
	{
		if(keyState[*it]==1) return 1;
		it++;
	}

	return 0;
}


void TD3AssistantMainForm::OnKeyDownHook(String key)
{
	if(ActiveControl)
	{
		if(ActiveControl->Tag==1)
		{
			return;
		}
	}

	if(key==edYoloLoopStart->Text)
	{
		StartYoloCycle();
	}

	if(key==edYoloLoopStop->Text)
	{
        StopYoloCycle();
    }

	if(key==edStart->Text && (bStarted==false || bPause))
	{
		if(cbDoNotStart->Checked) return;
		Start();
		PlayStartMp();
		return;
	}
	if(key==edStop->Text && (bStarted || bPause))
	{
		Stop();
		PlayStopMp();
		return;
	}

	SendKeyToTTS(key);


	if(bStarted==false)
	{
		if(cbDoNotStart->Checked) return;
		StartImmediately(key);
		return;
	}

	if(bStarted && key=="[ENTER]")
	{
		Stop();
		PlayStopMp();
		return;
	}


	{
		std::map<String,keyStopRow *>::iterator it = keyStopMap.find(key);
		if(it!=keyStopMap.end())
		{
			keyStopRow *row = it->second;
			if(row->type==0) // force stop
			{
				if(bStarted)
				{
					Stop();
					PlayStopMp();
                }
				return;
			}
			if(row->type==1) // pause toggle
			{
				bPause = !bPause;
				checkColor();
				return;
			}
			if(row->type==2) // pause hold
			{
				bPause = true;
				checkColor();
				return;
			}
		}
	}


	for(int i=0;i<8;i++)
	{
		keyRows[i].ProcessKeyDown(key);
	}
	checkColor();

}


void TD3AssistantMainForm::OnKeyUpHook(String key)
{
	if(ActiveControl)
	{
		if(ActiveControl->Tag==1)
		{
			return;
		}
	}



	if(bStarted==false)
	{
		StopImmediately(key);
		return;
	}



	for(int i=0;i<8;i++)
	{
		keyRows[i].ProcessKeyUp(key);
	}
	checkColor();


	{
		std::map<String,keyStopRow *>::iterator it = keyStopMap.find(key);
		if(it!=keyStopMap.end())
		{
			keyStopRow *row = it->second;
			if(row->type==2)
			{
				bPause = false;
				checkColor();
				return;
			}
		}
	}

}

bool TD3AssistantMainForm::OnMouseWheelHook(int delta)
{
	String key = "";
	if(delta==-120)
	{
		// wheel down
		key = "[WheelDn]";
	}
	if(delta==120)
	{
		// wheel up
		key = "[WheelUp]";
	}


	if(ActiveControl && MouseClickObject && bStarted==false)
	{
		if(ActiveControl->Tag==1)
		{
			TEdit *te = (TEdit *)ActiveControl;
			te->Text = key;
		}
		ActiveControl = 0;
		MouseClickObject = 0;
        return true;
	}



	if(key==edStart->Text && bStarted==false)
	{
		if(cbDoNotStart->Checked) return false;
		bStarted = true;
		Start();
		PlayStartMp();
		return true;
	}
	if(key==edStop->Text && bStarted)
	{
		bStarted = false;
		Stop();
        PlayStopMp();
		return true;
	}


	{
		static std::map<String,bool> flag;
		if(flag[key])
		{
			ProcessMouseUp(key);
			flag[key] = false;
			return true;
		}
		ProcessMouseDown(key);
		flag[key] = true;
		return true;
	}



	return false;

}

void TD3AssistantMainForm::OnMouseXButtonDown(int btn)
{
	// btn = 1 or 2 (XBUTTON1 , XBUTTON2)
	if(IsForegroundWindow(Handle)==false)
	{
		if(bStarted==false)
		{
			if(btn==1)
			{
				if(StartImmediately("[XButton1]")) return;
			}
			if(btn==2)
			{
				if(StartImmediately("[XButton2]")) return;
			}

		}
	}

	if(btn==1)
	{
		ProcessMouseDown("[XButton1]");
		return;
	}
	if(btn==2)
	{
		ProcessMouseDown("[XButton2]");
		return;
	}

}
void TD3AssistantMainForm::OnMouseXButtonUp(int btn)
{
	// btn = 1 or 2 (XBUTTON1 , XBUTTON2)
	if(bStarted==false)
	{
		if(btn==1)
		{
			StopImmediately("[XButton1]");
			return;
		}
		if(btn==2)
		{
			StopImmediately("[XButton2]");
			return;
		}

	}

	if(btn==1)
	{
		ProcessMouseUp("[XButton1]");
		return;
	}
	if(btn==2)
	{
		ProcessMouseUp("[XButton2]");
		return;
	}

}

void TD3AssistantMainForm::ProcessMouseDown(String key)
{
//	MessageDlg(key,mtInformation,TMsgDlgButtons()<<mbOK,0);
//    Memo1->Lines->Add(key);
	if(bStarted==false)
	{
		if(ActiveControl && MouseClickObject==ActiveControl)
		{
			TComponent *comp = (TComponent *)ActiveControl;
			if(comp->Tag==1)
			{
				TEdit *te = (TEdit *)comp;
				char delimiter = '|';

				if(te->Name.SubString(1,8)=="edActive" || te->Name.SubString(1,7)=="edPause" || te->Name.SubString(1,5)=="edKey")
				{
					if(cbMultiKeyAndMode->Checked)
					{
						delimiter = '&';
					}
				}

				if(key=="[XButton1]" || key=="[XButton2]")
				{

					if(te->Text.Length()==0 || cbMultiKey->Checked==false)
					{
						te->Text = key;
					}
					else
					{
						te->Text = te->Text+String(delimiter)+key;
					}
				}

				ActiveControl = 0;
				MouseClickObject = 0;
				return;
			}
		}

	}

//	String sss;
//	sss.printf(L"1 %s %s %d",key.c_str(),edStart->Text.c_str(),(int)bStarted);
//	Memo1->Lines->Add(sss);
	if(key==edStart->Text && bStarted==false)
	{
		if(cbDoNotStart->Checked) return;
//		if(key=="[mbLeft]") return;

		Start();
		bStarted = true;
		PlayStartMp();

//		sss.printf(L"5 %s %s %d",key.c_str(),edStart->Text.c_str(),(int)bStarted);
//		Memo1->Lines->Add(sss);
		return;
	}

//	sss.printf(L"2 %s %s %d",key.c_str(),edStart->Text.c_str(),(int)bStarted);
//	Memo1->Lines->Add(sss);

	if(key==edStop->Text && bStarted)
	{
		Stop();
		bStarted = false;
		PlayStopMp();
//		sss.printf(L"6 %s %s %d",key.c_str(),edStart->Text.c_str(),(int)bStarted);
//		Memo1->Lines->Add(sss);
		return;
	}

//	sss.printf(L"3 %s %s %d",key.c_str(),edStart->Text.c_str(),(int)bStarted);
//	Memo1->Lines->Add(sss);

	if(bStarted==false)
	{
		StartImmediately(key);
//		sss.printf(L"7 %s %s %d",key.c_str(),edStart->Text.c_str(),(int)bStarted);
//		Memo1->Lines->Add(sss);
		return;
	}
//	sss.printf(L"4 %s %s %d",key.c_str(),edStart->Text.c_str(),(int)bStarted);
//	Memo1->Lines->Add(sss);


	SendKeyToTTS(key);

	{
		std::map<String,keyStopRow *>::iterator it = keyStopMap.find(key);
		if(it!=keyStopMap.end())
		{
			keyStopRow *row = it->second;
			if(row->type==0)
			{
				if(bStarted)
				{
					Stop();
					PlayStopMp();
				}
				return;
			}
			if(row->type==1)
			{
				bPause = !bPause;
				checkColor();
				return;
			}
			if(row->type==2)
			{
				bPause = true;
				checkColor();
				return;
			}
		}
	}


		for(int i=0;i<8;i++)
		{
			keyRows[i].ProcessKeyDown(key);
		}
		checkColor();



}
void TD3AssistantMainForm::ProcessMouseUp(String key)
{

	if(bStarted==false)
	{
		StopImmediately(key);
		return;
	}

		for(int i=0;i<8;i++)
		{
			keyRows[i].ProcessKeyUp(key);
		}
		checkColor();



}

void TD3AssistantMainForm::OnMouseDownHook(int b,WPARAM wParam,LPARAM lParam)
{
	if(MouseClickObject)
	{
        return;
	}

	String key="";
	if(b==(int)mbLeft)
	{
		key = "[mbLeft]";
	}
	else
	if(b==(int)mbRight)
	{
		key = "[mbRight]";
	}
	else
	if(b==(int)mbMiddle)
	{
		key = "[mbMiddle]";
	}


	if(bUseSendQueue==false)
	{
		ProcessMouseDown(key);
	}



}
void TD3AssistantMainForm::OnMouseUpHook(int b,WPARAM wParam,LPARAM lParam)
{
	String key="";
	if(b==(int)mbLeft)
	{
		key = "[mbLeft]";
	}
	else
	if(b==(int)mbRight)
	{
		key = "[mbRight]";
	}
	else
	if(b==(int)mbMiddle)
	{
		key = "[mbMiddle]";
	}


	if(bUseSendQueue==false)
	{
		ProcessMouseUp(key);
    }


}


void TD3AssistantMainForm::PushDownKey(int vcode,int scancode)
{
	if(bPause) return;

#ifndef USESENDINPUT
	keybd_event(vcode,scancode,0,0);
#else
	INPUT input;
	::ZeroMemory(&input, sizeof(input));
	input.type = INPUT_KEYBOARD;
	input.ki.wVk  = vcode;
	//  input.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &input, sizeof(INPUT));
#endif
	if(sleepsec) Sleep(sleepsec);

}

void TD3AssistantMainForm::PushUpKey(int vcode,int scancode)
{
	if(bPause) return;
#ifndef USESENDINPUT
	keybd_event(vcode,scancode,KEYEVENTF_KEYUP,0);
#else
	INPUT input;
	::ZeroMemory(&input, sizeof(input));
	input.type = INPUT_KEYBOARD;
	input.ki.wVk  = vcode;
	input.ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(1, &input, sizeof(INPUT));
#endif
}

void TD3AssistantMainForm::PressKey(int vcode,int scancode)
{
	if(bPause) return;
#ifndef USESENDINPUT
	keybd_event(vcode,scancode,0,0);
	keybd_event(vcode,scancode,KEYEVENTF_KEYUP,0);
#else
	PushDownKey(vcode,scancode);
	PushUpKey(vcode,scancode);

	/*
	INPUT input[2];
	::ZeroMemory(input, sizeof(input));
	input[0].type = input[1].type = INPUT_KEYBOARD;
	input[0].ki.wVk  = input[1].ki.wVk = vcode;;
	input[1].ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(2, input, sizeof(INPUT));
}	*/
#endif
}

void TD3AssistantMainForm::MouseDownX(int btn)
{
	/*
	MOUSEINPUT input;
	::ZeroMemory(&input, sizeof(input));
	input.mouseData = btn;
	input.dwFlags =  MOUSEEVENTF_XDOWN;
	::SendInput(1,(INPUT *)&input,sizeof(MOUSEINPUT));
	*/

	INPUT    input;
	::ZeroMemory(&input, sizeof(input));

	input.type      = INPUT_MOUSE;
	input.mi.dwFlags  = MOUSEEVENTF_XDOWN;
	input.mi.mouseData = btn;
	::SendInput(1,&input,sizeof(INPUT));


	if(sleepsec) Sleep(sleepsec);

}

void TD3AssistantMainForm::MouseUpX(int btn)
{
	INPUT    input;
	::ZeroMemory(&input, sizeof(input));

	input.type      = INPUT_MOUSE;
	input.mi.dwFlags  = MOUSEEVENTF_XUP;
	input.mi.mouseData = btn;
	::SendInput(1,&input,sizeof(INPUT));

}


void TD3AssistantMainForm::MouseWheel(int delta)
{

	INPUT    input;
	::ZeroMemory(&input, sizeof(input));

	input.type      = INPUT_MOUSE;
	input.mi.dwFlags  = MOUSEEVENTF_WHEEL;
	input.mi.mouseData = delta;
	::SendInput(1,&input,sizeof(INPUT));

}



void TD3AssistantMainForm::MouseDown(TMouseButton button)
{
	if(bPause) return;


#ifndef USESENDINPUT
	if(button==mbLeft)
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	}
	else
	if(button==mbRight)
	{
		mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	}
	else
	if(button==mbMiddle)
	{
		mouse_event(MOUSEEVENTF_MIDDLEDOWN,0,0,0,0);
	}
#else
  INPUT    input;
	::ZeroMemory(&input, sizeof(input));

	if(button==mbLeft)
	{
		input.type      = INPUT_MOUSE;
		input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
		::SendInput(1,&input,sizeof(INPUT));
	}
	else
	if(button==mbRight)
	{
		input.type      = INPUT_MOUSE;
		input.mi.dwFlags  = MOUSEEVENTF_RIGHTDOWN;
		::SendInput(1,&input,sizeof(INPUT));

	}
	else
	if(button==mbMiddle)
	{
		input.type      = INPUT_MOUSE;
		input.mi.dwFlags  = MOUSEEVENTF_MIDDLEDOWN;
		::SendInput(1,&input,sizeof(INPUT));

	}


#endif


	if(sleepsec) Sleep(sleepsec);

}

void TD3AssistantMainForm::KeyDown(String key)
{
	if(key.Length()>0)
	{
		char vc = key[1];
		if(key.Length()>1)
		{
			vc = str2vkey(key);
			if(vc==0)
			{
				return;
			}
		}

		unsigned int sc = MapVirtualKey(vc,MAPVK_VK_TO_VSC);
		PushDownKey(vc,sc);
	}


}
void TD3AssistantMainForm::KeyUp(String key)
{
	if(key.Length()>0)
	{
		char vc = key[1];
		if(key.Length()>1)
		{
			vc = str2vkey(key);
			if(vc==0)
			{
				return;
			}
		}

		unsigned int sc = MapVirtualKey(vc,MAPVK_VK_TO_VSC);
		PushUpKey(vc,sc);
	}

}

void TD3AssistantMainForm::MouseDown(String key)
{
	if(key=="[mbLeft]")
	{
		MouseDown(mbLeft);
		return;
	}
	if(key=="[mbMiddle]")
	{
		MouseDown(mbMiddle);
		return;
	}
	if(key=="[mbRight]")
	{
		MouseDown(mbRight);
		return;
	}
	if(key=="[XButton1]")
	{
		MouseDownX(1);
		return;
	}
	if(key=="[XButton2]")
	{
		MouseDownX(2);
		return;
	}

}
void TD3AssistantMainForm::MouseUp(String key)
{
	if(key=="[mbLeft]")
	{
		MouseUp(mbLeft);
		return;
	}
	if(key=="[mbMiddle]")
	{
		MouseUp(mbMiddle);
		return;
	}
	if(key=="[mbRight]")
	{
		MouseUp(mbRight);
		return;
	}
	if(key=="[XButton1]")
	{
		MouseUpX(1);
		return;
	}
	if(key=="[XButton2]")
	{
		MouseUpX(2);
		return;
	}

}
void TD3AssistantMainForm::MouseUp(TMouseButton button)
{
	if(bPause) return;


#ifndef USESENDINPUT
	if(button==mbLeft)
	{
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	}
	else
	if(button==mbRight)
	{
		mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	}
	else
	if(button==mbMiddle)
	{
		mouse_event(MOUSEEVENTF_MIDDLEUP,0,0,0,0);
	}
#else
	INPUT    input;
	::ZeroMemory(&input, sizeof(input));

	if(button==mbLeft)
	{
		input.type      = INPUT_MOUSE;
		input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
		::SendInput(1,&input,sizeof(INPUT));
	}
	else
	if(button==mbRight)
	{
		input.type      = INPUT_MOUSE;
		input.mi.dwFlags  = MOUSEEVENTF_RIGHTUP;
		::SendInput(1,&input,sizeof(INPUT));

	}
	else
	if(button==mbMiddle)
	{
		input.type      = INPUT_MOUSE;
		input.mi.dwFlags  = MOUSEEVENTF_MIDDLEUP;
		::SendInput(1,&input,sizeof(INPUT));

	}


#endif

}

void TD3AssistantMainForm::MouseClick(TMouseButton button)
{
	if(bPause) return;

#ifndef USESENDINPUT
	if(button==mbLeft)
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	}else
	if(button==mbRight)
	{
		mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
		mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	}else
	if(button==mbMiddle)
	{
		mouse_event(MOUSEEVENTF_MIDDLEDOWN,0,0,0,0);
		mouse_event(MOUSEEVENTF_MIDDLEUP,0,0,0,0);
	}
#else
	MouseDown(button);
	MouseUp(button);
#endif

}

void TD3AssistantMainForm::SendToAppKey(keyRow &row,String &key,int opt)
{

	if(key=="[mbLeft]")
	{
		TMouseButton btn = mbLeft;
		if(row.toggle->Checked)
		{
			if(row.pushdown==false)
			{
				row.pushdown = true;
				MouseDown(btn);
				checkColor();
			}
			else
			{
				if(row.activekey.Length())
				{
					row.timer->Enabled = false;
				}
				row.pushdown = false;
				row.timer->Interval = mininterval;
				MouseUp(btn);
				checkColor();
			}
		}
		else
		{
			if(opt==0)
			{
				MouseClick(btn);
			}
			if(opt==1)
			{
				MouseDown(btn);
			}
			if(opt==2)
			{
				MouseUp(btn);
			}
		}

		return;
	}
	if(key=="[mbRight]")
	{
		TMouseButton btn = mbRight;
		if(row.toggle->Checked)
		{
			if(row.pushdown==false)
			{
				row.pushdown = true;
				MouseDown(btn);
				checkColor();
			}
			else
			{
				if(row.activekey.Length())
				{
					row.timer->Enabled = false;
				}
				row.pushdown = false;
				row.timer->Interval = mininterval;
				MouseUp(btn);
				checkColor();
			}
		}
		else
		{
			if(opt==0)
			{
				MouseClick(btn);
			}
			if(opt==1)
			{
				MouseDown(btn);
			}
			if(opt==2)
			{
				MouseUp(btn);
			}
		}
		return;
	}
	if(key=="[mbMiddle]")
	{
		TMouseButton btn = mbMiddle;
		if(row.toggle->Checked)
		{
			if(row.pushdown==false)
			{
				row.pushdown = true;
				MouseDown(btn);
				checkColor();
			}
			else
			{
				if(row.activekey.Length())
				{
					row.timer->Enabled = false;
				}
				row.pushdown = false;
				row.timer->Interval = mininterval;
				MouseUp(btn);
				checkColor();
			}
		}
		else
		{
			if(opt==0)
			{
				MouseClick(btn);
			}
			if(opt==1)
			{
				MouseDown(btn);
			}
			if(opt==2)
			{
				MouseUp(btn);
			}
		}
		return;
	}
	if(key=="[XButton1]")
	{
		if(row.toggle->Checked)
		{
			if(row.pushdown==false)
			{
				row.pushdown = true;
				MouseDownX(1);
				checkColor();
			}
			else
			{
				if(row.activekey.Length())
				{
					row.timer->Enabled = false;
				}
				row.pushdown = false;
				row.timer->Interval = mininterval;
				MouseUpX(1);
				checkColor();
			}
		}
		else
		{
			if(opt==0)
			{
				MouseDownX(1);
				MouseUpX(1);
			}
			if(opt==1)
			{
				MouseDownX(1);
			}
			if(opt==2)
			{
				MouseUpX(1);
			}
		}
		return;
	}

	if(key=="[XButton2]")
	{
		if(row.toggle->Checked)
		{
			if(row.pushdown==false)
			{
				row.pushdown = true;
				MouseDownX(2);
				checkColor();
			}
			else
			{
				if(row.activekey.Length())
				{
					row.timer->Enabled = false;
				}
				row.pushdown = false;
				row.timer->Interval = mininterval;
				MouseUpX(2);
				checkColor();
			}
		}
		else
		{
			if(opt==0)
			{
				MouseDownX(2);
				MouseUpX(2);
			}
			if(opt==1)
			{
				MouseDownX(2);
			}
			if(opt==2)
			{
				MouseUpX(2);
			}
		}
		return;
	}

	if(key=="[WheelUp]")
	{
		MouseWheel(120);
		return;
	}
	if(key=="[WheelDn]")
	{
		MouseWheel(-120);
		return;
	}


	if(key.Length()>0)
	{
		char vc = key[1];
		if(key.Length()>1)
		{
			vc = str2vkey(key);
			if(vc==0) return;
		}

		unsigned int sc = MapVirtualKey(vc,MAPVK_VK_TO_VSC);
		if(row.toggle->Checked)
		{
			if(row.pushdown==false)
			{
				PushDownKey(vc,sc);
				row.pushdown = true;

				checkColor();
			}
			else
			{
				PushUpKey(vc,sc);
				if(row.activekey.Length())
				{
					row.timer->Enabled = false;
				}
				row.timer->Interval = mininterval;
				row.pushdown = false;
				checkColor();

			}
		}
		else
		{
			if(opt==0)
			{
				PressKey(vc,sc);
			}
			if(opt==1)
			{
				PushDownKey(vc,sc);
			}
			if(opt==2)
			{
				PushUpKey(vc,sc);
			}
		}
		return;
	}

}

DWORD TD3AssistantMainForm::GetYoloTargetProcessId()
{
 	if(cbOnlyD3->Checked && edOnlyWindow->Text.Length())
	{
		DWORD pid;
		AnsiString s = edOnlyWindow->Text;
		HWND hwnd = ::FindWindow(0,s.c_str());
        if(hwnd==0) return 0;

		GetWindowThreadProcessId(hwnd,&pid);
        return pid;
	}

	return 0;

}
void __fastcall TD3AssistantMainForm::Timer1Timer(TObject *Sender)
{

	if(cbOnlyD3->Checked)
	{
		HWND hwnd = GetForegroundWindow();

		if(targetHwnd && hwnd!=targetHwnd)
		{
			return;
		}
		if(hwnd && targetHwnd==0)
		{
			char str[255];
			GetWindowText(hwnd,str,255);
			String s = str;
			if(s==edOnlyWindow->Text)
			{
				targetHwnd = hwnd;
			}
		}
		if(targetHwnd==0)
		{
			return;
		}
	}

	if(bPause) return;



	TTimer *timer = (TTimer *)Sender;
	keyRow *lprow = keyTimerMap[timer];
	keyRow &row = *lprow;

	row.ProcessTimer();



}
//---------------------------------------------------------------------------


void __fastcall TD3AssistantMainForm::cbStayOnTopClick(TObject *Sender)
{
	if(cbStayOnTop->Checked)
	{
		FormStyle = fsStayOnTop;
		return;
	}
	FormStyle = fsNormal;
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::WMActivate(TWMActivate &Message)
{
	if(Message.Active==false)
	{
		ActiveControl = 0;
		MouseClickObject = 0;

    }
	if(Message.Active && bStarted)
	{
		Stop();
		PlayStopMp();
	}
	setBlend();
}

//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::FormClose(TObject *Sender, TCloseAction &Action)

{
	StopHook();
	SaveEnv();

	KillYolo();

	Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::menuSaveAsClick(TObject *Sender)
{
	bool r = SaveDialog->Execute();
	if(r==false) return;
	String filename = SaveDialog->FileName;

	SaveIni(filename);

}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::menuNewClick(TObject *Sender)
{
	for(int i=0;i<ComponentCount;i++)
	{
		TComponent *comp = (TComponent *)Components[i];
		if(comp->ClassNameIs("TEdit") && (comp->Tag==1 || comp->Tag==2))
		{
			TEdit *te = (TEdit *)comp;
			te->Text = "";

		}
	}
	OpenFileName = "";
    stBar->Text = MLTS("New !!!");

}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::edDelay1KeyPress(TObject *Sender, System::WideChar &Key)

{
	if(Key==27)
	{
		TEdit *ed = (TEdit *)Sender;
		Key = 0;
		ed->Text = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::MenuAboutDlgClick(TObject *Sender)
{
	bool flg = false;
	if(FormStyle==fsStayOnTop)
	{
		FormStyle=fsNormal;
		flg = true;
	}
	AboutBox->ShowModal();

	if(flg)
	{
        FormStyle=fsStayOnTop;
    }
}
//---------------------------------------------------------------------------


void __fastcall TD3AssistantMainForm::MenuHelpClick(TObject *Sender)
{
	ShellExecute(NULL, "open", "https://drive.google.com/open?id=1Gce8ohyoRhIRGDaq7PvAKwx0oxshUxiQqRg49GUI7Cg",
			NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::MenuHomePageClick(TObject *Sender)
{

	ShellExecute(NULL, "open", "https://github.com/dooly386/d3assist",
			NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::MenuReleaseNoteClick(TObject *Sender)
{
	ShellExecute(NULL, "open", "https://drive.google.com/open?id=19Lg57gkBLVwSFHEEHM7WiDBG8qAHcw_d-oU543QR57U",
			NULL, NULL, SW_SHOWNORMAL);

}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::YoloMouseHomePageMenuClick(TObject *Sender)
{
	ShellExecute(NULL, "open", "https://pandateemo.github.io/YoloMouse/",
			NULL, NULL, SW_SHOWNORMAL);

}
//---------------------------------------------------------------------------



void __fastcall TD3AssistantMainForm::StartYoloMouseMenuClick(TObject *Sender)
{
	KillYolo();

#ifdef _WIN64
	AnsiString filename = ExtractFilePath(Application->ExeName)+"\\YoloMouse64.exe";
#else
	AnsiString filename = ExtractFilePath(Application->ExeName)+"\\YoloMouse32.exe";
#endif


	STARTUPINFO StartupInfo = {0};
	PROCESS_INFORMATION ProcessInfo;
	StartupInfo.cb = sizeof( STARTUPINFO );
	::CreateProcess(filename.c_str(),NULL, NULL, NULL, FALSE, 0, NULL, NULL, &StartupInfo, &ProcessInfo);

}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::StopYoloMouseMenuClick(TObject *Sender)
{
	KillYolo();
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::MenuSetYoloMouseTargetProcessClick(TObject *Sender)

{
	bool flag=0;

	if(FormStyle==fsStayOnTop)
	{
		flag = true;
		FormStyle = fsNormal;
	}

#ifdef _WIN64
	String InputString= Dialogs::InputBox(MLTS("Input Target Process Name"),MLTS("Please input target process name(ex:Diablo III64.exe) or *.*"), "Diablo III64.exe");
#else
	String InputString= Dialogs::InputBox(MLTS("Input Target Process Name"),MLTS("Please input target process name(ex:Diablo III.exe) or *.*"), "Diablo III.exe");
#endif

	CHAR apppath[MAX_PATH];
	HRESULT result = SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA, NULL, SHGFP_TYPE_CURRENT, apppath);

	String path = apppath;
	ForceDirectories(path+"\\YoloMouse");

	String inifile = path+"\\YoloMouse\\Target.ini";

	TStringList *strs = new TStringList;
	strs->Add(InputString);
	strs->SaveToFile(inifile);
	delete strs;

	if(flag)
	{
		FormStyle = fsStayOnTop;
    }


}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::FormShow(TObject *Sender)
{
	ActiveControl = 0;
    OnShow = 0;
	ProtectionAreaManagerForm->InitForm();


}
//---------------------------------------------------------------------------


void __fastcall TD3AssistantMainForm::PageControlChange(TObject *Sender)
{
/*
	if(PageControl->TabIndex==1)
	{
		PageControl->TabIndex = 0;
	}
*/
    cbMultiKey->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::lbRecentlyFilesDblClick(TObject *Sender)
{
	int idx = lbRecentlyFiles->ItemIndex;
	if(idx<0) return;

	String filename = lbRecentlyFilesFullPath->Items->Strings[idx];
    LoadIni(filename);

}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::DeleteRecentlyFileMenuClick(TObject *Sender)

{
	int idx = lbRecentlyFiles->ItemIndex;
	if(idx<0) return;
	lbRecentlyFiles->Items->Delete(idx);
	lbRecentlyFilesFullPath->Items->Delete(idx);

	String rfilename = ChangeFileExt(Application->ExeName,".files");
	lbRecentlyFilesFullPath->Items->SaveToFile(rfilename);


}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::edStartChange(TObject *Sender)
{
	bModified = true;
	if(!bLoading)
	{
		PrepareKeyRows();
	}
	TEdit *ed = (TEdit *)Sender;
    ed->Hint = StringReplace(ed->Text,"|"," ",TReplaceFlags() << rfReplaceAll);

}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::cbToggle1Click(TObject *Sender)
{
	bModified = true;
	if(!bLoading)
	{
		PrepareKeyRows();
    }
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)

{
	if(bModified)
	{
		int r = MessageDlg(MLTS("Some field(s) modified, do you want to continue?"),mtConfirmation,TMsgDlgButtons()<<mbYes<<mbNo,0);
		if(r==IDNO)
		{
			CanClose = false;
			return;
		}
	}

	CanClose = true;
}
//---------------------------------------------------------------------------

String GetURLAsString(String aURL)
{
//	String r = D3AssistantMainForm->IdHTTP->Get(aURL);
//    return r;
}

void __fastcall TD3AssistantMainForm::MenuCheckUpdateClick(TObject *Sender)
{
	ShellExecute(NULL, "open", "https://github.com/dooly386/d3assist",
			NULL, NULL, SW_SHOWNORMAL);


}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::FormCreate(TObject *Sender)
{
//    MenuCheckUpdateClick(0);
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::DeleteAllRecentlyFileMenuClick(TObject *Sender)

{
	lbRecentlyFiles->Items->Clear();
	lbRecentlyFilesFullPath->Items->Clear();

	String rfilename = ChangeFileExt(Application->ExeName,".files");
	lbRecentlyFilesFullPath->Items->SaveToFile(rfilename);

}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::edStopName1Change(TObject *Sender)
{
	bModified = true;
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::edKey1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if(Button==mbRight)
	{
		ActiveControl = 0;
		MouseClickObject = 0;
    }
}
//---------------------------------------------------------------------------


void __fastcall TD3AssistantMainForm::MenuOpenProtectionAreaManagerClick(TObject *Sender)

{
	ProtectionAreaManagerForm->Visible = true;

}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::MenuLoadFromAreaFileClick(TObject *Sender)
{
	ProtectionAreaManagerForm->MenuLoadAreaFromFileClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::TimerImmediatelyTimer(TObject *Sender)
{
	if(cbOnlyD3->Checked)
	{
		HWND hwnd = GetForegroundWindow();

		if(hwnd && targetHwnd==0)
		{
			char str[255];
			GetWindowText(hwnd,str,255);
			String s = str;
			if(s!=edOnlyWindow->Text)
			{
				targetHwnd = hwnd;
				return;
			}
		}
		if(hwnd==targetHwnd)
		{
            return;
        }
	}


	String key = edImmediatelyKey->Text;

	if(key=="[mbLeft]")
	{
		MouseClick(mbLeft);
		return;
	}
	if(key=="[mbRight]")
	{
		MouseClick(mbRight);
		return;
	}
	if(key=="[mbMiddle]")
	{
		MouseClick(mbMiddle);
		return;
	}



	if(key.Length()>0)
	{
		char vc = key[1];
		if(key.Length()>1)
		{
			vc = str2vkey(key);
			if(vc==0) return;
		}

		unsigned int sc = MapVirtualKey(vc,MAPVK_VK_TO_VSC);
		PressKey(vc,sc);
		return;
	}


}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::MenuOpenTTSManagerClick(TObject *Sender)
{
//	TTSManagerForm->Show();
	TTTSManagerForm *form = CreateNewTTSForm();
	form->Show();
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::MenuSkinDefaultClick(TObject *Sender)
{
//
	TMenuItem *p = (TMenuItem *)Sender;
	String name = p->Caption;
	if(name==MLTS("Default Window"))
	{
		TStyleManager::TrySetStyle("Windows");
		SkinName = "Windows";
	}
	else
	{
		SkinName = name;
	}
    SetSkin(SkinName);



}
//---------------------------------------------------------------------------



void __fastcall TD3AssistantMainForm::MenuDebugWindowClick(TObject *Sender)
{
	DebugWindowForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::N9Click(TObject *Sender)
{
	TMediaPlayerForm *form = CreateMediaPlayerForm(this);
    form->Show();
}
//---------------------------------------------------------------------------

struct yolocursor
{

	int group;
	int idx;

	TMediaPlayer *mp;
	yolocursor()
	{
        mp = 0;
    }
};

std::list<yolocursor> YoloCursors;
std::list<yolocursor>::iterator itYoloCursor;


void TD3AssistantMainForm::StartYoloCycle()
{

	if(CheckYoloMouseReady()==false && cbMediaOnly->Checked==false)
	{
		::SetForegroundWindowForce(Handle);
		::SetFocus(Handle);
		MessageDlg(MLTS("Yolomouse is not running, please start yolomouse and try again!!!"),mtConfirmation,TMsgDlgButtons()<<mbOK,0);
		return;
	}

	if(cbMediaOnly->Checked==false)
	{
		DWORD pid = GetYoloTargetProcessId();
		if(pid)
		{
			#ifndef _WIN64
				HWND hwnd = GetWinHandleByProcessName("YoloMouse32.exe");
			#else
				HWND hwnd = GetWinHandleByProcessName("YoloMouse64.exe");
			#endif

			SendMessage(hwnd,WM_USER+1001,0,pid);
	//		Caption = pid;
		}
		else
		{
			MessageDlg(MLTS("Yolomouse is not running, please start yolomouse and try again!!!"),mtConfirmation,TMsgDlgButtons()<<mbOK,0);
			return;
		}
    }



	YoloCursors.clear();

	for(int i=1;i<=8;i++)
	{
		TEdit *edName = (TEdit *)FindComponent(String("edYoloName")+i);
        if(edName->Text.Length()==0) continue;

		TEdit *ed1=0;
		TEdit *ed2=0;
		if(cbMediaOnly->Checked==false)
		{
			String name1 = String("edCurGrp")+String(i);
			ed1 = (TEdit *)FindComponent(name1);
			String name2 = String("edCurId")+String(i);
			ed2 = (TEdit *)FindComponent(name2);
			if(ed1->Text.Length()==0) continue;
			if(ed2->Text.Length()==0) continue;
		}

		String name3 = String("edSpeech")+String(i);
		TEdit *ed = (TEdit *)FindComponent(name3);

		TMediaPlayer *mp = 0;
		if(ed->Text.Length())
		{
			String mediafilename = GetYoloMediaFileByName(ed->Text);
			if(FileExists(mediafilename))
			{
				String name4 = String("mpYolo")+String(i);
				mp = (TMediaPlayer *)FindComponent(name4);
			}
		}




		int a = -1;
		int b = -1;
		if(ed1)
		{
			a = ed1->Text.ToInt();
			b = ed2->Text.ToInt();
		}

		yolocursor y;
		y.group = a;
		y.idx = b;
        y.mp = mp;
		YoloCursors.push_back(y);
	}
	itYoloCursor = YoloCursors.begin();
    if(itYoloCursor==YoloCursors.end()) return;

	TimerYoloCursor->Interval = mininterval;

	TimerYoloCursor->Enabled = true;

}

void TD3AssistantMainForm::StopYoloCycle()
{
	TimerYoloCursor->Enabled = false;
}


void __fastcall TD3AssistantMainForm::TimerYoloCursorTimer(TObject *Sender)
{

	TimerYoloCursor->Enabled = false;
	TimerYoloCursor->Interval = edYoloLoopInterval->Text.ToInt();

	HWND hwnd = 0;
	if(cbMediaOnly->Checked==false)
	{
		hwnd = GetYoloHandle();
		if(hwnd==0) return;
	}


	yolocursor &cur = *itYoloCursor;

	if(hwnd)
	{
		SendMessage(hwnd,WM_USER+1000,cur.group,cur.idx);
	}

	if(cur.mp)
	{
		if(cur.mp->Length)
		{
			cur.mp->Rewind();
			cur.mp->Play();
        }
    }

	itYoloCursor++;

	if(itYoloCursor==YoloCursors.end())
	{
        itYoloCursor = YoloCursors.begin();
	}

	TimerYoloCursor->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::edCurGrp1KeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
	ActiveControl = 0;
    MouseClickObject = 0;
}
//---------------------------------------------------------------------------


void __fastcall TD3AssistantMainForm::mpYolo1Click(TObject *Sender, TMPBtnType Button,
          bool &DoDefault)
{
//
	AnsiString path = GetYoloMediaPath();

	TMediaPlayer *mp = (TMediaPlayer *)Sender;
	if(mp->Mode==mpPlaying)
	{
		mp->Stop();
		mp->Rewind();
		DoDefault = false;
		return;
	}

	int tag = mp->Tag;
	TEdit *ed = (TEdit *)FindComponent(String("edSpeech")+tag);
	if(ed->Text.Length()==0)
	{
		DoDefault = false;
		return;
	}

	AnsiString mediafile = path+"\\"+ed->Text+".wav";
	if(FileExists(mediafile)==false)
	{
		DoDefault = false;
		return;
	}


	DoDefault = LoadMediaIfExist(mp,mediafile);
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::edYoloName1Change(TObject *Sender)
{
	bModified = true;
}
//---------------------------------------------------------------------------

bool TD3AssistantMainForm::LoadMediaIfExist(TMediaPlayer *mp,String filename)
{
	if(FileExists(filename)==false) return false;
    mp->FileName = "";
	if(IsUsedMediaFile(filename)==true) return false;

	mp->FileName = filename;
	mp->Open();
	bool r = mp->Mode!=mpNotReady;
	if(r==false)
	{
        mp->FileName = "";
	}
	return r;
}
void TD3AssistantMainForm::PlayStartMp()
{
	if(cbAudioWhenStartStop->Checked==false) return;

	if(mpStart->Mode!=mpNotReady)
	{
		mpStart->Play();
	}

}
void TD3AssistantMainForm::PlayStopMp()
{
	if(cbAudioWhenStartStop->Checked==false) return;
	if(mpStop->Mode!=mpNotReady)
	{
		mpStop->Play();
	}

}

void __fastcall TD3AssistantMainForm::mpStartClick(TObject *Sender, TMPBtnType Button,
          bool &DoDefault)
{
	if(mpStart->Mode==mpPlaying)
	{
		mpStart->Stop();
		mpStart->Rewind();
		DoDefault = false;
		return;
	}

	String name = edWaveNameStart->Text;
	if(name.Length()==0)
	{
		DoDefault = false;
		return;
	}

	String mediafilename = GetYoloMediaFileByName(name);
	DoDefault = LoadMediaIfExist(mpStart,mediafilename);
	if(DoDefault)
	{
		mpStart->FileName = mediafilename;
		mpStart->Open();
	}
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::mpStopClick(TObject *Sender, TMPBtnType Button,
		  bool &DoDefault)
{
	if(mpStop->Mode==mpPlaying)
	{
		mpStop->Stop();
		mpStop->Rewind();
		DoDefault = false;
		return;
	}

	String name = edWaveNameStop->Text;
	if(name.Length()==0)
	{
		DoDefault = false;
		return;
	}
	String mediafilename = GetYoloMediaFileByName(name);
	DoDefault = LoadMediaIfExist(mpStop,mediafilename);
	if(DoDefault)
	{
		mpStop->FileName = mediafilename;
		mpStop->Open();
    }



}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::cbAudioWhenStartStopClick(TObject *Sender)
{
	if(cbAudioWhenStartStop->Checked==false)
	{
		if(mpStart->Mode!=mpNotReady)
		{
			mpStart->Close();
		}
		if(mpStop->Mode!=mpNotReady)
		{
			mpStop->Close();
		}
		return;
	}

	{
		String mediafilename = GetYoloMediaFileByName(edWaveNameStart->Text);
		if(LoadMediaIfExist(mpStart,mediafilename))
		{
			mpStart->FileName = mediafilename;
			mpStart->Open();
		}
	}

	{
		String mediafilename = GetYoloMediaFileByName(edWaveNameStop->Text);
		if(LoadMediaIfExist(mpStop,mediafilename))
		{
			mpStop->FileName = mediafilename;
			mpStop->Open();
		}
	}

}
//---------------------------------------------------------------------------

void TD3AssistantMainForm::HideAllComponents()
{
	PPropInfo propinfo;
	for(int i=0;i<ComponentCount;i++)
	{
		TComponent *comp = Components[i];
		propinfo = GetPropInfo(comp,"Visible");
		if(propinfo)
		{
			SetOrdProp(comp,"Visible",0);
        }
	}
}
void TD3AssistantMainForm::ShowAllComponents()
{
	PPropInfo propinfo;
	for(int i=0;i<ComponentCount;i++)
	{
		TComponent *comp = Components[i];
		propinfo = GetPropInfo(comp,"Visible");
		if(propinfo)
		{
			SetOrdProp(comp,"Visible",1);
		}
	}

}

void TD3AssistantMainForm::Simplify()
{
	widthBk = Width;
	heightBk = Height;

	SimplifyUIForm->AlphaBlend = true;
	if(edAlphaValue->Text.Length())
	{
		SimplifyUIForm->AlphaBlendValue = edAlphaValue->Text.ToInt();
	}
	else
	{
		SimplifyUIForm->AlphaBlendValue = 100;
	}
	SimplifyUIForm->Parent = this;
	SimplifyUIForm->Show();

	BorderStyle = bsNone;
	Menu = 0;

	HideAllComponents();
	ClientWidth = SimplifyUIForm->ClientWidth;
	ClientHeight = SimplifyUIForm->ClientHeight;

	SimplifyUIForm->checkColor();

}
void TD3AssistantMainForm::UnSimplify()
{
	SimplifyUIForm->Hide();
//	SimplifyUIForm->Parent = 0;
	D3AssistantMainForm->Menu = D3AssistantMainForm->MainFormMenu;
	D3AssistantMainForm->ShowAllComponents();

	Width = widthBk;
	Height = heightBk;
	PageControl->TabIndex = 2;
	PageControl->TabIndex = 0;

	BorderIcons = BorderIcons << biSystemMenu;
	BorderIcons = BorderIcons << biMinimize;
	BorderIcons = BorderIcons << biMaximize;

	EnableMenuItem( GetSystemMenu( Handle, false), SC_CLOSE, MF_BYCOMMAND | MF_ENABLED );

	D3AssistantMainForm->BorderStyle = bsSizeable;

}


void __fastcall TD3AssistantMainForm::menuSimplifyUI1Click(TObject *Sender)
{

	Simplify();
}
//---------------------------------------------------------------------------


void __fastcall TD3AssistantMainForm::stBarChange(TObject *Sender)
{
	stBar->Hint = stBar->Text;
}
//---------------------------------------------------------------------------


void __fastcall TD3AssistantMainForm::menuCloseClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::menuLanguageClick(TObject *Sender)
{
	TMenuItem *menu = (TMenuItem *)Sender;
	String caption = menu->Caption;

    gSelectedLanguage = caption;
	String menufile = GetInstallPath()+"lang\\"+caption+".ini";

	InitMLTS(menufile);
//	ApplyMLTS(this);

	MessageDlg(MLTS("Program will be restarting for selected language"),mtConfirmation,TMsgDlgButtons()<<mbOK,0);

	SaveEnv();

	AnsiString exe = Application->ExeName;
	ShellExecute(0,"open",exe.c_str(),NULL, NULL, SW_SHOWNORMAL);

    Close();

}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::cbMediaOnlyClick(TObject *Sender)
{
//
	for(int i=1;i<=8;i++)
	{
		String grpname = String("edCurGrp")+i;
		String idname = String("edCurId")+i;
		TEdit *ed1 = (TEdit *)FindComponent(grpname);
		TEdit *ed2 = (TEdit *)FindComponent(idname);
		ed1->Enabled = !cbMediaOnly->Checked;
		ed2->Enabled = !cbMediaOnly->Checked;
	}
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::UnpausedKeyCheckTimerTimer(TObject *Sender)

{
	UnpausedKeyCheckTimer->Enabled = false;

	for(int i=0;i<8;i++)
	{
		keyRow *row = (keyRows+i);
		row->CheckUnpausedKey();
	}
    checkColor();
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::ApplicationEvents1Idle(TObject *Sender, bool &Done)

{
	//
//	Done = true;
	if(MouseClickObject)
	{
		return;
	}
	if(IsForegroundWindow(Handle))
	{
		eventq.clear();
        return;
    }




	while(eventq.size())
	{

		evtq q = eventq.front();
		eventq.pop_front();


		if(q.type==1) // mouse
		{
			if(q.down)
			{
				ProcessMouseDown(q.key);
			}
			else
			{
				ProcessMouseUp(q.key);
			}

		}
		if(q.type==2) // keyboard
		{
			if(q.down)
			{
				OnKeyDownHook(q.key);
			}
			else
			{
				OnKeyUpHook(q.key);
			}

		}
    }

}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::StopwatchTimerTimer(TObject *Sender)
{
	StopwatchTime += StopwatchTimer->Interval/1000.0;

	double eptime = edResetTime->Text.ToInt()/1000.0;
	if(eptime>0)
	{
		if(StopwatchTime>eptime)
		{
			StopwatchTime = 0;
        }
    }

	AnsiString s;
	s.printf("%2.3f sec",StopwatchTime);
	edTimeDisplay->Text = s;


}
//---------------------------------------------------------------------------

