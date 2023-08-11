#ifndef PUNTI_H
#define PUNTI_H

#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct {
    int x;
    int y;
}punto;

void leggi_punto(punto *p);

void stampa_punto(punto *p);

float distanza(punto *p1, punto *p2);

float max_distanza(punto *l, int n);

#endif