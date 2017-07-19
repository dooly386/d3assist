//---------------------------------------------------------------------------
/*
	Programmed by DoYoung Kang
	dooly386@gmail.com
	Copyright(c) dooly386@gmail.com
	2017.7.17
*/
#include <map>
#include <stdio.h>
#include <vcl.h>
#include <IniFiles.hpp>
#include <Tlhelp32.h>
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
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TD3AssistantMainForm *D3AssistantMainForm;
//---------------------------------------------------------------------------

//HKEY_CURRENT_USER\Control Panel\Desktop\LowLevelHooksTimeout
#define USESENDINPUT



HHOOK g_hKeyHook=0;
HHOOK g_hMouseHook=0;

bool pauseKbHook=false;
bool pauseMouseHook = false;






__fastcall TD3AssistantMainForm::TD3AssistantMainForm(TComponent* Owner)
	: TForm(Owner)
{
	bModified = false;
	bPause = false;
	targetHwnd = 0;
	OpenFileName = "";
	bStarted = false;
	pauseKbHook = false;
	pauseMouseHook = false;
	MouseClickObject = 0;
	bLoading = false;
	bRecordStarted = false;
	bPlayStarted = false;


	for(int i=0;i<ComponentCount;i++)
	{
		TComponent *comp = (TComponent *)Components[i];
		if(comp->ClassNameIs("TEdit") && (comp->Tag==1 || comp->Tag==2))
		{
			editlist.push_back((DWORD)comp);
		}
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


	LoadEnv();
	UpdateRecentlyLb();
	StartHook();


	std::list<String> files;
	GetAllFileNames("styles2\\*.vsf",files);

	std::list<String>::iterator it = files.begin();
	while(it!=files.end())
	{
		TMenuItem *p = new TMenuItem(this);
		p->OnClick = MenuSkinDefault->OnClick;
		p->Caption = *it;
		SkinsMenuGroup->Add(p);
		it++;
	}

	SetSkin(SkinName);

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
		if(ini->ValueExists("Setup","edPlayCount"))
		{
			edPlayCount->Text = ini->ReadString("Setup","edPlayCount","1");
		}
		if(ini->ValueExists("Setup","edPlaySpeed"))
		{
			edPlaySpeed->Text = ini->ReadString("Setup","edPlaySpeed","100");
		}



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
	ini->WriteString("Setup","edPlayCount",edPlayCount->Text);
	ini->WriteString("Setup","edPlaySpeed",edPlaySpeed->Text);

	delete ini;

}

void TD3AssistantMainForm::PrepareKeyRows()
{
	keyTimerMap.clear();
	keyPauseMap.clear();
	keyActiveMap.clear();

	keyStopMap.clear();

	TEdit *ed;
	for(int i=0;i<8;i++)
	{
		String keyname = String("edKey")+(i+1);
		String delayname = String("edDelay")+(i+1);
		String poname = String("edPause")+(i+1);
		String activekey = String("edActive")+(i+1);
		String timername = String("Timer")+(i+1);
		String togglename = String("cbToggle")+(i+1);

		keyRows[i].edkey = (TEdit *)FindComponent(keyname);
		keyRows[i].key = keyRows[i].edkey->Text;

		keyRows[i].eddelay = (TEdit *)FindComponent(delayname);
		if(keyRows[i].eddelay->Text.Length())
		{
			keyRows[i].interval = keyRows[i].eddelay->Text.ToInt();
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
		keyRows[i].pausekey = keyRows[i].edpause->Text;

		keyRows[i].edactive = (TEdit *)FindComponent(activekey);
		keyRows[i].activekey = keyRows[i].edactive->Text;

		keyRows[i].timer = (TTimer *)FindComponent(timername);

		keyRows[i].toggle = (TCheckBox *)FindComponent(togglename);
        keyRows[i].pushdown = false;
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


}

void TD3AssistantMainForm::disableRecord(int i)
{
	keyRows[i].edkey->Enabled = false;
	keyRows[i].eddelay->Enabled = false;
	keyRows[i].edpause->Enabled = false;
	keyRows[i].edactive->Enabled = false;
	keyRows[i].toggle->Enabled = false;

}

void TD3AssistantMainForm::checkColor()
{
	for(int i=0;i<8;i++)
	{
		keyRow &row = keyRows[i];
		TColor color = clWindow;
		if(row.timer->Enabled)
		{
			color = clLime;
			if(row.toggle->Checked)
			{
                color = clYellow;
			}
		}
		else
		{
			if(row.timer->Tag==10)
			{
                color = clLtGray;
            }
		}

		if(bPause && row.timer->Tag)
		{
            color = clLtGray;
        }
		row.edkey->Color = color;
		row.eddelay->Color = color;
		row.edpause->Color = color;
		row.edactive->Color = color;
	}
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

	delete ini;

	OpenFileName = filename;
	stBar->SimpleText = OpenFileName;

	UpdateRecentlyFile(filename);

	bModified = false;
	stBar->SimpleText = String("Saved ")+filename;



}
void TD3AssistantMainForm::LoadIni(String filename)
{

	if(FileExists(filename)==false) return;

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


	delete ini;

	OpenFileName = filename;
	UpdateRecentlyFile(OpenFileName);

	bModified = false;

	stBar->SimpleText = String("Load ")+filename;

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
//	if(ActiveControl==0) return;

	/*
	String s;
	s.printf(L"%02x",Key);
	Caption = s;
    */

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
				if(str.Length())
				{
					te->Text = str;
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
	/*
	if(edStart==Sender || edStop==Sender)
	{
		MouseClickObject = Sender;
		return;
	}
	*/
	if(ActiveControl==0) return;

	if(MouseClickObject==Sender)
	{
		TComponent *comp = (TComponent *)Sender;
		if(ActiveControl==Sender && comp->Tag==1)
		{
			if(Button==mbLeft)
			{
				TEdit *te = (TEdit *)Sender;
				te->Text = "[mbLeft]";
			}
			if(Button==mbRight)
			{
				TEdit *te = (TEdit *)Sender;
				te->Text = "[mbRight]";
			}
			if(Button==mbMiddle)
			{
				TEdit *te = (TEdit *)Sender;
				te->Text = "[mbMiddle]";
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
		int r = MessageDlg("Some field(s) modified, do you want to continue?",mtConfirmation,TMsgDlgButtons()<<mbYes<<mbNo,0);
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

	for(int i=0;i<8;i++)
	{
		keyRow &row = keyRows[i];
		if(row.key.Length() && row.interval>0)
		{
			row.timer->Interval = row.interval;
			row.timer->Tag = 10;
		}
	}

	keyPauseMap.clear();
	keyActiveMap.clear();
	for(int i=0;i<8;i++)
	{
		keyRow &row = keyRows[i];
		if(row.timer->Tag==0) continue;
		if(row.timer->Interval==0) continue;

		if(row.pausekey.Length())
		{
			keyPauseMap[row.pausekey].push_back(&row);
		}
		if(row.activekey.Length())
		{
			keyActiveMap[row.activekey].push_back(&row);
		}
	}



	for(int i=0;i<8;i++)
	{
		keyRow &row = keyRows[i];
		if(row.timer->Tag==0) continue;
		if(row.timer->Interval==0) continue;

		if(row.toggle->Checked)
		{
			row.timer->Interval = 1;

        }
		if(row.activekey.Length()==0)
		{
			row.timer->Enabled = true;
		}

	}


	StatusPanel->Caption = "Start";
	StatusPanel->Color = clLime;

	disableEditAll();
	checkColor();
	setBlend();

	if(cbMinimizeWhenStart->Checked)
	{
        WindowState = wsMinimized;
    }


}
void TD3AssistantMainForm::Stop()
{
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

	bStarted = false;
	bPause = false;

	for(int i=0;i<8;i++)
	{
		if(keyRows[i].key.Length() && keyRows[i].pushdown && keyRows[i].timer->Enabled)
		{
			String key = keyRows[i].key;
			if(key=="[mbLeft]")
			{
				MouseUp(mbLeft);
			}
			else
			if(key=="[mbRight]")
			{
				MouseUp(mbRight);
			}
			else
			if(key=="[mbMiddle]")
			{
				MouseUp(mbMiddle);
			}
			else
			if(key.Length()>1)
			{
				char vc = str2vkey(key);
				if(vc)
				{
					unsigned int sc = MapVirtualKey(vc,MAPVK_VK_TO_VSC);
					PushUpKey(vc,sc);
				}
			}
			else
			if(key.Length()==1)
			{
				char vc = key[1];
				unsigned int sc = MapVirtualKey(vc,MAPVK_VK_TO_VSC);
				PushUpKey(vc,sc);
			}
		}

		keyRows[i].timer->Enabled = false;
		keyRows[i].timer->Tag = 0;
		keyRows[i].pushdown = false;

	}
	targetHwnd = 0;

	StopAllTTS();

	StatusPanel->Caption = "Stop";
	StatusPanel->Color = clLtGray;

	enableEditAll();
	checkColor();
	setBlend();

	ActiveControl = 0;
	MouseClickObject = 0;



}

void TD3AssistantMainForm::StartImmediately(String key)
{
	if(cbDoNotStart->Checked) return;
	if(IsForegroundWindow(Handle)) return;
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

		}

	}

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

void TD3AssistantMainForm::OnKeyDownHook(String key)
{
//    stBar->SimpleText = key;
	if(ActiveControl)
	{
		if(ActiveControl->Tag==1)
		{
			return;
		}
	}

	if(key==edStart->Text && (bStarted==false || bPause))
	{
		if(cbDoNotStart->Checked) return;
		Start();
		return;
	}
	if(key==edStop->Text && (bStarted || bPause))
	{
		Stop();
		return;
	}



	if(bStarted==false)
	{
		if(cbDoNotStart->Checked) return;
		StartImmediately(key);
		return;
	}

	if(key=="[ENTER]")
	{
		Stop();
		return;
	}

	SendKeyToTTS(key);

	{
		std::map<String,keyStopRow *>::iterator it = keyStopMap.find(key);
		if(it!=keyStopMap.end())
		{
			keyStopRow *row = it->second;
			if(row->type==0) // force stop
			{
				Stop();
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



	std::map<String,std::list<keyRow *>>::iterator itpause = keyPauseMap.find(key);
	std::map<String,std::list<keyRow *>>::iterator itactive = keyActiveMap.find(key);

	if(itpause!=keyPauseMap.end())
	{
		std::list<keyRow *> &items = itpause->second;
		std::list<keyRow *>::iterator it = items.begin();
		while(it!=items.end())
		{
			keyRow &row = **(it);
			if(row.timer->Tag==0)
			{
				it++;
				continue;
			}
			if(row.timer->Enabled)
			{
				row.timer->Enabled = false;
				checkColor();
			}
			it++;
		}
	}
	if(itactive!=keyActiveMap.end())
	{

		std::list<keyRow *> &items = itactive->second;
		std::list<keyRow *>::iterator it = items.begin();
		while(it!=items.end())
		{
			keyRow &row = **(it);
			if(row.timer->Tag==0)
			{
				it++;
				continue;
			}
			if(row.timer->Enabled==false || row.toggle->Checked)
			{
				row.timer->Enabled = false;
				row.timer->Enabled = true;
				checkColor();
			}
			it++;
		}

	}

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

	{
		std::map<String,std::list<keyRow *>>::iterator it = keyPauseMap.find(key);
		if(it!=keyPauseMap.end())
		{
			std::list<keyRow *>::iterator it2 = it->second.begin();
			while(it2!=it->second.end())
			{
				keyRow &row = **it2;
				if(row.timer->Tag==0)
				{
					it2++;
					continue;
				}
				if(row.timer->Enabled==false)
				{
					row.timer->Enabled = true;
					checkColor();
				}
				it2++;
			}
		}
	}

	{
		std::map<String,std::list<keyRow *>>::iterator it = keyActiveMap.find(key);
		if(it!=keyActiveMap.end())
		{
			std::list<keyRow *>::iterator it2 = it->second.begin();
			while(it2!=it->second.end())
			{
				keyRow &row = **it2;
				if(row.timer->Tag==0)
				{
					it2++;
					continue;
				}

				if(row.timer->Enabled==true && pauseMouseHook==false)
				{
					row.timer->Enabled = false;
					checkColor();
				}
				it2++;
			}
		}
	}


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

	if(key==edStart->Text && bStarted==false)
	{
		if(cbDoNotStart->Checked) return false;
		bStarted = true;
		Start();
		return true;
	}
	if(key==edStop->Text && bStarted)
	{
		bStarted = false;
		Stop();
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
				StartImmediately("[XButton1]");
				return;
			}
			if(btn==2)
			{
				StartImmediately("[XButton2]");
				return;
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
	if(bStarted==false)
	{
		if(ActiveControl && MouseClickObject==ActiveControl)
		{
			TComponent *comp = (TComponent *)ActiveControl;
			if(comp->Tag==1)
			{

				if(key=="[XButton1]" || key=="[XButton2]")
				{
					TEdit *te = (TEdit *)comp;
					te->Text = key;
				}

				ActiveControl = 0;
				MouseClickObject = 0;
				return;
			}
		}

	}

	if(key==edStart->Text && bStarted==false)
	{
		if(cbDoNotStart->Checked) return;
		if(key=="[mbLeft]") return;
		Start();
		bStarted = true;
		return;
	}
	if(key==edStop->Text && bStarted)
	{
		Stop();
		bStarted = false;
		return;
	}

	if(bStarted==false)
	{
		StartImmediately(key);
		return;
	}

	{
		std::map<String,keyStopRow *>::iterator it = keyStopMap.find(key);
		if(it!=keyStopMap.end())
		{
			keyStopRow *row = it->second;
			if(row->type==0)
			{
				Stop();
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


	/*
	{
		std::map<String,std::list<keyRow *>>::iterator it = keyPauseMap.find(key);
		if(it!=keyPauseMap.end())
		{
			std::list<keyRow *>::iterator it2 = it->second.begin();
			while(it2!=it->second.end())
			{
				keyRow &row = **it2;
				if(row.timer->Tag==0)
				{
					it2++;
					continue;
				}
				if(row.timer->Enabled)
				{
					row.timer->Enabled = false;
					checkColor();
				}
				it2++;
			}
		}
	}
    */



	{
		std::map<String,std::list<keyRow *>>::iterator it = keyPauseMap.find(key);
		if(it!=keyPauseMap.end())
		{
			std::list<keyRow *>::iterator it2 = it->second.begin();
			while(it2!=it->second.end())
			{
				keyRow &row = **it2;
				if(row.timer->Tag==0)
				{
					it2++;
					continue;
				}
				if(row.timer->Enabled)
				{
					row.timer->Enabled = false;
					checkColor();
				}
				it2++;
			}
		}
	}

	{
		std::map<String,std::list<keyRow *>>::iterator it = keyActiveMap.find(key);
		if(it!=keyActiveMap.end())
		{
			std::list<keyRow *>::iterator it2 = it->second.begin();
			while(it2!=it->second.end())
			{
				keyRow &row = **it2;
				if(row.timer->Tag==0)
				{
					it2++;
					continue;
				}
				if(row.timer->Enabled==false || row.toggle->Checked)
				{
					row.timer->Enabled = false;
					row.timer->Enabled = true;
					checkColor();
				}
                it2++;
			}
		}
	}


}
void TD3AssistantMainForm::ProcessMouseUp(String key)
{

	{
		std::map<String,std::list<keyRow *>>::iterator it = keyPauseMap.find(key);
		if(it!=keyPauseMap.end())
		{
			std::list<keyRow *>::iterator it2=it->second.begin();
			while(it2!=it->second.end())
			{
				keyRow &row = **it2;
				if(row.timer->Tag==0)
				{
					it2++;
					continue;
				}
				if(row.timer->Enabled==false)
				{
					row.timer->Enabled = true;
					checkColor();
				}
				it2++;
			}
		}
	}

	{
		std::map<String,std::list<keyRow *>>::iterator it = keyActiveMap.find(key);
		if(it!=keyActiveMap.end())
		{
			std::list<keyRow *>::iterator it2=it->second.begin();
			while(it2!=it->second.end())
			{
				keyRow &row = **it2;
				if(row.timer->Tag==0)
				{
					it2++;
					continue;
				}

				if(row.timer->Enabled==true && pauseMouseHook==false)
				{
					row.timer->Enabled = false;
					checkColor();
				}
				it2++;
			}
		}
	}


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


	ProcessMouseDown(key);



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
	if(bStarted==false)
	{
		StopImmediately(key);
        return;
	}

	ProcessMouseUp(key);


}


void TD3AssistantMainForm::PushDownKey(int vcode,int scancode)
{
	if(bPause) return;

	pauseKbHook = true;
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
	pauseKbHook = false;

}

void TD3AssistantMainForm::PushUpKey(int vcode,int scancode)
{
	if(bPause) return;
	pauseKbHook = true;
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
	pauseKbHook = false;
}

void TD3AssistantMainForm::PressKey(int vcode,int scancode)
{
	if(bPause) return;
	pauseKbHook = true;
#ifndef USESENDINPUT
	keybd_event(vcode,scancode,0,0);
	keybd_event(vcode,scancode,KEYEVENTF_KEYUP,0);
#else
	INPUT input[2];
	::ZeroMemory(input, sizeof(input));
	input[0].type = input[1].type = INPUT_KEYBOARD;
	input[0].ki.wVk  = input[1].ki.wVk = vcode;;
	input[1].ki.dwFlags = KEYEVENTF_KEYUP;
	::SendInput(2, input, sizeof(INPUT));
#endif
	pauseKbHook = false;
}



void TD3AssistantMainForm::MouseDown(TMouseButton button)
{
	if(bPause) return;

	pauseMouseHook = true;

#ifndef USESENDINPUT
	if(button==mbLeft)
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		pauseMouseHook = false;
	}
	else
	if(button==mbRight)
	{
		mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
		pauseMouseHook = false;
	}
	else
	if(button==mbMiddle)
	{
		mouse_event(MOUSEEVENTF_MIDDLEDOWN,0,0,0,0);
		pauseMouseHook = false;
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

	pauseMouseHook = false;
}
void TD3AssistantMainForm::MouseUp(TMouseButton button)
{
	if(bPause) return;

	pauseMouseHook = true;

#ifndef USESENDINPUT
	if(button==mbLeft)
	{
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
		pauseMouseHook = false;
	}
	else
	if(button==mbRight)
	{
		mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
		pauseMouseHook = false;
	}
	else
	if(button==mbMiddle)
	{
		mouse_event(MOUSEEVENTF_MIDDLEUP,0,0,0,0);
		pauseMouseHook = false;
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

	pauseMouseHook = false;
}

void TD3AssistantMainForm::MouseClick(TMouseButton button)
{
	if(bPause) return;

	pauseMouseHook = true;
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
	INPUT    input[2];
	::ZeroMemory(input, sizeof(input));

	if(button==mbLeft)
	{
		input[0].type = input[1].type = INPUT_MOUSE;
		input[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		input[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
		::SendInput(2,input,sizeof(INPUT));
	}
	else
	if(button==mbRight)
	{
		input[0].type = input[1].type = INPUT_MOUSE;
		input[0].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
		input[1].mi.dwFlags = MOUSEEVENTF_RIGHTUP;
		::SendInput(2,input,sizeof(INPUT));

	}
	else
	if(button==mbMiddle)
	{
		input[0].type = input[1].type = INPUT_MOUSE;
		input[0].mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
		input[1].mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
		::SendInput(2,input,sizeof(INPUT));

	}

#endif

	pauseMouseHook = false;
}

void __fastcall TD3AssistantMainForm::Timer1Timer(TObject *Sender)
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

	TTimer *timer = (TTimer *)Sender;
	keyRow *lprow = keyTimerMap[timer];
	keyRow &row = *lprow;
	if(row.toggle->Checked)
	{
		row.timer->Interval = row.interval;
	}


	if(row.key=="[mbLeft]")
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
				row.timer->Interval = 1;
				MouseUp(btn);
				checkColor();
			}
		}
		else
		{
			MouseClick(btn);
		}
		return;
	}
	if(row.key=="[mbRight]")
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
				row.timer->Interval = 1;
				MouseUp(btn);
                checkColor();
			}
		}
		else
		{
			MouseClick(btn);
		}
		return;
	}
	if(row.key=="[mbMiddle]")
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
				row.timer->Interval = 1;
				MouseUp(btn);
				checkColor();
			}
		}
		else
		{
			MouseClick(btn);
		}
		return;
	}

	if(row.key.Length()>0)
	{
		char vc = row.key[1];
		if(row.key.Length()>1)
		{
			vc = str2vkey(row.key);
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
				row.timer->Interval = 1;
				row.pushdown = false;
				checkColor();

			}
		}
		else
		{
			PressKey(vc,sc);
			checkColor();
		}
		return;
	}



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
	if(Message.Active)
	{
		Stop();
	}
	setBlend();
}

//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::FormClose(TObject *Sender, TCloseAction &Action)

{
	StopHook();
	SaveEnv();

	KillYolo();

	actionClearRecordExecute(Sender);

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
			OpenFileName = "";
		}
	}

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
	AboutBox->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::FormMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled)
{
	if(ActiveControl==0) return;

	if(MouseClickObject)
	{
		if(ActiveControl->Tag==1)
		{
			TEdit *te = (TEdit *)ActiveControl;
			if(WheelDelta==120)
			{
				te->Text = "[WheelUp]";
			}
			else
			{
				te->Text = "[WheelDn]";
			}
		}
	}

	ActiveControl = 0;
	MouseClickObject = 0;

	Handled = true;
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
	::CreateProcess(filename.c_str(),
	 NULL, NULL, NULL, FALSE, 0, NULL, NULL, &StartupInfo, &ProcessInfo);
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::StopYoloMouseMenuClick(TObject *Sender)
{
	KillYolo();
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::MenuSetYoloMouseTargetProcessClick(TObject *Sender)

{
#ifdef _WIN64
	String InputString= Dialogs::InputBox("Input Target Process Name","Please input target process name(ex:Diablo III64.exe)", "Diablo III64.exe");
#else
	String InputString= Dialogs::InputBox("Input Target Process Name","Please input target process name(ex:Diablo III.exe)", "Diablo III.exe");
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


}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::FormShow(TObject *Sender)
{
	ActiveControl = 0;

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
		int r = MessageDlg("Some field(s) are modified, do you want to exit now?",mtConfirmation,TMsgDlgButtons()<<mbYes<<mbNo,0);
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
	ProtectionAreaManagerForm->Show();

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
	if(name=="Default")
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

void __fastcall TD3AssistantMainForm::ActionListMacroUpdate(TBasicAction *Action,
          bool &Handled)
{
/*
	Handled = true;

	return;
*/
	actionStopRecord->Enabled = bPlayStarted || bRecordStarted;
	if(bRecordStarted || bPlayStarted)
	{
		actionStartRecord->Enabled = false;
		actionPlayRecord->Enabled = false;
		actionClearRecord->Enabled = false;
		actionSaveRecord->Enabled = false;
		actionLoadRecord->Enabled = false;
		lbRecord->Enabled = false;
	}
	else
	{
		actionStartRecord->Enabled = true;
		actionPlayRecord->Enabled = true;
		actionClearRecord->Enabled = true;
		actionSaveRecord->Enabled = true;
		actionLoadRecord->Enabled = true;
		lbRecord->Enabled = true;
	}
    Handled = true;

}
//---------------------------------------------------------------------------

void TD3AssistantMainForm::AddRecord(keyMacro *p)
{
	lbRecord->Items->BeginUpdate();
	int idx = lbRecord->Items->AddObject(p->s,(TObject *)p);
	lbRecord->ItemIndex = idx;
	lbRecord->Items->EndUpdate();
}


void __fastcall TD3AssistantMainForm::actionStartRecordExecute(TObject *Sender)
{
	bRecordStarted = true;
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::actionStopRecordExecute(TObject *Sender)
{
	if(bRecordStarted)
	{
		keyMacro *p = new keyMacro;
		p->s = "[pause]";
        p->wParam = 0;
        AddRecord(p);
    }
	bRecordStarted = false;
	bPlayStarted = false;
	RecordPlayTimer->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::actionPlayRecordExecute(TObject *Sender)
{
	if(lbRecord->Items->Count==0) return;

	bPlayStarted = true;

//	int delay = edPlayDelay->Text.ToInt();

	CurrentPlayCount = 0;
	lbRecord->ItemIndex = 0;

	RecordPlayTimer->Interval = 300;
	RecordPlayTimer->Enabled = false;
	RecordPlayTimer->Enabled = true;


}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::actionClearRecordExecute(TObject *Sender)
{
	for(int i=0;i<lbRecord->Items->Count;i++)
	{
		keyMacro *p = (keyMacro *)lbRecord->Items->Objects[i];
		delete p;
	}
	lbRecord->Items->Clear();


}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::RecordPlayTimerTimer(TObject *Sender)
{
	RecordPlayTimer->Enabled = false;

	int idx = lbRecord->ItemIndex;
	if(idx<0) return;
	keyMacro *p = (keyMacro *)lbRecord->Items->Objects[idx];

	if(p->wParam==WM_LBUTTONDOWN)
	{
		::SetCursorPos(p->mouse.pt.x,p->mouse.pt.y);
		MouseDown(mbLeft);
	}
	if(p->wParam==WM_LBUTTONUP)
	{
		::SetCursorPos(p->mouse.pt.x,p->mouse.pt.y);
		MouseUp(mbLeft);
	}
	if(p->wParam==WM_RBUTTONDOWN)
	{
		::SetCursorPos(p->mouse.pt.x,p->mouse.pt.y);
		MouseDown(mbRight);
	}
	if(p->wParam==WM_RBUTTONUP)
	{
		::SetCursorPos(p->mouse.pt.x,p->mouse.pt.y);
		MouseUp(mbRight);
	}

	idx++;
	if(idx==lbRecord->Items->Count)
	{
		CurrentPlayCount++;
		if(CurrentPlayCount<edPlayCount->Text.ToInt())
		{
			lbRecord->ItemIndex = 0;
			RecordPlayTimer->Interval = 300;
			RecordPlayTimer->Enabled = true;
			return;
		}
		bPlayStarted = false;
		return;
	}

	lbRecord->ItemIndex = idx;

	if(p->wParam)
	{
		keyMacro *p2 = (keyMacro *)lbRecord->Items->Objects[idx];
		if(p2->wParam==0)
		{
			RecordPlayTimer->Interval = 300;
		}
		else
		{
			int d = p2->mouse.time-p->mouse.time;
            if(d<0) d = 300;
			double f = 100.0/edPlaySpeed->Text.ToDouble();
			RecordPlayTimer->Interval = (int)d*f;;
		}
	}
	if(p->wParam==0) // pause
	{
		RecordPlayTimer->Interval = 300;
	}

	RecordPlayTimer->Enabled = true;




}
//---------------------------------------------------------------------------
void TD3AssistantMainForm::SaveMacro(String filename)
{
	FILE *fp = _wfopen(filename.c_str(),L"w");
	if(fp==0) return; // error
	int count = lbRecord->Items->Count;

	fwrite(&count,sizeof(count),1,fp);

	for(int i=0;i<count;i++)
	{
		keyMacro *p2 = (keyMacro *)lbRecord->Items->Objects[i];
		fwrite(&p2->mouse,sizeof(MSLLHOOKSTRUCT),1,fp);
		fwrite(&p2->keybd,sizeof(KBDLLHOOKSTRUCT),1,fp);
		fwrite(&p2->wParam,sizeof(WPARAM),1,fp);
		fwrite(&p2->lParam,sizeof(LPARAM),1,fp);

	}


	fclose(fp);
	edMacroFileName->Text = String("Save-")+filename;
}
void TD3AssistantMainForm::LoadMacro(String filename)
{
	FILE *fp = _wfopen(filename.c_str(),L"r");
	if(fp==0) return; // error

	actionClearRecordExecute(0);

	int count;
	fread(&count,sizeof(count),1,fp);

	for(int i=0;i<count;i++)
	{
		keyMacro *p2 = new keyMacro;
		fread(&p2->mouse,sizeof(MSLLHOOKSTRUCT),1,fp);
		fread(&p2->keybd,sizeof(KBDLLHOOKSTRUCT),1,fp);
		fread(&p2->wParam,sizeof(WPARAM),1,fp);
		fread(&p2->lParam,sizeof(LPARAM),1,fp);

		if(p2->wParam==WM_LBUTTONDOWN)
		{
			p2->s.printf(L"WM_LBUTTONDOWN %d %d %d",p2->mouse.pt.x,p2->mouse.pt.y,p2->mouse.time);
		}
		if(p2->wParam==WM_LBUTTONUP)
		{
			p2->s.printf(L"WM_LBUTTONUP %d %d %d",p2->mouse.pt.x,p2->mouse.pt.y,p2->mouse.time);
		}
		if(p2->wParam==WM_RBUTTONDOWN)
		{
			p2->s.printf(L"WM_RBUTTONDOWN %d %d %d",p2->mouse.pt.x,p2->mouse.pt.y,p2->mouse.time);
		}
		if(p2->wParam==WM_RBUTTONUP)
		{
			p2->s.printf(L"WM_RBUTTONUP %d %d %d",p2->mouse.pt.x,p2->mouse.pt.y,p2->mouse.time);
		}
		if(p2->wParam==0)
		{
			p2->s = "[pause]";
		}

		AddRecord(p2);
	}



	fclose(fp);
	edMacroFileName->Text = String("Load-")+filename;
}

void __fastcall TD3AssistantMainForm::actionSaveRecordExecute(TObject *Sender)
{
	bool r = SaveDialogMacro->Execute();
	if(r==false) return;
	String filename = SaveDialogMacro->FileName;
	SaveMacro(filename);


}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::actionLoadRecordExecute(TObject *Sender)
{
	bool r = OpenDialogMacro->Execute();
	if(r==false) return;
	String filename = OpenDialogMacro->FileName;
    LoadMacro(filename);

}
//---------------------------------------------------------------------------

void __fastcall TD3AssistantMainForm::MenuDebugWindowClick(TObject *Sender)
{
    DebugWindowForm->Show();
}
//---------------------------------------------------------------------------

