//---------------------------------------------------------------------------
#include <sapi.h>

#include <list>

#include <vcl.h>
#include <IniFiles.hpp>
#pragma hdrstop

#include "TTSManagerFormUnit.h"
#include "UtilFunctions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTTSManagerForm *TTSManagerForm;
//---------------------------------------------------------------------------

/*
enum class SpeechVoiceSpeakFlags
{
  SVSFDefault = 0,
  SVSFlagsAsync = 1,
  SVSFPurgeBeforeSpeak = 2,
  SVSFIsFilename = 4,
  SVSFIsXML = 8,
  SVSFIsNotXML = 16,
  SVSFPersistXML = 32,
  SVSFNLPSpeakPunc = 64,
  SVSFParseSapi = 128,
  SVSFParseSsml = 256,
  SVSFParseAutodetect = 0,
  SVSFNLPMask = 64,
  SVSFParseMask = 384,
  SVSFVoiceMask = 511,
  SVSFUnusedFlags = (int)-512 //0xFFFFFE00
};
*/

std::list<TTTSManagerForm *> ttsforms;

TTTSManagerForm * CreateNewTTSForm()
{
	if(ttsforms.size()==0)
	{
		TTTSManagerForm *form = new TTTSManagerForm(0);
		ttsforms.push_back(form);
		return form;
	}
    return ttsforms.back();
}

void SendKeyToTTS(String key)
{
	std::list<TTTSManagerForm *>::iterator it = ttsforms.begin();
	while(it!=ttsforms.end())
	{
		TTTSManagerForm *form = *it;
		if(form->cbEnable->Checked)
		{
			if(form->edKey->Text==key)
			{
				form->Play();
			}
		}
		it++;
	}
}

void StopAllTTS()
{
	std::list<TTTSManagerForm *>::iterator it = ttsforms.begin();
	while(it!=ttsforms.end())
	{
		TTTSManagerForm *form = *it;
		form->Stop();
		it++;
	}

}


__fastcall TTTSManagerForm::TTTSManagerForm(TComponent* Owner)
	: TForm(Owner)
{
	ActiveControl = 0;
	SpVoice1 = 0;
	MouseClickObject = 0;
	LoadEnv();
	LoadFromFile(OpenFileName);
}
bool TTTSManagerForm::Enabled()
{
	return cbEnable->Checked;
}
String TTTSManagerForm::GetKey()
{
	return edKey->Text;
}

void TTTSManagerForm::ReleaseVoiceModule()
{
	if(SpVoice1)
	{
		SpVoice1->Release();
		SpVoice1 = 0;
	}
}
void TTTSManagerForm::PrepareVoiceModule()
{
	if(SpVoice1) return;
	::CoInitialize(NULL);
	HRESULT hr = CoCreateInstance(::CLSID_SpVoice, NULL, CLSCTX_ALL, ::IID_ISpVoice, (void **)&SpVoice1);

}

void TTTSManagerForm::Stop()
{
	if(SpVoice1==0) return;
	ReleaseVoiceModule();

}


void TTTSManagerForm::Speak()
{
	if(SpVoice1==0) return;

	if(cbTTSToFile->Checked)
	{

//		ISpStream *stm;
//		ISpStream::BindToFile( L"d:\\ttstemp.wav",  SPFM_CREATE_ALWAYS, &stm, 0);

		return;
	}
	SpVoice1->Speak(SpeakString.c_str(), ::SpeechVoiceSpeakFlags::SVSFlagsAsync, NULL);


}

void TTTSManagerForm::Play()
{
	PrepareVoiceModule();
	if(SpVoice1==0) return;

	SpeakString = moTTS->Lines->Text.Trim();
	Speak();

}

void __fastcall TTTSManagerForm::OnVoiceEndStream(System::TObject * Sender,long StreamNumber,VARIANT StreamPosition)
{

}

void __fastcall TTTSManagerForm::OnVoiceSentence(System::TObject * Sender,long StreamNumber/*[in]*/,
	VARIANT StreamPosition/*[in]*/,long CharacterPosition/*[in]*/,long Length/*[in]*/)
{
	Caption = StreamNumber;
}

void __fastcall  TTTSManagerForm::OnWord(System::TObject * Sender,
												   long StreamNumber/*[in]*/,
												   VARIANT StreamPosition/*[in]*/,
												   long CharacterPosition/*[in]*/,
												   long Length/*[in]*/)
{
//	Caption = CharacterPosition;

	String word = SpeakString.SubString(CharacterPosition+1,Length);
	/*
	int L = SpeakString.Length();
	String word;
	int i = CharacterPosition+1;
	while(true)
	{
		if(i>L) break;
		WORD w = SpeakString[i];
		if(w==0 || w==L' ' || w=='<' || w=='\r' || w=='\t' || w=='\n' ) break;
		word = word + wchar_t(w);
		i++;
	}

	if(word==L"repeat")
	{
		Stop();
		Speak();
	}
	*/
	if(cbRepeat->Checked)
	{
		long a = CharacterPosition+Length;
		if(SpeakString.Length()==a)
		{
			Stop();
			Speak();
		}
    }

}



//---------------------------------------------------------------------------
void __fastcall TTTSManagerForm::btnTTSTestClick(TObject *Sender)
{

//	ReleaseVoiceModule();
	PrepareVoiceModule();
	if(SpVoice1==0) return;


	SpeakString = edTTSTest->Text.Trim();
	Speak();

}

void TTTSManagerForm::SaveToFile(String filename)
{
	if(filename.Length()==0)
	{
		filename = ChangeFileExt(Application->ExeName,".ttsmemo");
	}
	moTTS->Lines->SaveToFile(filename);
	stBar->Text = String("Save-"+filename);
	OpenFileName = filename;
}

void TTTSManagerForm::LoadFromFile(String filename)
{
	if(filename.Length()==0)
	{
		filename = ChangeFileExt(Application->ExeName,".ttsmemo");
	}
	if(FileExists(filename))
	{
		moTTS->Lines->LoadFromFile(filename);
		stBar->Text = String("Load-"+filename);

		OpenFileName = filename;
    }
}

void TTTSManagerForm::SaveEnv()
{
	String filename = ChangeFileExt(Application->ExeName,".ttsini");
	TIniFile *ini = new TIniFile(filename);
	ini->WriteString("tts","ttstest",edTTSTest->Text);
	ini->WriteString("tts","edkey",edKey->Text);
	ini->WriteBool("tts","cbenable",cbEnable->Checked);
	ini->WriteString("tts","OpenFileName",OpenFileName);
	delete ini;



}
void TTTSManagerForm::LoadEnv()
{

	String filename = ChangeFileExt(Application->ExeName,".ttsini");
	if(FileExists(filename))
	{
		TIniFile *ini = new TIniFile(filename);
		edTTSTest->Text = ini->ReadString("tts","ttstest","æ»≥Á«œººø‰.<silence msec='3000'/>π›∞©Ω¿¥œ¥Ÿ.");
		edKey->Text = ini->ReadString("tts","edkey","");
		cbEnable->Checked = ini->ReadBool("tts","cbenable",false);
        OpenFileName = ini->ReadString("tts","OpenFileName","");
		delete ini;
	}

}
//---------------------------------------------------------------------------
void __fastcall TTTSManagerForm::btnPlayMemoClick(TObject *Sender)
{
	Play();

}
//---------------------------------------------------------------------------

void __fastcall TTTSManagerForm::FormClose(TObject *Sender, TCloseAction &Action)

{
	SaveEnv();
	Action = caFree;

//	std::list<TTTSManagerForm *>::iterator it = ttsforms.find((TTTSManagerForm *)this);
    ttsforms.remove(this);
}
//---------------------------------------------------------------------------

void __fastcall TTTSManagerForm::btnTTSTagManualClick(TObject *Sender)
{
	ShellExecute(NULL, "open", "https://drive.google.com/open?id=1EULaulOatSNygZHJAQBEEs8q3YCuQeBTe7QZR92v4f4",
			NULL, NULL, SW_SHOWNORMAL);

}
//---------------------------------------------------------------------------

void __fastcall TTTSManagerForm::edKeyKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(MouseClickObject==Sender)
	{
		if(ActiveControl==Sender)
		{
			String str = vk2str(Key);
			TEdit *te = (TEdit *)ActiveControl;
			if(str=="[ESC]")
			{
				if(te->Text.Length())
				{
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

void __fastcall TTTSManagerForm::edKeyKeyPress(TObject *Sender, System::WideChar &Key)

{
	Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TTTSManagerForm::edKeyMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
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

void __fastcall TTTSManagerForm::btnSaveToFileClick(TObject *Sender)
{
	bool r = SaveDialog->Execute();
	if(r==false) return;
	String filename = SaveDialog->FileName;
    SaveToFile(filename);
}
//---------------------------------------------------------------------------

void __fastcall TTTSManagerForm::btnLoadFromFileClick(TObject *Sender)
{
	bool r = OpenDialog->Execute();
	if(r==false) return;
	String filename = OpenDialog->FileName;
    LoadFromFile(filename);
}
//---------------------------------------------------------------------------

void __fastcall TTTSManagerForm::btnStopClick(TObject *Sender)
{
	Stop();
}
//---------------------------------------------------------------------------



void __fastcall TTTSManagerForm::btnCloseClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TTTSManagerForm::btnHideClick(TObject *Sender)
{
    Hide();
}
//---------------------------------------------------------------------------

