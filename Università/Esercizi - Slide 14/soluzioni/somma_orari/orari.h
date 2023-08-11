#ifndef ORARI_H_
#define ORARI_H_

#include <stdio.h>

typedef struct {int hh, mm; } orario;

void leggi_orario(orario *o);

void stampa_orario(orario o);

int confronto_orario(orario o1, orario o2);

void stampa_orari(orario *l, int n);

void inserisci_orario(orario *l, int *n, orario o);

#endif
