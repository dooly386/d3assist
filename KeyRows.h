//---------------------------------------------------------------------------

#ifndef KeyRowsH
#define KeyRowsH
//---------------------------------------------------------------------------
#include <map>

struct keyRow
{
	TEdit *edkey;
	TEdit *eddelay;
	TEdit *edpause;
	TEdit *edactive;
	TTimer *timer;
	TCheckBox *toggle;

	String key;
	int interval;
	String pausekey;
	String activekey;

	bool pushdown;
} ;


struct keyStopRow
{
	TEdit *edname;
	TEdit *edkey;

	String key;
	String name;
};


extern struct keyRow keyRows[8];
extern struct keyStopRow keyStopRows[16];


extern std::map<TTimer *,keyRow *> keyTimerMap;
extern std::map<String,keyRow *> keyPauseMap;
extern std::map<String,keyRow *> keyActiveMap;

extern std::map<String,keyStopRow *> keyStopMap;



#endif
