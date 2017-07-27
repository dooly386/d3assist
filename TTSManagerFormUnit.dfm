object TTSManagerForm: TTTSManagerForm
  Left = 0
  Top = 0
  Caption = 'Text to Speech Manager'
  ClientHeight = 489
  ClientWidth = 421
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  DesignSize = (
    421
    489)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 324
    Height = 13
    Caption = 'Your TTS Test'
  end
  object Label2: TLabel
    Left = 8
    Top = 64
    Width = 90
    Height = 13
    Caption = 'Start TTS Key'
  end
  object edTTSTest: TEdit
    Left = 8
    Top = 24
    Width = 324
    Height = 21
    TabStop = False
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 0
    Text = 'Hello.<silence msec="1000"/>Welcome to TTS'
  end
  object btnTTSTest: TButton
    Left = 338
    Top = 22
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Play'
    TabOrder = 1
    TabStop = False
    OnClick = btnTTSTestClick
  end
  object moTTS: TMemo
    Left = 8
    Top = 88
    Width = 322
    Height = 282
    TabStop = False
    Anchors = [akLeft, akTop, akRight, akBottom]
    Lines.Strings = (
      '<volume level="50"/>'
      '1<silence msec="1000"/>'
      '2<silence msec="1000"/>'
      '3<silence msec="1000"/>'
      '<volume level="70"/>'
      '4<silence msec="1000"/>'
      '5<silence msec="1000"/>'
      '<volume level="90"/>'
      '6<silence msec="1000"/>'
      '7<silence msec="1000"/>'
      '<volume level="100"/>'
      '8<silence msec="1000"/>'
      '9<silence msec="1000"/>'
      '10<silence msec="1000"/>')
    ScrollBars = ssVertical
    TabOrder = 2
    WordWrap = False
  end
  object btnPlayMemo: TButton
    Left = 8
    Top = 437
    Width = 75
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = 'Play'
    TabOrder = 3
    TabStop = False
    OnClick = btnPlayMemoClick
  end
  object edKey: TEdit
    Tag = 1
    Left = 104
    Top = 61
    Width = 97
    Height = 21
    TabStop = False
    Alignment = taCenter
    TabOrder = 4
    Text = '4'
    OnKeyDown = edKeyKeyDown
    OnKeyPress = edKeyKeyPress
    OnMouseDown = edKeyMouseDown
  end
  object cbEnable: TCheckBox
    Left = 232
    Top = 65
    Width = 181
    Height = 17
    TabStop = False
    Caption = 'Enable TTS'
    TabOrder = 5
  end
  object btnTTSTagManual: TButton
    Left = 170
    Top = 437
    Width = 113
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = 'TTS Tags Manual'
    TabOrder = 6
    TabStop = False
    OnClick = btnTTSTagManualClick
  end
  object btnSaveToFile: TButton
    Left = 338
    Top = 86
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Save'
    TabOrder = 7
    OnClick = btnSaveToFileClick
  end
  object btnLoadFromFile: TButton
    Left = 338
    Top = 117
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Load'
    TabOrder = 8
    OnClick = btnLoadFromFileClick
  end
  object stBar: TEdit
    Left = 0
    Top = 468
    Width = 421
    Height = 21
    Align = alBottom
    ReadOnly = True
    TabOrder = 9
  end
  object btnStop: TButton
    Left = 89
    Top = 437
    Width = 75
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = 'Stop'
    TabOrder = 10
    TabStop = False
    OnClick = btnStopClick
  end
  object cbRepeat: TCheckBox
    Left = 8
    Top = 377
    Width = 128
    Height = 17
    Anchors = [akLeft, akBottom]
    Caption = 'Repeat time(msec)'
    TabOrder = 11
  end
  object btnHide: TButton
    Left = 337
    Top = 160
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Hide'
    TabOrder = 12
    OnClick = btnHideClick
  end
  object btnClose: TButton
    Left = 338
    Top = 191
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Close'
    TabOrder = 13
    OnClick = btnCloseClick
  end
  object btnSaveToWaveFile: TButton
    Left = 8
    Top = 399
    Width = 128
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = 'Save to wave file'
    TabOrder = 14
    OnClick = btnSaveToWaveFileClick
  end
  object edWaveFileName: TEdit
    Left = 142
    Top = 401
    Width = 190
    Height = 21
    Alignment = taCenter
    Anchors = [akLeft, akBottom]
    TabOrder = 15
  end
  object edRepeatInterval: TEdit
    Left = 142
    Top = 376
    Width = 190
    Height = 21
    Alignment = taCenter
    Anchors = [akLeft, akBottom]
    NumbersOnly = True
    TabOrder = 16
    Text = '12000'
  end
  object OpenDialog: TOpenDialog
    DefaultExt = '.ttsmemo'
    Filter = 'TTS Memo Files|*.ttsmemo|All Files|*.*'
    Options = [ofHideReadOnly, ofFileMustExist, ofEnableSizing]
    Left = 176
    Top = 216
  end
  object SaveDialog: TSaveDialog
    DefaultExt = '.ttsmemo'
    Filter = 'TTS Memo Files|*.ttsmemo|All Files|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 176
    Top = 264
  end
  object RepeatTimer: TTimer
    Enabled = False
    OnTimer = RepeatTimerTimer
    Left = 216
    Top = 272
  end
end
