/*
	Programmed by DoYoung Kang
	dooly386@gmail.com
	Copyright(c) dooly386@gmail.com
	2017.7.17
*/
//---------------------------------------------------------------------------
#include <vcl.h>
#include <list>

#pragma hdrstop

#include "CallbackFunctions.h"
#include "D3AssistantMainUnit.h"
#include "UtilFunctions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

extern bool pauseKbHook;
extern bool pauseMouseHook;


extern HHOOK g_hKeyHook;
extern HHOOK g_hMouseHook;
extern std::list<RECT> gProtArea;


bool IsExistLeftDownMouse();
bool IsExistRightDownMouse();
bool IsExistMiddleDownMouse();

void ResetMouseDown();
void DBG(String s);
char* translate(int vk, int up);


unsigned long keyRepeatCount[256];
bool keyRepeatCountFlag = false;
bool altdown = false;
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	KBDLLHOOKSTRUCT *kb=(KBDLLHOOKSTRUCT *)lParam;
	/*
	if(keyRepeatCountFlag==false)
	{
		ZeroMemory(keyRepeatCount,sizeof(unsigned long)*256);
		keyRepeatCountFlag = true;
	}


	if(wParam==WM_KEYUP)
	{
		keyRepeatCount[kb->vkCode]=0;
	}

	if(keyRepeatCount[kb->vkCode])
	{
		return -1;
	}

	if(wParam==WM_KEYDOWN)
	{
		keyRepeatCount[kb->vkCode]++;
	}
	*/
//	DBG(kb->vkCode);

//    return -1;

	/*
	String s;
	if(altdown)
	{
		s.printf(L"true,%x",kb->vkCode);
	}
	else
	{
		s.printf(L"false,%x",kb->vkCode);
	}
	D3AssistantMainForm->Caption = s;
	*/

	if(D3AssistantMainForm->PageControl->ActivePage==D3AssistantMainForm->TabSheetMacro)
	{
		if(wParam==WM_KEYDOWN)
		{
			if(kb->vkCode==0x78) // F9
			{
				if(D3AssistantMainForm->bRecordStarted==false)
				{
					D3AssistantMainForm->actionPlayRecord->Execute();
					return -1;
				}

			}
			if(kb->vkCode==0x79) // F10
			{

			}
			if(kb->vkCode==0x7a) // F11
			{
				if(D3AssistantMainForm->bRecordStarted==false)
				{
					D3AssistantMainForm->actionStartRecord->Execute();
					return -1;
				}

			}
			if(kb->vkCode==0x7b) // F12
			{
				if(D3AssistantMainForm->bRecordStarted==true || D3AssistantMainForm->bPlayStarted)
				{
					D3AssistantMainForm->actionStopRecord->Execute();
					return -1;
				}

			}
		}
	}
	if(D3AssistantMainForm->bRecordStarted)
	{
		return CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
	}

	if(pauseKbHook && D3AssistantMainForm->bStarted)
	{
		return CallNextHookEx( g_hKeyHook, nCode, wParam, lParam );
	}

//	KBDLLHOOKSTRUCT *kb=(KBDLLHOOKSTRUCT *)lParam;
	char *str=0;
	if (wParam == WM_KEYUP)
	{
		if(kb->vkCode==0xa4)
		{
			altdown = false;
		}
		str = translate(kb->vkCode, 0);
		if(str && str[0])
		{
			D3AssistantMainForm->OnKeyUpHook(str);

		}

	}
	else if (wParam == WM_KEYDOWN)
	{
		str = translate(kb->vkCode, 0);
		if(str && str[0])
		{
			D3AssistantMainForm->OnKeyDownHook(str);
		}
	}
	else if (wParam==0x104  && kb->vkCode==0xa4) // alt key down
	{
		altdown = true;
		str = translate(kb->vkCode, 0);
		if(str && str[0])
		{
			D3AssistantMainForm->OnKeyDownHook(str);
		}

    }

	return CallNextHookEx( g_hKeyHook, nCode, wParam, lParam );
}




void PauseKeyMouseLeftDown();
bool InsideProtArea(POINT &pt);


LRESULT CALLBACK LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
//	D3AssistantMainForm->Memo1->Lines->Add(nCode);
//	D3AssistantMainForm->Memo1->Lines->Add(GET_XBUTTON_WPARAM(wParam));
//	D3AssistantMainForm->Memo1->Lines->Add(lParam);

	if(D3AssistantMainForm->bRecordStarted)
	{
		MSLLHOOKSTRUCT *p = (MSLLHOOKSTRUCT *)lParam;
		if(wParam==WM_LBUTTONDOWN)
		{
			keyMacro *k = new keyMacro;
			memcpy(&k->mouse,p,sizeof(MSLLHOOKSTRUCT));
			k->wParam = wParam;
			k->lParam = lParam;
			k->s.printf(L"WM_LBUTTONDOWN %d %d %d",p->pt.x,p->pt.y,p->time);
			D3AssistantMainForm->AddRecord(k);
		}
		if(wParam==WM_LBUTTONUP)
		{
			keyMacro *k = new keyMacro;
			memcpy(&k->mouse,p,sizeof(MSLLHOOKSTRUCT));
			k->wParam = wParam;
			k->lParam = lParam;
			k->s.printf(L"WM_LBUTTONUP %d %d %d",p->pt.x,p->pt.y,p->time);
			D3AssistantMainForm->AddRecord(k);
		}
		if(wParam==WM_RBUTTONDOWN)
		{
			keyMacro *k = new keyMacro;
			memcpy(&k->mouse,p,sizeof(MSLLHOOKSTRUCT));
			k->wParam = wParam;
			k->lParam = lParam;
			k->s.printf(L"WM_RBUTTONDOWN %d %d %d",p->pt.x,p->pt.y,p->time);
			D3AssistantMainForm->AddRecord(k);
		}
		if(wParam==WM_RBUTTONUP)
		{
			keyMacro *k = new keyMacro;
			memcpy(&k->mouse,p,sizeof(MSLLHOOKSTRUCT));
			k->wParam = wParam;
			k->lParam = lParam;
			k->s.printf(L"WM_RBUTTONUP %d %d %d",p->pt.x,p->pt.y,p->time);
			D3AssistantMainForm->AddRecord(k);
		}
		return CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
	}

	LRESULT r;
	if(pauseMouseHook)
	{
		if((wParam==WM_LBUTTONDOWN || wParam==WM_RBUTTONDOWN || wParam==WM_MBUTTONDOWN) && D3AssistantMainForm->bStarted)
		{
			MSLLHOOKSTRUCT *p = (MSLLHOOKSTRUCT *)lParam;
			if(InsideProtArea(p->pt))
			{
				return -1;
			}
			r = CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);

			return r;
		}
	}



	if (nCode >= 0)
	{
		if((wParam==WM_LBUTTONDOWN || wParam==WM_RBUTTONDOWN || wParam==WM_MBUTTONDOWN) && D3AssistantMainForm->bStarted)
		{
			MSLLHOOKSTRUCT *p = (MSLLHOOKSTRUCT *)lParam;
			if(InsideProtArea(p->pt))
			{
				return -1;
			}
		}
		switch(wParam)
		{
			case WM_XBUTTONDOWN:
				{
				MSLLHOOKSTRUCT *p = (MSLLHOOKSTRUCT *)lParam;
				short a = HIWORD(p->mouseData);
				D3AssistantMainForm->OnMouseXButtonDown(a);
				break;
				}
			case WM_XBUTTONUP:
				{
				MSLLHOOKSTRUCT *p = (MSLLHOOKSTRUCT *)lParam;
				short a = HIWORD(p->mouseData);
				D3AssistantMainForm->OnMouseXButtonUp(a);
				break;
				}
			case WM_LBUTTONDOWN:
				D3AssistantMainForm->OnMouseDownHook((int)mbLeft,wParam,lParam);
				//			if(D3AssistantMainForm->bStarted) return -1;
				break;
			case WM_LBUTTONUP:
				D3AssistantMainForm->OnMouseUpHook((int)mbLeft,wParam,lParam);
				if(IsExistLeftDownMouse() && D3AssistantMainForm->bStarted)
				{
					ResetMouseDown();
				//				D3AssistantMainForm->MouseDown(mbLeft);
				}
				//			if(D3AssistantMainForm->bStarted) return -1;
				break;

			case WM_RBUTTONDOWN:
				D3AssistantMainForm->OnMouseDownHook((int)mbRight,wParam,lParam);
				break;
			case WM_RBUTTONUP:
				D3AssistantMainForm->OnMouseUpHook((int)mbRight,wParam,lParam);
				if(IsExistRightDownMouse()&& D3AssistantMainForm->bStarted)
				{
					D3AssistantMainForm->MouseDown(mbRight);
				}
				break;
			case WM_MBUTTONDOWN:
				D3AssistantMainForm->OnMouseDownHook((int)mbMiddle,wParam,lParam);
				break;
			case WM_MBUTTONUP:
				D3AssistantMainForm->OnMouseUpHook((int)mbMiddle,wParam,lParam);
				if(IsExistMiddleDownMouse()&& D3AssistantMainForm->bStarted)
				{
					D3AssistantMainForm->MouseDown(mbMiddle);
				}

				break;
			case WM_MOUSEWHEEL:
				{
				MSLLHOOKSTRUCT *p = (MSLLHOOKSTRUCT *)lParam;
				short zDelta = HIWORD(p->mouseData); // -120 wheel down, 120 wheel up
				//D3AssistantMainForm->Memo1->Lines->Add(zDelta);
				D3AssistantMainForm->OnMouseWheelHook(zDelta);
				}
				break;
			}
	}
	return CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
}
