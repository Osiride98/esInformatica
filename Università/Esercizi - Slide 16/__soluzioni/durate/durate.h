#ifndef DURATE_H_
#define DURATE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hh, mm;
} Durata;

void leggi_durate(char *nome_file, Durata *l, int *n);

void stampa_durate(char *nome_file, Durata *l, int n);

#endif
