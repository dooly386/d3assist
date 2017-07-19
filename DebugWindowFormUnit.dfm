object DebugWindowForm: TDebugWindowForm
  Left = 0
  Top = 0
  Caption = 'Debug Window'
  ClientHeight = 476
  ClientWidth = 388
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 388
    Height = 448
    Align = alClient
    ScrollBars = ssVertical
    TabOrder = 0
    WordWrap = False
    ExplicitHeight = 345
  end
  object Panel1: TPanel
    Left = 0
    Top = 448
    Width = 388
    Height = 28
    Align = alBottom
    TabOrder = 1
    object cbKbdEvent: TCheckBox
      Left = 8
      Top = 6
      Width = 97
      Height = 17
      Caption = 'Keyboard'
      TabOrder = 0
    end
    object cbMouseEvent: TCheckBox
      Left = 144
      Top = 6
      Width = 97
      Height = 17
      Caption = 'Mouse'
      TabOrder = 1
    end
  end
end
