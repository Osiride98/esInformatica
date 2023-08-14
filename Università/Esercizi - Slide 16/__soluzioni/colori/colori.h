#ifndef COLORI_H_
#define COLORI_H_

#include <stdio.h>
#include <stdlib.h>

#define N_CSS 8

typedef struct {
    char codice[N_CSS];
} ColoreCSS;

typedef struct {
    int r, g, b;
} ColoreRGB;

void leggi_colori(char *nome_file,
                  ColoreCSS *lcss, int *ncss,
                  ColoreRGB *lrgb, int *nrgb);

void stampa_colori(ColoreCSS *lcss, int ncss,
                   ColoreRGB *lrgb, int nrgb);

#endif
