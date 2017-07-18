// ************************************************************************ //
// WARNING                                                                    
// -------                                                                    
// The types declared in this file were generated from data read from a       
// Type Library. If this type library is explicitly or indirectly (via        
// another type library referring to this type library) re-imported, or the   
// 'Refresh' command of the Type Library Editor activated while editing the   
// Type Library, the contents of this file will be regenerated and all        
// manual modifications will be lost.                                         
// ************************************************************************ //

// $Rev: 52393 $
// File generated on 2017-07-18 오전 8:40:25 from Type Library described below.

// ************************************************************************  //
// Type Lib: C:\WINDOWS\System32\Speech\Common\sapi.dll (1)
// LIBID: {C866CA3A-32F7-11D2-9602-00C04F8EE628}
// LCID: 0
// Helpfile: 
// HelpString: Microsoft Speech Object Library
// DepndLst: 
//   (1) v2.0 stdole, (C:\Windows\SysWOW64\stdole2.tlb)
// SYS_KIND: SYS_WIN32
// Errors:
//   Error creating palette bitmap of (TSpNotifyTranslator) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpObjectTokenCategory) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpObjectToken) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpResourceManager) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpStreamFormatConverter) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpMMAudioEnum) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpMMAudioIn) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpMMAudioOut) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpStream) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpVoice) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpSharedRecoContext) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpInprocRecognizer) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpSharedRecognizer) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpLexicon) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpUnCompressedLexicon) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpCompressedLexicon) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpShortcut) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpPhoneConverter) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpPhoneticAlphabetConverter) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpNullPhoneConverter) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpTextSelectionInformation) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpPhraseInfoBuilder) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpAudioFormat) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpWaveFormatEx) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpInProcRecoContext) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpCustomStream) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpFileStream) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
//   Error creating palette bitmap of (TSpMemoryStream) : Server C:\WINDOWS\System32\Speech\Common\sapi.dll contains no icons
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include <olectrls.hpp>
#include <oleserver.hpp>
#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#pragma option -w-8122
#include "SpeechLib_OCX.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Speechlib_tlb
{

ISpNotifyTranslatorPtr& TSpNotifyTranslator::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpNotifyTranslator::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpNotifyTranslator::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpNotifyTranslator::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpNotifyTranslator::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpNotifyTranslator::ConnectTo(ISpNotifyTranslatorPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpNotifyTranslator::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpNotifyTranslator;
  sd.IntfIID = __uuidof(ISpNotifyTranslator);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

void __fastcall TSpNotifyTranslator::Notify(void)
{
  GetDefaultInterface()->Notify();
}

void __fastcall TSpNotifyTranslator::InitWindowMessage(Speechlib_tlb::wireHWND hWnd/*[in]*/, 
                                                       unsigned Msg/*[in]*/, 
                                                       Speechlib_tlb::UINT_PTR wParam/*[in]*/, 
                                                       Speechlib_tlb::LONG_PTR lParam/*[in]*/)
{
  GetDefaultInterface()->InitWindowMessage(hWnd/*[in]*/, Msg/*[in]*/, wParam/*[in]*/, lParam/*[in]*/);
}

void __fastcall TSpNotifyTranslator::InitCallback(void** pfnCallback/*[in]*/, 
                                                  Speechlib_tlb::UINT_PTR wParam/*[in]*/, 
                                                  Speechlib_tlb::LONG_PTR lParam/*[in]*/)
{
  GetDefaultInterface()->InitCallback(pfnCallback/*[in]*/, wParam/*[in]*/, lParam/*[in]*/);
}

void __fastcall TSpNotifyTranslator::InitSpNotifyCallback(void** pSpCallback/*[in]*/, 
                                                          Speechlib_tlb::UINT_PTR wParam/*[in]*/, 
                                                          Speechlib_tlb::LONG_PTR lParam/*[in]*/)
{
  GetDefaultInterface()->InitSpNotifyCallback(pSpCallback/*[in]*/, wParam/*[in]*/, lParam/*[in]*/);
}

void __fastcall TSpNotifyTranslator::InitWin32Event(void* hEvent/*[in]*/, 
                                                    long fCloseHandleOnRelease/*[in]*/)
{
  GetDefaultInterface()->InitWin32Event(hEvent/*[in]*/, fCloseHandleOnRelease/*[in]*/);
}

void __fastcall TSpNotifyTranslator::Wait(unsigned_long dwMilliseconds/*[in]*/)
{
  GetDefaultInterface()->Wait(dwMilliseconds/*[in]*/);
}

void* __fastcall TSpNotifyTranslator::GetEventHandle(void)
{
  return  GetDefaultInterface()->GetEventHandle();
}

ISpeechObjectTokenCategoryPtr& TSpObjectTokenCategory::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpObjectTokenCategory::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpObjectTokenCategory::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpObjectTokenCategory::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpObjectTokenCategory::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpObjectTokenCategory::ConnectTo(ISpeechObjectTokenCategoryPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpObjectTokenCategory::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpObjectTokenCategory;
  sd.IntfIID = __uuidof(ISpeechObjectTokenCategory);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

void __fastcall TSpObjectTokenCategory::SetId(BSTR Id/*[in]*/, 
                                              VARIANT_BOOL CreateIfNotExist/*[in,def,opt]*/)
{
  GetDefaultInterface()->SetId(Id/*[in]*/, CreateIfNotExist/*[in,def,opt]*/);
}

Speechlib_tlb::ISpeechDataKey* __fastcall TSpObjectTokenCategory::GetDataKey(Speechlib_tlb::SpeechDataKeyLocation Location/*[in,def,opt]*/)
{
  Speechlib_tlb::ISpeechDataKey* DataKey = 0;
  OLECHECK(GetDefaultInterface()->GetDataKey(Location, (Speechlib_tlb::ISpeechDataKey**)&DataKey));
  return DataKey;
}

Speechlib_tlb::ISpeechObjectTokens* __fastcall TSpObjectTokenCategory::EnumerateTokens(BSTR RequiredAttributes/*[in,def,opt]*/, 
                                                                                       BSTR OptionalAttributes/*[in,def,opt]*/)
{
  Speechlib_tlb::ISpeechObjectTokens* Tokens = 0;
  OLECHECK(GetDefaultInterface()->EnumerateTokens(RequiredAttributes, OptionalAttributes, (Speechlib_tlb::ISpeechObjectTokens**)&Tokens));
  return Tokens;
}

BSTR __fastcall TSpObjectTokenCategory::get_Id(void)
{
  BSTR Id = 0;
  OLECHECK(GetDefaultInterface()->get_Id((BSTR*)&Id));
  return Id;
}

void __fastcall TSpObjectTokenCategory::set_Default(BSTR TokenId/*[in]*/)
{
  GetDefaultInterface()->set_Default(TokenId/*[in]*/);
}

BSTR __fastcall TSpObjectTokenCategory::get_Default(void)
{
  BSTR TokenId = 0;
  OLECHECK(GetDefaultInterface()->get_Default((BSTR*)&TokenId));
  return TokenId;
}

ISpeechObjectTokenPtr& TSpObjectToken::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpObjectToken::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpObjectToken::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpObjectToken::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpObjectToken::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpObjectToken::ConnectTo(ISpeechObjectTokenPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpObjectToken::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpObjectToken;
  sd.IntfIID = __uuidof(ISpeechObjectToken);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

BSTR __fastcall TSpObjectToken::GetDescription(long Locale/*[in,def,opt]*/)
{
  BSTR Description = 0;
  OLECHECK(GetDefaultInterface()->GetDescription(Locale, (BSTR*)&Description));
  return Description;
}

void __fastcall TSpObjectToken::SetId(BSTR Id/*[in]*/, BSTR CategoryID/*[in,def,opt]*/, 
                                      VARIANT_BOOL CreateIfNotExist/*[in,def,opt]*/)
{
  GetDefaultInterface()->SetId(Id/*[in]*/, CategoryID/*[in,def,opt]*/, 
                               CreateIfNotExist/*[in,def,opt]*/);
}

BSTR __fastcall TSpObjectToken::GetAttribute(BSTR AttributeName/*[in]*/)
{
  BSTR AttributeValue = 0;
  OLECHECK(GetDefaultInterface()->GetAttribute(AttributeName, (BSTR*)&AttributeValue));
  return AttributeValue;
}

LPUNKNOWN __fastcall TSpObjectToken::CreateInstance(LPUNKNOWN pUnkOuter/*[in,def,opt]*/, 
                                                    Speechlib_tlb::SpeechTokenContext ClsContext/*[in,def,opt]*/)
{
  LPUNKNOWN Object;
  OLECHECK(GetDefaultInterface()->CreateInstance(pUnkOuter, ClsContext, (LPUNKNOWN*)&Object));
  return Object;
}

void __fastcall TSpObjectToken::Remove(BSTR ObjectStorageCLSID/*[in]*/)
{
  GetDefaultInterface()->Remove(ObjectStorageCLSID/*[in]*/);
}

BSTR __fastcall TSpObjectToken::GetStorageFileName(BSTR ObjectStorageCLSID/*[in]*/, 
                                                   BSTR KeyName/*[in]*/, BSTR FileName/*[in]*/, 
                                                   Speechlib_tlb::SpeechTokenShellFolder Folder/*[in]*/)
{
  BSTR FilePath = 0;
  OLECHECK(GetDefaultInterface()->GetStorageFileName(ObjectStorageCLSID, KeyName, FileName, Folder, (BSTR*)&FilePath));
  return FilePath;
}

void __fastcall TSpObjectToken::RemoveStorageFileName(BSTR ObjectStorageCLSID/*[in]*/, 
                                                      BSTR KeyName/*[in]*/, 
                                                      VARIANT_BOOL DeleteFile/*[in]*/)
{
  GetDefaultInterface()->RemoveStorageFileName(ObjectStorageCLSID/*[in]*/, KeyName/*[in]*/, 
                                               DeleteFile/*[in]*/);
}

VARIANT_BOOL __fastcall TSpObjectToken::IsUISupported(BSTR TypeOfUI/*[in]*/, 
                                                      VARIANT* ExtraData/*[in,def,opt]*/, 
                                                      LPUNKNOWN Object/*[in,def,opt]*/)
{
  VARIANT_BOOL Supported;
  OLECHECK(GetDefaultInterface()->IsUISupported(TypeOfUI, ExtraData, Object, (VARIANT_BOOL*)&Supported));
  return Supported;
}

void __fastcall TSpObjectToken::DisplayUI(long hWnd/*[in]*/, BSTR Title/*[in]*/, 
                                          BSTR TypeOfUI/*[in]*/, VARIANT* ExtraData/*[in,def,opt]*/, 
                                          LPUNKNOWN Object/*[in,def,opt]*/)
{
  GetDefaultInterface()->DisplayUI(hWnd/*[in]*/, Title/*[in]*/, TypeOfUI/*[in]*/, 
                                   ExtraData/*[in,def,opt]*/, Object/*[in,def,opt]*/);
}

VARIANT_BOOL __fastcall TSpObjectToken::MatchesAttributes(BSTR Attributes/*[in]*/)
{
  VARIANT_BOOL Matches;
  OLECHECK(GetDefaultInterface()->MatchesAttributes(Attributes, (VARIANT_BOOL*)&Matches));
  return Matches;
}

BSTR __fastcall TSpObjectToken::get_Id(void)
{
  BSTR ObjectId = 0;
  OLECHECK(GetDefaultInterface()->get_Id((BSTR*)&ObjectId));
  return ObjectId;
}

Speechlib_tlb::ISpeechDataKeyPtr __fastcall TSpObjectToken::get_DataKey(void)
{
  Speechlib_tlb::ISpeechDataKeyPtr DataKey;
  OLECHECK(GetDefaultInterface()->get_DataKey(&DataKey));
  return DataKey;
}

Speechlib_tlb::ISpeechObjectTokenCategoryPtr __fastcall TSpObjectToken::get_Category(void)
{
  Speechlib_tlb::ISpeechObjectTokenCategoryPtr Category;
  OLECHECK(GetDefaultInterface()->get_Category(&Category));
  return Category;
}

ISpResourceManagerPtr& TSpResourceManager::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpResourceManager::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpResourceManager::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpResourceManager::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpResourceManager::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpResourceManager::ConnectTo(ISpResourceManagerPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpResourceManager::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpResourceManager;
  sd.IntfIID = __uuidof(ISpResourceManager);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

void __fastcall TSpResourceManager::RemoteQueryService(System::TGUID* guidService/*[in]*/, 
                                                       System::TGUID* riid/*[in]*/, 
                                                       LPUNKNOWN* ppvObject/*[out]*/)
{
  GetDefaultInterface()->RemoteQueryService(guidService/*[in]*/, riid/*[in]*/, ppvObject/*[out]*/);
}

void __fastcall TSpResourceManager::SetObject(System::TGUID* guidServiceId/*[in]*/, 
                                              LPUNKNOWN punkObject/*[in]*/)
{
  GetDefaultInterface()->SetObject(guidServiceId/*[in]*/, punkObject/*[in]*/);
}

void __fastcall TSpResourceManager::GetObject(System::TGUID* guidServiceId/*[in]*/, 
                                              System::TGUID* ObjectCLSID/*[in]*/, 
                                              System::TGUID* ObjectIID/*[in]*/, 
                                              long fReleaseWhenLastExternalRefReleased/*[in]*/, 
                                              void** ppObject/*[out]*/)
{
  GetDefaultInterface()->GetObject(guidServiceId/*[in]*/, ObjectCLSID/*[in]*/, ObjectIID/*[in]*/, 
                                   fReleaseWhenLastExternalRefReleased/*[in]*/, ppObject/*[out]*/);
}

ISpStreamFormatConverterPtr& TSpStreamFormatConverter::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpStreamFormatConverter::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpStreamFormatConverter::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpStreamFormatConverter::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpStreamFormatConverter::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpStreamFormatConverter::ConnectTo(ISpStreamFormatConverterPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpStreamFormatConverter::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpStreamFormatConverter;
  sd.IntfIID = __uuidof(ISpStreamFormatConverter);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

void __fastcall TSpStreamFormatConverter::RemoteRead(unsigned_char* pv/*[out]*/, 
                                                     unsigned_long cb/*[in]*/, 
                                                     unsigned_long* pcbRead/*[out]*/)
{
  GetDefaultInterface()->RemoteRead(pv/*[out]*/, cb/*[in]*/, pcbRead/*[out]*/);
}

void __fastcall TSpStreamFormatConverter::RemoteWrite(unsigned_char* pv/*[in]*/, 
                                                      unsigned_long cb/*[in]*/, 
                                                      unsigned_long* pcbWritten/*[out]*/)
{
  GetDefaultInterface()->RemoteWrite(pv/*[in]*/, cb/*[in]*/, pcbWritten/*[out]*/);
}

void __fastcall TSpStreamFormatConverter::RemoteSeek(Speechlib_tlb::_LARGE_INTEGER dlibMove/*[in]*/, 
                                                     unsigned_long dwOrigin/*[in]*/, 
                                                     Speechlib_tlb::_ULARGE_INTEGER* plibNewPosition/*[out]*/)
{
  GetDefaultInterface()->RemoteSeek(dlibMove/*[in]*/, dwOrigin/*[in]*/, plibNewPosition/*[out]*/);
}

void __fastcall TSpStreamFormatConverter::SetSize(Speechlib_tlb::_ULARGE_INTEGER libNewSize/*[in]*/)
{
  GetDefaultInterface()->SetSize(libNewSize/*[in]*/);
}

void __fastcall TSpStreamFormatConverter::RemoteCopyTo(Speechlib_tlb::IStream* pstm/*[in]*/, 
                                                       Speechlib_tlb::_ULARGE_INTEGER cb/*[in]*/, 
                                                       Speechlib_tlb::_ULARGE_INTEGER* pcbRead/*[out]*/, 
                                                       Speechlib_tlb::_ULARGE_INTEGER* pcbWritten/*[out]*/)
{
  GetDefaultInterface()->RemoteCopyTo(pstm/*[in]*/, cb/*[in]*/, pcbRead/*[out]*/, 
                                      pcbWritten/*[out]*/);
}

void __fastcall TSpStreamFormatConverter::Commit(unsigned_long grfCommitFlags/*[in]*/)
{
  GetDefaultInterface()->Commit(grfCommitFlags/*[in]*/);
}

void __fastcall TSpStreamFormatConverter::Revert(void)
{
  GetDefaultInterface()->Revert();
}

void __fastcall TSpStreamFormatConverter::LockRegion(Speechlib_tlb::_ULARGE_INTEGER libOffset/*[in]*/, 
                                                     Speechlib_tlb::_ULARGE_INTEGER cb/*[in]*/, 
                                                     unsigned_long dwLockType/*[in]*/)
{
  GetDefaultInterface()->LockRegion(libOffset/*[in]*/, cb/*[in]*/, dwLockType/*[in]*/);
}

void __fastcall TSpStreamFormatConverter::UnlockRegion(Speechlib_tlb::_ULARGE_INTEGER libOffset/*[in]*/, 
                                                       Speechlib_tlb::_ULARGE_INTEGER cb/*[in]*/, 
                                                       unsigned_long dwLockType/*[in]*/)
{
  GetDefaultInterface()->UnlockRegion(libOffset/*[in]*/, cb/*[in]*/, dwLockType/*[in]*/);
}

void __fastcall TSpStreamFormatConverter::Stat(Speechlib_tlb::tagSTATSTG* pstatstg/*[out]*/, 
                                               unsigned_long grfStatFlag/*[in]*/)
{
  GetDefaultInterface()->Stat(pstatstg/*[out]*/, grfStatFlag/*[in]*/);
}

void __fastcall TSpStreamFormatConverter::Clone(Speechlib_tlb::IStream** ppstm/*[out]*/)
{
  GetDefaultInterface()->Clone(ppstm/*[out]*/);
}

void __fastcall TSpStreamFormatConverter::GetFormat(System::TGUID* pguidFormatId/*[in]*/, 
                                                    Speechlib_tlb::WAVEFORMATEX** ppCoMemWaveFormatEx/*[out]*/)
{
  GetDefaultInterface()->GetFormat(pguidFormatId/*[in]*/, ppCoMemWaveFormatEx/*[out]*/);
}

void __fastcall TSpStreamFormatConverter::SetBaseStream(Speechlib_tlb::ISpStreamFormat* pStream/*[in]*/, 
                                                        long fSetFormatToBaseStreamFormat/*[in]*/, 
                                                        long fWriteToBaseStream/*[in]*/)
{
  GetDefaultInterface()->SetBaseStream(pStream/*[in]*/, fSetFormatToBaseStreamFormat/*[in]*/, 
                                       fWriteToBaseStream/*[in]*/);
}

void __fastcall TSpStreamFormatConverter::GetBaseStream(Speechlib_tlb::ISpStreamFormat** ppStream/*[out]*/)
{
  GetDefaultInterface()->GetBaseStream(ppStream/*[out]*/);
}

void __fastcall TSpStreamFormatConverter::SetFormat(System::TGUID* rguidFormatIdOfConvertedStream/*[in]*/, 
                                                    Speechlib_tlb::WAVEFORMATEX* pWaveFormatExOfConvertedStream/*[in]*/)
{
  GetDefaultInterface()->SetFormat(rguidFormatIdOfConvertedStream/*[in]*/, 
                                   pWaveFormatExOfConvertedStream/*[in]*/);
}

void __fastcall TSpStreamFormatConverter::ResetSeekPosition(void)
{
  GetDefaultInterface()->ResetSeekPosition();
}

void __fastcall TSpStreamFormatConverter::ScaleConvertedToBaseOffset(unsigned_int64 ullOffsetConvertedStream/*[in]*/, 
                                                                     unsigned_int64* pullOffsetBaseStream/*[out]*/)
{
  GetDefaultInterface()->ScaleConvertedToBaseOffset(ullOffsetConvertedStream/*[in]*/, 
                                                    pullOffsetBaseStream/*[out]*/);
}

void __fastcall TSpStreamFormatConverter::ScaleBaseToConvertedOffset(unsigned_int64 ullOffsetBaseStream/*[in]*/, 
                                                                     unsigned_int64* pullOffsetConvertedStream/*[out]*/)
{
  GetDefaultInterface()->ScaleBaseToConvertedOffset(ullOffsetBaseStream/*[in]*/, 
                                                    pullOffsetConvertedStream/*[out]*/);
}

IEnumSpObjectTokensPtr& TSpMMAudioEnum::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpMMAudioEnum::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpMMAudioEnum::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpMMAudioEnum::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpMMAudioEnum::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpMMAudioEnum::ConnectTo(IEnumSpObjectTokensPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpMMAudioEnum::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpMMAudioEnum;
  sd.IntfIID = __uuidof(IEnumSpObjectTokens);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

void __fastcall TSpMMAudioEnum::Next(unsigned_long celt/*[in]*/, 
                                     Speechlib_tlb::ISpObjectToken** pelt/*[out]*/, 
                                     unsigned_long* pceltFetched/*[out]*/)
{
  GetDefaultInterface()->Next(celt/*[in]*/, pelt/*[out]*/, pceltFetched/*[out]*/);
}

void __fastcall TSpMMAudioEnum::Skip(unsigned_long celt/*[in]*/)
{
  GetDefaultInterface()->Skip(celt/*[in]*/);
}

void __fastcall TSpMMAudioEnum::Reset(void)
{
  GetDefaultInterface()->Reset();
}

void __fastcall TSpMMAudioEnum::Clone(Speechlib_tlb::IEnumSpObjectTokens** ppEnum/*[out]*/)
{
  GetDefaultInterface()->Clone(ppEnum/*[out]*/);
}

void __fastcall TSpMMAudioEnum::Item(unsigned_long Index/*[in]*/, 
                                     Speechlib_tlb::ISpObjectToken** ppToken/*[out]*/)
{
  GetDefaultInterface()->Item(Index/*[in]*/, ppToken/*[out]*/);
}

void __fastcall TSpMMAudioEnum::GetCount(unsigned_long* pCount/*[out]*/)
{
  GetDefaultInterface()->GetCount(pCount/*[out]*/);
}

ISpeechMMSysAudioPtr& TSpMMAudioIn::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpMMAudioIn::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpMMAudioIn::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpMMAudioIn::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpMMAudioIn::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpMMAudioIn::ConnectTo(ISpeechMMSysAudioPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpMMAudioIn::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpMMAudioIn;
  sd.IntfIID = __uuidof(ISpeechMMSysAudio);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

long __fastcall TSpMMAudioIn::Read(VARIANT* Buffer/*[out]*/, long NumberOfBytes/*[in]*/)
{
  long BytesRead;
  OLECHECK(GetDefaultInterface()->Read(Buffer, NumberOfBytes, (long*)&BytesRead));
  return BytesRead;
}

long __fastcall TSpMMAudioIn::Write(VARIANT Buffer/*[in]*/)
{
  long BytesWritten;
  OLECHECK(GetDefaultInterface()->Write(Buffer, (long*)&BytesWritten));
  return BytesWritten;
}

VARIANT __fastcall TSpMMAudioIn::Seek(VARIANT Position/*[in]*/, 
                                      Speechlib_tlb::SpeechStreamSeekPositionType Origin/*[in,def,opt]*/)
{
  VARIANT NewPosition;
  OLECHECK(GetDefaultInterface()->Seek(Position, Origin, (VARIANT*)&NewPosition));
  return NewPosition;
}

void __fastcall TSpMMAudioIn::SetState(Speechlib_tlb::SpeechAudioState State/*[in]*/)
{
  GetDefaultInterface()->SetState(State/*[in]*/);
}

Speechlib_tlb::ISpeechAudioFormatPtr __fastcall TSpMMAudioIn::get_Format(void)
{
  Speechlib_tlb::ISpeechAudioFormatPtr AudioFormat;
  OLECHECK(GetDefaultInterface()->get_Format(&AudioFormat));
  return AudioFormat;
}

void __fastcall TSpMMAudioIn::_set_Format(Speechlib_tlb::ISpeechAudioFormat* AudioFormat/*[in]*/)
{
  GetDefaultInterface()->_set_Format(AudioFormat/*[in]*/);
}

Speechlib_tlb::ISpeechAudioStatusPtr __fastcall TSpMMAudioIn::get_Status(void)
{
  Speechlib_tlb::ISpeechAudioStatusPtr Status;
  OLECHECK(GetDefaultInterface()->get_Status(&Status));
  return Status;
}

Speechlib_tlb::ISpeechAudioBufferInfoPtr __fastcall TSpMMAudioIn::get_BufferInfo(void)
{
  Speechlib_tlb::ISpeechAudioBufferInfoPtr BufferInfo;
  OLECHECK(GetDefaultInterface()->get_BufferInfo(&BufferInfo));
  return BufferInfo;
}

Speechlib_tlb::ISpeechAudioFormatPtr __fastcall TSpMMAudioIn::get_DefaultFormat(void)
{
  Speechlib_tlb::ISpeechAudioFormatPtr StreamFormat;
  OLECHECK(GetDefaultInterface()->get_DefaultFormat(&StreamFormat));
  return StreamFormat;
}

long __fastcall TSpMMAudioIn::get_Volume(void)
{
  long Volume;
  OLECHECK(GetDefaultInterface()->get_Volume((long*)&Volume));
  return Volume;
}

void __fastcall TSpMMAudioIn::set_Volume(long Volume/*[in]*/)
{
  GetDefaultInterface()->set_Volume(Volume/*[in]*/);
}

long __fastcall TSpMMAudioIn::get_BufferNotifySize(void)
{
  long BufferNotifySize;
  OLECHECK(GetDefaultInterface()->get_BufferNotifySize((long*)&BufferNotifySize));
  return BufferNotifySize;
}

void __fastcall TSpMMAudioIn::set_BufferNotifySize(long BufferNotifySize/*[in]*/)
{
  GetDefaultInterface()->set_BufferNotifySize(BufferNotifySize/*[in]*/);
}

long __fastcall TSpMMAudioIn::get_EventHandle(void)
{
  long EventHandle;
  OLECHECK(GetDefaultInterface()->get_EventHandle((long*)&EventHandle));
  return EventHandle;
}

long __fastcall TSpMMAudioIn::get_DeviceId(void)
{
  long DeviceId;
  OLECHECK(GetDefaultInterface()->get_DeviceId((long*)&DeviceId));
  return DeviceId;
}

void __fastcall TSpMMAudioIn::set_DeviceId(long DeviceId/*[in]*/)
{
  GetDefaultInterface()->set_DeviceId(DeviceId/*[in]*/);
}

long __fastcall TSpMMAudioIn::get_LineId(void)
{
  long LineId;
  OLECHECK(GetDefaultInterface()->get_LineId((long*)&LineId));
  return LineId;
}

void __fastcall TSpMMAudioIn::set_LineId(long LineId/*[in]*/)
{
  GetDefaultInterface()->set_LineId(LineId/*[in]*/);
}

long __fastcall TSpMMAudioIn::get_MMHandle(void)
{
  long Handle;
  OLECHECK(GetDefaultInterface()->get_MMHandle((long*)&Handle));
  return Handle;
}

ISpeechMMSysAudioPtr& TSpMMAudioOut::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpMMAudioOut::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpMMAudioOut::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpMMAudioOut::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpMMAudioOut::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpMMAudioOut::ConnectTo(ISpeechMMSysAudioPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpMMAudioOut::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpMMAudioOut;
  sd.IntfIID = __uuidof(ISpeechMMSysAudio);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

long __fastcall TSpMMAudioOut::Read(VARIANT* Buffer/*[out]*/, long NumberOfBytes/*[in]*/)
{
  long BytesRead;
  OLECHECK(GetDefaultInterface()->Read(Buffer, NumberOfBytes, (long*)&BytesRead));
  return BytesRead;
}

long __fastcall TSpMMAudioOut::Write(VARIANT Buffer/*[in]*/)
{
  long BytesWritten;
  OLECHECK(GetDefaultInterface()->Write(Buffer, (long*)&BytesWritten));
  return BytesWritten;
}

VARIANT __fastcall TSpMMAudioOut::Seek(VARIANT Position/*[in]*/, 
                                       Speechlib_tlb::SpeechStreamSeekPositionType Origin/*[in,def,opt]*/)
{
  VARIANT NewPosition;
  OLECHECK(GetDefaultInterface()->Seek(Position, Origin, (VARIANT*)&NewPosition));
  return NewPosition;
}

void __fastcall TSpMMAudioOut::SetState(Speechlib_tlb::SpeechAudioState State/*[in]*/)
{
  GetDefaultInterface()->SetState(State/*[in]*/);
}

Speechlib_tlb::ISpeechAudioFormatPtr __fastcall TSpMMAudioOut::get_Format(void)
{
  Speechlib_tlb::ISpeechAudioFormatPtr AudioFormat;
  OLECHECK(GetDefaultInterface()->get_Format(&AudioFormat));
  return AudioFormat;
}

void __fastcall TSpMMAudioOut::_set_Format(Speechlib_tlb::ISpeechAudioFormat* AudioFormat/*[in]*/)
{
  GetDefaultInterface()->_set_Format(AudioFormat/*[in]*/);
}

Speechlib_tlb::ISpeechAudioStatusPtr __fastcall TSpMMAudioOut::get_Status(void)
{
  Speechlib_tlb::ISpeechAudioStatusPtr Status;
  OLECHECK(GetDefaultInterface()->get_Status(&Status));
  return Status;
}

Speechlib_tlb::ISpeechAudioBufferInfoPtr __fastcall TSpMMAudioOut::get_BufferInfo(void)
{
  Speechlib_tlb::ISpeechAudioBufferInfoPtr BufferInfo;
  OLECHECK(GetDefaultInterface()->get_BufferInfo(&BufferInfo));
  return BufferInfo;
}

Speechlib_tlb::ISpeechAudioFormatPtr __fastcall TSpMMAudioOut::get_DefaultFormat(void)
{
  Speechlib_tlb::ISpeechAudioFormatPtr StreamFormat;
  OLECHECK(GetDefaultInterface()->get_DefaultFormat(&StreamFormat));
  return StreamFormat;
}

long __fastcall TSpMMAudioOut::get_Volume(void)
{
  long Volume;
  OLECHECK(GetDefaultInterface()->get_Volume((long*)&Volume));
  return Volume;
}

void __fastcall TSpMMAudioOut::set_Volume(long Volume/*[in]*/)
{
  GetDefaultInterface()->set_Volume(Volume/*[in]*/);
}

long __fastcall TSpMMAudioOut::get_BufferNotifySize(void)
{
  long BufferNotifySize;
  OLECHECK(GetDefaultInterface()->get_BufferNotifySize((long*)&BufferNotifySize));
  return BufferNotifySize;
}

void __fastcall TSpMMAudioOut::set_BufferNotifySize(long BufferNotifySize/*[in]*/)
{
  GetDefaultInterface()->set_BufferNotifySize(BufferNotifySize/*[in]*/);
}

long __fastcall TSpMMAudioOut::get_EventHandle(void)
{
  long EventHandle;
  OLECHECK(GetDefaultInterface()->get_EventHandle((long*)&EventHandle));
  return EventHandle;
}

long __fastcall TSpMMAudioOut::get_DeviceId(void)
{
  long DeviceId;
  OLECHECK(GetDefaultInterface()->get_DeviceId((long*)&DeviceId));
  return DeviceId;
}

void __fastcall TSpMMAudioOut::set_DeviceId(long DeviceId/*[in]*/)
{
  GetDefaultInterface()->set_DeviceId(DeviceId/*[in]*/);
}

long __fastcall TSpMMAudioOut::get_LineId(void)
{
  long LineId;
  OLECHECK(GetDefaultInterface()->get_LineId((long*)&LineId));
  return LineId;
}

void __fastcall TSpMMAudioOut::set_LineId(long LineId/*[in]*/)
{
  GetDefaultInterface()->set_LineId(LineId/*[in]*/);
}

long __fastcall TSpMMAudioOut::get_MMHandle(void)
{
  long Handle;
  OLECHECK(GetDefaultInterface()->get_MMHandle((long*)&Handle));
  return Handle;
}

ISpStreamPtr& TSpStream::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpStream::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpStream::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpStream::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpStream::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpStream::ConnectTo(ISpStreamPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpStream::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpStream;
  sd.IntfIID = __uuidof(ISpStream);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

void __fastcall TSpStream::RemoteRead(unsigned_char* pv/*[out]*/, unsigned_long cb/*[in]*/, 
                                      unsigned_long* pcbRead/*[out]*/)
{
  GetDefaultInterface()->RemoteRead(pv/*[out]*/, cb/*[in]*/, pcbRead/*[out]*/);
}

void __fastcall TSpStream::RemoteWrite(unsigned_char* pv/*[in]*/, unsigned_long cb/*[in]*/, 
                                       unsigned_long* pcbWritten/*[out]*/)
{
  GetDefaultInterface()->RemoteWrite(pv/*[in]*/, cb/*[in]*/, pcbWritten/*[out]*/);
}

void __fastcall TSpStream::RemoteSeek(Speechlib_tlb::_LARGE_INTEGER dlibMove/*[in]*/, 
                                      unsigned_long dwOrigin/*[in]*/, 
                                      Speechlib_tlb::_ULARGE_INTEGER* plibNewPosition/*[out]*/)
{
  GetDefaultInterface()->RemoteSeek(dlibMove/*[in]*/, dwOrigin/*[in]*/, plibNewPosition/*[out]*/);
}

void __fastcall TSpStream::SetSize(Speechlib_tlb::_ULARGE_INTEGER libNewSize/*[in]*/)
{
  GetDefaultInterface()->SetSize(libNewSize/*[in]*/);
}

void __fastcall TSpStream::RemoteCopyTo(Speechlib_tlb::IStream* pstm/*[in]*/, 
                                        Speechlib_tlb::_ULARGE_INTEGER cb/*[in]*/, 
                                        Speechlib_tlb::_ULARGE_INTEGER* pcbRead/*[out]*/, 
                                        Speechlib_tlb::_ULARGE_INTEGER* pcbWritten/*[out]*/)
{
  GetDefaultInterface()->RemoteCopyTo(pstm/*[in]*/, cb/*[in]*/, pcbRead/*[out]*/, 
                                      pcbWritten/*[out]*/);
}

void __fastcall TSpStream::Commit(unsigned_long grfCommitFlags/*[in]*/)
{
  GetDefaultInterface()->Commit(grfCommitFlags/*[in]*/);
}

void __fastcall TSpStream::Revert(void)
{
  GetDefaultInterface()->Revert();
}

void __fastcall TSpStream::LockRegion(Speechlib_tlb::_ULARGE_INTEGER libOffset/*[in]*/, 
                                      Speechlib_tlb::_ULARGE_INTEGER cb/*[in]*/, 
                                      unsigned_long dwLockType/*[in]*/)
{
  GetDefaultInterface()->LockRegion(libOffset/*[in]*/, cb/*[in]*/, dwLockType/*[in]*/);
}

void __fastcall TSpStream::UnlockRegion(Speechlib_tlb::_ULARGE_INTEGER libOffset/*[in]*/, 
                                        Speechlib_tlb::_ULARGE_INTEGER cb/*[in]*/, 
                                        unsigned_long dwLockType/*[in]*/)
{
  GetDefaultInterface()->UnlockRegion(libOffset/*[in]*/, cb/*[in]*/, dwLockType/*[in]*/);
}

void __fastcall TSpStream::Stat(Speechlib_tlb::tagSTATSTG* pstatstg/*[out]*/, 
                                unsigned_long grfStatFlag/*[in]*/)
{
  GetDefaultInterface()->Stat(pstatstg/*[out]*/, grfStatFlag/*[in]*/);
}

void __fastcall TSpStream::Clone(Speechlib_tlb::IStream** ppstm/*[out]*/)
{
  GetDefaultInterface()->Clone(ppstm/*[out]*/);
}

void __fastcall TSpStream::GetFormat(System::TGUID* pguidFormatId/*[in]*/, 
                                     Speechlib_tlb::WAVEFORMATEX** ppCoMemWaveFormatEx/*[out]*/)
{
  GetDefaultInterface()->GetFormat(pguidFormatId/*[in]*/, ppCoMemWaveFormatEx/*[out]*/);
}

void __fastcall TSpStream::SetBaseStream(Speechlib_tlb::IStream* pStream/*[in]*/, 
                                         System::TGUID* rguidFormat/*[in]*/, 
                                         Speechlib_tlb::WAVEFORMATEX* pWaveFormatEx/*[in]*/)
{
  GetDefaultInterface()->SetBaseStream(pStream/*[in]*/, rguidFormat/*[in]*/, pWaveFormatEx/*[in]*/);
}

void __fastcall TSpStream::GetBaseStream(Speechlib_tlb::IStream** ppStream/*[out]*/)
{
  GetDefaultInterface()->GetBaseStream(ppStream/*[out]*/);
}

void __fastcall TSpStream::BindToFile(LPWSTR pszFileName/*[in]*/, 
                                      Speechlib_tlb::SPFILEMODE eMode/*[in]*/, 
                                      System::TGUID* pFormatId/*[in]*/, 
                                      Speechlib_tlb::WAVEFORMATEX* pWaveFormatEx, 
                                      unsigned_int64 ullEventInterest/*[in]*/)
{
  GetDefaultInterface()->BindToFile(pszFileName/*[in]*/, eMode/*[in]*/, pFormatId/*[in]*/, 
                                    pWaveFormatEx, ullEventInterest/*[in]*/);
}

void __fastcall TSpStream::Close(void)
{
  GetDefaultInterface()->Close();
}

ISpeechVoicePtr& TSpVoice::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpVoice::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpVoice::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpVoice::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpVoice::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpVoice::ConnectTo(ISpeechVoicePtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpVoice::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpVoice;
  sd.IntfIID = __uuidof(ISpeechVoice);
  sd.EventIID= __uuidof(_ISpeechVoiceEvents);
  ServerData = &sd;
}

void __fastcall TSpVoice::InvokeEvent(int id, Vcl::Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 1: {
      if (OnStartStream) {
        (OnStartStream)(this, params[0], params[1]);
      }
      break;
      }
    case 2: {
      if (OnEndStream) {
        (OnEndStream)(this, params[0], params[1]);
      }
      break;
      }
    case 3: {
      if (OnVoiceChange) {
        (OnVoiceChange)(this, params[0], params[1], (Speechlib_tlb::ISpeechObjectTokenPtr)(LPDISPATCH)(params[2].pdispVal));
      }
      break;
      }
    case 4: {
      if (OnBookmark) {
        (OnBookmark)(this, params[0], params[1], params[2].bstrVal, params[3]);
      }
      break;
      }
    case 5: {
      if (OnWord) {
        (OnWord)(this, params[0], params[1], params[2], params[3]);
      }
      break;
      }
    case 7: {
      if (OnSentence) {
        (OnSentence)(this, params[0], params[1], params[2], params[3]);
      }
      break;
      }
    case 6: {
      if (OnPhoneme) {
        (OnPhoneme)(this, params[0], params[1], params[2], params[3], (Speechlib_tlb::SpeechVisemeFeature)(int)params[4], params[5]);
      }
      break;
      }
    case 8: {
      if (OnViseme) {
        (OnViseme)(this, params[0], params[1], params[2], (Speechlib_tlb::SpeechVisemeType)(int)params[3], (Speechlib_tlb::SpeechVisemeFeature)(int)params[4], (Speechlib_tlb::SpeechVisemeType)(int)params[5]);
      }
      break;
      }
    case 9: {
      if (OnAudioLevel) {
        (OnAudioLevel)(this, params[0], params[1], params[2]);
      }
      break;
      }
    case 10: {
      if (OnEnginePrivate) {
        (OnEnginePrivate)(this, params[0], params[1], params[2]);
      }
      break;
      }
    default:
      break;
  }
}

long __fastcall TSpVoice::Speak(BSTR Text/*[in]*/, 
                                Speechlib_tlb::SpeechVoiceSpeakFlags Flags/*[in,def,opt]*/)
{
  long StreamNumber;
  OLECHECK(GetDefaultInterface()->Speak(Text, Flags, (long*)&StreamNumber));
  return StreamNumber;
}

long __fastcall TSpVoice::SpeakStream(Speechlib_tlb::ISpeechBaseStream* Stream/*[in]*/, 
                                      Speechlib_tlb::SpeechVoiceSpeakFlags Flags/*[in,def,opt]*/)
{
  long StreamNumber;
  OLECHECK(GetDefaultInterface()->SpeakStream(Stream, Flags, (long*)&StreamNumber));
  return StreamNumber;
}

void __fastcall TSpVoice::Pause(void)
{
  GetDefaultInterface()->Pause();
}

void __fastcall TSpVoice::Resume(void)
{
  GetDefaultInterface()->Resume();
}

long __fastcall TSpVoice::Skip(BSTR Type/*[in]*/, long NumItems/*[in]*/)
{
  long NumSkipped;
  OLECHECK(GetDefaultInterface()->Skip(Type, NumItems, (long*)&NumSkipped));
  return NumSkipped;
}

Speechlib_tlb::ISpeechObjectTokens* __fastcall TSpVoice::GetVoices(BSTR RequiredAttributes/*[in,def,opt]*/, 
                                                                   BSTR OptionalAttributes/*[in,def,opt]*/)
{
  Speechlib_tlb::ISpeechObjectTokens* ObjectTokens = 0;
  OLECHECK(GetDefaultInterface()->GetVoices(RequiredAttributes, OptionalAttributes, (Speechlib_tlb::ISpeechObjectTokens**)&ObjectTokens));
  return ObjectTokens;
}

Speechlib_tlb::ISpeechObjectTokens* __fastcall TSpVoice::GetAudioOutputs(BSTR RequiredAttributes/*[in,def,opt]*/, 
                                                                         BSTR OptionalAttributes/*[in,def,opt]*/)
{
  Speechlib_tlb::ISpeechObjectTokens* ObjectTokens = 0;
  OLECHECK(GetDefaultInterface()->GetAudioOutputs(RequiredAttributes, OptionalAttributes, (Speechlib_tlb::ISpeechObjectTokens**)&ObjectTokens));
  return ObjectTokens;
}

VARIANT_BOOL __fastcall TSpVoice::WaitUntilDone(long msTimeout/*[in]*/)
{
  VARIANT_BOOL Done;
  OLECHECK(GetDefaultInterface()->WaitUntilDone(msTimeout, (VARIANT_BOOL*)&Done));
  return Done;
}

long __fastcall TSpVoice::SpeakCompleteEvent(void)
{
  long Handle;
  OLECHECK(GetDefaultInterface()->SpeakCompleteEvent((long*)&Handle));
  return Handle;
}

VARIANT_BOOL __fastcall TSpVoice::IsUISupported(BSTR TypeOfUI/*[in]*/, 
                                                VARIANT* ExtraData/*[in,def,opt]*/)
{
  VARIANT_BOOL Supported;
  OLECHECK(GetDefaultInterface()->IsUISupported(TypeOfUI, ExtraData, (VARIANT_BOOL*)&Supported));
  return Supported;
}

void __fastcall TSpVoice::DisplayUI(long hWndParent/*[in]*/, BSTR Title/*[in]*/, 
                                    BSTR TypeOfUI/*[in]*/, VARIANT* ExtraData/*[in,def,opt]*/)
{
  GetDefaultInterface()->DisplayUI(hWndParent/*[in]*/, Title/*[in]*/, TypeOfUI/*[in]*/, 
                                   ExtraData/*[in,def,opt]*/);
}

Speechlib_tlb::ISpeechVoiceStatusPtr __fastcall TSpVoice::get_Status(void)
{
  Speechlib_tlb::ISpeechVoiceStatusPtr Status;
  OLECHECK(GetDefaultInterface()->get_Status(&Status));
  return Status;
}

Speechlib_tlb::ISpeechObjectTokenPtr __fastcall TSpVoice::get_Voice(void)
{
  Speechlib_tlb::ISpeechObjectTokenPtr Voice;
  OLECHECK(GetDefaultInterface()->get_Voice(&Voice));
  return Voice;
}

void __fastcall TSpVoice::_set_Voice(Speechlib_tlb::ISpeechObjectToken* Voice/*[in]*/)
{
  GetDefaultInterface()->_set_Voice(Voice/*[in]*/);
}

Speechlib_tlb::ISpeechObjectTokenPtr __fastcall TSpVoice::get_AudioOutput(void)
{
  Speechlib_tlb::ISpeechObjectTokenPtr AudioOutput;
  OLECHECK(GetDefaultInterface()->get_AudioOutput(&AudioOutput));
  return AudioOutput;
}

void __fastcall TSpVoice::_set_AudioOutput(Speechlib_tlb::ISpeechObjectToken* AudioOutput/*[in]*/)
{
  GetDefaultInterface()->_set_AudioOutput(AudioOutput/*[in]*/);
}

Speechlib_tlb::ISpeechBaseStreamPtr __fastcall TSpVoice::get_AudioOutputStream(void)
{
  Speechlib_tlb::ISpeechBaseStreamPtr AudioOutputStream;
  OLECHECK(GetDefaultInterface()->get_AudioOutputStream(&AudioOutputStream));
  return AudioOutputStream;
}

void __fastcall TSpVoice::_set_AudioOutputStream(Speechlib_tlb::ISpeechBaseStream* AudioOutputStream/*[in]*/)
{
  GetDefaultInterface()->_set_AudioOutputStream(AudioOutputStream/*[in]*/);
}

long __fastcall TSpVoice::get_Rate(void)
{
  long Rate;
  OLECHECK(GetDefaultInterface()->get_Rate((long*)&Rate));
  return Rate;
}

void __fastcall TSpVoice::set_Rate(long Rate/*[in]*/)
{
  GetDefaultInterface()->set_Rate(Rate/*[in]*/);
}

long __fastcall TSpVoice::get_Volume(void)
{
  long Volume;
  OLECHECK(GetDefaultInterface()->get_Volume((long*)&Volume));
  return Volume;
}

void __fastcall TSpVoice::set_Volume(long Volume/*[in]*/)
{
  GetDefaultInterface()->set_Volume(Volume/*[in]*/);
}

void __fastcall TSpVoice::set_AllowAudioOutputFormatChangesOnNextSet(VARIANT_BOOL Allow/*[in]*/)
{
  GetDefaultInterface()->set_AllowAudioOutputFormatChangesOnNextSet(Allow/*[in]*/);
}

VARIANT_BOOL __fastcall TSpVoice::get_AllowAudioOutputFormatChangesOnNextSet(void)
{
  VARIANT_BOOL Allow;
  OLECHECK(GetDefaultInterface()->get_AllowAudioOutputFormatChangesOnNextSet((VARIANT_BOOL*)&Allow));
  return Allow;
}

Speechlib_tlb::SpeechVoiceEvents __fastcall TSpVoice::get_EventInterests(void)
{
  Speechlib_tlb::SpeechVoiceEvents EventInterestFlags;
  OLECHECK(GetDefaultInterface()->get_EventInterests((Speechlib_tlb::SpeechVoiceEvents*)&EventInterestFlags));
  return EventInterestFlags;
}

void __fastcall TSpVoice::set_EventInterests(Speechlib_tlb::SpeechVoiceEvents EventInterestFlags/*[in]*/)
{
  GetDefaultInterface()->set_EventInterests(EventInterestFlags/*[in]*/);
}

void __fastcall TSpVoice::set_Priority(Speechlib_tlb::SpeechVoicePriority Priority/*[in]*/)
{
  GetDefaultInterface()->set_Priority(Priority/*[in]*/);
}

Speechlib_tlb::SpeechVoicePriority __fastcall TSpVoice::get_Priority(void)
{
  Speechlib_tlb::SpeechVoicePriority Priority;
  OLECHECK(GetDefaultInterface()->get_Priority((Speechlib_tlb::SpeechVoicePriority*)&Priority));
  return Priority;
}

void __fastcall TSpVoice::set_AlertBoundary(Speechlib_tlb::SpeechVoiceEvents Boundary/*[in]*/)
{
  GetDefaultInterface()->set_AlertBoundary(Boundary/*[in]*/);
}

Speechlib_tlb::SpeechVoiceEvents __fastcall TSpVoice::get_AlertBoundary(void)
{
  Speechlib_tlb::SpeechVoiceEvents Boundary;
  OLECHECK(GetDefaultInterface()->get_AlertBoundary((Speechlib_tlb::SpeechVoiceEvents*)&Boundary));
  return Boundary;
}

void __fastcall TSpVoice::set_SynchronousSpeakTimeout(long msTimeout/*[in]*/)
{
  GetDefaultInterface()->set_SynchronousSpeakTimeout(msTimeout/*[in]*/);
}

long __fastcall TSpVoice::get_SynchronousSpeakTimeout(void)
{
  long msTimeout;
  OLECHECK(GetDefaultInterface()->get_SynchronousSpeakTimeout((long*)&msTimeout));
  return msTimeout;
}

ISpeechRecoContextPtr& TSpSharedRecoContext::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpSharedRecoContext::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpSharedRecoContext::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpSharedRecoContext::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpSharedRecoContext::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpSharedRecoContext::ConnectTo(ISpeechRecoContextPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpSharedRecoContext::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpSharedRecoContext;
  sd.IntfIID = __uuidof(ISpeechRecoContext);
  sd.EventIID= __uuidof(_ISpeechRecoContextEvents);
  ServerData = &sd;
}

void __fastcall TSpSharedRecoContext::InvokeEvent(int id, Vcl::Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 1: {
      if (OnStartStream) {
        (OnStartStream)(this, params[0], params[1]);
      }
      break;
      }
    case 2: {
      if (OnEndStream) {
        (OnEndStream)(this, params[0], params[1], params[2]);
      }
      break;
      }
    case 3: {
      if (OnBookmark) {
        (OnBookmark)(this, params[0], params[1], params[2], (Speechlib_tlb::SpeechBookmarkOptions)(int)params[3]);
      }
      break;
      }
    case 4: {
      if (OnSoundStart) {
        (OnSoundStart)(this, params[0], params[1]);
      }
      break;
      }
    case 5: {
      if (OnSoundEnd) {
        (OnSoundEnd)(this, params[0], params[1]);
      }
      break;
      }
    case 6: {
      if (OnPhraseStart) {
        (OnPhraseStart)(this, params[0], params[1]);
      }
      break;
      }
    case 7: {
      if (OnRecognition) {
        (OnRecognition)(this, params[0], params[1], (Speechlib_tlb::SpeechRecognitionType)(int)params[2], (Speechlib_tlb::ISpeechRecoResultPtr)(LPDISPATCH)(params[3].pdispVal));
      }
      break;
      }
    case 8: {
      if (OnHypothesis) {
        (OnHypothesis)(this, params[0], params[1], (Speechlib_tlb::ISpeechRecoResultPtr)(LPDISPATCH)(params[2].pdispVal));
      }
      break;
      }
    case 9: {
      if (OnPropertyNumberChange) {
        (OnPropertyNumberChange)(this, params[0], params[1], params[2].bstrVal, params[3]);
      }
      break;
      }
    case 10: {
      if (OnPropertyStringChange) {
        (OnPropertyStringChange)(this, params[0], params[1], params[2].bstrVal, params[3].bstrVal);
      }
      break;
      }
    case 11: {
      if (OnFalseRecognition) {
        (OnFalseRecognition)(this, params[0], params[1], (Speechlib_tlb::ISpeechRecoResultPtr)(LPDISPATCH)(params[2].pdispVal));
      }
      break;
      }
    case 12: {
      if (OnInterference) {
        (OnInterference)(this, params[0], params[1], (Speechlib_tlb::SpeechInterference)(int)params[2]);
      }
      break;
      }
    case 13: {
      if (OnRequestUI) {
        (OnRequestUI)(this, params[0], params[1], params[2].bstrVal);
      }
      break;
      }
    case 14: {
      if (OnRecognizerStateChange) {
        (OnRecognizerStateChange)(this, params[0], params[1], (Speechlib_tlb::SpeechRecognizerState)(int)params[2]);
      }
      break;
      }
    case 15: {
      if (OnAdaptation) {
        (OnAdaptation)(this, params[0], params[1]);
      }
      break;
      }
    case 16: {
      if (OnRecognitionForOtherContext) {
        (OnRecognitionForOtherContext)(this, params[0], params[1]);
      }
      break;
      }
    case 17: {
      if (OnAudioLevel) {
        (OnAudioLevel)(this, params[0], params[1], params[2]);
      }
      break;
      }
    case 18: {
      if (OnEnginePrivate) {
        (OnEnginePrivate)(this, params[0], params[1], params[2]);
      }
      break;
      }
    default:
      break;
  }
}

void __fastcall TSpSharedRecoContext::Pause(void)
{
  GetDefaultInterface()->Pause();
}

void __fastcall TSpSharedRecoContext::Resume(void)
{
  GetDefaultInterface()->Resume();
}

Speechlib_tlb::ISpeechRecoGrammar* __fastcall TSpSharedRecoContext::CreateGrammar(VARIANT GrammarId/*[in,def,opt]*/)
{
  Speechlib_tlb::ISpeechRecoGrammar* Grammar = 0;
  OLECHECK(GetDefaultInterface()->CreateGrammar(GrammarId, (Speechlib_tlb::ISpeechRecoGrammar**)&Grammar));
  return Grammar;
}

Speechlib_tlb::ISpeechRecoResult* __fastcall TSpSharedRecoContext::CreateResultFromMemory(VARIANT* ResultBlock/*[in]*/)
{
  Speechlib_tlb::ISpeechRecoResult* Result = 0;
  OLECHECK(GetDefaultInterface()->CreateResultFromMemory(ResultBlock, (Speechlib_tlb::ISpeechRecoResult**)&Result));
  return Result;
}

void __fastcall TSpSharedRecoContext::Bookmark(Speechlib_tlb::SpeechBookmarkOptions Options/*[in]*/, 
                                               VARIANT StreamPos/*[in]*/, VARIANT BookmarkId/*[in]*/)
{
  GetDefaultInterface()->Bookmark(Options/*[in]*/, StreamPos/*[in]*/, BookmarkId/*[in]*/);
}

void __fastcall TSpSharedRecoContext::SetAdaptationData(BSTR AdaptationString/*[in]*/)
{
  GetDefaultInterface()->SetAdaptationData(AdaptationString/*[in]*/);
}

Speechlib_tlb::ISpeechRecognizerPtr __fastcall TSpSharedRecoContext::get_Recognizer(void)
{
  Speechlib_tlb::ISpeechRecognizerPtr Recognizer;
  OLECHECK(GetDefaultInterface()->get_Recognizer(&Recognizer));
  return Recognizer;
}

Speechlib_tlb::SpeechInterference __fastcall TSpSharedRecoContext::get_AudioInputInterferenceStatus(void)
{
  Speechlib_tlb::SpeechInterference Interference;
  OLECHECK(GetDefaultInterface()->get_AudioInputInterferenceStatus((Speechlib_tlb::SpeechInterference*)&Interference));
  return Interference;
}

BSTR __fastcall TSpSharedRecoContext::get_RequestedUIType(void)
{
  BSTR UIType = 0;
  OLECHECK(GetDefaultInterface()->get_RequestedUIType((BSTR*)&UIType));
  return UIType;
}

void __fastcall TSpSharedRecoContext::_set_Voice(Speechlib_tlb::ISpeechVoice* Voice/*[in]*/)
{
  GetDefaultInterface()->_set_Voice(Voice/*[in]*/);
}

Speechlib_tlb::ISpeechVoicePtr __fastcall TSpSharedRecoContext::get_Voice(void)
{
  Speechlib_tlb::ISpeechVoicePtr Voice;
  OLECHECK(GetDefaultInterface()->get_Voice(&Voice));
  return Voice;
}

void __fastcall TSpSharedRecoContext::set_AllowVoiceFormatMatchingOnNextSet(VARIANT_BOOL pAllow/*[in]*/)
{
  GetDefaultInterface()->set_AllowVoiceFormatMatchingOnNextSet(pAllow/*[in]*/);
}

VARIANT_BOOL __fastcall TSpSharedRecoContext::get_AllowVoiceFormatMatchingOnNextSet(void)
{
  VARIANT_BOOL pAllow;
  OLECHECK(GetDefaultInterface()->get_AllowVoiceFormatMatchingOnNextSet((VARIANT_BOOL*)&pAllow));
  return pAllow;
}

void __fastcall TSpSharedRecoContext::set_VoicePurgeEvent(Speechlib_tlb::SpeechRecoEvents EventInterest/*[in]*/)
{
  GetDefaultInterface()->set_VoicePurgeEvent(EventInterest/*[in]*/);
}

Speechlib_tlb::SpeechRecoEvents __fastcall TSpSharedRecoContext::get_VoicePurgeEvent(void)
{
  Speechlib_tlb::SpeechRecoEvents EventInterest;
  OLECHECK(GetDefaultInterface()->get_VoicePurgeEvent((Speechlib_tlb::SpeechRecoEvents*)&EventInterest));
  return EventInterest;
}

void __fastcall TSpSharedRecoContext::set_EventInterests(Speechlib_tlb::SpeechRecoEvents EventInterest/*[in]*/)
{
  GetDefaultInterface()->set_EventInterests(EventInterest/*[in]*/);
}

Speechlib_tlb::SpeechRecoEvents __fastcall TSpSharedRecoContext::get_EventInterests(void)
{
  Speechlib_tlb::SpeechRecoEvents EventInterest;
  OLECHECK(GetDefaultInterface()->get_EventInterests((Speechlib_tlb::SpeechRecoEvents*)&EventInterest));
  return EventInterest;
}

void __fastcall TSpSharedRecoContext::set_CmdMaxAlternates(long MaxAlternates/*[in]*/)
{
  GetDefaultInterface()->set_CmdMaxAlternates(MaxAlternates/*[in]*/);
}

long __fastcall TSpSharedRecoContext::get_CmdMaxAlternates(void)
{
  long MaxAlternates;
  OLECHECK(GetDefaultInterface()->get_CmdMaxAlternates((long*)&MaxAlternates));
  return MaxAlternates;
}

void __fastcall TSpSharedRecoContext::set_State(Speechlib_tlb::SpeechRecoContextState State/*[in]*/)
{
  GetDefaultInterface()->set_State(State/*[in]*/);
}

Speechlib_tlb::SpeechRecoContextState __fastcall TSpSharedRecoContext::get_State(void)
{
  Speechlib_tlb::SpeechRecoContextState State;
  OLECHECK(GetDefaultInterface()->get_State((Speechlib_tlb::SpeechRecoContextState*)&State));
  return State;
}

void __fastcall TSpSharedRecoContext::set_RetainedAudio(Speechlib_tlb::SpeechRetainedAudioOptions Option/*[in]*/)
{
  GetDefaultInterface()->set_RetainedAudio(Option/*[in]*/);
}

Speechlib_tlb::SpeechRetainedAudioOptions __fastcall TSpSharedRecoContext::get_RetainedAudio(void)
{
  Speechlib_tlb::SpeechRetainedAudioOptions Option;
  OLECHECK(GetDefaultInterface()->get_RetainedAudio((Speechlib_tlb::SpeechRetainedAudioOptions*)&Option));
  return Option;
}

void __fastcall TSpSharedRecoContext::_set_RetainedAudioFormat(Speechlib_tlb::ISpeechAudioFormat* Format/*[in]*/)
{
  GetDefaultInterface()->_set_RetainedAudioFormat(Format/*[in]*/);
}

Speechlib_tlb::ISpeechAudioFormatPtr __fastcall TSpSharedRecoContext::get_RetainedAudioFormat(void)
{
  Speechlib_tlb::ISpeechAudioFormatPtr Format;
  OLECHECK(GetDefaultInterface()->get_RetainedAudioFormat(&Format));
  return Format;
}

ISpeechRecognizerPtr& TSpInprocRecognizer::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpInprocRecognizer::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpInprocRecognizer::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpInprocRecognizer::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpInprocRecognizer::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpInprocRecognizer::ConnectTo(ISpeechRecognizerPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpInprocRecognizer::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpInprocRecognizer;
  sd.IntfIID = __uuidof(ISpeechRecognizer);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

void __fastcall TSpInprocRecognizer::EmulateRecognition(VARIANT TextElements/*[in]*/, 
                                                        VARIANT* ElementDisplayAttributes/*[in,def,opt]*/, 
                                                        long LanguageId/*[in,def,opt]*/)
{
  GetDefaultInterface()->EmulateRecognition(TextElements/*[in]*/, 
                                            ElementDisplayAttributes/*[in,def,opt]*/, 
                                            LanguageId/*[in,def,opt]*/);
}

Speechlib_tlb::ISpeechRecoContext* __fastcall TSpInprocRecognizer::CreateRecoContext(void)
{
  Speechlib_tlb::ISpeechRecoContext* NewContext = 0;
  OLECHECK(GetDefaultInterface()->CreateRecoContext((Speechlib_tlb::ISpeechRecoContext**)&NewContext));
  return NewContext;
}

Speechlib_tlb::ISpeechAudioFormat* __fastcall TSpInprocRecognizer::GetFormat(Speechlib_tlb::SpeechFormatType Type/*[in]*/)
{
  Speechlib_tlb::ISpeechAudioFormat* Format = 0;
  OLECHECK(GetDefaultInterface()->GetFormat(Type, (Speechlib_tlb::ISpeechAudioFormat**)&Format));
  return Format;
}

VARIANT_BOOL __fastcall TSpInprocRecognizer::SetPropertyNumber(BSTR Name/*[in]*/, long Value/*[in]*/)
{
  VARIANT_BOOL Supported;
  OLECHECK(GetDefaultInterface()->SetPropertyNumber(Name, Value, (VARIANT_BOOL*)&Supported));
  return Supported;
}

VARIANT_BOOL __fastcall TSpInprocRecognizer::GetPropertyNumber(BSTR Name/*[in]*/, 
                                                               long* Value/*[in,out]*/)
{
  VARIANT_BOOL Supported;
  OLECHECK(GetDefaultInterface()->GetPropertyNumber(Name, Value, (VARIANT_BOOL*)&Supported));
  return Supported;
}

VARIANT_BOOL __fastcall TSpInprocRecognizer::SetPropertyString(BSTR Name/*[in]*/, BSTR Value/*[in]*/)
{
  VARIANT_BOOL Supported;
  OLECHECK(GetDefaultInterface()->SetPropertyString(Name, Value, (VARIANT_BOOL*)&Supported));
  return Supported;
}

VARIANT_BOOL __fastcall TSpInprocRecognizer::GetPropertyString(BSTR Name/*[in]*/, 
                                                               BSTR* Value/*[in,out]*/)
{
  VARIANT_BOOL Supported;
  OLECHECK(GetDefaultInterface()->GetPropertyString(Name, Value, (VARIANT_BOOL*)&Supported));
  return Supported;
}

VARIANT_BOOL __fastcall TSpInprocRecognizer::IsUISupported(BSTR TypeOfUI/*[in]*/, 
                                                           VARIANT* ExtraData/*[in,def,opt]*/)
{
  VARIANT_BOOL Supported;
  OLECHECK(GetDefaultInterface()->IsUISupported(TypeOfUI, ExtraData, (VARIANT_BOOL*)&Supported));
  return Supported;
}

void __fastcall TSpInprocRecognizer::DisplayUI(long hWndParent/*[in]*/, BSTR Title/*[in]*/, 
                                               BSTR TypeOfUI/*[in]*/, 
                                               VARIANT* ExtraData/*[in,def,opt]*/)
{
  GetDefaultInterface()->DisplayUI(hWndParent/*[in]*/, Title/*[in]*/, TypeOfUI/*[in]*/, 
                                   ExtraData/*[in,def,opt]*/);
}

Speechlib_tlb::ISpeechObjectTokens* __fastcall TSpInprocRecognizer::GetRecognizers(BSTR RequiredAttributes/*[in,def,opt]*/, 
                                                                                   BSTR OptionalAttributes/*[in,def,opt]*/)
{
  Speechlib_tlb::ISpeechObjectTokens* ObjectTokens = 0;
  OLECHECK(GetDefaultInterface()->GetRecognizers(RequiredAttributes, OptionalAttributes, (Speechlib_tlb::ISpeechObjectTokens**)&ObjectTokens));
  return ObjectTokens;
}

Speechlib_tlb::ISpeechObjectTokens* __fastcall TSpInprocRecognizer::GetAudioInputs(BSTR RequiredAttributes/*[in,def,opt]*/, 
                                                                                   BSTR OptionalAttributes/*[in,def,opt]*/)
{
  Speechlib_tlb::ISpeechObjectTokens* ObjectTokens = 0;
  OLECHECK(GetDefaultInterface()->GetAudioInputs(RequiredAttributes, OptionalAttributes, (Speechlib_tlb::ISpeechObjectTokens**)&ObjectTokens));
  return ObjectTokens;
}

Speechlib_tlb::ISpeechObjectTokens* __fastcall TSpInprocRecognizer::GetProfiles(BSTR RequiredAttributes/*[in,def,opt]*/, 
                                                                                BSTR OptionalAttributes/*[in,def,opt]*/)
{
  Speechlib_tlb::ISpeechObjectTokens* ObjectTokens = 0;
  OLECHECK(GetDefaultInterface()->GetProfiles(RequiredAttributes, OptionalAttributes, (Speechlib_tlb::ISpeechObjectTokens**)&ObjectTokens));
  return ObjectTokens;
}

void __fastcall TSpInprocRecognizer::_set_Recognizer(Speechlib_tlb::ISpeechObjectToken* Recognizer/*[in]*/)
{
  GetDefaultInterface()->_set_Recognizer(Recognizer/*[in]*/);
}

Speechlib_tlb::ISpeechObjectTokenPtr __fastcall TSpInprocRecognizer::get_Recognizer(void)
{
  Speechlib_tlb::ISpeechObjectTokenPtr Recognizer;
  OLECHECK(GetDefaultInterface()->get_Recognizer(&Recognizer));
  return Recognizer;
}

void __fastcall TSpInprocRecognizer::set_AllowAudioInputFormatChangesOnNextSet(VARIANT_BOOL Allow/*[in]*/)
{
  GetDefaultInterface()->set_AllowAudioInputFormatChangesOnNextSet(Allow/*[in]*/);
}

VARIANT_BOOL __fastcall TSpInprocRecognizer::get_AllowAudioInputFormatChangesOnNextSet(void)
{
  VARIANT_BOOL Allow;
  OLECHECK(GetDefaultInterface()->get_AllowAudioInputFormatChangesOnNextSet((VARIANT_BOOL*)&Allow));
  return Allow;
}

void __fastcall TSpInprocRecognizer::_set_AudioInput(Speechlib_tlb::ISpeechObjectToken* AudioInput/*[in,def,opt]*/)
{
  GetDefaultInterface()->_set_AudioInput(AudioInput/*[in,def,opt]*/);
}

Speechlib_tlb::ISpeechObjectTokenPtr __fastcall TSpInprocRecognizer::get_AudioInput(void)
{
  Speechlib_tlb::ISpeechObjectTokenPtr AudioInput;
  OLECHECK(GetDefaultInterface()->get_AudioInput(&AudioInput));
  return AudioInput;
}

void __fastcall TSpInprocRecognizer::_set_AudioInputStream(Speechlib_tlb::ISpeechBaseStream* AudioInputStream/*[in,def,opt]*/)
{
  GetDefaultInterface()->_set_AudioInputStream(AudioInputStream/*[in,def,opt]*/);
}

Speechlib_tlb::ISpeechBaseStreamPtr __fastcall TSpInprocRecognizer::get_AudioInputStream(void)
{
  Speechlib_tlb::ISpeechBaseStreamPtr AudioInputStream;
  OLECHECK(GetDefaultInterface()->get_AudioInputStream(&AudioInputStream));
  return AudioInputStream;
}

VARIANT_BOOL __fastcall TSpInprocRecognizer::get_IsShared(void)
{
  VARIANT_BOOL Shared;
  OLECHECK(GetDefaultInterface()->get_IsShared((VARIANT_BOOL*)&Shared));
  return Shared;
}

void __fastcall TSpInprocRecognizer::set_State(Speechlib_tlb::SpeechRecognizerState State/*[in]*/)
{
  GetDefaultInterface()->set_State(State/*[in]*/);
}

Speechlib_tlb::SpeechRecognizerState __fastcall TSpInprocRecognizer::get_State(void)
{
  Speechlib_tlb::SpeechRecognizerState State;
  OLECHECK(GetDefaultInterface()->get_State((Speechlib_tlb::SpeechRecognizerState*)&State));
  return State;
}

Speechlib_tlb::ISpeechRecognizerStatusPtr __fastcall TSpInprocRecognizer::get_Status(void)
{
  Speechlib_tlb::ISpeechRecognizerStatusPtr Status;
  OLECHECK(GetDefaultInterface()->get_Status(&Status));
  return Status;
}

void __fastcall TSpInprocRecognizer::_set_Profile(Speechlib_tlb::ISpeechObjectToken* Profile/*[in,def,opt]*/)
{
  GetDefaultInterface()->_set_Profile(Profile/*[in,def,opt]*/);
}

Speechlib_tlb::ISpeechObjectTokenPtr __fastcall TSpInprocRecognizer::get_Profile(void)
{
  Speechlib_tlb::ISpeechObjectTokenPtr Profile;
  OLECHECK(GetDefaultInterface()->get_Profile(&Profile));
  return Profile;
}

ISpeechRecognizerPtr& TSpSharedRecognizer::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpSharedRecognizer::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpSharedRecognizer::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpSharedRecognizer::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpSharedRecognizer::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpSharedRecognizer::ConnectTo(ISpeechRecognizerPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpSharedRecognizer::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpSharedRecognizer;
  sd.IntfIID = __uuidof(ISpeechRecognizer);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

void __fastcall TSpSharedRecognizer::EmulateRecognition(VARIANT TextElements/*[in]*/, 
                                                        VARIANT* ElementDisplayAttributes/*[in,def,opt]*/, 
                                                        long LanguageId/*[in,def,opt]*/)
{
  GetDefaultInterface()->EmulateRecognition(TextElements/*[in]*/, 
                                            ElementDisplayAttributes/*[in,def,opt]*/, 
                                            LanguageId/*[in,def,opt]*/);
}

Speechlib_tlb::ISpeechRecoContext* __fastcall TSpSharedRecognizer::CreateRecoContext(void)
{
  Speechlib_tlb::ISpeechRecoContext* NewContext = 0;
  OLECHECK(GetDefaultInterface()->CreateRecoContext((Speechlib_tlb::ISpeechRecoContext**)&NewContext));
  return NewContext;
}

Speechlib_tlb::ISpeechAudioFormat* __fastcall TSpSharedRecognizer::GetFormat(Speechlib_tlb::SpeechFormatType Type/*[in]*/)
{
  Speechlib_tlb::ISpeechAudioFormat* Format = 0;
  OLECHECK(GetDefaultInterface()->GetFormat(Type, (Speechlib_tlb::ISpeechAudioFormat**)&Format));
  return Format;
}

VARIANT_BOOL __fastcall TSpSharedRecognizer::SetPropertyNumber(BSTR Name/*[in]*/, long Value/*[in]*/)
{
  VARIANT_BOOL Supported;
  OLECHECK(GetDefaultInterface()->SetPropertyNumber(Name, Value, (VARIANT_BOOL*)&Supported));
  return Supported;
}

VARIANT_BOOL __fastcall TSpSharedRecognizer::GetPropertyNumber(BSTR Name/*[in]*/, 
                                                               long* Value/*[in,out]*/)
{
  VARIANT_BOOL Supported;
  OLECHECK(GetDefaultInterface()->GetPropertyNumber(Name, Value, (VARIANT_BOOL*)&Supported));
  return Supported;
}

VARIANT_BOOL __fastcall TSpSharedRecognizer::SetPropertyString(BSTR Name/*[in]*/, BSTR Value/*[in]*/)
{
  VARIANT_BOOL Supported;
  OLECHECK(GetDefaultInterface()->SetPropertyString(Name, Value, (VARIANT_BOOL*)&Supported));
  return Supported;
}

VARIANT_BOOL __fastcall TSpSharedRecognizer::GetPropertyString(BSTR Name/*[in]*/, 
                                                               BSTR* Value/*[in,out]*/)
{
  VARIANT_BOOL Supported;
  OLECHECK(GetDefaultInterface()->GetPropertyString(Name, Value, (VARIANT_BOOL*)&Supported));
  return Supported;
}

VARIANT_BOOL __fastcall TSpSharedRecognizer::IsUISupported(BSTR TypeOfUI/*[in]*/, 
                                                           VARIANT* ExtraData/*[in,def,opt]*/)
{
  VARIANT_BOOL Supported;
  OLECHECK(GetDefaultInterface()->IsUISupported(TypeOfUI, ExtraData, (VARIANT_BOOL*)&Supported));
  return Supported;
}

void __fastcall TSpSharedRecognizer::DisplayUI(long hWndParent/*[in]*/, BSTR Title/*[in]*/, 
                                               BSTR TypeOfUI/*[in]*/, 
                                               VARIANT* ExtraData/*[in,def,opt]*/)
{
  GetDefaultInterface()->DisplayUI(hWndParent/*[in]*/, Title/*[in]*/, TypeOfUI/*[in]*/, 
                                   ExtraData/*[in,def,opt]*/);
}

Speechlib_tlb::ISpeechObjectTokens* __fastcall TSpSharedRecognizer::GetRecognizers(BSTR RequiredAttributes/*[in,def,opt]*/, 
                                                                                   BSTR OptionalAttributes/*[in,def,opt]*/)
{
  Speechlib_tlb::ISpeechObjectTokens* ObjectTokens = 0;
  OLECHECK(GetDefaultInterface()->GetRecognizers(RequiredAttributes, OptionalAttributes, (Speechlib_tlb::ISpeechObjectTokens**)&ObjectTokens));
  return ObjectTokens;
}

Speechlib_tlb::ISpeechObjectTokens* __fastcall TSpSharedRecognizer::GetAudioInputs(BSTR RequiredAttributes/*[in,def,opt]*/, 
                                                                                   BSTR OptionalAttributes/*[in,def,opt]*/)
{
  Speechlib_tlb::ISpeechObjectTokens* ObjectTokens = 0;
  OLECHECK(GetDefaultInterface()->GetAudioInputs(RequiredAttributes, OptionalAttributes, (Speechlib_tlb::ISpeechObjectTokens**)&ObjectTokens));
  return ObjectTokens;
}

Speechlib_tlb::ISpeechObjectTokens* __fastcall TSpSharedRecognizer::GetProfiles(BSTR RequiredAttributes/*[in,def,opt]*/, 
                                                                                BSTR OptionalAttributes/*[in,def,opt]*/)
{
  Speechlib_tlb::ISpeechObjectTokens* ObjectTokens = 0;
  OLECHECK(GetDefaultInterface()->GetProfiles(RequiredAttributes, OptionalAttributes, (Speechlib_tlb::ISpeechObjectTokens**)&ObjectTokens));
  return ObjectTokens;
}

void __fastcall TSpSharedRecognizer::_set_Recognizer(Speechlib_tlb::ISpeechObjectToken* Recognizer/*[in]*/)
{
  GetDefaultInterface()->_set_Recognizer(Recognizer/*[in]*/);
}

Speechlib_tlb::ISpeechObjectTokenPtr __fastcall TSpSharedRecognizer::get_Recognizer(void)
{
  Speechlib_tlb::ISpeechObjectTokenPtr Recognizer;
  OLECHECK(GetDefaultInterface()->get_Recognizer(&Recognizer));
  return Recognizer;
}

void __fastcall TSpSharedRecognizer::set_AllowAudioInputFormatChangesOnNextSet(VARIANT_BOOL Allow/*[in]*/)
{
  GetDefaultInterface()->set_AllowAudioInputFormatChangesOnNextSet(Allow/*[in]*/);
}

VARIANT_BOOL __fastcall TSpSharedRecognizer::get_AllowAudioInputFormatChangesOnNextSet(void)
{
  VARIANT_BOOL Allow;
  OLECHECK(GetDefaultInterface()->get_AllowAudioInputFormatChangesOnNextSet((VARIANT_BOOL*)&Allow));
  return Allow;
}

void __fastcall TSpSharedRecognizer::_set_AudioInput(Speechlib_tlb::ISpeechObjectToken* AudioInput/*[in,def,opt]*/)
{
  GetDefaultInterface()->_set_AudioInput(AudioInput/*[in,def,opt]*/);
}

Speechlib_tlb::ISpeechObjectTokenPtr __fastcall TSpSharedRecognizer::get_AudioInput(void)
{
  Speechlib_tlb::ISpeechObjectTokenPtr AudioInput;
  OLECHECK(GetDefaultInterface()->get_AudioInput(&AudioInput));
  return AudioInput;
}

void __fastcall TSpSharedRecognizer::_set_AudioInputStream(Speechlib_tlb::ISpeechBaseStream* AudioInputStream/*[in,def,opt]*/)
{
  GetDefaultInterface()->_set_AudioInputStream(AudioInputStream/*[in,def,opt]*/);
}

Speechlib_tlb::ISpeechBaseStreamPtr __fastcall TSpSharedRecognizer::get_AudioInputStream(void)
{
  Speechlib_tlb::ISpeechBaseStreamPtr AudioInputStream;
  OLECHECK(GetDefaultInterface()->get_AudioInputStream(&AudioInputStream));
  return AudioInputStream;
}

VARIANT_BOOL __fastcall TSpSharedRecognizer::get_IsShared(void)
{
  VARIANT_BOOL Shared;
  OLECHECK(GetDefaultInterface()->get_IsShared((VARIANT_BOOL*)&Shared));
  return Shared;
}

void __fastcall TSpSharedRecognizer::set_State(Speechlib_tlb::SpeechRecognizerState State/*[in]*/)
{
  GetDefaultInterface()->set_State(State/*[in]*/);
}

Speechlib_tlb::SpeechRecognizerState __fastcall TSpSharedRecognizer::get_State(void)
{
  Speechlib_tlb::SpeechRecognizerState State;
  OLECHECK(GetDefaultInterface()->get_State((Speechlib_tlb::SpeechRecognizerState*)&State));
  return State;
}

Speechlib_tlb::ISpeechRecognizerStatusPtr __fastcall TSpSharedRecognizer::get_Status(void)
{
  Speechlib_tlb::ISpeechRecognizerStatusPtr Status;
  OLECHECK(GetDefaultInterface()->get_Status(&Status));
  return Status;
}

void __fastcall TSpSharedRecognizer::_set_Profile(Speechlib_tlb::ISpeechObjectToken* Profile/*[in,def,opt]*/)
{
  GetDefaultInterface()->_set_Profile(Profile/*[in,def,opt]*/);
}

Speechlib_tlb::ISpeechObjectTokenPtr __fastcall TSpSharedRecognizer::get_Profile(void)
{
  Speechlib_tlb::ISpeechObjectTokenPtr Profile;
  OLECHECK(GetDefaultInterface()->get_Profile(&Profile));
  return Profile;
}

ISpeechLexiconPtr& TSpLexicon::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpLexicon::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpLexicon::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpLexicon::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpLexicon::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpLexicon::ConnectTo(ISpeechLexiconPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpLexicon::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpLexicon;
  sd.IntfIID = __uuidof(ISpeechLexicon);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

Speechlib_tlb::ISpeechLexiconWords* __fastcall TSpLexicon::GetWords(Speechlib_tlb::SpeechLexiconType Flags/*[in,def,opt]*/, 
                                                                    long* GenerationId/*[out,def,opt]*/)
{
  Speechlib_tlb::ISpeechLexiconWords* Words = 0;
  OLECHECK(GetDefaultInterface()->GetWords(Flags, GenerationId, (Speechlib_tlb::ISpeechLexiconWords**)&Words));
  return Words;
}

void __fastcall TSpLexicon::AddPronunciation(BSTR bstrWord/*[in]*/, long LangId/*[in]*/, 
                                             Speechlib_tlb::SpeechPartOfSpeech PartOfSpeech/*[in,def,opt]*/, 
                                             BSTR bstrPronunciation/*[in,def,opt]*/)
{
  GetDefaultInterface()->AddPronunciation(bstrWord/*[in]*/, LangId/*[in]*/, 
                                          PartOfSpeech/*[in,def,opt]*/, 
                                          bstrPronunciation/*[in,def,opt]*/);
}

void __fastcall TSpLexicon::AddPronunciationByPhoneIds(BSTR bstrWord/*[in]*/, long LangId/*[in]*/, 
                                                       Speechlib_tlb::SpeechPartOfSpeech PartOfSpeech/*[in,def,opt]*/, 
                                                       VARIANT* PhoneIds/*[in,def,opt]*/)
{
  GetDefaultInterface()->AddPronunciationByPhoneIds(bstrWord/*[in]*/, LangId/*[in]*/, 
                                                    PartOfSpeech/*[in,def,opt]*/, 
                                                    PhoneIds/*[in,def,opt]*/);
}

void __fastcall TSpLexicon::RemovePronunciation(BSTR bstrWord/*[in]*/, long LangId/*[in]*/, 
                                                Speechlib_tlb::SpeechPartOfSpeech PartOfSpeech/*[in,def,opt]*/, 
                                                BSTR bstrPronunciation/*[in,def,opt]*/)
{
  GetDefaultInterface()->RemovePronunciation(bstrWord/*[in]*/, LangId/*[in]*/, 
                                             PartOfSpeech/*[in,def,opt]*/, 
                                             bstrPronunciation/*[in,def,opt]*/);
}

void __fastcall TSpLexicon::RemovePronunciationByPhoneIds(BSTR bstrWord/*[in]*/, long LangId/*[in]*/, 
                                                          Speechlib_tlb::SpeechPartOfSpeech PartOfSpeech/*[in,def,opt]*/, 
                                                          VARIANT* PhoneIds/*[in,def,opt]*/)
{
  GetDefaultInterface()->RemovePronunciationByPhoneIds(bstrWord/*[in]*/, LangId/*[in]*/, 
                                                       PartOfSpeech/*[in,def,opt]*/, 
                                                       PhoneIds/*[in,def,opt]*/);
}

Speechlib_tlb::ISpeechLexiconPronunciations* __fastcall TSpLexicon::GetPronunciations(BSTR bstrWord/*[in]*/, 
                                                                                      long LangId/*[in,def,opt]*/, 
                                                                                      Speechlib_tlb::SpeechLexiconType TypeFlags/*[in,def,opt]*/)
{
  Speechlib_tlb::ISpeechLexiconPronunciations* ppPronunciations = 0;
  OLECHECK(GetDefaultInterface()->GetPronunciations(bstrWord, LangId, TypeFlags, (Speechlib_tlb::ISpeechLexiconPronunciations**)&ppPronunciations));
  return ppPronunciations;
}

Speechlib_tlb::ISpeechLexiconWords* __fastcall TSpLexicon::GetGenerationChange(long* GenerationId/*[in,out]*/)
{
  Speechlib_tlb::ISpeechLexiconWords* ppWords = 0;
  OLECHECK(GetDefaultInterface()->GetGenerationChange(GenerationId, (Speechlib_tlb::ISpeechLexiconWords**)&ppWords));
  return ppWords;
}

long __fastcall TSpLexicon::get_GenerationId(void)
{
  long GenerationId;
  OLECHECK(GetDefaultInterface()->get_GenerationId((long*)&GenerationId));
  return GenerationId;
}

ISpeechLexiconPtr& TSpUnCompressedLexicon::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpUnCompressedLexicon::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpUnCompressedLexicon::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpUnCompressedLexicon::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpUnCompressedLexicon::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpUnCompressedLexicon::ConnectTo(ISpeechLexiconPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpUnCompressedLexicon::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpUnCompressedLexicon;
  sd.IntfIID = __uuidof(ISpeechLexicon);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

Speechlib_tlb::ISpeechLexiconWords* __fastcall TSpUnCompressedLexicon::GetWords(Speechlib_tlb::SpeechLexiconType Flags/*[in,def,opt]*/, 
                                                                                long* GenerationId/*[out,def,opt]*/)
{
  Speechlib_tlb::ISpeechLexiconWords* Words = 0;
  OLECHECK(GetDefaultInterface()->GetWords(Flags, GenerationId, (Speechlib_tlb::ISpeechLexiconWords**)&Words));
  return Words;
}

void __fastcall TSpUnCompressedLexicon::AddPronunciation(BSTR bstrWord/*[in]*/, long LangId/*[in]*/, 
                                                         Speechlib_tlb::SpeechPartOfSpeech PartOfSpeech/*[in,def,opt]*/, 
                                                         BSTR bstrPronunciation/*[in,def,opt]*/)
{
  GetDefaultInterface()->AddPronunciation(bstrWord/*[in]*/, LangId/*[in]*/, 
                                          PartOfSpeech/*[in,def,opt]*/, 
                                          bstrPronunciation/*[in,def,opt]*/);
}

void __fastcall TSpUnCompressedLexicon::AddPronunciationByPhoneIds(BSTR bstrWord/*[in]*/, 
                                                                   long LangId/*[in]*/, 
                                                                   Speechlib_tlb::SpeechPartOfSpeech PartOfSpeech/*[in,def,opt]*/, 
                                                                   VARIANT* PhoneIds/*[in,def,opt]*/)
{
  GetDefaultInterface()->AddPronunciationByPhoneIds(bstrWord/*[in]*/, LangId/*[in]*/, 
                                                    PartOfSpeech/*[in,def,opt]*/, 
                                                    PhoneIds/*[in,def,opt]*/);
}

void __fastcall TSpUnCompressedLexicon::RemovePronunciation(BSTR bstrWord/*[in]*/, 
                                                            long LangId/*[in]*/, 
                                                            Speechlib_tlb::SpeechPartOfSpeech PartOfSpeech/*[in,def,opt]*/, 
                                                            BSTR bstrPronunciation/*[in,def,opt]*/)
{
  GetDefaultInterface()->RemovePronunciation(bstrWord/*[in]*/, LangId/*[in]*/, 
                                             PartOfSpeech/*[in,def,opt]*/, 
                                             bstrPronunciation/*[in,def,opt]*/);
}

void __fastcall TSpUnCompressedLexicon::RemovePronunciationByPhoneIds(BSTR bstrWord/*[in]*/, 
                                                                      long LangId/*[in]*/, 
                                                                      Speechlib_tlb::SpeechPartOfSpeech PartOfSpeech/*[in,def,opt]*/, 
                                                                      VARIANT* PhoneIds/*[in,def,opt]*/)
{
  GetDefaultInterface()->RemovePronunciationByPhoneIds(bstrWord/*[in]*/, LangId/*[in]*/, 
                                                       PartOfSpeech/*[in,def,opt]*/, 
                                                       PhoneIds/*[in,def,opt]*/);
}

Speechlib_tlb::ISpeechLexiconPronunciations* __fastcall TSpUnCompressedLexicon::GetPronunciations(BSTR bstrWord/*[in]*/, 
                                                                                                  long LangId/*[in,def,opt]*/, 
                                                                                                  Speechlib_tlb::SpeechLexiconType TypeFlags/*[in,def,opt]*/)
{
  Speechlib_tlb::ISpeechLexiconPronunciations* ppPronunciations = 0;
  OLECHECK(GetDefaultInterface()->GetPronunciations(bstrWord, LangId, TypeFlags, (Speechlib_tlb::ISpeechLexiconPronunciations**)&ppPronunciations));
  return ppPronunciations;
}

Speechlib_tlb::ISpeechLexiconWords* __fastcall TSpUnCompressedLexicon::GetGenerationChange(long* GenerationId/*[in,out]*/)
{
  Speechlib_tlb::ISpeechLexiconWords* ppWords = 0;
  OLECHECK(GetDefaultInterface()->GetGenerationChange(GenerationId, (Speechlib_tlb::ISpeechLexiconWords**)&ppWords));
  return ppWords;
}

long __fastcall TSpUnCompressedLexicon::get_GenerationId(void)
{
  long GenerationId;
  OLECHECK(GetDefaultInterface()->get_GenerationId((long*)&GenerationId));
  return GenerationId;
}

ISpLexiconPtr& TSpCompressedLexicon::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpCompressedLexicon::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpCompressedLexicon::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpCompressedLexicon::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpCompressedLexicon::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpCompressedLexicon::ConnectTo(ISpLexiconPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpCompressedLexicon::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpCompressedLexicon;
  sd.IntfIID = __uuidof(ISpLexicon);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

void __fastcall TSpCompressedLexicon::GetPronunciations(LPWSTR pszWord/*[in]*/, 
                                                        unsigned_short LangId/*[in]*/, 
                                                        unsigned_long dwFlags/*[in]*/, 
                                                        Speechlib_tlb::SPWORDPRONUNCIATIONLIST* pWordPronunciationList/*[in,out]*/)
{
  GetDefaultInterface()->GetPronunciations(pszWord/*[in]*/, LangId/*[in]*/, dwFlags/*[in]*/, 
                                           pWordPronunciationList/*[in,out]*/);
}

void __fastcall TSpCompressedLexicon::AddPronunciation(LPWSTR pszWord/*[in]*/, 
                                                       unsigned_short LangId/*[in]*/, 
                                                       Speechlib_tlb::SPPARTOFSPEECH ePartOfSpeech/*[in]*/, 
                                                       LPWSTR pszPronunciation/*[in]*/)
{
  GetDefaultInterface()->AddPronunciation(pszWord/*[in]*/, LangId/*[in]*/, ePartOfSpeech/*[in]*/, 
                                          pszPronunciation/*[in]*/);
}

void __fastcall TSpCompressedLexicon::RemovePronunciation(LPWSTR pszWord/*[in]*/, 
                                                          unsigned_short LangId/*[in]*/, 
                                                          Speechlib_tlb::SPPARTOFSPEECH ePartOfSpeech/*[in]*/, 
                                                          LPWSTR pszPronunciation/*[in]*/)
{
  GetDefaultInterface()->RemovePronunciation(pszWord/*[in]*/, LangId/*[in]*/, ePartOfSpeech/*[in]*/, 
                                             pszPronunciation/*[in]*/);
}

void __fastcall TSpCompressedLexicon::GetGeneration(unsigned_long* pdwGeneration/*[out]*/)
{
  GetDefaultInterface()->GetGeneration(pdwGeneration/*[out]*/);
}

void __fastcall TSpCompressedLexicon::GetGenerationChange(unsigned_long dwFlags/*[in]*/, 
                                                          unsigned_long* pdwGeneration/*[in,out]*/, 
                                                          Speechlib_tlb::SPWORDLIST* pWordList/*[in,out]*/)
{
  GetDefaultInterface()->GetGenerationChange(dwFlags/*[in]*/, pdwGeneration/*[in,out]*/, 
                                             pWordList/*[in,out]*/);
}

void __fastcall TSpCompressedLexicon::GetWords(unsigned_long dwFlags/*[in]*/, 
                                               unsigned_long* pdwGeneration/*[in,out]*/, 
                                               unsigned_long* pdwCookie/*[in,out]*/, 
                                               Speechlib_tlb::SPWORDLIST* pWordList/*[in,out]*/)
{
  GetDefaultInterface()->GetWords(dwFlags/*[in]*/, pdwGeneration/*[in,out]*/, pdwCookie/*[in,out]*/, 
                                  pWordList/*[in,out]*/);
}

ISpShortcutPtr& TSpShortcut::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpShortcut::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpShortcut::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpShortcut::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpShortcut::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpShortcut::ConnectTo(ISpShortcutPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpShortcut::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpShortcut;
  sd.IntfIID = __uuidof(ISpShortcut);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

void __fastcall TSpShortcut::AddShortcut(LPWSTR pszDisplay/*[in]*/, unsigned_short LangId/*[in]*/, 
                                         LPWSTR pszSpoken/*[in]*/, 
                                         Speechlib_tlb::SPSHORTCUTTYPE shType/*[in]*/)
{
  GetDefaultInterface()->AddShortcut(pszDisplay/*[in]*/, LangId/*[in]*/, pszSpoken/*[in]*/, 
                                     shType/*[in]*/);
}

void __fastcall TSpShortcut::RemoveShortcut(LPWSTR pszDisplay/*[in]*/, unsigned_short LangId/*[in]*/, 
                                            LPWSTR pszSpoken/*[in]*/, 
                                            Speechlib_tlb::SPSHORTCUTTYPE shType/*[in]*/)
{
  GetDefaultInterface()->RemoveShortcut(pszDisplay/*[in]*/, LangId/*[in]*/, pszSpoken/*[in]*/, 
                                        shType/*[in]*/);
}

void __fastcall TSpShortcut::GetShortcuts(unsigned_short LangId/*[in]*/, 
                                          Speechlib_tlb::SPSHORTCUTPAIRLIST* pShortcutpairList/*[in,out]*/)
{
  GetDefaultInterface()->GetShortcuts(LangId/*[in]*/, pShortcutpairList/*[in,out]*/);
}

void __fastcall TSpShortcut::GetGeneration(unsigned_long* pdwGeneration/*[out]*/)
{
  GetDefaultInterface()->GetGeneration(pdwGeneration/*[out]*/);
}

void __fastcall TSpShortcut::GetWordsFromGenerationChange(unsigned_long* pdwGeneration/*[in,out]*/, 
                                                          Speechlib_tlb::SPWORDLIST* pWordList/*[in,out]*/)
{
  GetDefaultInterface()->GetWordsFromGenerationChange(pdwGeneration/*[in,out]*/, 
                                                      pWordList/*[in,out]*/);
}

void __fastcall TSpShortcut::GetWords(unsigned_long* pdwGeneration/*[in,out]*/, 
                                      unsigned_long* pdwCookie/*[in,out]*/, 
                                      Speechlib_tlb::SPWORDLIST* pWordList/*[in,out]*/)
{
  GetDefaultInterface()->GetWords(pdwGeneration/*[in,out]*/, pdwCookie/*[in,out]*/, 
                                  pWordList/*[in,out]*/);
}

void __fastcall TSpShortcut::GetShortcutsForGeneration(unsigned_long* pdwGeneration/*[in,out]*/, 
                                                       unsigned_long* pdwCookie/*[in,out]*/, 
                                                       Speechlib_tlb::SPSHORTCUTPAIRLIST* pShortcutpairList/*[in,out]*/)
{
  GetDefaultInterface()->GetShortcutsForGeneration(pdwGeneration/*[in,out]*/, pdwCookie/*[in,out]*/, 
                                                   pShortcutpairList/*[in,out]*/);
}

void __fastcall TSpShortcut::GetGenerationChange(unsigned_long* pdwGeneration/*[in,out]*/, 
                                                 Speechlib_tlb::SPSHORTCUTPAIRLIST* pShortcutpairList/*[in,out]*/)
{
  GetDefaultInterface()->GetGenerationChange(pdwGeneration/*[in,out]*/, 
                                             pShortcutpairList/*[in,out]*/);
}

ISpeechPhoneConverterPtr& TSpPhoneConverter::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpPhoneConverter::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpPhoneConverter::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpPhoneConverter::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpPhoneConverter::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpPhoneConverter::ConnectTo(ISpeechPhoneConverterPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpPhoneConverter::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpPhoneConverter;
  sd.IntfIID = __uuidof(ISpeechPhoneConverter);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

VARIANT __fastcall TSpPhoneConverter::PhoneToId(BSTR Phonemes/*[in]*/)
{
  VARIANT IdArray;
  OLECHECK(GetDefaultInterface()->PhoneToId(Phonemes, (VARIANT*)&IdArray));
  return IdArray;
}

BSTR __fastcall TSpPhoneConverter::IdToPhone(VARIANT IdArray/*[in]*/)
{
  BSTR Phonemes = 0;
  OLECHECK(GetDefaultInterface()->IdToPhone(IdArray, (BSTR*)&Phonemes));
  return Phonemes;
}

long __fastcall TSpPhoneConverter::get_LanguageId(void)
{
  long LanguageId;
  OLECHECK(GetDefaultInterface()->get_LanguageId((long*)&LanguageId));
  return LanguageId;
}

void __fastcall TSpPhoneConverter::set_LanguageId(long LanguageId/*[in]*/)
{
  GetDefaultInterface()->set_LanguageId(LanguageId/*[in]*/);
}

ISpPhoneticAlphabetConverterPtr& TSpPhoneticAlphabetConverter::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpPhoneticAlphabetConverter::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpPhoneticAlphabetConverter::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpPhoneticAlphabetConverter::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpPhoneticAlphabetConverter::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpPhoneticAlphabetConverter::ConnectTo(ISpPhoneticAlphabetConverterPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpPhoneticAlphabetConverter::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpPhoneticAlphabetConverter;
  sd.IntfIID = __uuidof(ISpPhoneticAlphabetConverter);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

void __fastcall TSpPhoneticAlphabetConverter::GetLangId(unsigned_short* pLangID/*[out]*/)
{
  GetDefaultInterface()->GetLangId(pLangID/*[out]*/);
}

void __fastcall TSpPhoneticAlphabetConverter::SetLangId(unsigned_short LangId/*[in]*/)
{
  GetDefaultInterface()->SetLangId(LangId/*[in]*/);
}

void __fastcall TSpPhoneticAlphabetConverter::SAPI2UPS(unsigned_short* pszSAPIId/*[in]*/, 
                                                       unsigned_short* pszUPSId/*[out]*/, 
                                                       unsigned_long cMaxLength/*[in]*/)
{
  GetDefaultInterface()->SAPI2UPS(pszSAPIId/*[in]*/, pszUPSId/*[out]*/, cMaxLength/*[in]*/);
}

void __fastcall TSpPhoneticAlphabetConverter::UPS2SAPI(unsigned_short* pszUPSId/*[in]*/, 
                                                       unsigned_short* pszSAPIId/*[out]*/, 
                                                       unsigned_long cMaxLength/*[in]*/)
{
  GetDefaultInterface()->UPS2SAPI(pszUPSId/*[in]*/, pszSAPIId/*[out]*/, cMaxLength/*[in]*/);
}

void __fastcall TSpPhoneticAlphabetConverter::GetMaxConvertLength(unsigned_long cSrcLength/*[in]*/, 
                                                                  long bSAPI2UPS/*[in]*/, 
                                                                  unsigned_long* pcMaxDestLength/*[out]*/)
{
  GetDefaultInterface()->GetMaxConvertLength(cSrcLength/*[in]*/, bSAPI2UPS/*[in]*/, 
                                             pcMaxDestLength/*[out]*/);
}

ISpPhoneConverterPtr& TSpNullPhoneConverter::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpNullPhoneConverter::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpNullPhoneConverter::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpNullPhoneConverter::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpNullPhoneConverter::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpNullPhoneConverter::ConnectTo(ISpPhoneConverterPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpNullPhoneConverter::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpNullPhoneConverter;
  sd.IntfIID = __uuidof(ISpPhoneConverter);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

void __fastcall TSpNullPhoneConverter::SetObjectToken(Speechlib_tlb::ISpObjectToken* pToken/*[in]*/)
{
  GetDefaultInterface()->SetObjectToken(pToken/*[in]*/);
}

void __fastcall TSpNullPhoneConverter::GetObjectToken(Speechlib_tlb::ISpObjectToken** ppToken/*[out]*/)
{
  GetDefaultInterface()->GetObjectToken(ppToken/*[out]*/);
}

void __fastcall TSpNullPhoneConverter::PhoneToId(LPWSTR pszPhone/*[in]*/, 
                                                 unsigned_short* pId/*[out]*/)
{
  GetDefaultInterface()->PhoneToId(pszPhone/*[in]*/, pId/*[out]*/);
}

void __fastcall TSpNullPhoneConverter::IdToPhone(LPWSTR pId/*[in]*/, 
                                                 unsigned_short* pszPhone/*[out]*/)
{
  GetDefaultInterface()->IdToPhone(pId/*[in]*/, pszPhone/*[out]*/);
}

ISpeechTextSelectionInformationPtr& TSpTextSelectionInformation::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpTextSelectionInformation::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpTextSelectionInformation::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpTextSelectionInformation::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpTextSelectionInformation::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpTextSelectionInformation::ConnectTo(ISpeechTextSelectionInformationPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpTextSelectionInformation::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpTextSelectionInformation;
  sd.IntfIID = __uuidof(ISpeechTextSelectionInformation);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

void __fastcall TSpTextSelectionInformation::set_ActiveOffset(long ActiveOffset/*[in]*/)
{
  GetDefaultInterface()->set_ActiveOffset(ActiveOffset/*[in]*/);
}

long __fastcall TSpTextSelectionInformation::get_ActiveOffset(void)
{
  long ActiveOffset;
  OLECHECK(GetDefaultInterface()->get_ActiveOffset((long*)&ActiveOffset));
  return ActiveOffset;
}

void __fastcall TSpTextSelectionInformation::set_ActiveLength(long ActiveLength/*[in]*/)
{
  GetDefaultInterface()->set_ActiveLength(ActiveLength/*[in]*/);
}

long __fastcall TSpTextSelectionInformation::get_ActiveLength(void)
{
  long ActiveLength;
  OLECHECK(GetDefaultInterface()->get_ActiveLength((long*)&ActiveLength));
  return ActiveLength;
}

void __fastcall TSpTextSelectionInformation::set_SelectionOffset(long SelectionOffset/*[in]*/)
{
  GetDefaultInterface()->set_SelectionOffset(SelectionOffset/*[in]*/);
}

long __fastcall TSpTextSelectionInformation::get_SelectionOffset(void)
{
  long SelectionOffset;
  OLECHECK(GetDefaultInterface()->get_SelectionOffset((long*)&SelectionOffset));
  return SelectionOffset;
}

void __fastcall TSpTextSelectionInformation::set_SelectionLength(long SelectionLength/*[in]*/)
{
  GetDefaultInterface()->set_SelectionLength(SelectionLength/*[in]*/);
}

long __fastcall TSpTextSelectionInformation::get_SelectionLength(void)
{
  long SelectionLength;
  OLECHECK(GetDefaultInterface()->get_SelectionLength((long*)&SelectionLength));
  return SelectionLength;
}

ISpeechPhraseInfoBuilderPtr& TSpPhraseInfoBuilder::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpPhraseInfoBuilder::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpPhraseInfoBuilder::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpPhraseInfoBuilder::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpPhraseInfoBuilder::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpPhraseInfoBuilder::ConnectTo(ISpeechPhraseInfoBuilderPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpPhraseInfoBuilder::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpPhraseInfoBuilder;
  sd.IntfIID = __uuidof(ISpeechPhraseInfoBuilder);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

Speechlib_tlb::ISpeechPhraseInfo* __fastcall TSpPhraseInfoBuilder::RestorePhraseFromMemory(VARIANT* PhraseInMemory/*[in]*/)
{
  Speechlib_tlb::ISpeechPhraseInfo* PhraseInfo = 0;
  OLECHECK(GetDefaultInterface()->RestorePhraseFromMemory(PhraseInMemory, (Speechlib_tlb::ISpeechPhraseInfo**)&PhraseInfo));
  return PhraseInfo;
}

ISpeechAudioFormatPtr& TSpAudioFormat::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpAudioFormat::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpAudioFormat::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpAudioFormat::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpAudioFormat::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpAudioFormat::ConnectTo(ISpeechAudioFormatPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpAudioFormat::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpAudioFormat;
  sd.IntfIID = __uuidof(ISpeechAudioFormat);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

Speechlib_tlb::ISpeechWaveFormatEx* __fastcall TSpAudioFormat::GetWaveFormatEx(void)
{
  Speechlib_tlb::ISpeechWaveFormatEx* SpeechWaveFormatEx = 0;
  OLECHECK(GetDefaultInterface()->GetWaveFormatEx((Speechlib_tlb::ISpeechWaveFormatEx**)&SpeechWaveFormatEx));
  return SpeechWaveFormatEx;
}

void __fastcall TSpAudioFormat::SetWaveFormatEx(Speechlib_tlb::ISpeechWaveFormatEx* SpeechWaveFormatEx/*[in]*/)
{
  GetDefaultInterface()->SetWaveFormatEx(SpeechWaveFormatEx/*[in]*/);
}

Speechlib_tlb::SpeechAudioFormatType __fastcall TSpAudioFormat::get_Type(void)
{
  Speechlib_tlb::SpeechAudioFormatType AudioFormat;
  OLECHECK(GetDefaultInterface()->get_Type((Speechlib_tlb::SpeechAudioFormatType*)&AudioFormat));
  return AudioFormat;
}

void __fastcall TSpAudioFormat::set_Type(Speechlib_tlb::SpeechAudioFormatType AudioFormat/*[in]*/)
{
  GetDefaultInterface()->set_Type(AudioFormat/*[in]*/);
}

BSTR __fastcall TSpAudioFormat::get_Guid(void)
{
  BSTR Guid = 0;
  OLECHECK(GetDefaultInterface()->get_Guid((BSTR*)&Guid));
  return Guid;
}

void __fastcall TSpAudioFormat::set_Guid(BSTR Guid/*[in]*/)
{
  GetDefaultInterface()->set_Guid(Guid/*[in]*/);
}

ISpeechWaveFormatExPtr& TSpWaveFormatEx::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpWaveFormatEx::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpWaveFormatEx::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpWaveFormatEx::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpWaveFormatEx::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpWaveFormatEx::ConnectTo(ISpeechWaveFormatExPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpWaveFormatEx::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpWaveFormatEx;
  sd.IntfIID = __uuidof(ISpeechWaveFormatEx);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

short __fastcall TSpWaveFormatEx::get_FormatTag(void)
{
  short FormatTag;
  OLECHECK(GetDefaultInterface()->get_FormatTag((short*)&FormatTag));
  return FormatTag;
}

void __fastcall TSpWaveFormatEx::set_FormatTag(short FormatTag/*[in]*/)
{
  GetDefaultInterface()->set_FormatTag(FormatTag/*[in]*/);
}

short __fastcall TSpWaveFormatEx::get_Channels(void)
{
  short Channels;
  OLECHECK(GetDefaultInterface()->get_Channels((short*)&Channels));
  return Channels;
}

void __fastcall TSpWaveFormatEx::set_Channels(short Channels/*[in]*/)
{
  GetDefaultInterface()->set_Channels(Channels/*[in]*/);
}

long __fastcall TSpWaveFormatEx::get_SamplesPerSec(void)
{
  long SamplesPerSec;
  OLECHECK(GetDefaultInterface()->get_SamplesPerSec((long*)&SamplesPerSec));
  return SamplesPerSec;
}

void __fastcall TSpWaveFormatEx::set_SamplesPerSec(long SamplesPerSec/*[in]*/)
{
  GetDefaultInterface()->set_SamplesPerSec(SamplesPerSec/*[in]*/);
}

long __fastcall TSpWaveFormatEx::get_AvgBytesPerSec(void)
{
  long AvgBytesPerSec;
  OLECHECK(GetDefaultInterface()->get_AvgBytesPerSec((long*)&AvgBytesPerSec));
  return AvgBytesPerSec;
}

void __fastcall TSpWaveFormatEx::set_AvgBytesPerSec(long AvgBytesPerSec/*[in]*/)
{
  GetDefaultInterface()->set_AvgBytesPerSec(AvgBytesPerSec/*[in]*/);
}

short __fastcall TSpWaveFormatEx::get_BlockAlign(void)
{
  short BlockAlign;
  OLECHECK(GetDefaultInterface()->get_BlockAlign((short*)&BlockAlign));
  return BlockAlign;
}

void __fastcall TSpWaveFormatEx::set_BlockAlign(short BlockAlign/*[in]*/)
{
  GetDefaultInterface()->set_BlockAlign(BlockAlign/*[in]*/);
}

short __fastcall TSpWaveFormatEx::get_BitsPerSample(void)
{
  short BitsPerSample;
  OLECHECK(GetDefaultInterface()->get_BitsPerSample((short*)&BitsPerSample));
  return BitsPerSample;
}

void __fastcall TSpWaveFormatEx::set_BitsPerSample(short BitsPerSample/*[in]*/)
{
  GetDefaultInterface()->set_BitsPerSample(BitsPerSample/*[in]*/);
}

VARIANT __fastcall TSpWaveFormatEx::get_ExtraData(void)
{
  VARIANT ExtraData;
  OLECHECK(GetDefaultInterface()->get_ExtraData((VARIANT*)&ExtraData));
  return ExtraData;
}

void __fastcall TSpWaveFormatEx::set_ExtraData(VARIANT ExtraData/*[in]*/)
{
  GetDefaultInterface()->set_ExtraData(ExtraData/*[in]*/);
}

ISpeechRecoContextPtr& TSpInProcRecoContext::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpInProcRecoContext::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpInProcRecoContext::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpInProcRecoContext::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpInProcRecoContext::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpInProcRecoContext::ConnectTo(ISpeechRecoContextPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpInProcRecoContext::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpInProcRecoContext;
  sd.IntfIID = __uuidof(ISpeechRecoContext);
  sd.EventIID= __uuidof(_ISpeechRecoContextEvents);
  ServerData = &sd;
}

void __fastcall TSpInProcRecoContext::InvokeEvent(int id, Vcl::Oleserver::TVariantArray& params)
{
  switch(id)
  {
    case 1: {
      if (OnStartStream) {
        (OnStartStream)(this, params[0], params[1]);
      }
      break;
      }
    case 2: {
      if (OnEndStream) {
        (OnEndStream)(this, params[0], params[1], params[2]);
      }
      break;
      }
    case 3: {
      if (OnBookmark) {
        (OnBookmark)(this, params[0], params[1], params[2], (Speechlib_tlb::SpeechBookmarkOptions)(int)params[3]);
      }
      break;
      }
    case 4: {
      if (OnSoundStart) {
        (OnSoundStart)(this, params[0], params[1]);
      }
      break;
      }
    case 5: {
      if (OnSoundEnd) {
        (OnSoundEnd)(this, params[0], params[1]);
      }
      break;
      }
    case 6: {
      if (OnPhraseStart) {
        (OnPhraseStart)(this, params[0], params[1]);
      }
      break;
      }
    case 7: {
      if (OnRecognition) {
        (OnRecognition)(this, params[0], params[1], (Speechlib_tlb::SpeechRecognitionType)(int)params[2], (Speechlib_tlb::ISpeechRecoResultPtr)(LPDISPATCH)(params[3].pdispVal));
      }
      break;
      }
    case 8: {
      if (OnHypothesis) {
        (OnHypothesis)(this, params[0], params[1], (Speechlib_tlb::ISpeechRecoResultPtr)(LPDISPATCH)(params[2].pdispVal));
      }
      break;
      }
    case 9: {
      if (OnPropertyNumberChange) {
        (OnPropertyNumberChange)(this, params[0], params[1], params[2].bstrVal, params[3]);
      }
      break;
      }
    case 10: {
      if (OnPropertyStringChange) {
        (OnPropertyStringChange)(this, params[0], params[1], params[2].bstrVal, params[3].bstrVal);
      }
      break;
      }
    case 11: {
      if (OnFalseRecognition) {
        (OnFalseRecognition)(this, params[0], params[1], (Speechlib_tlb::ISpeechRecoResultPtr)(LPDISPATCH)(params[2].pdispVal));
      }
      break;
      }
    case 12: {
      if (OnInterference) {
        (OnInterference)(this, params[0], params[1], (Speechlib_tlb::SpeechInterference)(int)params[2]);
      }
      break;
      }
    case 13: {
      if (OnRequestUI) {
        (OnRequestUI)(this, params[0], params[1], params[2].bstrVal);
      }
      break;
      }
    case 14: {
      if (OnRecognizerStateChange) {
        (OnRecognizerStateChange)(this, params[0], params[1], (Speechlib_tlb::SpeechRecognizerState)(int)params[2]);
      }
      break;
      }
    case 15: {
      if (OnAdaptation) {
        (OnAdaptation)(this, params[0], params[1]);
      }
      break;
      }
    case 16: {
      if (OnRecognitionForOtherContext) {
        (OnRecognitionForOtherContext)(this, params[0], params[1]);
      }
      break;
      }
    case 17: {
      if (OnAudioLevel) {
        (OnAudioLevel)(this, params[0], params[1], params[2]);
      }
      break;
      }
    case 18: {
      if (OnEnginePrivate) {
        (OnEnginePrivate)(this, params[0], params[1], params[2]);
      }
      break;
      }
    default:
      break;
  }
}

void __fastcall TSpInProcRecoContext::Pause(void)
{
  GetDefaultInterface()->Pause();
}

void __fastcall TSpInProcRecoContext::Resume(void)
{
  GetDefaultInterface()->Resume();
}

Speechlib_tlb::ISpeechRecoGrammar* __fastcall TSpInProcRecoContext::CreateGrammar(VARIANT GrammarId/*[in,def,opt]*/)
{
  Speechlib_tlb::ISpeechRecoGrammar* Grammar = 0;
  OLECHECK(GetDefaultInterface()->CreateGrammar(GrammarId, (Speechlib_tlb::ISpeechRecoGrammar**)&Grammar));
  return Grammar;
}

Speechlib_tlb::ISpeechRecoResult* __fastcall TSpInProcRecoContext::CreateResultFromMemory(VARIANT* ResultBlock/*[in]*/)
{
  Speechlib_tlb::ISpeechRecoResult* Result = 0;
  OLECHECK(GetDefaultInterface()->CreateResultFromMemory(ResultBlock, (Speechlib_tlb::ISpeechRecoResult**)&Result));
  return Result;
}

void __fastcall TSpInProcRecoContext::Bookmark(Speechlib_tlb::SpeechBookmarkOptions Options/*[in]*/, 
                                               VARIANT StreamPos/*[in]*/, VARIANT BookmarkId/*[in]*/)
{
  GetDefaultInterface()->Bookmark(Options/*[in]*/, StreamPos/*[in]*/, BookmarkId/*[in]*/);
}

void __fastcall TSpInProcRecoContext::SetAdaptationData(BSTR AdaptationString/*[in]*/)
{
  GetDefaultInterface()->SetAdaptationData(AdaptationString/*[in]*/);
}

Speechlib_tlb::ISpeechRecognizerPtr __fastcall TSpInProcRecoContext::get_Recognizer(void)
{
  Speechlib_tlb::ISpeechRecognizerPtr Recognizer;
  OLECHECK(GetDefaultInterface()->get_Recognizer(&Recognizer));
  return Recognizer;
}

Speechlib_tlb::SpeechInterference __fastcall TSpInProcRecoContext::get_AudioInputInterferenceStatus(void)
{
  Speechlib_tlb::SpeechInterference Interference;
  OLECHECK(GetDefaultInterface()->get_AudioInputInterferenceStatus((Speechlib_tlb::SpeechInterference*)&Interference));
  return Interference;
}

BSTR __fastcall TSpInProcRecoContext::get_RequestedUIType(void)
{
  BSTR UIType = 0;
  OLECHECK(GetDefaultInterface()->get_RequestedUIType((BSTR*)&UIType));
  return UIType;
}

void __fastcall TSpInProcRecoContext::_set_Voice(Speechlib_tlb::ISpeechVoice* Voice/*[in]*/)
{
  GetDefaultInterface()->_set_Voice(Voice/*[in]*/);
}

Speechlib_tlb::ISpeechVoicePtr __fastcall TSpInProcRecoContext::get_Voice(void)
{
  Speechlib_tlb::ISpeechVoicePtr Voice;
  OLECHECK(GetDefaultInterface()->get_Voice(&Voice));
  return Voice;
}

void __fastcall TSpInProcRecoContext::set_AllowVoiceFormatMatchingOnNextSet(VARIANT_BOOL pAllow/*[in]*/)
{
  GetDefaultInterface()->set_AllowVoiceFormatMatchingOnNextSet(pAllow/*[in]*/);
}

VARIANT_BOOL __fastcall TSpInProcRecoContext::get_AllowVoiceFormatMatchingOnNextSet(void)
{
  VARIANT_BOOL pAllow;
  OLECHECK(GetDefaultInterface()->get_AllowVoiceFormatMatchingOnNextSet((VARIANT_BOOL*)&pAllow));
  return pAllow;
}

void __fastcall TSpInProcRecoContext::set_VoicePurgeEvent(Speechlib_tlb::SpeechRecoEvents EventInterest/*[in]*/)
{
  GetDefaultInterface()->set_VoicePurgeEvent(EventInterest/*[in]*/);
}

Speechlib_tlb::SpeechRecoEvents __fastcall TSpInProcRecoContext::get_VoicePurgeEvent(void)
{
  Speechlib_tlb::SpeechRecoEvents EventInterest;
  OLECHECK(GetDefaultInterface()->get_VoicePurgeEvent((Speechlib_tlb::SpeechRecoEvents*)&EventInterest));
  return EventInterest;
}

void __fastcall TSpInProcRecoContext::set_EventInterests(Speechlib_tlb::SpeechRecoEvents EventInterest/*[in]*/)
{
  GetDefaultInterface()->set_EventInterests(EventInterest/*[in]*/);
}

Speechlib_tlb::SpeechRecoEvents __fastcall TSpInProcRecoContext::get_EventInterests(void)
{
  Speechlib_tlb::SpeechRecoEvents EventInterest;
  OLECHECK(GetDefaultInterface()->get_EventInterests((Speechlib_tlb::SpeechRecoEvents*)&EventInterest));
  return EventInterest;
}

void __fastcall TSpInProcRecoContext::set_CmdMaxAlternates(long MaxAlternates/*[in]*/)
{
  GetDefaultInterface()->set_CmdMaxAlternates(MaxAlternates/*[in]*/);
}

long __fastcall TSpInProcRecoContext::get_CmdMaxAlternates(void)
{
  long MaxAlternates;
  OLECHECK(GetDefaultInterface()->get_CmdMaxAlternates((long*)&MaxAlternates));
  return MaxAlternates;
}

void __fastcall TSpInProcRecoContext::set_State(Speechlib_tlb::SpeechRecoContextState State/*[in]*/)
{
  GetDefaultInterface()->set_State(State/*[in]*/);
}

Speechlib_tlb::SpeechRecoContextState __fastcall TSpInProcRecoContext::get_State(void)
{
  Speechlib_tlb::SpeechRecoContextState State;
  OLECHECK(GetDefaultInterface()->get_State((Speechlib_tlb::SpeechRecoContextState*)&State));
  return State;
}

void __fastcall TSpInProcRecoContext::set_RetainedAudio(Speechlib_tlb::SpeechRetainedAudioOptions Option/*[in]*/)
{
  GetDefaultInterface()->set_RetainedAudio(Option/*[in]*/);
}

Speechlib_tlb::SpeechRetainedAudioOptions __fastcall TSpInProcRecoContext::get_RetainedAudio(void)
{
  Speechlib_tlb::SpeechRetainedAudioOptions Option;
  OLECHECK(GetDefaultInterface()->get_RetainedAudio((Speechlib_tlb::SpeechRetainedAudioOptions*)&Option));
  return Option;
}

void __fastcall TSpInProcRecoContext::_set_RetainedAudioFormat(Speechlib_tlb::ISpeechAudioFormat* Format/*[in]*/)
{
  GetDefaultInterface()->_set_RetainedAudioFormat(Format/*[in]*/);
}

Speechlib_tlb::ISpeechAudioFormatPtr __fastcall TSpInProcRecoContext::get_RetainedAudioFormat(void)
{
  Speechlib_tlb::ISpeechAudioFormatPtr Format;
  OLECHECK(GetDefaultInterface()->get_RetainedAudioFormat(&Format));
  return Format;
}

ISpeechCustomStreamPtr& TSpCustomStream::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpCustomStream::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpCustomStream::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpCustomStream::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpCustomStream::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpCustomStream::ConnectTo(ISpeechCustomStreamPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpCustomStream::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpCustomStream;
  sd.IntfIID = __uuidof(ISpeechCustomStream);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

long __fastcall TSpCustomStream::Read(VARIANT* Buffer/*[out]*/, long NumberOfBytes/*[in]*/)
{
  long BytesRead;
  OLECHECK(GetDefaultInterface()->Read(Buffer, NumberOfBytes, (long*)&BytesRead));
  return BytesRead;
}

long __fastcall TSpCustomStream::Write(VARIANT Buffer/*[in]*/)
{
  long BytesWritten;
  OLECHECK(GetDefaultInterface()->Write(Buffer, (long*)&BytesWritten));
  return BytesWritten;
}

VARIANT __fastcall TSpCustomStream::Seek(VARIANT Position/*[in]*/, 
                                         Speechlib_tlb::SpeechStreamSeekPositionType Origin/*[in,def,opt]*/)
{
  VARIANT NewPosition;
  OLECHECK(GetDefaultInterface()->Seek(Position, Origin, (VARIANT*)&NewPosition));
  return NewPosition;
}

Speechlib_tlb::ISpeechAudioFormatPtr __fastcall TSpCustomStream::get_Format(void)
{
  Speechlib_tlb::ISpeechAudioFormatPtr AudioFormat;
  OLECHECK(GetDefaultInterface()->get_Format(&AudioFormat));
  return AudioFormat;
}

void __fastcall TSpCustomStream::_set_Format(Speechlib_tlb::ISpeechAudioFormat* AudioFormat/*[in]*/)
{
  GetDefaultInterface()->_set_Format(AudioFormat/*[in]*/);
}

LPUNKNOWN __fastcall TSpCustomStream::get_BaseStream(void)
{
  LPUNKNOWN ppUnkStream;
  OLECHECK(GetDefaultInterface()->get_BaseStream((LPUNKNOWN*)&ppUnkStream));
  return ppUnkStream;
}

void __fastcall TSpCustomStream::_set_BaseStream(LPUNKNOWN ppUnkStream/*[in]*/)
{
  GetDefaultInterface()->_set_BaseStream(ppUnkStream/*[in]*/);
}

ISpeechFileStreamPtr& TSpFileStream::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpFileStream::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpFileStream::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpFileStream::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpFileStream::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpFileStream::ConnectTo(ISpeechFileStreamPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpFileStream::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpFileStream;
  sd.IntfIID = __uuidof(ISpeechFileStream);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

long __fastcall TSpFileStream::Read(VARIANT* Buffer/*[out]*/, long NumberOfBytes/*[in]*/)
{
  long BytesRead;
  OLECHECK(GetDefaultInterface()->Read(Buffer, NumberOfBytes, (long*)&BytesRead));
  return BytesRead;
}

long __fastcall TSpFileStream::Write(VARIANT Buffer/*[in]*/)
{
  long BytesWritten;
  OLECHECK(GetDefaultInterface()->Write(Buffer, (long*)&BytesWritten));
  return BytesWritten;
}

VARIANT __fastcall TSpFileStream::Seek(VARIANT Position/*[in]*/, 
                                       Speechlib_tlb::SpeechStreamSeekPositionType Origin/*[in,def,opt]*/)
{
  VARIANT NewPosition;
  OLECHECK(GetDefaultInterface()->Seek(Position, Origin, (VARIANT*)&NewPosition));
  return NewPosition;
}

void __fastcall TSpFileStream::Open(BSTR FileName/*[in]*/, 
                                    Speechlib_tlb::SpeechStreamFileMode FileMode/*[in,def,opt]*/, 
                                    VARIANT_BOOL DoEvents/*[in,def,opt]*/)
{
  GetDefaultInterface()->Open(FileName/*[in]*/, FileMode/*[in,def,opt]*/, DoEvents/*[in,def,opt]*/);
}

void __fastcall TSpFileStream::Close(void)
{
  GetDefaultInterface()->Close();
}

Speechlib_tlb::ISpeechAudioFormatPtr __fastcall TSpFileStream::get_Format(void)
{
  Speechlib_tlb::ISpeechAudioFormatPtr AudioFormat;
  OLECHECK(GetDefaultInterface()->get_Format(&AudioFormat));
  return AudioFormat;
}

void __fastcall TSpFileStream::_set_Format(Speechlib_tlb::ISpeechAudioFormat* AudioFormat/*[in]*/)
{
  GetDefaultInterface()->_set_Format(AudioFormat/*[in]*/);
}

ISpeechMemoryStreamPtr& TSpMemoryStream::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TSpMemoryStream::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TSpMemoryStream::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TSpMemoryStream::Disconnect()
{
  if (m_DefaultIntf) {

    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TSpMemoryStream::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TSpMemoryStream::ConnectTo(ISpeechMemoryStreamPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TSpMemoryStream::InitServerData()
{
  static Vcl::Oleserver::TServerData sd;
  sd.ClassID = CLSID_SpMemoryStream;
  sd.IntfIID = __uuidof(ISpeechMemoryStream);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

long __fastcall TSpMemoryStream::Read(VARIANT* Buffer/*[out]*/, long NumberOfBytes/*[in]*/)
{
  long BytesRead;
  OLECHECK(GetDefaultInterface()->Read(Buffer, NumberOfBytes, (long*)&BytesRead));
  return BytesRead;
}

long __fastcall TSpMemoryStream::Write(VARIANT Buffer/*[in]*/)
{
  long BytesWritten;
  OLECHECK(GetDefaultInterface()->Write(Buffer, (long*)&BytesWritten));
  return BytesWritten;
}

VARIANT __fastcall TSpMemoryStream::Seek(VARIANT Position/*[in]*/, 
                                         Speechlib_tlb::SpeechStreamSeekPositionType Origin/*[in,def,opt]*/)
{
  VARIANT NewPosition;
  OLECHECK(GetDefaultInterface()->Seek(Position, Origin, (VARIANT*)&NewPosition));
  return NewPosition;
}

void __fastcall TSpMemoryStream::SetData(VARIANT Data/*[in]*/)
{
  GetDefaultInterface()->SetData(Data/*[in]*/);
}

VARIANT __fastcall TSpMemoryStream::GetData(void)
{
  VARIANT pData;
  OLECHECK(GetDefaultInterface()->GetData((VARIANT*)&pData));
  return pData;
}

Speechlib_tlb::ISpeechAudioFormatPtr __fastcall TSpMemoryStream::get_Format(void)
{
  Speechlib_tlb::ISpeechAudioFormatPtr AudioFormat;
  OLECHECK(GetDefaultInterface()->get_Format(&AudioFormat));
  return AudioFormat;
}

void __fastcall TSpMemoryStream::_set_Format(Speechlib_tlb::ISpeechAudioFormat* AudioFormat/*[in]*/)
{
  GetDefaultInterface()->_set_Format(AudioFormat/*[in]*/);
}


};     // namespace Speechlib_tlb


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Speechlib_ocx
{

void __fastcall PACKAGE Register()
{
  // [28]
  System::Classes::TComponentClass cls_svr[] = {
                              __classid(Speechlib_tlb::TSpNotifyTranslator), 
                              __classid(Speechlib_tlb::TSpObjectTokenCategory), 
                              __classid(Speechlib_tlb::TSpObjectToken), 
                              __classid(Speechlib_tlb::TSpResourceManager), 
                              __classid(Speechlib_tlb::TSpStreamFormatConverter), 
                              __classid(Speechlib_tlb::TSpMMAudioEnum), 
                              __classid(Speechlib_tlb::TSpMMAudioIn), 
                              __classid(Speechlib_tlb::TSpMMAudioOut), 
                              __classid(Speechlib_tlb::TSpStream), 
                              __classid(Speechlib_tlb::TSpVoice), 
                              __classid(Speechlib_tlb::TSpSharedRecoContext), 
                              __classid(Speechlib_tlb::TSpInprocRecognizer), 
                              __classid(Speechlib_tlb::TSpSharedRecognizer), 
                              __classid(Speechlib_tlb::TSpLexicon), 
                              __classid(Speechlib_tlb::TSpUnCompressedLexicon), 
                              __classid(Speechlib_tlb::TSpCompressedLexicon), 
                              __classid(Speechlib_tlb::TSpShortcut), 
                              __classid(Speechlib_tlb::TSpPhoneConverter), 
                              __classid(Speechlib_tlb::TSpPhoneticAlphabetConverter), 
                              __classid(Speechlib_tlb::TSpNullPhoneConverter), 
                              __classid(Speechlib_tlb::TSpTextSelectionInformation), 
                              __classid(Speechlib_tlb::TSpPhraseInfoBuilder), 
                              __classid(Speechlib_tlb::TSpAudioFormat), 
                              __classid(Speechlib_tlb::TSpWaveFormatEx), 
                              __classid(Speechlib_tlb::TSpInProcRecoContext), 
                              __classid(Speechlib_tlb::TSpCustomStream), 
                              __classid(Speechlib_tlb::TSpFileStream), 
                              __classid(Speechlib_tlb::TSpMemoryStream)
                           };
  System::Classes::RegisterComponents("SAPI", cls_svr,
                     sizeof(cls_svr)/sizeof(cls_svr[0])-1);
}

};     // namespace Speechlib_ocx
