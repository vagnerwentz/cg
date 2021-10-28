//---------------------------------------------------------------------------

#pragma hdrstop

#include "uDisplayFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void DisplayFile::toString(TListBox *listBox) {
    listBox->Items->Clear();

	for (int index = 0; index < poligonos.size(); index++) {
		listBox->Items->Add(poligonos[index].toString());
	}
}

void DisplayFile::desenha(TCanvas *canvas, Janela mundo, Janela viewPort, int tipoReta) {
     // Linha area de desenho
	canvas->Brush->Color = clWhite;
	canvas->FillRect(Rect(0,0,500,500));
	

    for (int index = 0; index < poligonos.size(); index++) {
		poligonos[index].desenha(canvas, mundo, viewPort, tipoReta);
	}
}