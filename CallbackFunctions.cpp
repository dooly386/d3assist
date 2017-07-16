/*
	Programmed by DoYoung Kang
	dooly386@gmail.com
	Copyright(c) dooly386@gmail.com
	2017.7.17
*/
//---------------------------------------------------------------------------
#include <vcl.h>

#pragma hdrstop

#include "CallbackFunctions.h"
#include "D3AssistantMainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

extern bool pauseKbHook;
extern bool pauseMouseHook;


extern HHOOK g_hKeyHook;
extern HHOOK g_hMouseHook;


bool IsExistLeftDownMouse();
bool IsExistRightDownMouse();
bool IsExistMiddleDownMouse();

void ResetMouseDown();
void DBG(String s);

int shift = 0, caps = 0 , ctrl=0;
char* translate(int vk, int up)
{
	/*
	if (up)
	{
		if ((vk == 0x10) || (vk == 0xa0) || (vk == 0xa1)) shift = 0;
		if(vk==0xa2) ctrl = 0;
		return 0;
	} else if ((vk==0x10)||(vk==0xa0)||(vk==0xa1))
	{
		shift=1; return 0;
	}
	shift = 0;

	if(vk==0xa2)
	{
		ctrl = 1;
		return 0;
	}
    */

	static char buf[16];
	memset(buf, 0, 16);

	switch (vk)
	{
		case 0x08: strcpy(buf, "[BS]"); return buf;
		case 0x09: strcpy(buf, "[TAB]"); return buf;
		case 0x0d: strcpy(buf, "[ENTER]"); return buf;
		case 0x25: strcpy(buf, "[LT]"); return buf;
		case 0x26: strcpy(buf, "[UP]"); return buf;
		case 0x27: strcpy(buf, "[RT]"); return buf;
		case 0x28: strcpy(buf, "[DN]"); return buf;
		case 27: strcpy(buf, "[ESC]"); return buf;
		case 46: strcpy(buf,"[DEL]"); return buf;
		case 45: strcpy(buf,"[INS]"); return buf;
		case 36: strcpy(buf,"[HOME]"); return buf;
		case 35: strcpy(buf,"[END]"); return buf;
		case 33: strcpy(buf,"[PGUP]"); return buf;
		case 34: strcpy(buf,"[PGDN]"); return buf;
		case 19: strcpy(buf,"[PAUSE]"); return buf;
	}


		if (vk > 0x69 && vk < 0x70)
		{
			buf[0] = (char)(vk - 0x40);
		} else if (vk > 0x6f && vk < 0x88)
		{
			sprintf(buf, "[F%d]", vk - 0x6f);
		} else if (isalpha(vk))
		{
			if (!caps)
				if (shift) { buf[0] = (char)(toupper(vk)); } else { buf[0] = (char)(toupper(vk)); }
			else
				if (!shift) { buf[0] = (char)(toupper(vk)); } else { buf[0] = (char)(toupper(vk)); }
		} else {
			switch (vk)
			{
				case '1': if (!shift) {buf[0]=(char)vk;} else {buf[0]='!';} break;
				case '2': if (!shift) {buf[0]=(char)vk;} else {buf[0]='@';} break;
				case '3': if (!shift) {buf[0]=(char)vk;} else {buf[0]='#';} break;
				case '4': if (!shift) {buf[0]=(char)vk;} else {buf[0]='$';} break;
				case '5': if (!shift) {buf[0]=(char)vk;} else {buf[0]='%';} break;
				case '6': if (!shift) {buf[0]=(char)vk;} else {buf[0]='^';} break;
				case '7': if (!shift) {buf[0]=(char)vk;} else {buf[0]='&';} break;
				case '8': if (!shift) {buf[0]=(char)vk;} else {buf[0]='*';} break;
				case '9': if (!shift) {buf[0]=(char)vk;} else {buf[0]='(';} break;
				case '0': if (!shift) {buf[0]=(char)vk;} else {buf[0]=')';} break;
				case 0xba: if (!shift) {buf[0]=';';} else {buf[0]=':';} break;
				case 0xbb: if (!shift) {buf[0]='=';} else {buf[0]='+';} break;
				case 0xbc: if (!shift) {buf[0]=',';} else {buf[0]='<';} break;
				case 0xbd: if (!shift) {buf[0]='-';} else {buf[0]='_';} break;
				case 0xbe: if (!shift) {buf[0]='.';} else {buf[0]='>';} break;
				case 0xbf: if (!shift) {buf[0]='/';} else {buf[0]='?';} break;
				case 0xc0: if (!shift) {buf[0]='`';} else {buf[0]='~';} break;
				case 0xdb: if (!shift) {buf[0]='[';} else {buf[0]='{';} break;
				case 0xdc: if (!shift) {buf[0]='\\';} else {buf[0]='|';} break;
				case 0xdd: if (!shift) {buf[0]=']';} else {buf[0]='}';} break;
				case 0xde: if (!shift) {buf[0]='\'';} else {buf[0]='\"';} break;
			}
		}
	/*
	if(ctrl)
	{
		char temp[128];
		strcpy(temp,buf);
		sprintf(buf,"CTRL+%s",temp);
	}
    */
	return buf;
}


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


LRESULT CALLBACK LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
//	D3AssistantMainForm->Memo1->Lines->Add(nCode);
//	D3AssistantMainForm->Memo1->Lines->Add(GET_XBUTTON_WPARAM(wParam));
//	D3AssistantMainForm->Memo1->Lines->Add(lParam);


	LRESULT r;
	if(pauseMouseHook)
	{
		r = CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
		return r;
	}




  if (nCode >= 0)
  {
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
