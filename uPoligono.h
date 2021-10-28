//---------------------------------------------------------------------------

#ifndef uPoligonoH
#define uPoligonoH

#include "uPonto.h"
#include <Vcl.StdCtrls.hpp>
#include <vector>
#include "uJanela.h"
#include "uPonto.h"
//---------------------------------------------------------------------------
class Poligono {
	public:
		std::vector<Ponto> pontos;
		int id;
		char tipo;

		void toString(TListBox *listBox);
		UnicodeString toString();
		void desenha(TCanvas *canvas, Janela mundo, Janela viewPort, int tipoReta);
		Poligono circunferencia(double xCentral, double yCentral, int raio);
		void desenhaPontoCircunferencia(Poligono *aux, int xCentral, int yCentral, int x, int y);
		void transladar(double deslocamentoX, double deslocamentoY);
		void escalonar(double escalonarX, double escalonarY);
		void rotacionar(double angulo);
		void reflexao(double reflexaoX, double reflexaoY);
		void rotacaoHomogenea(double angulo);
		Poligono clipping(Janela clipping);
		Ponto novoPonto(Ponto pontoAuxiliar, double x, double y);
        double calculoTangente(int index);

	private:
		Ponto centro();
		void multiplicacaoMatriz(double matrizAuxiliar[1][3], double matrizUm[1][3],double matrizDois[3][3]);
};

#endif
