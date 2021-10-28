//---------------------------------------------------------------------------

#pragma hdrstop

#include "uPonto.h"
#define ESQUERDA 1
#define DIREITA 2
#define CIMA 8
#define EMBAIXO 4
//---------------------------------------------------------------------------
#pragma package(smart_init)

Ponto::Ponto() {
	x = y = 0;
}

Ponto::Ponto(double nX, double nY) {
	x = nX;
	y = nY;
}

UnicodeString Ponto::toString() {
	return "(" + FloatToStr(x) + "," + FloatToStr(y) + ")";
}

int Ponto::xMundoToViewPort(Janela mundo, Janela viewPort) {
	return (x - mundo.xMin)/(mundo.xMax - mundo.xMin)
		* (viewPort.xMax - viewPort.xMin);
}

int Ponto::yMundoToViewPort(Janela mundo, Janela viewPort) {
	return (1 - (y - mundo.yMin)/(mundo.yMax - mundo.yMin))
		* (viewPort.yMax - viewPort.yMin);
}

int Ponto::xViewPort(Janela mundo, Janela viewPort){
  return  (1 + ((x - mundo.xMax)/(mundo.xMax - mundo.xMin))) * (viewPort.xMax - viewPort.xMin);
}

int Ponto::yViewPort(Janela mundo, Janela viewPort){
    return  (-((y - mundo.yMax)/(mundo.yMax - mundo.yMin))) * (viewPort.yMax - viewPort.yMin);
}

void Ponto::transladar(double deslocamentoX, double deslocamentoY) {
	x += deslocamentoX;
    y += deslocamentoY;
}

void Ponto::escalonar(double escalonarX, double escalonarY) {
	x *= escalonarX;
    y *= escalonarY;
}

void Ponto::rotacionar(double angulo) {
	double radiano = angulo * M_PI/180;
	double xAnterior = x;

	x = (x*cos(radiano)) - (y*sin(radiano));
	y = (xAnterior*sin(radiano)) + (y*cos(radiano));
}

void Ponto::reflexao(double reflexaoX, double reflexaoY) {
   x *= reflexaoX;
   y *= reflexaoY;
}


int Ponto::cohen(Janela clipping) {
	int regiao = 0;
	if (x < clipping.xMin) {
		regiao += ESQUERDA;
	} else if (x > clipping.xMax) {
		regiao += DIREITA;
	}

	if (y < clipping.yMin) {
		regiao += EMBAIXO;
	} else if (y > clipping.yMax) {
		regiao += CIMA;
	}

	return regiao;
}
