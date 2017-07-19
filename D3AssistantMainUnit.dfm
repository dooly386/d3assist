object D3AssistantMainForm: TD3AssistantMainForm
  Left = 0
  Top = 0
  Caption = 'D3Assist v1.0.0.1'
  ClientHeight = 470
  ClientWidth = 482
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  Menu = MainMenu
  OldCreateOrder = False
  Position = poScreenCenter
  ShowHint = True
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnMouseWheel = FormMouseWheel
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl: TPageControl
    Left = 0
    Top = 113
    Width = 482
    Height = 338
    ActivePage = KeySettingTabSheet
    Align = alClient
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 1
    OnChange = PageControlChange
    ExplicitWidth = 407
    object KeySettingTabSheet: TTabSheet
      Caption = 'Key/Mouse'
      DoubleBuffered = True
      ParentDoubleBuffered = False
      ExplicitWidth = 399
      object Label4: TLabel
        Left = 105
        Top = 8
        Width = 121
        Height = 13
        Caption = 'Delay and Interval(msec)'
      end
      object Label5: TLabel
        Left = 286
        Top = 8
        Width = 50
        Height = 13
        Caption = 'Pause Key'
      end
      object Label7: TLabel
        Left = 380
        Top = 8
        Width = 51
        Height = 13
        Caption = 'Active Key'
      end
      object Label8: TLabel
        Left = 0
        Top = 297
        Width = 474
        Height = 13
        Align = alBottom
        Caption = 'Press [ESC] key for delete selected field or press backspace'
        ExplicitWidth = 287
      end
      object Label15: TLabel
        Left = 237
        Top = 8
        Width = 35
        Height = 13
        Caption = 'Holding'
      end
      object Label14: TLabel
        Left = 200
        Top = 256
        Width = 112
        Height = 13
        Caption = '<<-- Immediately -->>'
      end
      object edActive1: TEdit
        Tag = 1
        Left = 380
        Top = 24
        Width = 88
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 0
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edPause1: TEdit
        Tag = 1
        Left = 286
        Top = 24
        Width = 88
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 1
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edDelay1: TEdit
        Tag = 2
        Left = 162
        Top = 24
        Width = 66
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        NumbersOnly = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 2
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edKey1: TEdit
        Tag = 1
        Left = 3
        Top = 24
        Width = 98
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentCtl3D = False
        ParentDoubleBuffered = False
        ParentFont = False
        TabOrder = 3
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edKey2: TEdit
        Tag = 1
        Left = 3
        Top = 51
        Width = 98
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentCtl3D = False
        ParentDoubleBuffered = False
        ParentFont = False
        TabOrder = 4
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edDelay2: TEdit
        Tag = 2
        Left = 162
        Top = 51
        Width = 66
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        NumbersOnly = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 5
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edPause2: TEdit
        Tag = 1
        Left = 286
        Top = 51
        Width = 88
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 6
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edActive2: TEdit
        Tag = 1
        Left = 380
        Top = 51
        Width = 88
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 7
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edActive3: TEdit
        Tag = 1
        Left = 380
        Top = 78
        Width = 88
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 8
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edPause3: TEdit
        Tag = 1
        Left = 286
        Top = 78
        Width = 88
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 9
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edDelay3: TEdit
        Tag = 2
        Left = 162
        Top = 78
        Width = 66
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        NumbersOnly = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 10
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edKey3: TEdit
        Tag = 1
        Left = 3
        Top = 78
        Width = 98
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentCtl3D = False
        ParentDoubleBuffered = False
        ParentFont = False
        TabOrder = 11
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edKey4: TEdit
        Tag = 1
        Left = 3
        Top = 105
        Width = 98
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentCtl3D = False
        ParentDoubleBuffered = False
        ParentFont = False
        TabOrder = 12
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edKey5: TEdit
        Tag = 1
        Left = 3
        Top = 132
        Width = 98
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentCtl3D = False
        ParentDoubleBuffered = False
        ParentFont = False
        TabOrder = 13
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edKey6: TEdit
        Tag = 1
        Left = 3
        Top = 159
        Width = 98
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentCtl3D = False
        ParentDoubleBuffered = False
        ParentFont = False
        TabOrder = 14
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edKey7: TEdit
        Tag = 1
        Left = 3
        Top = 186
        Width = 98
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentCtl3D = False
        ParentDoubleBuffered = False
        ParentFont = False
        TabOrder = 15
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edKey8: TEdit
        Tag = 1
        Left = 3
        Top = 213
        Width = 98
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentCtl3D = False
        ParentDoubleBuffered = False
        ParentFont = False
        TabOrder = 16
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edDelay8: TEdit
        Tag = 2
        Left = 162
        Top = 213
        Width = 66
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        NumbersOnly = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 17
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edDelay7: TEdit
        Tag = 2
        Left = 162
        Top = 186
        Width = 66
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        NumbersOnly = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 18
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edDelay6: TEdit
        Tag = 2
        Left = 162
        Top = 159
        Width = 66
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        NumbersOnly = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 19
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edDelay5: TEdit
        Tag = 2
        Left = 162
        Top = 132
        Width = 66
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        NumbersOnly = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 20
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edDelay4: TEdit
        Tag = 2
        Left = 162
        Top = 105
        Width = 66
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        NumbersOnly = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 21
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edPause4: TEdit
        Tag = 1
        Left = 286
        Top = 105
        Width = 88
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 22
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edPause5: TEdit
        Tag = 1
        Left = 286
        Top = 132
        Width = 88
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 23
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edPause6: TEdit
        Tag = 1
        Left = 286
        Top = 159
        Width = 88
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 24
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edPause7: TEdit
        Tag = 1
        Left = 286
        Top = 186
        Width = 88
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 25
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edPause8: TEdit
        Tag = 1
        Left = 286
        Top = 213
        Width = 88
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 26
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edActive8: TEdit
        Tag = 1
        Left = 380
        Top = 213
        Width = 88
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 27
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edActive7: TEdit
        Tag = 1
        Left = 380
        Top = 186
        Width = 88
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 28
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edActive6: TEdit
        Tag = 1
        Left = 380
        Top = 159
        Width = 88
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 29
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edActive5: TEdit
        Tag = 1
        Left = 380
        Top = 132
        Width = 88
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 30
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edActive4: TEdit
        Tag = 1
        Left = 380
        Top = 105
        Width = 88
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 31
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object cbToggle1: TCheckBox
        Left = 243
        Top = 27
        Width = 17
        Height = 17
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 32
        OnClick = cbToggle1Click
      end
      object cbToggle2: TCheckBox
        Left = 243
        Top = 53
        Width = 17
        Height = 17
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 33
        OnClick = cbToggle1Click
      end
      object cbToggle3: TCheckBox
        Left = 243
        Top = 80
        Width = 17
        Height = 17
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 34
        OnClick = cbToggle1Click
      end
      object cbToggle4: TCheckBox
        Left = 243
        Top = 107
        Width = 17
        Height = 17
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 35
        OnClick = cbToggle1Click
      end
      object cbToggle5: TCheckBox
        Left = 243
        Top = 134
        Width = 17
        Height = 17
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 36
        OnClick = cbToggle1Click
      end
      object cbToggle6: TCheckBox
        Left = 243
        Top = 161
        Width = 17
        Height = 17
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 37
        OnClick = cbToggle1Click
      end
      object cbToggle7: TCheckBox
        Left = 243
        Top = 188
        Width = 17
        Height = 17
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 38
        OnClick = cbToggle1Click
      end
      object cbToggle8: TCheckBox
        Left = 243
        Top = 215
        Width = 17
        Height = 17
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 39
        OnClick = cbToggle1Click
      end
      object edImmediatelyKey: TEdit
        Tag = 1
        Left = 3
        Top = 250
        Width = 96
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentCtl3D = False
        ParentDoubleBuffered = False
        ParentFont = False
        TabOrder = 40
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edImmediatelyDelay: TEdit
        Tag = 2
        Left = 105
        Top = 250
        Width = 66
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        NumbersOnly = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 41
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edImmediatelyActive: TEdit
        Tag = 1
        Left = 380
        Top = 250
        Width = 88
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 42
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edInit1: TEdit
        Tag = 2
        Left = 106
        Top = 24
        Width = 50
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        NumbersOnly = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 43
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edInit2: TEdit
        Tag = 2
        Left = 106
        Top = 51
        Width = 50
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        NumbersOnly = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 44
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edInit3: TEdit
        Tag = 2
        Left = 106
        Top = 78
        Width = 50
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        NumbersOnly = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 45
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edInit4: TEdit
        Tag = 2
        Left = 106
        Top = 105
        Width = 50
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        NumbersOnly = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 46
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edInit5: TEdit
        Tag = 2
        Left = 106
        Top = 132
        Width = 50
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        NumbersOnly = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 47
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edInit6: TEdit
        Tag = 2
        Left = 106
        Top = 159
        Width = 50
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        NumbersOnly = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 48
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edInit7: TEdit
        Tag = 2
        Left = 106
        Top = 186
        Width = 50
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        NumbersOnly = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 49
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edInit8: TEdit
        Tag = 2
        Left = 106
        Top = 213
        Width = 50
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        NumbersOnly = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 50
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object cbMultiKey: TCheckBox
        Left = 28
        Top = 4
        Width = 49
        Height = 17
        Caption = 'Key+'
        TabOrder = 51
      end
    end
    object EnvironmentTabSheet: TTabSheet
      Caption = 'Stop Keys'
      ImageIndex = 1
      ExplicitWidth = 399
      object Label9: TLabel
        Left = 3
        Top = 0
        Width = 27
        Height = 13
        Caption = 'Name'
      end
      object Label10: TLabel
        Left = 114
        Top = 0
        Width = 18
        Height = 13
        Caption = 'Key'
      end
      object Label11: TLabel
        Left = 206
        Top = 0
        Width = 27
        Height = 13
        Caption = 'Name'
      end
      object Label12: TLabel
        Left = 317
        Top = 0
        Width = 18
        Height = 13
        Caption = 'Key'
      end
      object Label13: TLabel
        Left = 3
        Top = 232
        Width = 248
        Height = 26
        Caption = 'name usage'#13#10'name = stop, name+ = pause, name- = pause hold'
      end
      object edStopName1: TEdit
        Tag = 1
        Left = 3
        Top = 16
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 0
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
      end
      object edStopKey1: TEdit
        Tag = 1
        Left = 114
        Top = 16
        Width = 81
        Height = 21
        TabStop = False
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edStopName2: TEdit
        Tag = 1
        Left = 3
        Top = 43
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 2
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
      end
      object edStopKey2: TEdit
        Tag = 1
        Left = 114
        Top = 43
        Width = 81
        Height = 21
        TabStop = False
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edStopName3: TEdit
        Tag = 1
        Left = 3
        Top = 70
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 4
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
      end
      object edStopKey3: TEdit
        Tag = 1
        Left = 114
        Top = 70
        Width = 81
        Height = 21
        TabStop = False
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edStopName4: TEdit
        Tag = 1
        Left = 3
        Top = 97
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 6
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
      end
      object edStopKey4: TEdit
        Tag = 1
        Left = 114
        Top = 97
        Width = 81
        Height = 21
        TabStop = False
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 7
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edStopName5: TEdit
        Tag = 1
        Left = 3
        Top = 124
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 8
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
      end
      object edStopKey5: TEdit
        Tag = 1
        Left = 114
        Top = 124
        Width = 81
        Height = 21
        TabStop = False
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 9
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edStopName6: TEdit
        Tag = 1
        Left = 3
        Top = 151
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 10
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
      end
      object edStopKey6: TEdit
        Tag = 1
        Left = 114
        Top = 151
        Width = 81
        Height = 21
        TabStop = False
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 11
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edStopName7: TEdit
        Tag = 1
        Left = 3
        Top = 178
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 12
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
      end
      object edStopKey7: TEdit
        Tag = 1
        Left = 114
        Top = 178
        Width = 81
        Height = 21
        TabStop = False
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 13
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edStopName8: TEdit
        Tag = 1
        Left = 3
        Top = 205
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 14
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
      end
      object edStopKey8: TEdit
        Tag = 1
        Left = 114
        Top = 205
        Width = 81
        Height = 21
        TabStop = False
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 15
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edStopKey9: TEdit
        Tag = 1
        Left = 317
        Top = 16
        Width = 81
        Height = 21
        TabStop = False
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 16
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edStopName9: TEdit
        Tag = 1
        Left = 206
        Top = 16
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 17
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
      end
      object edStopName10: TEdit
        Tag = 1
        Left = 206
        Top = 43
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 18
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
      end
      object edStopKey10: TEdit
        Tag = 1
        Left = 317
        Top = 43
        Width = 81
        Height = 21
        TabStop = False
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 19
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edStopKey11: TEdit
        Tag = 1
        Left = 317
        Top = 70
        Width = 81
        Height = 21
        TabStop = False
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 20
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edStopName11: TEdit
        Tag = 1
        Left = 206
        Top = 70
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 21
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
      end
      object edStopName12: TEdit
        Tag = 1
        Left = 206
        Top = 97
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 22
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
      end
      object edStopKey12: TEdit
        Tag = 1
        Left = 317
        Top = 97
        Width = 81
        Height = 21
        TabStop = False
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 23
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edStopKey13: TEdit
        Tag = 1
        Left = 317
        Top = 124
        Width = 81
        Height = 21
        TabStop = False
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 24
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edStopName13: TEdit
        Tag = 1
        Left = 206
        Top = 124
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 25
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
      end
      object edStopName14: TEdit
        Tag = 1
        Left = 206
        Top = 151
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 26
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
      end
      object edStopKey14: TEdit
        Tag = 1
        Left = 317
        Top = 151
        Width = 81
        Height = 21
        TabStop = False
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 27
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edStopKey15: TEdit
        Tag = 1
        Left = 317
        Top = 178
        Width = 81
        Height = 21
        TabStop = False
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 28
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edStopName15: TEdit
        Tag = 1
        Left = 206
        Top = 178
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 29
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
      end
      object edStopName16: TEdit
        Tag = 1
        Left = 206
        Top = 205
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 30
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
      end
      object edStopKey16: TEdit
        Tag = 1
        Left = 317
        Top = 205
        Width = 81
        Height = 21
        TabStop = False
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 31
        OnChange = edStopName1Change
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
    end
    object TabSheet1: TTabSheet
      Caption = 'Environment'
      ImageIndex = 2
      ExplicitWidth = 399
      object Label6: TLabel
        Left = 19
        Top = 72
        Width = 56
        Height = 13
        Caption = 'Alpha Blend'
      end
      object cbStayOnTop: TCheckBox
        Left = 3
        Top = 12
        Width = 89
        Height = 17
        TabStop = False
        Caption = 'Stay on top'
        TabOrder = 0
        OnClick = cbStayOnTopClick
      end
      object cbOnlyD3: TCheckBox
        Left = 3
        Top = 44
        Width = 88
        Height = 17
        TabStop = False
        Caption = 'Only Window'
        TabOrder = 1
      end
      object edOnlyWindow: TEdit
        Left = 97
        Top = 42
        Width = 97
        Height = 21
        TabStop = False
        TabOrder = 2
        Text = #46356#50500#48660#47196' III'
      end
      object edAlphaValue: TEdit
        Left = 97
        Top = 69
        Width = 97
        Height = 21
        TabStop = False
        Alignment = taCenter
        NumbersOnly = True
        TabOrder = 3
        Text = '200'
      end
      object cbMinimizeWhenStart: TCheckBox
        Left = 3
        Top = 96
        Width = 177
        Height = 17
        Caption = 'Minimize when start'
        TabOrder = 4
      end
    end
    object TabSheetMacro: TTabSheet
      Caption = 'Macro'
      ImageIndex = 3
      ExplicitWidth = 399
      DesignSize = (
        474
        310)
      object Label16: TLabel
        Left = 3
        Top = 192
        Width = 52
        Height = 13
        Caption = 'Play Count'
      end
      object Label17: TLabel
        Left = 3
        Top = 235
        Width = 52
        Height = 13
        Caption = 'Speed (%)'
      end
      object btnStartRecord: TButton
        Left = 3
        Top = 3
        Width = 141
        Height = 25
        Action = actionStartRecord
        TabOrder = 0
      end
      object btnStopRecord: TButton
        Left = 3
        Top = 34
        Width = 141
        Height = 25
        Action = actionStopRecord
        TabOrder = 1
      end
      object btnPlayRecord: TButton
        Left = 3
        Top = 65
        Width = 141
        Height = 25
        Action = actionPlayRecord
        TabOrder = 2
      end
      object btnClearRecord: TButton
        Left = 3
        Top = 96
        Width = 141
        Height = 25
        Action = actionClearRecord
        TabOrder = 3
      end
      object btnSaveRecord: TButton
        Left = 3
        Top = 127
        Width = 141
        Height = 25
        Action = actionSaveRecord
        TabOrder = 4
      end
      object btnLoadRecord: TButton
        Left = 3
        Top = 158
        Width = 141
        Height = 25
        Action = actionLoadRecord
        TabOrder = 5
      end
      object lbRecord: TListBox
        Left = 171
        Top = 8
        Width = 291
        Height = 273
        Anchors = [akLeft, akTop, akRight, akBottom]
        ItemHeight = 13
        TabOrder = 6
        ExplicitWidth = 216
      end
      object edPlayCount: TEdit
        Left = 3
        Top = 208
        Width = 106
        Height = 21
        TabStop = False
        Alignment = taCenter
        NumbersOnly = True
        TabOrder = 7
        Text = '1'
      end
      object edPlaySpeed: TEdit
        Left = 3
        Top = 254
        Width = 106
        Height = 21
        TabStop = False
        Alignment = taCenter
        NumbersOnly = True
        TabOrder = 8
        Text = '100'
      end
      object edMacroFileName: TEdit
        Left = 0
        Top = 289
        Width = 474
        Height = 21
        Align = alBottom
        ReadOnly = True
        TabOrder = 9
        ExplicitWidth = 399
      end
    end
  end
  object stBar: TStatusBar
    Left = 0
    Top = 451
    Width = 482
    Height = 19
    DoubleBuffered = True
    Panels = <>
    ParentDoubleBuffered = False
    SimplePanel = True
    SimpleText = 'Welcome D3Assist'
    ExplicitWidth = 407
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 482
    Height = 113
    Align = alTop
    TabOrder = 2
    ExplicitWidth = 407
    DesignSize = (
      482
      113)
    object lbRecentlyFilesFullPath: TListBox
      Left = 412
      Top = 8
      Width = 145
      Height = 97
      ItemHeight = 13
      TabOrder = 5
      Visible = False
    end
    object GroupBox1: TGroupBox
      Left = 0
      Top = 0
      Width = 169
      Height = 105
      Caption = 'Start/Stop'
      TabOrder = 0
      object Label1: TLabel
        Left = 16
        Top = 43
        Width = 45
        Height = 13
        Caption = 'Start Key'
      end
      object Label2: TLabel
        Left = 16
        Top = 70
        Width = 43
        Height = 13
        Caption = 'Stop Key'
      end
      object edStart: TEdit
        Tag = 1
        Left = 67
        Top = 40
        Width = 81
        Height = 19
        TabStop = False
        Alignment = taCenter
        BevelInner = bvNone
        BevelOuter = bvNone
        Ctl3D = False
        DoubleBuffered = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 0
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object edStop: TEdit
        Tag = 1
        Left = 67
        Top = 67
        Width = 81
        Height = 19
        TabStop = False
        Alignment = taCenter
        Ctl3D = False
        DoubleBuffered = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 1
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
        OnMouseUp = edKey1MouseUp
      end
      object cbDoNotStart: TCheckBox
        Left = 16
        Top = 16
        Width = 97
        Height = 17
        Alignment = taLeftJustify
        Caption = 'Do not start'
        Ctl3D = False
        DoubleBuffered = True
        ParentCtl3D = False
        ParentDoubleBuffered = False
        TabOrder = 2
      end
    end
    object btnSave: TButton
      Left = 175
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Save'
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 1
      TabStop = False
      OnClick = btnSaveClick
    end
    object btnLoad: TButton
      Left = 175
      Top = 39
      Width = 75
      Height = 25
      Caption = 'Load'
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 2
      TabStop = False
      OnClick = btnLoadClick
    end
    object StatusPanel: TPanel
      Left = 175
      Top = 70
      Width = 75
      Height = 23
      BevelOuter = bvNone
      Caption = 'Stop'
      Color = clRed
      DoubleBuffered = True
      ParentBackground = False
      ParentDoubleBuffered = False
      TabOrder = 3
    end
    object lbRecentlyFiles: TListBox
      Left = 261
      Top = 8
      Width = 217
      Height = 97
      Anchors = [akLeft, akTop, akRight]
      Ctl3D = False
      DoubleBuffered = True
      ItemHeight = 13
      ParentCtl3D = False
      ParentDoubleBuffered = False
      PopupMenu = PopupMenu1
      TabOrder = 4
      OnDblClick = lbRecentlyFilesDblClick
      ExplicitWidth = 142
    end
  end
  object SaveDialog: TSaveDialog
    DefaultExt = '.ini'
    Filter = 'Ini Files|*.ini|All Files|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 576
    Top = 8
  end
  object OpenDialog: TOpenDialog
    DefaultExt = '.ini'
    Filter = 'Ini Files|*.ini|All Files|*.*'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 616
    Top = 8
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 100
    OnTimer = Timer1Timer
    Left = 664
    Top = 8
  end
  object Timer2: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 696
    Top = 8
  end
  object Timer3: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 728
    Top = 8
  end
  object Timer4: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 760
    Top = 8
  end
  object Timer5: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 664
    Top = 56
  end
  object Timer6: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 696
    Top = 56
  end
  object Timer7: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 728
    Top = 56
  end
  object Timer8: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 760
    Top = 56
  end
  object MainMenu: TMainMenu
    AutoHotkeys = maManual
    AutoLineReduction = maManual
    Left = 280
    Top = 8
    object F1: TMenuItem
      Caption = 'File'
      object menuNew: TMenuItem
        Caption = 'New'
        OnClick = menuNewClick
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object menuOpen: TMenuItem
        Caption = 'Open'
        OnClick = btnLoadClick
      end
      object menuSave: TMenuItem
        Caption = 'Save'
        OnClick = btnSaveClick
      end
      object menuSaveAs: TMenuItem
        Caption = 'Save As...'
        OnClick = menuSaveAsClick
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object menuClose: TMenuItem
        Caption = 'Close'
      end
    end
    object MenuGroupAddOn: TMenuItem
      Caption = 'Addon'
      object P1: TMenuItem
        Caption = 'Protection'
        object MenuOpenProtectionAreaManager: TMenuItem
          Caption = 'Open Protection Manager'
          OnClick = MenuOpenProtectionAreaManagerClick
        end
        object N5: TMenuItem
          Caption = '-'
        end
        object MenuLoadFromAreaFile: TMenuItem
          Caption = 'Load from Area File'
          OnClick = MenuLoadFromAreaFileClick
        end
      end
      object T1: TMenuItem
        Caption = 'TTS'
        object MenuOpenTTSManager: TMenuItem
          Caption = 'Open TTS Manager Form'
          OnClick = MenuOpenTTSManagerClick
        end
      end
      object Y1: TMenuItem
        Caption = 'YoloMouse'
        object StartYoloMouseMenu: TMenuItem
          Caption = 'Start YoloMouse'
          OnClick = StartYoloMouseMenuClick
        end
        object StopYoloMouseMenu: TMenuItem
          Caption = 'Stop YoloMouse'
          OnClick = StopYoloMouseMenuClick
        end
        object MenuSetYoloMouseTargetProcess: TMenuItem
          Caption = 'Set YoloMouse Target Process Name'
          OnClick = MenuSetYoloMouseTargetProcessClick
        end
        object N4: TMenuItem
          Caption = '-'
        end
        object YoloMouseHomePageMenu: TMenuItem
          Caption = 'YoloMouse HomePage'
          OnClick = YoloMouseHomePageMenuClick
        end
      end
      object MenuDebugWindow: TMenuItem
        Caption = 'Debug Window'
        OnClick = MenuDebugWindowClick
      end
    end
    object H1: TMenuItem
      Caption = 'Help'
      object MenuHelp: TMenuItem
        Caption = 'Help'
        OnClick = MenuHelpClick
      end
      object N6: TMenuItem
        Caption = '-'
      end
      object MenuHomePage: TMenuItem
        Caption = 'Home Page'
        OnClick = MenuHomePageClick
      end
      object MenuCheckUpdate: TMenuItem
        Caption = 'Visit Github for Source code and binary'
        OnClick = MenuCheckUpdateClick
      end
      object MenuReleaseNote: TMenuItem
        Caption = 'Release Note...'
        OnClick = MenuReleaseNoteClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object SkinsMenuGroup: TMenuItem
        Caption = 'Skins'
        object MenuSkinDefault: TMenuItem
          Caption = 'Default'
          OnClick = MenuSkinDefaultClick
        end
      end
      object N7: TMenuItem
        Caption = '-'
      end
      object MenuAboutDlg: TMenuItem
        Caption = 'About'
        OnClick = MenuAboutDlgClick
      end
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 315
    Top = 7
    object DeleteRecentlyFileMenu: TMenuItem
      Caption = 'Delete'
      OnClick = DeleteRecentlyFileMenuClick
    end
    object DeleteAllRecentlyFileMenu: TMenuItem
      Caption = 'Delete All'
      OnClick = DeleteAllRecentlyFileMenuClick
    end
  end
  object TimerImmediately: TTimer
    Enabled = False
    Interval = 100
    OnTimer = TimerImmediatelyTimer
    Left = 616
    Top = 56
  end
  object ActionListMacro: TActionList
    OnUpdate = ActionListMacroUpdate
    Left = 276
    Top = 57
    object actionStartRecord: TAction
      Caption = 'Record (F11)'
      Enabled = False
      OnExecute = actionStartRecordExecute
    end
    object actionStopRecord: TAction
      Caption = 'Stop (F12)'
      Enabled = False
      OnExecute = actionStopRecordExecute
    end
    object actionPlayRecord: TAction
      Caption = 'Play (F9)'
      Enabled = False
      OnExecute = actionPlayRecordExecute
    end
    object actionClearRecord: TAction
      Caption = 'Clear Record'
      Enabled = False
      OnExecute = actionClearRecordExecute
    end
    object actionSaveRecord: TAction
      Caption = 'Save Record'
      Enabled = False
      OnExecute = actionSaveRecordExecute
    end
    object actionLoadRecord: TAction
      Caption = 'Load Record'
      Enabled = False
      OnExecute = actionLoadRecordExecute
    end
  end
  object RecordPlayTimer: TTimer
    Enabled = False
    OnTimer = RecordPlayTimerTimer
    Left = 312
    Top = 56
  end
  object OpenDialogMacro: TOpenDialog
    DefaultExt = '.assmac'
    Filter = 'Macro Files|*.assmac|All Files|*.*'
    Options = [ofHideReadOnly, ofFileMustExist, ofEnableSizing]
    Left = 392
    Top = 56
  end
  object SaveDialogMacro: TSaveDialog
    DefaultExt = '.assmac'
    Filter = 'Macro Files|*.assmac|All Files|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 352
    Top = 56
  end
end
