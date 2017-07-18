object TTSManagerForm: TTTSManagerForm
  Left = 0
  Top = 0
  Caption = 'Text to Speech Manager'
  ClientHeight = 419
  ClientWidth = 364
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
    364
    419)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 67
    Height = 13
    Caption = 'Your TTS Test'
  end
  object Label2: TLabel
    Left = 8
    Top = 64
    Width = 18
    Height = 13
    Caption = 'Key'
  end
  object edTTSTest: TEdit
    Left = 8
    Top = 24
    Width = 267
    Height = 21
    TabStop = False
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 0
    Text = #50504#45397#54616#49464#50836'.<silence msec="3000"/>'#48152#44049#49845#45768#45796'.'
    ExplicitWidth = 261
  end
  object btnTTSTest: TButton
    Left = 281
    Top = 22
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Play'
    TabOrder = 1
    TabStop = False
    OnClick = btnTTSTestClick
    ExplicitLeft = 275
  end
  object moTTS: TMemo
    Left = 8
    Top = 88
    Width = 351
    Height = 292
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
    ExplicitWidth = 435
    ExplicitHeight = 499
  end
  object btnPlayMemo: TButton
    Left = 8
    Top = 386
    Width = 75
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = 'Play'
    TabOrder = 3
    TabStop = False
    OnClick = btnPlayMemoClick
    ExplicitTop = 593
  end
  object edKey: TEdit
    Tag = 1
    Left = 40
    Top = 61
    Width = 121
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
    Left = 176
    Top = 65
    Width = 97
    Height = 17
    TabStop = False
    Caption = 'Enable TTS'
    TabOrder = 5
  end
  object btnTTSTagManual: TButton
    Left = 89
    Top = 386
    Width = 168
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = 'TTS Tags Manual'
    TabOrder = 6
    TabStop = False
    OnClick = btnTTSTagManualClick
    ExplicitTop = 593
  end
end
