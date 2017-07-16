object D3AssistantMainForm: TD3AssistantMainForm
  Left = 0
  Top = 0
  ActiveControl = GroupBox1
  Caption = 'D3Assist v1.0.0.1'
  ClientHeight = 421
  ClientWidth = 413
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  Menu = MainMenu
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnMouseWheel = FormMouseWheel
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 169
    Height = 105
    Caption = 'Start/Stop'
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 32
      Width = 45
      Height = 13
      Caption = 'Start Key'
    end
    object Label2: TLabel
      Left = 16
      Top = 64
      Width = 43
      Height = 13
      Caption = 'Stop Key'
    end
    object edStart: TEdit
      Tag = 1
      Left = 67
      Top = 34
      Width = 81
      Height = 21
      TabStop = False
      Alignment = taCenter
      TabOrder = 0
      OnChange = edStartChange
      OnContextPopup = edStartContextPopup
      OnKeyDown = edStartKeyDown
      OnKeyPress = edStartKeyPress
      OnMouseDown = edKey1MouseDown
    end
    object edStop: TEdit
      Tag = 1
      Left = 67
      Top = 61
      Width = 81
      Height = 21
      TabStop = False
      Alignment = taCenter
      TabOrder = 1
      OnChange = edStartChange
      OnContextPopup = edStartContextPopup
      OnKeyDown = edStartKeyDown
      OnKeyPress = edStartKeyPress
      OnMouseDown = edKey1MouseDown
    end
  end
  object Memo1: TMemo
    Left = 561
    Top = 8
    Width = 262
    Height = 359
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object btnSave: TButton
    Left = 175
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Save'
    TabOrder = 2
    TabStop = False
    OnClick = btnSaveClick
  end
  object btnLoad: TButton
    Left = 175
    Top = 39
    Width = 75
    Height = 25
    Caption = 'Load'
    TabOrder = 3
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
    ParentBackground = False
    TabOrder = 4
  end
  object stBar: TStatusBar
    Left = 0
    Top = 402
    Width = 413
    Height = 19
    Panels = <>
    SimplePanel = True
    SimpleText = 'Welcome D3Assist'
  end
  object PageControl: TPageControl
    Left = -1
    Top = 111
    Width = 409
    Height = 290
    ActivePage = KeySettingTabSheet
    TabOrder = 6
    OnChange = PageControlChange
    object KeySettingTabSheet: TTabSheet
      Caption = 'Key/Mouse'
      object Label3: TLabel
        Left = 28
        Top = 8
        Width = 18
        Height = 13
        Caption = 'Key'
      end
      object Label4: TLabel
        Left = 90
        Top = 8
        Width = 59
        Height = 13
        Caption = 'Delay(msec)'
      end
      object Label5: TLabel
        Left = 214
        Top = 8
        Width = 50
        Height = 13
        Caption = 'Pause Key'
      end
      object Label7: TLabel
        Left = 308
        Top = 8
        Width = 51
        Height = 13
        Caption = 'Active Key'
      end
      object Label8: TLabel
        Left = 0
        Top = 249
        Width = 401
        Height = 13
        Align = alBottom
        Caption = 'Press [ESC] key for delete selected field or press backspace'
        ExplicitWidth = 287
      end
      object Label15: TLabel
        Left = 165
        Top = 8
        Width = 35
        Height = 13
        Caption = 'Holding'
      end
      object edActive1: TEdit
        Tag = 1
        Left = 308
        Top = 24
        Width = 88
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 0
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edPause1: TEdit
        Tag = 1
        Left = 214
        Top = 24
        Width = 88
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 1
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edDelay1: TEdit
        Tag = 2
        Left = 90
        Top = 24
        Width = 66
        Height = 21
        TabStop = False
        Alignment = taCenter
        NumbersOnly = True
        TabOrder = 2
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edKey1: TEdit
        Tag = 1
        Left = 3
        Top = 24
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
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edKey2: TEdit
        Tag = 1
        Left = 3
        Top = 51
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
        TabOrder = 4
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edDelay2: TEdit
        Tag = 2
        Left = 90
        Top = 51
        Width = 66
        Height = 21
        TabStop = False
        Alignment = taCenter
        NumbersOnly = True
        TabOrder = 5
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edPause2: TEdit
        Tag = 1
        Left = 214
        Top = 51
        Width = 88
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 6
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edActive2: TEdit
        Tag = 1
        Left = 308
        Top = 51
        Width = 88
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 7
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edActive3: TEdit
        Tag = 1
        Left = 308
        Top = 78
        Width = 88
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 8
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edPause3: TEdit
        Tag = 1
        Left = 214
        Top = 78
        Width = 88
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 9
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edDelay3: TEdit
        Tag = 2
        Left = 90
        Top = 78
        Width = 66
        Height = 21
        TabStop = False
        Alignment = taCenter
        NumbersOnly = True
        TabOrder = 10
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edKey3: TEdit
        Tag = 1
        Left = 3
        Top = 78
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
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edKey4: TEdit
        Tag = 1
        Left = 3
        Top = 105
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
        TabOrder = 12
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edKey5: TEdit
        Tag = 1
        Left = 3
        Top = 132
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
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edKey6: TEdit
        Tag = 1
        Left = 3
        Top = 159
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
        TabOrder = 14
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edKey7: TEdit
        Tag = 1
        Left = 3
        Top = 186
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
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edKey8: TEdit
        Tag = 1
        Left = 3
        Top = 213
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
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edDelay8: TEdit
        Tag = 2
        Left = 90
        Top = 213
        Width = 66
        Height = 21
        TabStop = False
        Alignment = taCenter
        NumbersOnly = True
        TabOrder = 17
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edDelay7: TEdit
        Tag = 2
        Left = 90
        Top = 186
        Width = 66
        Height = 21
        TabStop = False
        Alignment = taCenter
        NumbersOnly = True
        TabOrder = 18
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edDelay6: TEdit
        Tag = 2
        Left = 90
        Top = 159
        Width = 66
        Height = 21
        TabStop = False
        Alignment = taCenter
        NumbersOnly = True
        TabOrder = 19
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edDelay5: TEdit
        Tag = 2
        Left = 90
        Top = 132
        Width = 66
        Height = 21
        TabStop = False
        Alignment = taCenter
        NumbersOnly = True
        TabOrder = 20
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edDelay4: TEdit
        Tag = 2
        Left = 90
        Top = 105
        Width = 66
        Height = 21
        TabStop = False
        Alignment = taCenter
        NumbersOnly = True
        TabOrder = 21
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyPress = edDelay1KeyPress
      end
      object edPause4: TEdit
        Tag = 1
        Left = 214
        Top = 105
        Width = 88
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 22
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edPause5: TEdit
        Tag = 1
        Left = 214
        Top = 132
        Width = 88
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 23
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edPause6: TEdit
        Tag = 1
        Left = 214
        Top = 159
        Width = 88
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 24
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edPause7: TEdit
        Tag = 1
        Left = 214
        Top = 186
        Width = 88
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 25
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edPause8: TEdit
        Tag = 1
        Left = 214
        Top = 213
        Width = 88
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 26
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edActive8: TEdit
        Tag = 1
        Left = 308
        Top = 213
        Width = 88
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 27
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edActive7: TEdit
        Tag = 1
        Left = 308
        Top = 186
        Width = 88
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 28
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edActive6: TEdit
        Tag = 1
        Left = 308
        Top = 159
        Width = 88
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 29
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edActive5: TEdit
        Tag = 1
        Left = 308
        Top = 132
        Width = 88
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 30
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edActive4: TEdit
        Tag = 1
        Left = 308
        Top = 105
        Width = 88
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 31
        OnChange = edStartChange
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object cbToggle1: TCheckBox
        Left = 171
        Top = 27
        Width = 17
        Height = 17
        TabOrder = 32
        OnClick = cbToggle1Click
      end
      object cbToggle2: TCheckBox
        Left = 171
        Top = 53
        Width = 17
        Height = 17
        TabOrder = 33
        OnClick = cbToggle1Click
      end
      object cbToggle3: TCheckBox
        Left = 171
        Top = 80
        Width = 17
        Height = 17
        TabOrder = 34
        OnClick = cbToggle1Click
      end
      object cbToggle4: TCheckBox
        Left = 171
        Top = 107
        Width = 17
        Height = 17
        TabOrder = 35
        OnClick = cbToggle1Click
      end
      object cbToggle5: TCheckBox
        Left = 171
        Top = 134
        Width = 17
        Height = 17
        TabOrder = 36
        OnClick = cbToggle1Click
      end
      object cbToggle6: TCheckBox
        Left = 171
        Top = 161
        Width = 17
        Height = 17
        TabOrder = 37
        OnClick = cbToggle1Click
      end
      object cbToggle7: TCheckBox
        Left = 171
        Top = 188
        Width = 17
        Height = 17
        TabOrder = 38
        OnClick = cbToggle1Click
      end
      object cbToggle8: TCheckBox
        Left = 171
        Top = 215
        Width = 17
        Height = 17
        TabOrder = 39
        OnClick = cbToggle1Click
      end
    end
    object EnvironmentTabSheet: TTabSheet
      Caption = 'Pause All Key(not yet)'
      ImageIndex = 1
      object Label9: TLabel
        Left = 3
        Top = 21
        Width = 27
        Height = 13
        Caption = 'Name'
      end
      object Label10: TLabel
        Left = 114
        Top = 21
        Width = 18
        Height = 13
        Caption = 'Key'
      end
      object Label11: TLabel
        Left = 206
        Top = 21
        Width = 27
        Height = 13
        Caption = 'Name'
      end
      object Label12: TLabel
        Left = 317
        Top = 21
        Width = 18
        Height = 13
        Caption = 'Key'
      end
      object Label13: TLabel
        Left = 70
        Top = 3
        Width = 74
        Height = 13
        Caption = 'Toggle Method '
      end
      object Label14: TLabel
        Left = 270
        Top = 3
        Width = 60
        Height = 13
        Caption = 'Hold Method'
      end
      object edToggleName1: TEdit
        Tag = 1
        Left = 3
        Top = 37
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 0
        Text = 'Inventory'
        OnContextPopup = edStartContextPopup
      end
      object edToggleKey1: TEdit
        Tag = 1
        Left = 114
        Top = 37
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
        Text = 'I'
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edToggleName2: TEdit
        Tag = 1
        Left = 3
        Top = 64
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 2
        Text = 'Inventory'
        OnContextPopup = edStartContextPopup
      end
      object edToggleKey2: TEdit
        Tag = 1
        Left = 114
        Top = 64
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
        Text = 'I'
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edToggleName3: TEdit
        Tag = 1
        Left = 3
        Top = 91
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 4
        Text = 'Inventory'
        OnContextPopup = edStartContextPopup
      end
      object edToggleKey3: TEdit
        Tag = 1
        Left = 114
        Top = 91
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
        Text = 'I'
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edToggleName4: TEdit
        Tag = 1
        Left = 3
        Top = 118
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 6
        Text = 'Inventory'
        OnContextPopup = edStartContextPopup
      end
      object edToggleKey4: TEdit
        Tag = 1
        Left = 114
        Top = 118
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
        Text = 'I'
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edToggleName5: TEdit
        Tag = 1
        Left = 3
        Top = 145
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 8
        Text = 'Inventory'
        OnContextPopup = edStartContextPopup
      end
      object edToggleKey5: TEdit
        Tag = 1
        Left = 114
        Top = 145
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
        Text = 'I'
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edToggleName6: TEdit
        Tag = 1
        Left = 3
        Top = 172
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 10
        Text = 'Inventory'
        OnContextPopup = edStartContextPopup
      end
      object edToggleKey6: TEdit
        Tag = 1
        Left = 114
        Top = 172
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
        Text = 'I'
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edToggleName7: TEdit
        Tag = 1
        Left = 3
        Top = 199
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 12
        Text = 'Inventory'
        OnContextPopup = edStartContextPopup
      end
      object edToggleKey7: TEdit
        Tag = 1
        Left = 114
        Top = 199
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
        Text = 'I'
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edToggleName8: TEdit
        Tag = 1
        Left = 3
        Top = 226
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 14
        Text = 'Inventory'
        OnContextPopup = edStartContextPopup
      end
      object edToggleKey8: TEdit
        Tag = 1
        Left = 114
        Top = 226
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
        Text = 'I'
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edHoldKey1: TEdit
        Tag = 1
        Left = 317
        Top = 37
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
        Text = 'I'
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edHoldName1: TEdit
        Tag = 1
        Left = 206
        Top = 37
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 17
        Text = 'Inventory'
        OnContextPopup = edStartContextPopup
      end
      object edHoldName2: TEdit
        Tag = 1
        Left = 206
        Top = 64
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 18
        Text = 'Inventory'
        OnContextPopup = edStartContextPopup
      end
      object edHoldKey2: TEdit
        Tag = 1
        Left = 317
        Top = 64
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
        Text = 'I'
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edHoldKey3: TEdit
        Tag = 1
        Left = 317
        Top = 91
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
        Text = 'I'
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edHoldName3: TEdit
        Tag = 1
        Left = 206
        Top = 91
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 21
        Text = 'Inventory'
        OnContextPopup = edStartContextPopup
      end
      object edHoldName4: TEdit
        Tag = 1
        Left = 206
        Top = 118
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 22
        Text = 'Inventory'
        OnContextPopup = edStartContextPopup
      end
      object edHoldKey4: TEdit
        Tag = 1
        Left = 317
        Top = 118
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
        Text = 'I'
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edHoldKey5: TEdit
        Tag = 1
        Left = 317
        Top = 145
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
        Text = 'I'
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edHoldName5: TEdit
        Tag = 1
        Left = 206
        Top = 145
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 25
        Text = 'Inventory'
        OnContextPopup = edStartContextPopup
      end
      object edHoldName6: TEdit
        Tag = 1
        Left = 206
        Top = 172
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 26
        Text = 'Inventory'
        OnContextPopup = edStartContextPopup
      end
      object edHoldKey6: TEdit
        Tag = 1
        Left = 317
        Top = 172
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
        Text = 'I'
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edHoldKey7: TEdit
        Tag = 1
        Left = 317
        Top = 199
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
        Text = 'I'
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
      object edHoldName7: TEdit
        Tag = 1
        Left = 206
        Top = 199
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 29
        Text = 'Inventory'
        OnContextPopup = edStartContextPopup
      end
      object edHoldName8: TEdit
        Tag = 1
        Left = 206
        Top = 226
        Width = 105
        Height = 21
        TabStop = False
        Alignment = taCenter
        TabOrder = 30
        Text = 'Inventory'
        OnContextPopup = edStartContextPopup
      end
      object edHoldKey8: TEdit
        Tag = 1
        Left = 317
        Top = 226
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
        Text = 'I'
        OnContextPopup = edStartContextPopup
        OnKeyDown = edStartKeyDown
        OnKeyPress = edStartKeyPress
        OnMouseDown = edKey1MouseDown
      end
    end
    object TabSheet1: TTabSheet
      Caption = 'Environment'
      ImageIndex = 2
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
      object cbCheckUpdateOnStart: TCheckBox
        Left = 3
        Top = 96
        Width = 177
        Height = 17
        Caption = 'Check Update on Start'
        TabOrder = 4
      end
    end
  end
  object lbRecentlyFiles: TListBox
    Left = 258
    Top = 8
    Width = 145
    Height = 97
    ItemHeight = 13
    PopupMenu = PopupMenu1
    TabOrder = 7
    OnDblClick = lbRecentlyFilesDblClick
  end
  object lbRecentlyFilesFullPath: TListBox
    Left = 298
    Top = 24
    Width = 145
    Height = 97
    ItemHeight = 13
    TabOrder = 8
    Visible = False
  end
  object SaveDialog: TSaveDialog
    DefaultExt = '.ini'
    Filter = 'Ini Files|*.ini|All Files|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 416
    Top = 136
  end
  object OpenDialog: TOpenDialog
    DefaultExt = '.ini'
    Filter = 'Ini Files|*.ini|All Files|*.*'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 416
    Top = 184
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 100
    OnTimer = Timer1Timer
    Left = 464
    Top = 136
  end
  object Timer2: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 464
    Top = 184
  end
  object Timer3: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 464
    Top = 232
  end
  object Timer4: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 464
    Top = 280
  end
  object Timer5: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 512
    Top = 136
  end
  object Timer6: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 512
    Top = 184
  end
  object Timer7: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 512
    Top = 232
  end
  object Timer8: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 512
    Top = 280
  end
  object MainMenu: TMainMenu
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
    object H1: TMenuItem
      Caption = 'Help'
      object MenuHelp: TMenuItem
        Caption = 'Help'
        OnClick = MenuHelpClick
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
      object MenuAboutDlg: TMenuItem
        Caption = 'About'
        OnClick = MenuAboutDlgClick
      end
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 235
    Top = 95
    object DeleteRecentlyFileMenu: TMenuItem
      Caption = 'Delete'
      OnClick = DeleteRecentlyFileMenuClick
    end
    object DeleteAllRecentlyFileMenu: TMenuItem
      Caption = 'Delete All'
      OnClick = DeleteAllRecentlyFileMenuClick
    end
  end
  object IdHTTP: TIdHTTP
    AllowCookies = True
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.ContentLength = -1
    Request.ContentRangeEnd = -1
    Request.ContentRangeStart = -1
    Request.ContentRangeInstanceLength = -1
    Request.Accept = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/3.0 (compatible; Indy Library)'
    Request.Ranges.Units = 'bytes'
    Request.Ranges = <>
    HTTPOptions = [hoForceEncodeParams]
    Left = 488
    Top = 72
  end
end
