object Form1: TForm1
  Left = 390
  Top = 159
  Width = 1135
  Height = 689
  Caption = #1040#1057#1058#1059#1069'('#1057#1069#1058'7009) '#1054#1040#1054' "'#1041#1069#1052#1047'"'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 512
    Top = 8
    Width = 44
    Height = 13
    Caption = #1053#1072' '#1076#1077#1085#1100':'
  end
  object TreeView1: TTreeView
    Left = 8
    Top = 48
    Width = 193
    Height = 361
    Indent = 19
    PopupMenu = PopupMenu1
    ReadOnly = True
    TabOrder = 0
    OnClick = TreeView1Click
    Items.Data = {
      01000000280000000000000000000000FFFFFFFFFFFFFFFF0000000001000000
      0FC0D1D2D3DD20CEC0CE22C1DDCCC722310000000000000000000000FFFFFFFF
      FFFFFFFF000000000200000018C0E4ECE8EDE8F1F2F0E0F6E8EEEDEDFBE920EA
      EEF0EFF3F11F0000000000000000000000FFFFFFFFFFFFFFFF00000000000000
      0006D0CF2D382D351F0000000000000000000000FFFFFFFFFFFFFFFF00000000
      0000000006D0CF2D312D35}
  end
  object PageControl1: TPageControl
    Left = 248
    Top = 48
    Width = 841
    Height = 393
    ActivePage = TabSheet5
    TabIndex = 4
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = #1047#1072' '#1084#1077#1089#1103#1094' '#1087#1086' '#1076#1085#1103#1084
    end
    object TabSheet2: TTabSheet
      Caption = #1047#1072' '#1075#1086#1076' '#1087#1086' '#1084#1077#1089#1103#1094#1072#1084
      ImageIndex = 1
    end
    object TabSheet3: TTabSheet
      Caption = #1043#1088#1072#1092#1080#1082' '#1079#1072' '#1084#1077#1089#1103#1094
      ImageIndex = 2
      object DBChart1: TDBChart
        Left = 96
        Top = 48
        Width = 400
        Height = 250
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        Title.Text.Strings = (
          'TDBChart')
        TabOrder = 0
      end
    end
    object TabSheet4: TTabSheet
      Caption = #1056#1072#1089#1089#1095#1077#1090' '#1088#1072#1089#1093#1086#1076#1072
      ImageIndex = 3
    end
    object TabSheet5: TTabSheet
      Caption = #1057#1095#1077#1090#1095#1080#1082
      ImageIndex = 4
      object Button3: TButton
        Left = 648
        Top = 328
        Width = 123
        Height = 25
        Caption = #1057#1095#1080#1090#1072#1090#1100' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1102
        TabOrder = 0
        OnClick = Button3Click
      end
      object ValueListEditor1: TValueListEditor
        Left = 42
        Top = 40
        Width = 735
        Height = 276
        KeyOptions = [keyEdit]
        Strings.Strings = (
          #1058#1080#1087' '#1087#1088#1080#1073#1086#1088#1072' ='
          #1047#1072#1074#1086#1076#1089#1082#1086#1081' '#1085#1086#1084#1077#1088'='
          #1042#1077#1088#1089#1080#1103' '#1087#1088#1086#1090#1086#1082#1086#1083#1072' '#1086#1073#1084#1077#1085#1072'='
          #1042#1077#1088#1089#1080#1103' '#1087#1088#1086#1096#1080#1074#1082#1080' '#1089#1095#1077#1090#1095#1080#1082#1072'='
          #1044#1072#1090#1072' '#1074#1099#1087#1091#1089#1082#1072'='
          #1057#1095#1077#1090#1095#1080#1082' '#1087#1077#1088#1077#1079#1072#1075#1088#1091#1079#1086#1082'='
          #1057#1095#1077#1090#1095#1080#1082' WDT='
          #1057#1095#1077#1090#1095#1080#1082' '#1086#1096#1080#1073#1086#1082'='
          #1053#1072#1087#1088#1103#1078#1077#1085#1080#1077' '#1085#1072' '#1073#1072#1090#1072#1088#1077#1077'='
          #1042#1088#1077#1084#1103' '#1088#1072#1073#1086#1090#1099' '#1074' '#1095#1072#1089#1072#1093'=')
        TabOrder = 1
        TitleCaptions.Strings = (
          #1055#1072#1088#1072#1084#1077#1090#1088
          #1047#1085#1072#1095#1077#1085#1080#1077)
        ColWidths = (
          160
          569)
      end
    end
  end
  object Button1: TButton
    Left = 912
    Top = 8
    Width = 105
    Height = 25
    Caption = #1063#1090#1077#1085#1080#1077
    TabOrder = 2
  end
  object DateTimePicker1: TDateTimePicker
    Left = 560
    Top = 8
    Width = 186
    Height = 21
    CalAlignment = dtaLeft
    Date = 42510.4902508912
    Time = 42510.4902508912
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 3
  end
  object Button2: TButton
    Left = 56
    Top = 16
    Width = 97
    Height = 25
    Caption = #1055#1088#1086#1074#1077#1088#1082#1072' '#1089#1074#1103#1079#1080
    TabOrder = 4
  end
  object RichEdit1: TRichEdit
    Left = 192
    Top = 448
    Width = 185
    Height = 89
    Lines.Strings = (
      'RichEdit1')
    TabOrder = 5
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 8
    object N1: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
      object N3: TMenuItem
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' com '#1087#1086#1088#1090#1072
      end
      object N4: TMenuItem
        Caption = #1042#1099#1093#1086#1076' '#1080#1079' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
        OnClick = N4Click
      end
    end
    object N2: TMenuItem
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
    end
  end
  object ComPort1: TComPort
    BaudRate = br9600
    Port = 'COM1'
    Parity.Bits = prNone
    StopBits = sbOneStopBit
    DataBits = dbEight
    Events = [evRxChar, evTxEmpty, evRxFlag, evRing, evBreak, evCTS, evDSR, evError, evRLSD, evRx80Full]
    FlowControl.OutCTSFlow = False
    FlowControl.OutDSRFlow = False
    FlowControl.ControlDTR = dtrDisable
    FlowControl.ControlRTS = rtsDisable
    FlowControl.XonXoffOut = False
    FlowControl.XonXoffIn = False
    StoredProps = [spBasic]
    TriggersOnRxChar = True
    Left = 160
    Top = 8
  end
  object PopupMenu1: TPopupMenu
    Left = 208
    Top = 8
    object N5: TMenuItem
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    end
    object N6: TMenuItem
      Caption = #1059#1076#1072#1083#1080#1090#1100' '
      OnClick = N6Click
    end
    object N7: TMenuItem
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
    end
    object N8: TMenuItem
      Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103
      OnClick = N8Click
    end
  end
end
