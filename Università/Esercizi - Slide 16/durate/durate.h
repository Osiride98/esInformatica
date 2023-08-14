#ifndef DURATE_H
#define DURATE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int ore;
    int minuti;
}durata;

void leggi_durate(char *nome_file, durata *l, int *n);

void stampa_durate(char *nome_file, durata *l, int n);


#endif