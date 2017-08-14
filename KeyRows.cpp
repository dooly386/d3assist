//---------------------------------------------------------------------------
#include <map>
#include <vcl.h>

#pragma hdrstop

#include "KeyRows.h"
#include "D3AssistantMainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int mininterval=30;
struct keyRow keyRows[8];
struct keyStopRow keyStopRows[16];

std::map<TTimer *,keyRow *> keyTimerMap;
std::map<String,std::list<keyRow *>> keyPauseMap;
std::map<String,std::list<keyRow *>> keyActiveMap;
std::list<keyRow *> keyHoldMap;



std::map<String,keyStopRow *> keyStopMap;


void GetForceRunKey(const String &key,std::list<keyRow *> &rows)
{
	for(int i=0;i<8;i++)
	{
		if(keyRows[i].pausekey==key && keyRows[i].activekey==key)
		{
			rows.push_back(keyRows+i);
		}
	}

}

bool IsExistLeftDownMouse()
{
	std::map<TTimer *,keyRow *>::iterator it = keyTimerMap.begin();
	if(it==keyTimerMap.end()) return false;
	while(it!=keyTimerMap.end())
	{
		if(it->second->pushdown)
		{
			if(it->second->key=="[mbLeft]") return true;
		}
		it++;
	}

	/*
	for(int i=0;i<8;i++)
	{
		if(keyRows[i].key=="[mbLeft]")
		{
			if(keyRows[i].pushdown)
			{
				return true;
			}
		}
	}
	*/
	return false;
}
bool IsExistRightDownMouse()
{
	std::map<TTimer *,keyRow *>::iterator it = keyTimerMap.begin();
	if(it==keyTimerMap.end()) return false;
	while(it!=keyTimerMap.end())
	{
		if(it->second->pushdown)
		{
			if(it->second->key=="[mbRight]") return true;
		}
		it++;
	}
	/*
	for(int i=0;i<8;i++)
	{
		if(keyRows[i].key=="[mbRight]")
		{
			if(keyRows[i].pushdown)
			{
				return true;
			}
		}
	}
    */
	return false;
}
bool IsExistMiddleDownMouse()
{
	std::map<TTimer *,keyRow *>::iterator it = keyTimerMap.begin();
	if(it==keyTimerMap.end()) return false;
	while(it!=keyTimerMap.end())
	{
		if(it->second->pushdown)
		{
			if(it->second->key=="[mbMiddle]") return true;
		}
		it++;
	}

/*	for(int i=0;i<8;i++)
	{
		if(keyRows[i].key=="[mbMiddle]")
		{
			if(keyRows[i].pushdown)
			{
				return true;
			}
		}
	}
*/
	return false;
}


void PauseKeyMouseLeftDown()
{
	for(int i=0;i<8;i++)
	{
		if(keyRows[i].interval>0)
		{
			if(keyRows[i].pausekey=="[mbLeft]")
			{
				keyRows[i].timer->Enabled = false;
				D3AssistantMainForm->checkColor();
			}
		}
	}

}

void ResetMouseDown()
{
	for(int i=0;i<8;i++)
	{
		if(keyRows[i].interval>0)
		{
			if(keyRows[i].pushdown && keyRows[i].toggle->Checked && keyRows[i].activekey.Length()==0)
			{
				keyRows[i].pushdown = false;
				keyRows[i].timer->Enabled = false;
				keyRows[i].timer->Interval = mininterval;
				keyRows[i].timer->Enabled = true;
			}
        }
	}
}





keyRow::keyRow()
{
	edkey = 0;
	edinit = 0;
	eddelay = 0;
	edpause = 0;
	edactive = 0;
	eddesc = 0;

	timer = 0;
	toggle = 0;

	initial = 0;
	interval = 0;
	pausecount = 0;

	pushdown = false;
	enabled = false;
	paused = false;
}
void keyRow::clear()
{
	pausecount = 0;
	activecount = 0;
	pushdown = false;
	enabled = false;
	paused = false;

	keys.clear();
	keysand.clear();
	pausekeys.clear();
	activekeys.clear();
	pausekeysand.clear();
	activekeysand.clear();
}


void keyRow::SendToAppKey(keyRow &row,String &key,int opt)
{

	if(key=="[mbLeft]")
	{
		TMouseButton btn = mbLeft;
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

		return;
	}
	if(key=="[mbRight]")
	{
		TMouseButton btn = mbRight;
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
		return;
	}
	if(key=="[mbMiddle]")
	{
		TMouseButton btn = mbMiddle;
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
		return;
	}
	if(key=="[XButton1]")
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
		return;
	}

	if(key=="[XButton2]")
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
		return;
	}

}

int keyRow::GetKeyState(const String &key)
{
	if(keyState.find(key)==keyState.end()) return 0; // no state
	return keyState[key]; // 1 press, 0 release

}

void keyRow::TimerOn()
{
	timer->Enabled = false;
	if(initial)
	{
		timer->Interval = initial;
	}
	else
	{
		timer->Interval = mininterval;
	}
	timer->Enabled = true;
}
void keyRow::TimerOff()
{
	timer->Enabled = false;

	if(D3AssistantMainForm->cbKeyReleaseWhenTimerOff->Checked)
	{
		if(keyState.find(key)!=keyState.end())
		{
			if(keyState[key]==1)
			{
				keyState[key] = 0;
				SendToAppKey(2); // key up;
			}
		}
    }

}

void keyRow::ProcessPause()
{
	if(pausekey.Length()==0) return;


	if(pausekeysand.size())
	{
		if(GetKeyState(pausekey)==0)
		{
			paused = false;
			return;
		}
		std::set<String>::iterator it = pausekeysand.begin();
		while(it!=pausekeysand.end())
		{
			if(GetKeyState(*it)==0)
			{
				paused = false;
				return;
			}
			it++;
		}
		paused = true;
		TimerOff();
		return;
	}

	if(GetKeyState(pausekey)==1)
	{
		paused = true;
		TimerOff();
		return;
	}

	std::set<String>::iterator it = pausekeys.begin();
	while(it!=pausekeys.end())
	{
		if(GetKeyState(*it)==1)
		{
			paused = true;
			TimerOff();
			return;
		}
		it++;

	}

	paused = false;
	return;
}

int iii = 0;
void keyRow::ProcessActive()
{
//		if(timer->Enabled) return true;

//	D3AssistantMainForm->Caption = activekey;

	if(activekey.Length()==0) return;

	if(activekeysand.size())
	{
		if(GetKeyState(activekey)==0)
		{
			TimerOff();
			return;
		}

		std::set<String>::iterator it = activekeysand.begin();
		while(it!=activekeysand.end())
		{
			if(GetKeyState(*it)==0)
			{
				TimerOff();
				return;
			}
			it++;
		}
		TimerOn();

		return;
	}

	if(GetKeyState(activekey)==1)
	{
		TimerOn();
		return;
	}
	std::set<String>::iterator it = activekeys.begin();
	while(it!=activekeys.end())
	{
		if(GetKeyState(*it)==1)
		{
			TimerOn();
			return;
		}
		it++;
	}


	TimerOff();
	return;
}


void keyRow::CheckUnpausedKey()
{
	if(enabled==false) return;

	if(paused==false && timer->Enabled==false && activekey.Length()==0 && pausekey.Length())
	{
		SendToAppKey(2);
		TimerOff();
		TimerOn();
	}
}

void keyRow::ProcessKeyDown(const String &key)
{
	if(enabled==false) return;

	keyState[key] = 1;
	ProcessActive();
	ProcessPause();
//		MessageBeep(-1);
}

void keyRow::ProcessKeyUp(const String &key)
{
	if(enabled==false) return;
	keyState[key] = 0;

	ProcessPause();
	ProcessActive();

    CheckUnpausedKey();

}

void keyRow::SendToAppKey(int opt)
{
	if(enabled==false) return;
	SendToAppKey(*this,key,opt);

	{
		std::list<String>::iterator it = keys.begin();
		while(it!=keys.end())
		{
			SendToAppKey(*this,*it,opt);
			it++;
		}
	}
    {
		std::list<String>::iterator it2 = keysand.begin();
		while(it2!=keysand.end())
		{
			SendToAppKey(*this,*it2,opt);
			it2++;
		}

	}


}

void keyRow::ProcessTimer()
{
	if(enabled==false) return;
	timer->Enabled = false;
	timer->Interval = interval;

	if(toggle->Checked)
	{
		SendToAppKey(2);
		SendToAppKey(1);
	}
	else
	{
		if(keysand.size()==0)
		{
			SendToAppKey(*this,key,0);
			std::list<String>::iterator it = keys.begin();
			while(it!=keys.end())
			{
				SendToAppKey(*this,*it,0); // click
				it++;
			}
		}
		else
		{
			SendToAppKey(*this,key,1);
			std::list<String>::iterator it = keysand.begin();
			while(it!=keysand.end())
			{
				SendToAppKey(*this,*it,1); // down
				it++;
			}

			SendToAppKey(*this,key,2);
			std::list<String>::iterator it2 = keysand.begin();
			while(it2!=keysand.end())
			{
				SendToAppKey(*this,*it2,2); // up
				it2++;
			}

		}
    }

	timer->Enabled = true;
//        MessageBeep(-1);


}

