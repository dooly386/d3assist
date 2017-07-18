//---------------------------------------------------------------------------

#include <vcl.h>
#include <IniFiles.hpp>
#pragma hdrstop

#include "TTSManagerFormUnit.h"
#include "SpeechLib_OCX.h"
#include "SpeechLib_TLB.h"
#include "UtilFunctions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTTSManagerForm *TTSManagerForm;
//---------------------------------------------------------------------------
Speechlib_tlb::TSpVoice *SpVoice1;

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

__fastcall TTTSManagerForm::TTTSManagerForm(TComponent* Owner)
	: TForm(Owner)
{
	ActiveControl = 0;
	SpVoice1 = 0;
	MouseClickObject = 0;
    LoadEnv();
}
bool TTTSManagerForm::Enabled()
{
	return cbEnable->Checked;
}
String TTTSManagerForm::GetKey()
{
	return edKey->Text;
}
void TTTSManagerForm::Play()
{
	if(SpVoice1)
	{
		delete SpVoice1;
		SpVoice1 = 0;
	}

	try
	{
		SpVoice1 = new Speechlib_tlb::TSpVoice(this);
		SpVoice1->Volume = 100;

		int opt = (int)SpeechVoiceSpeakFlags::SVSFlagsAsync;
		opt = opt | (int)SpeechVoiceSpeakFlags::SVSFIsXML;
		SpVoice1->Speak(moTTS->Lines->Text.c_str(),(SpeechVoiceSpeakFlags)opt);
	}
	catch(...)
	{

	}

}
//---------------------------------------------------------------------------
void __fastcall TTTSManagerForm::btnTTSTestClick(TObject *Sender)
{

	if(SpVoice1)
	{
		delete SpVoice1;
		SpVoice1 = 0;
	}

	try
	{
		SpVoice1 = new Speechlib_tlb::TSpVoice(this);
		SpVoice1->Volume = 100;

		int opt = (int)SpeechVoiceSpeakFlags::SVSFlagsAsync;
		opt = opt | (int)SpeechVoiceSpeakFlags::SVSFIsXML;
		SpVoice1->Speak(edTTSTest->Text.c_str(),(SpeechVoiceSpeakFlags)opt);
	}
	catch(...)
	{

    }

}
void TTTSManagerForm::SaveEnv()
{
	String filename = ChangeFileExt(Application->ExeName,".ttsini");
	TIniFile *ini = new TIniFile(filename);
	ini->WriteString("tts","ttstest",edTTSTest->Text);
	ini->WriteString("tts","edkey",edKey->Text);
	ini->WriteBool("tts","cbenable",cbEnable->Checked);
	delete ini;

	String filenamememo = ChangeFileExt(Application->ExeName,".ttsmemo");
    moTTS->Lines->SaveToFile(filenamememo);

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
		delete ini;

		String filenamememo = ChangeFileExt(Application->ExeName,".ttsmemo");
		if(FileExists(filenamememo))
		{
			moTTS->Lines->LoadFromFile(filenamememo);
		}

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
    MouseClickObject = Sender;
}
//---------------------------------------------------------------------------

