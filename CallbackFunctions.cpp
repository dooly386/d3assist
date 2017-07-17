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


LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if(pauseKbHook)
	{
		return CallNextHookEx( g_hKeyHook, nCode, wParam, lParam );
	}
	KBDLLHOOKSTRUCT *kb=(KBDLLHOOKSTRUCT *)lParam;
	char *str=0;
	if (wParam == WM_KEYUP)
	{
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

	return CallNextHookEx( g_hKeyHook, nCode, wParam, lParam );
}




void PauseKeyMouseLeftDown();
bool InsideProtArea(POINT &pt);


LRESULT CALLBACK LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
//	D3AssistantMainForm->Memo1->Lines->Add(nCode);
//	D3AssistantMainForm->Memo1->Lines->Add(GET_XBUTTON_WPARAM(wParam));
//	D3AssistantMainForm->Memo1->Lines->Add(lParam);


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
		}
		r = CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
		return r;
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
			break;
		case WM_LBUTTONUP:
			D3AssistantMainForm->OnMouseUpHook((int)mbLeft,wParam,lParam);
			if(IsExistLeftDownMouse())
			{
				ResetMouseDown();
//				D3AssistantMainForm->MouseDown(mbLeft);
			}

			break;
		case WM_RBUTTONDOWN:
			D3AssistantMainForm->OnMouseDownHook((int)mbRight,wParam,lParam);
			break;
		case WM_RBUTTONUP:
			D3AssistantMainForm->OnMouseUpHook((int)mbRight,wParam,lParam);
			if(IsExistRightDownMouse())
			{
				D3AssistantMainForm->MouseDown(mbRight);
			}
			break;
		case WM_MBUTTONDOWN:
			D3AssistantMainForm->OnMouseDownHook((int)mbMiddle,wParam,lParam);
			break;
		case WM_MBUTTONUP:
			D3AssistantMainForm->OnMouseUpHook((int)mbMiddle,wParam,lParam);
			if(IsExistMiddleDownMouse())
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
