object Form1: TForm1
  Left = 319
  Top = 210
  Width = 1135
  Height = 506
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
    TabOrder = 0
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
    Height = 369
    ActivePage = TabSheet4
    TabIndex = 3
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
    end
    object TabSheet4: TTabSheet
      Caption = #1056#1072#1089#1089#1095#1077#1090' '#1088#1072#1089#1093#1086#1076#1072
      ImageIndex = 3
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
  object MainMenu1: TMainMenu
    Left = 16
    Top = 8
    object N1: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1080#1090#1100' '#1087#1086#1088#1090
      object N3: TMenuItem
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1087#1086#1088#1090#1072
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
end
