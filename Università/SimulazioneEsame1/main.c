#include "piante.h"
#include "piante.c"

#define MAX_DIM 100

int main (){
//PARTE 1
printf("---PARTE 1 ---\n");

int dimP;

Peperoncino vp[MAX_DIM];

int resRead = leggiProdotti("prodotti.txt", vp, &dimP);

if( resRead == 0){
    printf("Lettura Corretta");
}

printf("valore dim Prodotti = %d\n", dimP);

Peperoncino p;

printf("Scegliere Varietà Peperoncino = ");
scanf("%s", &p.nome);

stampaProdotto(p);

//PARTE 2
printf("---PARTE 2---\n");

int dimA;

Acquisto va[MAX_DIM];

int dimAcq = leggiAcquisti("acquisti.txt", va, &dimA);

printf("valore dim Acquisti = %d\n", dimA);

Acquisto a;

printf("Scegliere COD Peperoncino = ");
scanf("%s", &a.codice);

stampaAcquisto(a);

//PARTE 3
printf("---PARTE 3---\n");

char codPep;

printf("Scegliere COD Peperoncino = ");
scanf("%s", &codPep);

int resRicerca = cercaPeperoncino(vp, dimP, &codPep);

if (resRicerca == -1){
    printf("Prodotto non presente\n");
}

//PARTE 4
printf("---PARTE 4---\n");

char cf[CF_MAX_CHAR];

printf("Inserire CF -> ");
scanf("%s", &cf);

float scontrino =  totaleScontrino(va, dimA, vp, dimP, cf);

printf("Importo Scontrino = %.3f", scontrino);

}