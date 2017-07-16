; -- 64Bit.iss --
; Demonstrates installation of a program built for the x64 (a.k.a. AMD64)
; architecture.
; To successfully run this installation and the program it installs,
; you must have a "x64" edition of Windows.

; SEE THE DOCUMENTATION FOR DETAILS ON CREATING .ISS SCRIPT FILES!


[Setup]
AppName=d3assist
AppVersion=1.0.0.5
AppPublisher=DoYoung Kang  (dooly386)
AppPublisherURL=https://github.com/dooly386/d3assist
DefaultDirName={pf32}\d3assist
DefaultGroupName=d3assist
UninstallDisplayIcon={app}\d3assist32.exe
Compression=none
SolidCompression=no
OutputDir=setup
LanguageDetectionMethod=uilanguage

#define MyDateTimeString GetDateTimeString('yyyy-mm-dd hh-nn-ss', '', '');
;OutputBaseFilename=setup_{#MyDateTimeString}
OutputBaseFilename=setup32

; "ArchitecturesAllowed=x64" specifies that Setup cannot run on
; anything but x64.                                                                          
;ArchitecturesAllowed=x64
; "ArchitecturesInstallIn64BitMode=x64" requests that the install be
; done in "64-bit mode" on x64, meaning it should use the native
; 64-bit Program Files directory and the 64-bit view of the registry.
ArchitecturesInstallIn64BitMode=x64

UninstallFilesDir={app}\uninst


[Dirs]
Name: "{app}"; Permissions: everyone-full

[Files]
Source: "..\Final\*"; DestDir: "{app}";



[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "korean"; MessagesFile: "compiler:Languages\Korean.isl"
Name: "dutch"; MessagesFile: "compiler:Languages\Dutch.isl"
Name: "japanese"; MessagesFile: "compiler:Languages\Japanese.isl"
Name: "french"; MessagesFile: "compiler:Languages\French.isl"
Name: "italian"; MessagesFile: "compiler:Languages\Italian.isl"
Name: "spanish"; MessagesFile: "compiler:Languages\Spanish.isl"

[Icons]
Name: "{group}\d3assist"; Filename: "{app}\d3assist32.exe"; Comment: "d3assist win32 application"
Name: "{commondesktop}\d3assist"; Filename: "{app}\d3assist32.exe"; Comment: "d3assist win32 application"

[UninstallDelete]
Type:files; Name: "{app}"


[Run]
;Filename: "{app}\d3assist64.exe"; Description: "d3assist x64 application";