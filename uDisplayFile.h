//---------------------------------------------------------------------------

#ifndef uDisplayFileH
#define uDisplayFileH
#include <vector>
#include <Vcl.StdCtrls.hpp>
#include "uPoligono.h"
//---------------------------------------------------------------------------
class DisplayFile {
	public:
		std::vector<Poligono> poligonos;

		void toString(TListBox *listBox);
		void desenha(TCanvas *canvas, Janela mundo, Janela viewPort, int tipoReta);
};

#endif
