object Form1: TForm1
  Left = 278
  Top = 124
  BorderStyle = bsSingle
  Caption = '!?'
  ClientHeight = 635
  ClientWidth = 1127
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
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
      02000000280000000000000000000000FFFFFFFFFFFFFFFF0000000001000000
      0FC0D1D2D3DD20CEC0CE22C1DDCCC722310000000000000000000000FFFFFFFF
      FFFFFFFF000000000200000018C0E4ECE8EDE8F1F2F0E0F6E8EEEDEDFBE920EA
      EEF0EFF3F11F0000000000000000000000FFFFFFFFFFFFFFFF00000000000000
      0006D0CF2D382D351F0000000000000000000000FFFFFFFFFFFFFFFF00000000
      0000000006D0CF2D312D351D0000000000000000000000FFFFFFFFFFFFFFFF00
      000000010000000454657374200000000000000000000000FFFFFFFFFFFFFFFF
      000000000000000007544543542D3138}
  end
  object PageControl1: TPageControl
    Left = 248
    Top = 48
    Width = 793
    Height = 505
    ActivePage = TabSheet2
    TabIndex = 1
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = #1047#1072' '#1084#1077#1089#1103#1094' '#1087#1086' '#1076#1085#1103#1084
      object Label3: TLabel
        Left = 536
        Top = 3
        Width = 80
        Height = 13
        Caption = #1062#1077#1085#1072' '#1079#1072' 1 '#1050#1042#1090'.'#1095
      end
      object Button1: TButton
        Left = 704
        Top = 442
        Width = 75
        Height = 25
        Caption = #1055#1088#1086#1095#1080#1090#1072#1090#1100
        TabOrder = 0
        OnClick = Button1Click
      end
      object StringGrid1: TStringGrid
        Left = 7
        Top = 34
        Width = 770
        Height = 393
        ColCount = 9
        FixedCols = 0
        RowCount = 35
        TabOrder = 1
        ColWidths = (
          64
          89
          82
          73
          82
          70
          71
          100
          104)
      end
      object ProgressBar1: TProgressBar
        Left = 16
        Top = 450
        Width = 673
        Height = 17
        Min = 0
        Max = 100
        TabOrder = 2
      end
      object Edit2: TEdit
        Left = 632
        Top = 0
        Width = 121
        Height = 21
        TabOrder = 3
        Text = '1820'
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1047#1072' '#1075#1086#1076' '#1087#1086' '#1084#1077#1089#1103#1094#1072#1084
      ImageIndex = 1
      object StringGrid2: TStringGrid
        Left = 24
        Top = 24
        Width = 753
        Height = 393
        ColCount = 9
        DefaultColWidth = 80
        FixedCols = 0
        RowCount = 28
        TabOrder = 0
        ColWidths = (
          80
          88
          80
          80
          80
          80
          80
          80
          80)
      end
      object Button5: TButton
        Left = 675
        Top = 441
        Width = 75
        Height = 25
        Caption = #1057#1095#1080#1090#1072#1090#1100
        TabOrder = 1
        OnClick = Button5Click
      end
      object RadioButton1: TRadioButton
        Left = 88
        Top = 432
        Width = 113
        Height = 17
        Caption = 'C '#1085#1072#1095#1072#1083#1072'  '#1075#1086#1076#1072
        Checked = True
        TabOrder = 2
        TabStop = True
      end
      object RadioButton2: TRadioButton
        Left = 224
        Top = 432
        Width = 113
        Height = 17
        Caption = #1047#1072' '#1087#1088#1086#1096#1083#1099#1081' '#1075#1086#1076
        TabOrder = 3
      end
      object RadioButton3: TRadioButton
        Left = 368
        Top = 432
        Width = 137
        Height = 17
        Caption = #1047#1072' '#1087#1086#1089#1083#1077#1076#1085#1080#1077' 2 '#1075#1086#1076#1072
        TabOrder = 4
      end
    end
    object TabSheet3: TTabSheet
      Caption = #1043#1088#1072#1092#1080#1082' '#1079#1072' '#1084#1077#1089#1103#1094
      ImageIndex = 2
      object Chart1: TChart
        Left = 40
        Top = 24
        Width = 657
        Height = 369
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        Gradient.Direction = gdBottomTop
        LeftWall.Brush.Color = clWhite
        Title.Color = clWhite
        Title.Text.Strings = (
          #1043#1088#1072#1092#1080#1082' '#1087#1088#1080#1088#1072#1097#1077#1085#1080#1103' '#1101#1085#1077#1088#1075#1080#1080' '#1079#1072' '#1084#1077#1089#1103#1094' '#1087#1086' '#1089#1091#1090#1082#1072#1084)
        BottomAxis.Grid.Style = psDashDotDot
        BottomAxis.Grid.Visible = False
        BottomAxis.Title.Caption = #1044#1072#1090#1072
        BottomAxis.Title.Font.Charset = DEFAULT_CHARSET
        BottomAxis.Title.Font.Color = clBlack
        BottomAxis.Title.Font.Height = -13
        BottomAxis.Title.Font.Name = 'Arial'
        BottomAxis.Title.Font.Style = [fsBold]
        DepthAxis.MinorTicks.Color = 4194432
        LeftAxis.Axis.Width = 1
        LeftAxis.ExactDateTime = False
        LeftAxis.Grid.Style = psDashDot
        LeftAxis.Grid.SmallDots = True
        LeftAxis.GridCentered = True
        LeftAxis.LabelStyle = talValue
        LeftAxis.Ticks.Style = psDashDotDot
        LeftAxis.Ticks.SmallDots = True
        LeftAxis.Title.Caption = #1069#1085#1077#1088#1075#1080#1103' '#1082#1042#1090'. '#1095
        LeftAxis.Title.Font.Charset = DEFAULT_CHARSET
        LeftAxis.Title.Font.Color = clBlack
        LeftAxis.Title.Font.Height = -13
        LeftAxis.Title.Font.Name = 'Arial'
        LeftAxis.Title.Font.Style = [fsBold]
        Legend.Visible = False
        TopAxis.Grid.Visible = False
        BevelInner = bvRaised
        BorderStyle = bsSingle
        TabOrder = 0
        object Series1: TAreaSeries
          Cursor = crArrow
          Marks.ArrowLength = 8
          Marks.Style = smsValue
          Marks.Visible = False
          SeriesColor = clBlue
          DrawArea = True
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          Stairs = True
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
      end
      object Button6: TButton
        Left = 664
        Top = 432
        Width = 75
        Height = 25
        Caption = 'Button6'
        TabOrder = 1
        OnClick = Button6Click
      end
    end
    object TabSheet4: TTabSheet
      Caption = #1056#1072#1089#1089#1095#1077#1090' '#1088#1072#1089#1093#1086#1076#1072
      ImageIndex = 3
    end
    object TabSheet5: TTabSheet
      Caption = #1057#1095#1077#1090#1095#1080#1082
      ImageIndex = 4
      object Label2: TLabel
        Left = 40
        Top = 0
        Width = 119
        Height = 20
        Caption = #1057#1077#1090#1077#1074#1086#1081' '#1072#1076#1088#1077#1089':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Button3: TButton
        Left = 656
        Top = 384
        Width = 123
        Height = 25
        Caption = #1057#1095#1080#1090#1072#1090#1100' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1102
        TabOrder = 0
        OnClick = Button3Click
      end
      object ValueListEditor1: TValueListEditor
        Left = 42
        Top = 24
        Width = 735
        Height = 233
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
          #1042#1088#1077#1084#1103' '#1088#1072#1073#1086#1090#1099' '#1074' '#1095#1072#1089#1072#1093'='
          #1057#1077#1090#1077#1074#1086#1081' '#1072#1076#1088#1077#1089'=')
        TabOrder = 1
        TitleCaptions.Strings = (
          #1055#1072#1088#1072#1084#1077#1090#1088
          #1047#1085#1072#1095#1077#1085#1080#1077)
        ColWidths = (
          160
          569)
      end
      object Edit1: TEdit
        Left = 168
        Top = 0
        Width = 121
        Height = 21
        TabOrder = 2
      end
      object Button4: TButton
        Left = 295
        Top = -3
        Width = 114
        Height = 25
        Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1072#1076#1088#1077#1089
        TabOrder = 3
        OnClick = Button4Click
      end
      object CheckBox1: TCheckBox
        Left = 43
        Top = 265
        Width = 198
        Height = 17
        Caption = #1057#1095#1077#1090#1095#1080#1082' '#1079#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1085
        TabOrder = 4
      end
      object CheckBox2: TCheckBox
        Left = 43
        Top = 281
        Width = 198
        Height = 17
        Caption = #1057#1095#1077#1090#1095#1080#1082' '#1079#1072#1097#1080#1097#1077#1085' '#1087#1072#1088#1086#1083#1077#1084
        TabOrder = 5
      end
      object CheckBox3: TCheckBox
        Left = 43
        Top = 297
        Width = 198
        Height = 17
        Caption = #1053#1072#1088#1091#1096#1077#1085#1072' '#1090#1077#1093#1085'. '#1087#1077#1088#1077#1084#1099#1095#1082#1072
        TabOrder = 6
      end
      object CheckBox4: TCheckBox
        Left = 43
        Top = 313
        Width = 198
        Height = 17
        Caption = #1087#1077#1088#1077#1093#1086#1076' '#1085#1072' '#1079#1080#1084#1085#1077#1077'/'#1083#1077#1090#1085#1077#1077' '#1074#1088#1077#1084#1103
        TabOrder = 7
      end
      object CheckBox5: TCheckBox
        Left = 43
        Top = 345
        Width = 198
        Height = 17
        Caption = #1055#1088#1077#1074#1099#1096#1077#1085' '#1083#1080#1084#1080#1090' '#1089#1080#1085#1093#1088'. '#1074#1088#1077#1084#1077#1085#1080
        TabOrder = 8
      end
      object CheckBox6: TCheckBox
        Left = 43
        Top = 361
        Width = 198
        Height = 17
        Caption = #1056#1072#1079#1088#1103#1078#1077#1085#1072' '#1073#1072#1090#1072#1088#1077#1103' (<2.2 '#1042')'
        TabOrder = 9
      end
      object CheckBox13: TCheckBox
        Left = 272
        Top = 358
        Width = 229
        Height = 17
        Caption = #1082#1086#1085#1090#1088#1086#1083#1100' '#1087#1088#1077#1074'. '#1086#1073#1097#1077#1075#1086' '#1083#1080#1084#1080#1090#1072' '#1101#1085#1077#1088#1075#1080#1080
        TabOrder = 10
      end
      object CheckBox14: TCheckBox
        Left = 506
        Top = 269
        Width = 271
        Height = 17
        Caption = #1074#1099#1093#1086#1076' '#1088#1077#1072#1082#1090'.  (0-'#1088#1077#1072#1082#1090'. '#1101#1085#1077#1088#1075',1-'#1086#1090#1082#1083'. '#1085#1072#1075#1088#1091#1079#1082#1080')'
        TabOrder = 11
      end
      object CheckBox15: TCheckBox
        Left = 506
        Top = 285
        Width = 271
        Height = 17
        Caption = #1088#1072#1073#1086#1090#1099' '#1090#1077#1083#1077#1084#1077#1090#1088#1080#1080' (0 -  2000 '#1080#1084#1087', 1 -  10000 '#1080#1084#1087')'
        TabOrder = 12
      end
      object CheckBox16: TCheckBox
        Left = 506
        Top = 301
        Width = 271
        Height = 17
        Caption = #1082#1086#1085#1090#1088#1086#1083#1100' '#1087#1088#1077#1074#1099#1096#1077#1085#1080#1103' '#1089#1091#1090#1086#1095#1085#1086#1075#1086' '#1083#1080#1084#1080#1090#1072' '#1101#1085#1077#1088#1075#1080#1080
        TabOrder = 13
      end
      object CheckBox17: TCheckBox
        Left = 506
        Top = 317
        Width = 271
        Height = 17
        Caption = #1088#1072#1079#1088#1077#1096#1077#1085#1086' '#1089#1091#1084#1084#1080#1088#1086#1074#1072#1085#1080#1077' '#1101#1085#1077#1088#1075#1080#1080' '#1087#1086' '#1084#1086#1076#1091#1083#1102
        TabOrder = 14
      end
      object CheckBox18: TCheckBox
        Left = 506
        Top = 332
        Width = 271
        Height = 17
        Caption = #1088#1072#1073#1086#1090#1072'  '#1087#1086' '#1080#1089#1082#1083#1102#1095#1077#1085#1080#1102' '#1074' '#1082#1072#1083#1077#1085#1076#1072#1088#1077
        TabOrder = 15
      end
      object CheckBox19: TCheckBox
        Left = 43
        Top = 330
        Width = 222
        Height = 17
        Caption = #1088#1072#1079#1088'.  '#1088#1072#1073#1086#1090#1072' '#1087#1086' '#1090#1072#1088#1080#1092#1085#1086#1081' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        TabOrder = 16
      end
      object CheckBox20: TCheckBox
        Left = 506
        Top = 345
        Width = 261
        Height = 17
        Caption = #1088#1072#1079#1088#1077#1096#1077#1085#1086' '#1089#1086#1093#1088#1072#1085#1077#1085#1080#1077' '#1089#1088#1077#1079#1086#1074' '#1072#1082#1090#1080#1074#1085#1086#1081' '#1101#1085#1077#1088#1075#1080#1080
        TabOrder = 17
      end
      object CheckBox21: TCheckBox
        Left = 506
        Top = 359
        Width = 261
        Height = 17
        Caption = #1088#1072#1079#1088#1077#1096#1077#1085#1086' '#1089#1086#1093#1088#1072#1085#1077#1085#1080#1077' '#1089#1088#1077#1079#1086#1074' '#1088#1077#1072#1082#1090#1080#1074#1085#1086#1081' '#1101#1085#1077#1088#1075#1080#1080
        TabOrder = 18
      end
      object CheckBox7: TCheckBox
        Left = 272
        Top = 267
        Width = 215
        Height = 17
        Caption = #1057#1073#1086#1081' '#1095#1072#1089#1086#1074' '#1088#1077#1072#1083#1100#1085#1086#1075#1086' '#1074#1088#1077#1084#1077#1085#1080
        TabOrder = 19
      end
      object CheckBox8: TCheckBox
        Left = 272
        Top = 283
        Width = 215
        Height = 17
        Caption = #1055#1088#1077#1074#1099#1096#1077#1085' '#1087#1086#1088#1086#1075' '#1086#1075#1088#1072#1085#1080#1095#1077#1085#1080#1103' '#1085#1072#1075#1088#1091#1079#1082#1080
        TabOrder = 20
      end
      object CheckBox9: TCheckBox
        Left = 272
        Top = 299
        Width = 215
        Height = 17
        Caption = #1053#1072#1083#1080#1095#1077' '#1085#1072#1087#1088#1103#1078#1077#1085#1080#1103' '#1092#1072#1079#1099' A'
        TabOrder = 21
      end
      object CheckBox10: TCheckBox
        Left = 272
        Top = 313
        Width = 215
        Height = 17
        Caption = #1053#1072#1083#1080#1095#1077' '#1085#1072#1087#1088#1103#1078#1077#1085#1080#1103' '#1092#1072#1079#1099' B'
        TabOrder = 22
      end
      object CheckBox11: TCheckBox
        Left = 272
        Top = 328
        Width = 215
        Height = 17
        Caption = #1053#1072#1083#1080#1095#1077' '#1085#1072#1087#1088#1103#1078#1077#1085#1080#1103' '#1092#1072#1079#1099' C'
        TabOrder = 23
      end
      object CheckBox12: TCheckBox
        Left = 272
        Top = 343
        Width = 215
        Height = 17
        Caption = #1082#1086#1085#1090#1088#1086#1083#1100' '#1087#1088#1077#1074'. '#1087#1086#1088#1086#1075#1072' '#1084#1086#1097#1085#1086#1089#1090#1080
        TabOrder = 24
      end
    end
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
    TabOrder = 2
  end
  object Button2: TButton
    Left = 56
    Top = 16
    Width = 97
    Height = 25
    Caption = #1055#1088#1086#1074#1077#1088#1082#1072' '#1089#1074#1103#1079#1080
    TabOrder = 3
  end
  object RichEdit1: TRichEdit
    Left = 32
    Top = 432
    Width = 185
    Height = 89
    Lines.Strings = (
      'RichEdit1')
    TabOrder = 4
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 8
    object N1: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
      object N3: TMenuItem
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' com '#1087#1086#1088#1090#1072
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1042#1099#1093#1086#1076' '#1080#1079' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
        OnClick = N4Click
      end
    end
    object N2: TMenuItem
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      OnClick = N2Click
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
    OnRxChar = ComPort1RxChar
    OnRx80Full = ComPort1Rx80Full
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
  object Timer1: TTimer
    Enabled = False
    Interval = 5000
    OnTimer = Timer1Timer
    Left = 264
  end
  object TimerTimeout: TTimer
    Enabled = False
    Interval = 3000
    OnTimer = TimerTimeoutTimer
    Left = 304
  end
end
