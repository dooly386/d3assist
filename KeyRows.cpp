//---------------------------------------------------------------------------
#include <map>
#include <vcl.h>

#pragma hdrstop

#include "KeyRows.h"
#include "D3AssistantMainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

struct keyRow keyRows[8];
struct keyStopRow keyStopRows[16];

std::map<TTimer *,keyRow *> keyTimerMap;
std::map<String,std::list<keyRow *>> keyPauseMap;
std::map<String,std::list<keyRow *>> keyActiveMap;


std::map<String,keyStopRow *> keyStopMap;


bool IsForceRunKey(String key)
{
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
				keyRows[i].timer->Interval = 1;
				keyRows[i].timer->Enabled = true;
			}
        }
	}
}

