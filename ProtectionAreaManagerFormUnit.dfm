object ProtectionAreaManagerForm: TProtectionAreaManagerForm
  Left = 0
  Top = 0
  AlphaBlend = True
  AlphaBlendValue = 100
  BorderStyle = bsNone
  Caption = 'ProtectionAreaManagerForm'
  ClientHeight = 579
  ClientWidth = 835
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  PopupMenu = MainPopupMenu
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  OnMouseUp = FormMouseUp
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object AreaPanel: TPanel
    Left = 80
    Top = 88
    Width = 217
    Height = 153
    Cursor = crSizeAll
    Color = clLime
    ParentBackground = False
    PopupMenu = PanelPopupMenu
    TabOrder = 0
    OnMouseDown = AreaPanelMouseDown
    OnMouseMove = AreaPanelMouseMove
    OnMouseUp = AreaPanelMouseUp
  end
  object MainPopupMenu: TPopupMenu
    Left = 640
    Top = 192
    object MenuLoadFromAreaFile: TMenuItem
      Caption = 'Load from Area File'
      OnClick = MenuLoadAreaFromFileClick
    end
    object MenuSaveToAreaFile: TMenuItem
      Caption = 'Save to Area File'
      OnClick = MenuSaveAreaToFileClick
    end
    object N6: TMenuItem
      Caption = '-'
    end
    object MenuFitToBackWindow: TMenuItem
      Caption = 'Fit to Back Window'
      OnClick = MenuFitToBackWindowClick
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object MenuMaximizeWindow: TMenuItem
      Caption = 'Maximize Window'
      OnClick = MenuMaximizeWindowClick
    end
    object MenuRestoreWindow: TMenuItem
      Caption = 'Restore Window'
      OnClick = MenuRestoreWindowClick
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object I1: TMenuItem
      Caption = 'Increase Alpha'
      ShortCut = 16422
      OnClick = I1Click
    end
    object D1: TMenuItem
      Caption = 'Decrease Alpha'
      ShortCut = 16424
      OnClick = D1Click
    end
    object N3: TMenuItem
      Caption = '-'
    end
    object MenuClearAndCloseWindow: TMenuItem
      Caption = 'Clear Area and Close Window'
      OnClick = MenuClearAndCloseWindowClick
    end
    object MenuCloseWindow: TMenuItem
      Caption = 'Close Window'
      OnClick = MenuCloseWindowClick
    end
  end
  object PanelPopupMenu: TPopupMenu
    Left = 640
    Top = 248
    object MenuPlaceArea: TMenuItem
      Caption = 'Place Area'
      OnClick = MenuPlaceAreaClick
    end
    object MenuDeleteLastArea: TMenuItem
      Caption = 'Delete Last Area'
      OnClick = MenuDeleteLastAreaClick
    end
    object MenuDeleteOverlappedArea: TMenuItem
      Caption = 'Delete Overlapped Area'
      OnClick = MenuDeleteOverlappedAreaClick
    end
    object N5: TMenuItem
      Caption = '-'
    end
    object MenuLoadAreaFromFile: TMenuItem
      Caption = 'Load Area from File'
      OnClick = MenuLoadAreaFromFileClick
    end
    object MenuSaveAreaToFile: TMenuItem
      Caption = 'Save Area to File'
      OnClick = MenuSaveAreaToFileClick
    end
    object N4: TMenuItem
      Caption = '-'
    end
    object MenuClearAllAreas: TMenuItem
      Caption = 'Clear all Areas'
      OnClick = MenuClearAllAreasClick
    end
  end
  object OpenDialog: TOpenDialog
    DefaultExt = '.rect'
    Filter = 'Area Files|*.rect|All Files|*.*'
    Options = [ofHideReadOnly, ofFileMustExist, ofEnableSizing]
    Left = 376
    Top = 424
  end
  object SaveDialog: TSaveDialog
    DefaultExt = '.rect'
    Filter = 'Area Files|*.rect|All Files|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 440
    Top = 424
  end
end