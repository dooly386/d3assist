object DebugWindowForm: TDebugWindowForm
  Left = 0
  Top = 0
  Caption = 'Debug Window'
  ClientHeight = 476
  ClientWidth = 590
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
    Width = 590
    Height = 448
    Align = alClient
    ScrollBars = ssVertical
    TabOrder = 0
    WordWrap = False
    ExplicitWidth = 388
  end
  object Panel1: TPanel
    Left = 0
    Top = 448
    Width = 590
    Height = 28
    Align = alBottom
    TabOrder = 1
    ExplicitWidth = 388
    object cbKbdEvent: TCheckBox
      Left = 8
      Top = 6
      Width = 97
      Height = 17
      Caption = 'Keyboard'
      Checked = True
      State = cbChecked
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
