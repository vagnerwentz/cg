//---------------------------------------------------------------------------

#ifndef uPontoH
#define uPontoH
#include <Vcl.StdCtrls.hpp>
#include "uJanela.h"
//---------------------------------------------------------------------------
class Ponto {
	public:
		double x;
		double y;

		Ponto();
		Ponto(double, double);

		UnicodeString toString();

		int xMundoToViewPort(Janela mundo, Janela viewPort);
		int yMundoToViewPort(Janela mundo, Janela viewPort);
		int xViewPort(Janela mundo, Janela viewPort);
		int yViewPort(Janela mundo, Janela viewPort);
		void transladar(double deslocamentoX, double deslocamentoY);
		void escalonar(double escalonarX, double escalonarY);
		void rotacionar(double angulo);
		void reflexao(double reflexaoX, double reflexaoY);
        int cohen(Janela clipping);
};
#endif
