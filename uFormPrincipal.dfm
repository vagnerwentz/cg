object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Projeto de CG'
  ClientHeight = 623
  ClientWidth = 1112
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object labelViewPort: TLabel
    Left = 474
    Top = 588
    Width = 108
    Height = 19
    Caption = 'View Port (0,0)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object labelMundo: TLabel
    Left = 81
    Top = 588
    Width = 93
    Height = 19
    Caption = 'Mundo (0, 0)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 616
    Top = 189
    Width = 33
    Height = 13
    Caption = 'Pontos'
  end
  object Label2: TLabel
    Left = 616
    Top = 62
    Width = 45
    Height = 13
    Caption = 'Poligonos'
  end
  object Label3: TLabel
    Left = 610
    Top = 448
    Width = 70
    Height = 13
    Caption = 'xMundoMinimo'
  end
  object Label4: TLabel
    Left = 770
    Top = 448
    Width = 70
    Height = 13
    Caption = 'yMundoMinimo'
  end
  object Label5: TLabel
    Left = 608
    Top = 507
    Width = 74
    Height = 13
    Caption = 'xMundoMaximo'
  end
  object Label6: TLabel
    Left = 770
    Top = 507
    Width = 74
    Height = 13
    Caption = 'yMundoMaximo'
  end
  object Label7: TLabel
    Left = 655
    Top = 391
    Width = 43
    Height = 13
    Caption = 'Reflexao'
  end
  object Label8: TLabel
    Left = 920
    Top = 313
    Width = 100
    Height = 13
    Caption = 'Rotacao Homogenea'
  end
  object Panel1: TPanel
    Left = 80
    Top = 80
    Width = 502
    Height = 502
    TabOrder = 0
    object Image1: TImage
      Left = 1
      Top = 1
      Width = 500
      Height = 500
      Align = alClient
      OnMouseDown = Image1MouseDown
      OnMouseMove = Image1MouseMove
      ExplicitLeft = 168
      ExplicitTop = 216
      ExplicitWidth = 105
      ExplicitHeight = 105
    end
  end
  object buttonTesteClick: TButton
    Left = 743
    Top = 80
    Width = 139
    Height = 50
    Caption = 'Criar Poligono'
    TabOrder = 1
    OnClick = buttonTesteClickClick
  end
  object listBoxPontos: TListBox
    Left = 616
    Top = 208
    Width = 121
    Height = 97
    ItemHeight = 13
    TabOrder = 2
    OnMouseDown = listBoxPontosMouseDown
  end
  object listBoxPoligonos: TListBox
    Left = 616
    Top = 81
    Width = 121
    Height = 97
    ItemHeight = 13
    TabOrder = 3
    OnMouseDown = listBoxPoligonosMouseDown
  end
  object editXMundoMinimo: TEdit
    Left = 608
    Top = 467
    Width = 121
    Height = 21
    TabOrder = 4
    Text = '-250'
  end
  object editYMundoMinimo: TEdit
    Left = 770
    Top = 467
    Width = 121
    Height = 21
    TabOrder = 5
    Text = '-250'
  end
  object editXMundoMaximo: TEdit
    Left = 608
    Top = 526
    Width = 121
    Height = 21
    TabOrder = 6
    Text = '250'
  end
  object editYMundoMaximo: TEdit
    Left = 770
    Top = 526
    Width = 121
    Height = 21
    TabOrder = 7
    Text = '250'
  end
  object buttonAtualizaMundo: TButton
    Left = 696
    Top = 553
    Width = 105
    Height = 57
    Caption = 'Atualiza Mundo'
    TabOrder = 8
    OnClick = buttonAtualizaMundoClick
  end
  object buttonCima: TButton
    Left = 960
    Top = 59
    Width = 75
    Height = 25
    Caption = 'Cima'
    TabOrder = 9
    OnClick = buttonCimaClick
  end
  object buttonEmbaixo: TButton
    Left = 960
    Top = 122
    Width = 75
    Height = 25
    Caption = 'Embaixo'
    TabOrder = 10
    OnClick = buttonEmbaixoClick
  end
  object buttonEsquerda: TButton
    Left = 888
    Top = 91
    Width = 75
    Height = 25
    Caption = 'Esquerda'
    TabOrder = 11
    OnClick = buttonEsquerdaClick
  end
  object buttonDireita: TButton
    Left = 1032
    Top = 91
    Width = 75
    Height = 25
    Caption = 'Direita'
    TabOrder = 12
    OnClick = buttonDireitaClick
  end
  object buttonZoomIn: TButton
    Left = 920
    Top = 153
    Width = 75
    Height = 25
    Caption = 'Zoom In'
    TabOrder = 13
    OnClick = buttonZoomInClick
  end
  object buttonZoomOut: TButton
    Left = 1001
    Top = 153
    Width = 75
    Height = 25
    Caption = 'Zoom Out'
    TabOrder = 14
    OnClick = buttonZoomOutClick
  end
  object radioGroupTipoDeReta: TRadioGroup
    Left = 904
    Top = 200
    Width = 185
    Height = 105
    Caption = 'Tipo de reta'
    ItemIndex = 0
    Items.Strings = (
      'MoveTo'
      'DDA'
      'Bresenham')
    TabOrder = 15
    OnClick = radioGroupTipoDeRetaClick
  end
  object buttonCircunferencia: TButton
    Left = 743
    Top = 136
    Width = 139
    Height = 56
    Caption = 'Circunferencia'
    TabOrder = 16
    OnClick = buttonCircunferenciaClick
  end
  object buttonTransladar: TButton
    Left = 626
    Top = 359
    Width = 103
    Height = 26
    Caption = 'Transladar'
    TabOrder = 17
    OnClick = buttonTransladarClick
  end
  object editXTransladar: TEdit
    Left = 626
    Top = 332
    Width = 46
    Height = 21
    TabOrder = 18
    Text = 'X'
  end
  object editYTransladar: TEdit
    Left = 678
    Top = 332
    Width = 46
    Height = 21
    TabOrder = 19
    Text = 'Y'
  end
  object editXEscalonar: TEdit
    Left = 743
    Top = 332
    Width = 46
    Height = 21
    TabOrder = 20
    Text = 'X'
  end
  object editYEscalonar: TEdit
    Left = 795
    Top = 332
    Width = 46
    Height = 21
    TabOrder = 21
    Text = 'Y'
  end
  object buttonEscalonar: TButton
    Left = 743
    Top = 359
    Width = 103
    Height = 26
    Caption = 'Escalonar'
    TabOrder = 22
    OnClick = buttonEscalonarClick
  end
  object editAnguloRotacionar: TEdit
    Left = 860
    Top = 332
    Width = 61
    Height = 21
    TabOrder = 23
  end
  object buttonRotacionar: TButton
    Left = 860
    Top = 359
    Width = 61
    Height = 26
    Caption = 'Rotacionar'
    TabOrder = 24
    OnClick = buttonRotacionarClick
  end
  object buttonReflexaoX: TButton
    Left = 605
    Top = 410
    Width = 75
    Height = 25
    Caption = 'X'
    TabOrder = 25
    OnClick = buttonReflexaoXClick
  end
  object buttonReflexaoY: TButton
    Left = 686
    Top = 410
    Width = 75
    Height = 25
    Caption = 'Y'
    TabOrder = 26
    OnClick = buttonReflexaoYClick
  end
  object editRotacaoHomogenea: TEdit
    Left = 935
    Top = 332
    Width = 75
    Height = 21
    TabOrder = 27
  end
  object buttonRotacaoHomogenea: TButton
    Left = 935
    Top = 359
    Width = 75
    Height = 25
    Caption = 'Rotacionar'
    TabOrder = 28
    OnClick = buttonRotacaoHomogeneaClick
  end
  object buttonClipping: TButton
    Left = 743
    Top = 208
    Width = 139
    Height = 49
    Caption = 'Clipping'
    TabOrder = 29
    OnClick = buttonClippingClick
  end
end
