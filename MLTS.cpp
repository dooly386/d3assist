//---------------------------------------------------------------------------
#include <map>
#include <vcl.h>
#include <IniFiles.hpp>

#pragma hdrstop

#include "MLTS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


std::map<String,String> mltsmap;


void InitMLTS(String filename)
{
	mltsmap.clear();

	TIniFile *ini = new TIniFile(filename);

	TStringList *strs = new TStringList;
	ini->ReadSection("lang",strs);
	for(int i=0;i<strs->Count;i++)
	{
		String key = strs->Strings[i];
		String value = ini->ReadString("lang",key,key);
        mltsmap[key] = value;
    }

	delete strs;
	delete ini;
//	mltsmap["Save"] = "저장";
//    mltsmap["Load"] = "읽기";
}


String MLTS(const String &s)
{

	if(mltsmap.find(s)==mltsmap.end()) return s;
	return mltsmap[s];
}


void ApplyMLTS(TForm *form)
{
	PPropInfo propinfo;

	for(int i=0;i<form->ComponentCount;i++)
	{
		TComponent *comp = form->Components[i];
		propinfo = GetPropInfo(comp,"Caption");
		if(propinfo)
		{
			String s = GetStrProp(comp,"Caption");
			SetStrProp(comp,"Caption",MLTS(s));
		}
    }
}
