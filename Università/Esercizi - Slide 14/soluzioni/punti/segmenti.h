#ifndef SEGMENTI_H_
#define SEGMENTI_H_

#include "punti.h"

typedef struct { punto p, q; } segmento;

segmento crea_segmento(punto *p, punto *q);

void stampa_con_lunghezza(segmento *s);

void crea_segmenti(segmento *ls, punto *lp, int n);

#endif
