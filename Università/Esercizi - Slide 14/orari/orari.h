#ifndef ORARI_H
#define ORARI_H

#include <stdio.h>
#include <string.h>

// nel file header (*.h) inserisco le definizioni dei tipi di stato con include guard (direttive)
// dichiarazioni delle funzioni

typedef struct {
    int ore;
    int minuti;
}orario;

void leggi_orario(orario *o1);

void stampa_orario(orario o1);

void stampa_orari(orario *l, int n);

int confronta_orario(orario o1, orario o2);

void inserisci_orario(orario *l, int *n, orario o);

#endif