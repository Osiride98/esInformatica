#ifndef SEGMENTI_H
#define SEGMENTI_H

#include "punti.h"

#include<stdio.h>
#include<string.h>
#include<math.h>



// typedef struct {
//     int x;
//     int y;
// }punto;

typedef struct {
    int xi;
    int xf;
    int yi;
    int yf;
}segmento;

//void leggi_punto(punto *p);

segmento crea_segmento(punto *p, punto *q);

void stampa_con_lunghezza(segmento *s);

void crea_segmenti(segmento *ls, punto *lp, int n);

#endif