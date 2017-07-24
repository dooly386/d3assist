; -- 64Bit.iss --
; Demonstrates installation of a program built for the x64 (a.k.a. AMD64)
; architecture.
; To successfully run this installation and the program it installs,
; you must have a "x64" edition of Windows.

; SEE THE DOCUMENTATION FOR DETAILS ON CREATING .ISS SCRIPT FILES!


[Setup]
AppName=d3assist
AppVersion=1.0.2.xx
AppPublisher=DoYoung Kang  (dooly386@gmail.com)
AppPublisherURL=https://github.com/dooly386/d3assist
DefaultDirName={pf}\d3assist
DefaultGroupName=d3assist
UninstallDisplayIcon={app}\d3assist64.exe                                                                                       
Compression=none
SolidCompression=no
OutputDir=setup
LanguageDetectionMethod=uilanguage

#define MyDateTimeString GetDateTimeString('yyyy-mm-dd hh-nn-ss', '', '');
;OutputBaseFilename=setup_{#MyDateTimeString}
OutputBaseFilename=setup64

; "ArchitecturesAllowed=x64" specifies that Setup cannot run on
; anything but x64.
ArchitecturesAllowed=x64
; "ArchitecturesInstallIn64BitMode=x64" requests that the install be
; done in "64-bit mode" on x64, meaning it should use the native
; 64-bit Program Files directory and the 64-bit view of the registry.
ArchitecturesInstallIn64BitMode=x64

UninstallFilesDir={app}\uninst


[Dirs]
Name: "{app}"; Permissions: everyone-full;


[Files]
Source: "..\Final\D3Assist32.exe"; DestDir: "{app}"; Flags: ignoreversion;
Source: "..\Final\D3Assist64.exe"; DestDir: "{app}"; Flags: ignoreversion;
Source: "..\Final\YoloMouse32.exe"; DestDir: "{app}"; Flags: ignoreversion;
Source: "..\Final\YoloMouse64.exe"; DestDir: "{app}"; Flags: ignoreversion;
Source: "..\Final\Yolo32.dll"; DestDir: "{app}"; Flags: ignoreversion;
Source: "..\Final\Yolo64.dll"; DestDir: "{app}"; Flags: ignoreversion;

Source: "..\Final\Cursors\Default\*"; DestDir: "{app}\Cursors\Default";
Source: "..\Final\styles2\*.*"; DestDir: "{app}\styles2";
Source: "..\Final\tts\*.*"; DestDir: "{app}\tts";

Source: "..\readme.htm"; DestDir: "{app}";
Source: "..\LICENSE"; DestDir: "{app}";



[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "korean"; MessagesFile: "compiler:Languages\Korean.isl"
Name: "dutch"; MessagesFile: "compiler:Languages\Dutch.isl"
Name: "japanese"; MessagesFile: "compiler:Languages\Japanese.isl"
Name: "french"; MessagesFile: "compiler:Languages\French.isl"
Name: "italian"; MessagesFile: "compiler:Languages\Italian.isl"
Name: "spanish"; MessagesFile: "compiler:Languages\Spanish.isl"

[Icons]
Name: "{group}\d3assist64"; Filename: "{app}\d3assist64.exe"; Comment: "d3assist x64 application"
Name: "{commondesktop}\d3assist64"; Filename: "{app}\d3assist64.exe"; Comment: "d3assist x64 application"
[UninstallDelete]
Type:files; Name: "{app}"


[Run]
;Filename: "{app}\d3assist64.exe"; Description: "d3assist x64 application";