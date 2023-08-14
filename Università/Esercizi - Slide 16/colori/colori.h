#ifndef COLORI_H
#define COLORI_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "config.h"


typedef struct {
    char formato;
    char cssColour [CHAR_HEX];
}ColoreCSS;

typedef struct {
    char formato;
    char rgbColor [CHAR_HEX];
}ColoreRGB;

void leggi_colori(char *nome_file,
ColoreCSS *lcss, int *ncss,
ColoreRGB *lrgb, int *nrgb);

void stampa_colori(ColoreCSS *lcss, int ncss,
ColoreRGB *lrgb, int nrgb);

#endif