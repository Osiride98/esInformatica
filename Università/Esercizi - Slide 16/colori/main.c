#include "colori.h"
#include "colori.c"

#define N 5

int main (){
//PARTE 1
printf("---Parte 1---\n");

int a = N, b = N;

int *nCSS = &a;
int *nRGB = &b;

ColoreCSS arrayCSS_color[*nCSS];
ColoreRGB arrayRGB_color[*nRGB];

char file[] = "colori.txt";

leggi_colori(file,arrayCSS_color, nCSS, arrayRGB_color, nRGB);

//PARTE 2
printf("---Parte 2---\n");

stampa_colori(arrayCSS_color, *nCSS, arrayRGB_color, *nRGB);

}