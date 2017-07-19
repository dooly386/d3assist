//---------------------------------------------------------------------------

#ifndef KeyRowsH
#define KeyRowsH
//---------------------------------------------------------------------------
#include <map>
#include <list>

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

	keyRow()
	{
		edkey = 0;
		eddelay = 0;
		edpause = 0;
		edactive = 0;
		timer = 0;
		toggle = 0;

        pushdown = false;

	}

} ;


struct keyStopRow
{

	TEdit *edname;
	TEdit *edkey;

	String key;
	String name;

	int type; // 0 stop, 1 pause, 2 pause hold    , name, name+, name-
	bool paused;

	keyStopRow()
	{
		edname = 0;
		edkey = 0;
		type = 0;
        paused = false;
    }
};

struct keyMacro
{
	MSLLHOOKSTRUCT mouse;
	KBDLLHOOKSTRUCT keybd;
	WPARAM wParam;
    LPARAM lParam;
    String s;
};


extern struct keyRow keyRows[8];
extern struct keyStopRow keyStopRows[16];


extern std::map<TTimer *,keyRow *> keyTimerMap;

extern std::map<String,std::list<keyRow *>> keyPauseMap;
extern std::map<String,std::list<keyRow *>> keyActiveMap;

extern std::map<String,keyStopRow *> keyStopMap;

void GetForceRunKey(const String &key,std::list<keyRow *> &rows);
void ResetMouseDown();



#endif
