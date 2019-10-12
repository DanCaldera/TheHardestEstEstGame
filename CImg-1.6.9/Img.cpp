#include <iostream>
#include "CImg.h"
int SetDIBitsToDevice(
					  _In_       HDC        hdc,
					  _In_       int        XDest,
					  _In_       int        YDest,
					  _In_       DWORD      dwWidth,
					  _In_       DWORD      dwHeight,
					  _In_       int        XSrc,
					  _In_       int        YSrc,
					  _In_       UINT       uStartScan,
					  _In_       UINT       cScanLines,
					  _In_ const VOID       *lpvBits,
					  _In_ const BITMAPINFO *lpbmi,
					  _In_       UINT       fuColorUse
					  );

int azul[3] = {0,0,255};
int rojo[3] = {255,0,0};
	int verde[3] = {0,255,0};

int main (void) {
    cimg_library::CImg<int> imagen(/*ancho*/600,/*alto*/600,/*3d*/1,/*capas*/3);
    imagen.fill(255);
    imagen.display();

    char nombre[] = "lena.bmp";
    cimg_library::CImg<int> imagen_entrada(nombre);
    imagen_entrada.display("Imagen de Lena",true,0);

    char texto_mostrar[] = "Lena";
    char texto_ventana[] = "Imagen de Lena Modificada";
    imagen_entrada.draw_text(0,0,texto_mostrar,azul,verde,1,50);
    imagen_entrada.display(texto_ventana,true,0);

    imagen_entrada.save_bmp("Imagen_Modificada.bmp");
    imagen.save_bmp("Imagen_Blanca.bmp");

    return 0;
}
