object MediaPlayerForm: TMediaPlayerForm
  Left = 0
  Top = 0
  AlphaBlendValue = 200
  Caption = 'MediaPlayerForm'
  ClientHeight = 598
  ClientWidth = 827
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object MediaPlayer1: TMediaPlayer
    Left = 0
    Top = 568
    Width = 820
    Height = 30
    Align = alBottom
    DoubleBuffered = True
    Display = Panel1
    FileName = 'D:\ffmpeg\out.wmv'
    Shareable = True
    ParentDoubleBuffered = False
    TabOrder = 0
    ExplicitLeft = 56
    ExplicitTop = 319
    ExplicitWidth = 253
  end
  object Panel1: TPanel
    Left = 0
    Top = 50
    Width = 827
    Height = 518
    Align = alClient
    Caption = 'Panel1'
    TabOrder = 1
    ExplicitLeft = 16
    ExplicitTop = 64
    ExplicitWidth = 345
    ExplicitHeight = 185
  end
  object Button1: TButton
    Left = 0
    Top = 0
    Width = 827
    Height = 25
    Align = alTop
    Caption = 'Button1'
    TabOrder = 2
    OnClick = Button1Click
    ExplicitTop = 8
  end
  object Button2: TButton
    Left = 0
    Top = 25
    Width = 827
    Height = 25
    Align = alTop
    Caption = 'Button2'
    TabOrder = 3
    OnClick = Button2Click
    ExplicitLeft = 8
    ExplicitTop = 40
    ExplicitWidth = 75
  end
end
