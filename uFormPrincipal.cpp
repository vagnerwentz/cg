//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include "uFormPrincipal.h"
#include "uPonto.h"
#include "uJanela.h"
#include "uPoligono.h"
#include "uDisplayFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Ponto ponto;
Poligono poligono;
DisplayFile displayFile;
Janela viewPort(0, 0, 500, 500);
Janela mundo(-250, -250, 250, 250);
Janela clipping(-100, -100, 100, 100);

bool incluir = false;
int contaId = 0;
bool criaClip = false;
int contId = 1;
//---------------------------------------------------------------------------
double xViewPortToMundo(int x, Janela mundo, Janela viewPort) {
	return ((x-viewPort.xMin)/(viewPort.xMax - viewPort.xMin))
	 * (mundo.xMax - mundo.xMin) + mundo.xMin;
}

double yViewPortToMundo(int y, Janela mundo, Janela viewPort) {
	return (1 - (y-viewPort.yMin)/(viewPort.yMax - viewPort.yMin))
	 * (mundo.yMax - mundo.yMin) + mundo.yMin;
}


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	// Linha area de desenho
	Image1->Canvas->Brush->Color = clWhite;
	Image1->Canvas->FillRect(Rect(0,0,500,500));
	Image1->Canvas->Pen->Color = clBlack;
	Image1->Canvas->Pen->Width = 1;

	// Linha Vertical
	poligono.pontos.push_back(Ponto(0, mundo.yMax));
	poligono.pontos.push_back(Ponto(0, mundo.yMin));
	poligono.id = contaId++;
	poligono.tipo = 'E';
	displayFile.poligonos.push_back(poligono);
	poligono.pontos.clear();

	// Linha Horizontal
	poligono.pontos.push_back(Ponto(mundo.xMin, 0));
	poligono.pontos.push_back(Ponto(mundo.xMax, 0));
	poligono.id = contaId++;
	poligono.tipo = 'E';
	displayFile.poligonos.push_back(poligono);
	poligono.pontos.clear();

	// Area de Clipping
	poligono.pontos.push_back(Ponto(-100, -100));
	poligono.pontos.push_back(Ponto(-100, 100));
	poligono.pontos.push_back(Ponto(100, 100));
	poligono.pontos.push_back(Ponto(100, -100));
    poligono.pontos.push_back(Ponto(-100, -100));
	poligono.id = contaId++;
	poligono.tipo = 'C';
	displayFile.poligonos.push_back(poligono);
	poligono.pontos.clear();

    poligono.tipo = 'N';
	displayFile.toString(listBoxPoligonos);
	displayFile.desenha(Image1->Canvas, mundo, viewPort, radioGroupTipoDeReta->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	double xMundo, yMundo;
	xMundo = xViewPortToMundo(X, mundo, viewPort);
	yMundo = yViewPortToMundo(Y, mundo, viewPort);

	ponto = Ponto(xMundo, yMundo);

	labelViewPort->Caption = "View Port (" + IntToStr(X) + "," + IntToStr(Y) + ")";
	labelMundo->Caption = "Mundo " + ponto.toString();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if (Button == mbLeft) {
		if (incluir) {
			double xMundo, yMundo;
			xMundo = xViewPortToMundo(X, mundo, viewPort);
			yMundo = yViewPortToMundo(Y, mundo, viewPort);

			poligono.pontos.push_back(Ponto(xMundo, yMundo));
			poligono.toString(listBoxPontos);
			poligono.desenha(Image1->Canvas, mundo, viewPort, radioGroupTipoDeReta->ItemIndex);
		} else
			ShowMessage("Clique no botao para incluir pontos em um poligono");
	} else if (Button == mbRight && poligono.pontos.size() > 0) {
		incluir = false;
		poligono.id = contaId++;
        poligono.tipo = 'N';
		displayFile.poligonos.push_back(poligono);
		displayFile.toString(listBoxPoligonos);
        poligono.pontos.clear();
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::buttonTesteClickClick(TObject *Sender)
{
	incluir = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::listBoxPontosMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	// ShowMessage(IntToStr(listBoxPontos->ItemIndex));
}
//---------------------------------------------------------------------------


void __fastcall TForm1::listBoxPoligonosMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	displayFile.poligonos[listBoxPoligonos->ItemIndex].toString(listBoxPontos);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::buttonAtualizaMundoClick(TObject *Sender)
{
	mundo.xMin = StrToFloat(editXMundoMinimo->Text);
	mundo.yMin = StrToFloat(editYMundoMinimo->Text);
	mundo.xMax = StrToFloat(editXMundoMaximo->Text);
	mundo.yMax = StrToFloat(editYMundoMaximo->Text);
	AtualizaMundo();
}
//---------------------------------------------------------------------------

void TForm1::AtualizaMundo() {
	editXMundoMinimo->Text = FloatToStr(mundo.xMin);
	editXMundoMaximo->Text = FloatToStr(mundo.xMax);

	editYMundoMinimo->Text = FloatToStr(mundo.yMin);
	editYMundoMaximo->Text = FloatToStr(mundo.yMax);

	displayFile.poligonos[0].pontos[0].y = mundo.yMax;
	displayFile.poligonos[0].pontos[1].y = mundo.yMin;

	displayFile.poligonos[1].pontos[0].x = mundo.xMin;
	displayFile.poligonos[1].pontos[1].x = mundo.xMax;

	displayFile.desenha(Image1->Canvas, mundo, viewPort, radioGroupTipoDeReta->ItemIndex);
}

void __fastcall TForm1::buttonCimaClick(TObject *Sender)
{
	mundo.yMin += 10;
	mundo.yMax += 10;
	AtualizaMundo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::buttonZoomInClick(TObject *Sender)
{
	mundo.xMin += 10;
	mundo.xMax -= 10;

	mundo.yMin += 10;
	mundo.yMax -= 10;

	AtualizaMundo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::buttonZoomOutClick(TObject *Sender)
{
	mundo.xMin -= 10;
	mundo.xMax += 10;

	mundo.yMin -= 10;
	mundo.yMax += 10;

	AtualizaMundo();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::buttonEmbaixoClick(TObject *Sender)
{
	mundo.yMin -= 10;
	mundo.yMax -= 10;
	AtualizaMundo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::buttonDireitaClick(TObject *Sender)
{
   mundo.xMin += 10;
   mundo.xMax += 10;
   AtualizaMundo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::buttonEsquerdaClick(TObject *Sender)
{
	mundo.xMin -= 10;
	mundo.xMax -= 10;
	AtualizaMundo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::radioGroupTipoDeRetaClick(TObject *Sender)
{
	displayFile.desenha(Image1->Canvas, mundo, viewPort, radioGroupTipoDeReta->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::buttonCircunferenciaClick(TObject *Sender)
{
	poligono= poligono.circunferencia(0,0,100);
	poligono.id = contaId++;
	poligono.tipo = 'B';
	displayFile.poligonos.push_back(poligono);
	displayFile.toString(listBoxPoligonos);
	poligono.pontos.clear();
	displayFile.desenha(Image1->Canvas, mundo, viewPort, radioGroupTipoDeReta->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::buttonTransladarClick(TObject *Sender)
{
	if (listBoxPoligonos->ItemIndex > 1) {
		double deslocamentoDeX = StrToFloat(editXTransladar->Text);
		double deslocamentoDeY = StrToFloat(editYTransladar->Text);
		displayFile.poligonos[listBoxPoligonos->ItemIndex].transladar(deslocamentoDeX, deslocamentoDeY);
		displayFile.desenha(Image1->Canvas, mundo, viewPort, radioGroupTipoDeReta->ItemIndex);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::buttonEscalonarClick(TObject *Sender)
{
	if (listBoxPoligonos->ItemIndex > 1) {
		double escalonarX = StrToFloat(editXEscalonar->Text);
		double escalonarY = StrToFloat(editYEscalonar->Text);
		displayFile.poligonos[listBoxPoligonos->ItemIndex].escalonar(escalonarX, escalonarY);
		displayFile.desenha(Image1->Canvas, mundo , viewPort , radioGroupTipoDeReta->ItemIndex);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::buttonRotacionarClick(TObject *Sender)
{
	if(listBoxPoligonos->ItemIndex > 1){
		displayFile.poligonos[listBoxPoligonos->ItemIndex].rotacionar(StrToFloat(editAnguloRotacionar->Text));
		displayFile.desenha(Image1->Canvas, mundo , viewPort , radioGroupTipoDeReta->ItemIndex);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::buttonReflexaoXClick(TObject *Sender)
{
    if(listBoxPoligonos->ItemIndex > 1){
	displayFile.poligonos[listBoxPoligonos->ItemIndex].reflexao(-1, 1);
		displayFile.desenha(Image1->Canvas, mundo , viewPort , radioGroupTipoDeReta->ItemIndex);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::buttonReflexaoYClick(TObject *Sender)
{
	if(listBoxPoligonos->ItemIndex > 1){
		displayFile.poligonos[listBoxPoligonos->ItemIndex].reflexao(1, -1);
		displayFile.desenha(Image1->Canvas, mundo , viewPort , radioGroupTipoDeReta->ItemIndex);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::buttonRotacaoHomogeneaClick(TObject *Sender)
{
	if(listBoxPoligonos->ItemIndex > 1){
		displayFile.poligonos[listBoxPoligonos->ItemIndex].rotacaoHomogenea(StrToFloat(editRotacaoHomogenea->Text));
		displayFile.desenha(Image1->Canvas, mundo , viewPort , radioGroupTipoDeReta->ItemIndex);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::buttonClippingClick(TObject *Sender)
{
	if (criaClip == false) {
		poligono.pontos.push_back(Ponto(clipping.xMin, clipping.yMax));
		poligono.pontos.push_back(Ponto(clipping.xMax, clipping.yMax));
		poligono.pontos.push_back(Ponto(clipping.xMax, clipping.xMin));
		poligono.pontos.push_back(Ponto(clipping.xMin, clipping.yMin));
		poligono.pontos.push_back(Ponto(clipping.xMin, clipping.yMax));

		poligono.tipo = 'C';
		poligono.id = contId++;

		displayFile.poligonos.push_back(poligono);

		poligono.pontos.clear();

		displayFile.desenha(Image1->Canvas, mundo, viewPort, radioGroupTipoDeReta->ItemIndex);
		criaClip = true;

	}

	int max = displayFile.poligonos.size();

	for (int i = 2; i <= max; i++) {
		if ((displayFile.poligonos[i].tipo != 'C') &&
			(displayFile.poligonos[i].tipo != 'A')) {
			Poligono Pol;

			Pol = displayFile.poligonos[i].clipping(clipping);
			Pol.tipo = 'A';
			Pol.id = contId++;
			displayFile.poligonos.push_back(Pol);
			poligono.pontos.clear();
		}
	}

	displayFile.toString(listBoxPoligonos);
	displayFile.desenha(Image1->Canvas, mundo, viewPort, radioGroupTipoDeReta->ItemIndex);
}
//---------------------------------------------------------------------------


