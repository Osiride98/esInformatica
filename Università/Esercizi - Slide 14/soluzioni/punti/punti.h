#ifndef PUNTI_H_
#define PUNTI_H_

#include <stdio.h>
#include <math.h>

typedef struct { float x, y; } punto;

void leggi_punto(punto *p);

void stampa_punto(punto *p);

float distanza(punto *p1, punto *p2);

float max_distanza(punto *l, int n);

#endif
