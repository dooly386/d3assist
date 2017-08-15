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
#include "DebugWindowFormUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)




extern HHOOK g_hKeyHook;
extern HHOOK g_hMouseHook;
extern std::list<RECT> gProtArea;
extern std::list<evtq> eventq;

bool IsExistLeftDownMouse();
bool IsExistRightDownMouse();
bool IsExistMiddleDownMouse();

char* translate(int vk, int up);


void DBG(String s);

bool CheckKeyState = false;
bool bUseSendQueue = true;


bool altdown = false;
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{

	KBDLLHOOKSTRUCT *kb=(KBDLLHOOKSTRUCT *)lParam;

	altdown = kb->flags & LLKHF_ALTDOWN;
	bool injected = kb->flags & LLKHF_INJECTED;

	if(DebugWindowForm->Visible && DebugWindowForm->cbKbdEvent->Checked)
	{
		String s;
		s.printf(L"nCode=%d,wParam=%x,lParam=%x,vkCode=%x,scCode=%x,flags=%x,time=%d",nCode,wParam,lParam,kb->vkCode,kb->scanCode,kb->flags,kb->time);
		if(altdown)
		{
			s = s+",ALT";
		}
		if(injected)
		{
			s = s+",INJ";
		}
		DBG(s);
	}

	if(injected && D3AssistantMainForm->bStarted)
	{
		return CallNextHookEx( g_hKeyHook, nCode, wParam, lParam );
	}


	int r = -1;
	char *str=0;
	bool processed = false;
	if (wParam == WM_KEYUP || wParam==0x105)
	{
		str = translate(kb->vkCode, 0);
		if(str && str[0])
		{
			if(CheckKeyState && GetKeyState(str)==0)
			{
				return -1;
			}

			keyState[str] = 0;


			r = CallNextHookEx( g_hKeyHook, nCode, wParam, lParam );

			if(bUseSendQueue)
			{
				evtq q;
				q.type = 2;
				q.key = str;
				q.down = false;
				eventq.push_back(q);
			}
			else
			{
				D3AssistantMainForm->OnKeyUpHook(str);

            }

			processed = true;
		}

	}
	else if (wParam == WM_KEYDOWN || wParam==0x104)
	{
		str = translate(kb->vkCode, 0);
		if(str && str[0])
		{
			if(CheckKeyState && GetKeyState(str)==1)
			{
				return -1;
			}

			keyState[str] = 1;


			r = CallNextHookEx( g_hKeyHook, nCode, wParam, lParam );


			if(bUseSendQueue)
			{
				evtq q;
				q.type = 2;
				q.key = str;
				q.down = true;
				eventq.push_back(q);
			}
			else
			{
				D3AssistantMainForm->OnKeyDownHook(str);
			}

			processed = true;
		}
	}
	/*
	else if (wParam==0x104  && kb->vkCode==0xa4) // alt key down
	{
		//altdown = true;
		str = translate(kb->vkCode, 0);
		if(str && str[0])
		{
			r = CallNextHookEx( g_hKeyHook, nCode, wParam, lParam );
			D3AssistantMainForm->OnKeyDownHook(str);
			processed = true;
		}

	}
	*/

	if(processed==false)
	{
		return CallNextHookEx( g_hKeyHook, nCode, wParam, lParam );
	}
	return r;
}




void PauseKeyMouseLeftDown();
bool InsideProtArea(POINT &pt);



LRESULT CALLBACK LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
//	D3AssistantMainForm->Memo1->Lines->Add(nCode);
//	D3AssistantMainForm->Memo1->Lines->Add(GET_XBUTTON_WPARAM(wParam));
//	D3AssistantMainForm->Memo1->Lines->Add(lParam);

	MSLLHOOKSTRUCT *mp = (MSLLHOOKSTRUCT *)lParam;

	bool injected = mp->flags & LLMHF_INJECTED;

	if(DebugWindowForm->Visible && DebugWindowForm->cbMouseEvent->Checked)
	{
		if(wParam!=WM_MOUSEMOVE)
		{
			String s;
			short a = HIWORD(mp->mouseData);
			s.printf(L"nCode=%d,wParam=%x,lParam=%x,mouseData=%d",nCode,wParam,lParam,a);
			if(injected)
			{
				s = s + ",INJ";
			}
			DBG(s);


		}
	}





	int r;
	if(injected)
	{
		if((wParam==WM_LBUTTONDOWN || wParam==WM_RBUTTONDOWN || wParam==WM_MBUTTONDOWN || wParam==WM_LBUTTONUP || wParam==WM_RBUTTONUP || wParam==WM_MBUTTONUP) && D3AssistantMainForm->bStarted)
		{
			if(InsideProtArea(mp->pt))
			{
				return -1;
			}
		}
		r = CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
		return r;
	}


	r = -1;
	bool processed = false;

	if (nCode >= 0)
	{
		if((wParam==WM_LBUTTONDOWN || wParam==WM_RBUTTONDOWN || wParam==WM_MBUTTONDOWN || wParam==WM_LBUTTONUP || wParam==WM_RBUTTONUP || wParam==WM_MBUTTONUP) && D3AssistantMainForm->bStarted)
		{
			if(InsideProtArea(mp->pt))
			{
				return -1;
			}
		}
		switch(wParam)
		{
			case WM_XBUTTONDOWN:
				{
				short a = HIWORD(mp->mouseData);
				String key="[XButton1]";
				if(a==2)
				{
					key="[XButton2]";
				}
				if(CheckKeyState && GetKeyState(key)==1) return -1;

				keyState[key] = 1;

				r = CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
				if(bUseSendQueue)
				{
					evtq q;
					q.type = 1;
					q.key = key;
					q.down = true;
					eventq.push_back(q);
				}
				else
				{
					D3AssistantMainForm->OnMouseXButtonDown(a);
				}
				processed = true;
				break;
				}
			case WM_XBUTTONUP:
				{
				short a = HIWORD(mp->mouseData);
				String key="[XButton1]";
				if(a==2)
				{
					key="[XButton2]";
				}
				if(CheckKeyState && GetKeyState(key)==0) return -1;

				keyState[key] = 0;


				r = CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);

				if(bUseSendQueue)
				{
					evtq q;
					q.type = 1;
					q.key = key;
					q.down = false;
					eventq.push_back(q);
				}
				else
				{
					D3AssistantMainForm->OnMouseXButtonUp(a);
				}
				processed = true;
				break;
				}
			case WM_LBUTTONDOWN:
				if(CheckKeyState && GetKeyState("[mbLeft]")==1)
				{
					return -1;
				}
				keyState["[mbLeft]"] = 1;
				r = CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
				if(bUseSendQueue)
				{
					evtq q;
					q.type = 1;
					q.key = "[mbLeft]";
					q.down = true;
					eventq.push_back(q);
				}
				else
				{
					D3AssistantMainForm->OnMouseDownHook((int)mbLeft,wParam,lParam);

                }

				//			if(D3AssistantMainForm->bStarted) return -1;
				processed = true;
				break;
			case WM_LBUTTONUP:
				if(CheckKeyState && GetKeyState("[mbLeft]")==0)
				{
					return -1;
				}
				keyState["[mbLeft]"] = 0;
				r = CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
				if(bUseSendQueue)
				{
					evtq q;
					q.type = 1;
					q.key = "[mbLeft]";
					q.down = false;
					eventq.push_back(q);
				}
				else
				{
					D3AssistantMainForm->OnMouseUpHook((int)mbLeft,wParam,lParam);
                }


				processed = true;
				break;

			case WM_RBUTTONDOWN:
				if(CheckKeyState && GetKeyState("[mbRight]")==1) return -1;
				keyState["[mbRight]"] = 1;
				r = CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
				if(bUseSendQueue)
				{
					evtq q;
					q.type = 1;
					q.key = "[mbRight]";
					q.down = true;
					eventq.push_back(q);
				}
				else
				{
					D3AssistantMainForm->OnMouseDownHook((int)mbRight,wParam,lParam);
				}


				processed = true;
				break;
			case WM_RBUTTONUP:
				if(CheckKeyState && GetKeyState("[mbRight]")==0) return -1;
				keyState["[mbRight]"] = 0;
				r = CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
				if(bUseSendQueue)
				{
					evtq q;
					q.type = 1;
					q.key = "[mbRight]";
					q.down = false;
					eventq.push_back(q);
				}
				else
				{
					D3AssistantMainForm->OnMouseUpHook((int)mbRight,wParam,lParam);
                }

				processed = true;
				break;
			case WM_MBUTTONDOWN:
				if(CheckKeyState && GetKeyState("[mbMiddle]")==1) return -1;
				keyState["[mbMiddle]"] = 1;
				r = CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);

				if(bUseSendQueue)
				{
					evtq q;
					q.type = 1;
					q.key = "[mbMiddle]";
					q.down = true;
					eventq.push_back(q);
				}
				else
				{
					D3AssistantMainForm->OnMouseDownHook((int)mbMiddle,wParam,lParam);
				}

				processed = true;
				break;
			case WM_MBUTTONUP:
				if(CheckKeyState && GetKeyState("[mbMiddle]")==0) return -1;
				keyState["[mbMiddle]"] = 0;
				r = CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
				if(bUseSendQueue)
				{
					evtq q;
					q.type = 1;
					q.key = "[mbMiddle]";
					q.down = false;
					eventq.push_back(q);
				}
				else
				{
					D3AssistantMainForm->OnMouseUpHook((int)mbMiddle,wParam,lParam);
                }
				processed = true;
				break;
			case WM_MOUSEWHEEL:
				{
				short zDelta = HIWORD(mp->mouseData); // -120 wheel down, 120 wheel up
				String key="[WheelUp]";
				if(zDelta<0)
				{
					key="[WheelDn]";
				}

				if(GetKeyState(key)==0)
				{
					keyState[key] = 1;
				}
				else
				{
					keyState[key] = 0;
				}

				r = CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
				//D3AssistantMainForm->Memo1->Lines->Add(zDelta);
				D3AssistantMainForm->OnMouseWheelHook(zDelta);
				processed = true;
				}
				break;
			}
	}
	if(processed==false)
	{
		return CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
	}
	return r;
}
