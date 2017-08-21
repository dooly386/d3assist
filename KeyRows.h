//---------------------------------------------------------------------------

#ifndef KeyRowsH
#define KeyRowsH
//---------------------------------------------------------------------------
#include <map>
#include <list>
#include <set>
#include <UtilFunctions.h>

extern std::map<String,int> keyState;  //0 up, 1 down
extern int mininterval;
class keyRow
{
public:
	TEdit *edkey;
    TEdit *edinit;
	TEdit *eddelay;
	TEdit *edpause;
	TEdit *edactive;
    TEdit *eddesc;
	TTimer *timer;
	TCheckBox *toggle;

	String key;
	std::list<String> keys;
	std::list<String> keysand;

	int initial; // inital interval
	int interval; // seq interval

	String pausekey;
	std::set<String> pausekeys;
	std::set<String> pausekeysand;

	String activekey;
	std::set<String> activekeys;
	std::set<String> activekeysand;

	bool pushdown;
	int pausecount;
	int activecount;

	bool enabled;
    bool paused;


	keyRow();
	void clear();
    void SendToAppKey(int opt);
	void SendToAppKey(keyRow &row,String &key,int opt);
	void TimerOn();
	void TimerOff();

	void ProcessPause(const String &key);
	void ProcessActive(const String &key);

	void ProcessKeyDown(const String &key);
	void ProcessKeyUp(const String &key);
	void ProcessTimer();
	void CheckUnpausedKey();

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
extern std::list<keyRow *> keyHoldMap;

extern std::map<String,keyStopRow *> keyStopMap;

void GetForceRunKey(const String &key,std::list<keyRow *> &rows);
void ResetMouseDown();


struct evtq
{
	int type; // 1 mouse, 2 keyboard
	bool down; // 1 down, 2 up
    String key;
};

#endif
