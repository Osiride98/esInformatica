#include "punti.h"
#include "punti.c"
#include "segmenti.h"
#include "segmenti.c"

#define N 4

int main(){
//PARTE 1 
printf("---Parte 1---\n");

punto arrayPunti[N];
punto p;

for (int i = 0; i < N; i++){
    leggi_punto(&p);
    arrayPunti[i] = p;
    stampa_punto(&p);
}

//PARTE 2 
printf("---Parte 2---\n");

segmento s;

s = crea_segmento(&arrayPunti[0],&arrayPunti[1]);

stampa_con_lunghezza(&s);

//PARTE 3
printf("---Parte 3---\n");

int n=N;
int dimArraySegm = (n*(n-1))/2;

segmento arraySegmenti[dimArraySegm];

crea_segmenti(arraySegmenti,arrayPunti,N);

}