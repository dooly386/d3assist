//---------------------------------------------------------------------------
#include <map>
#include <vcl.h>

#pragma hdrstop

#include "KeyRows.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

struct keyRow keyRows[8];
struct keyStopRow keyStopRows[16];

std::map<TTimer *,keyRow *> keyTimerMap;
std::map<String,keyRow *> keyPauseMap;
std::map<String,keyRow *> keyActiveMap;


std::map<String,keyStopRow *> keyStopMap;

