#ifndef ORARI_H
#define ORARI_H

#include <stdio.h>
#include <string.h>

typedef struct {
    int ore;
    int minuti;
}orario;

void leggi_orario(orario *s);

orario somma_orari(orario o1, orario o2);

#endif