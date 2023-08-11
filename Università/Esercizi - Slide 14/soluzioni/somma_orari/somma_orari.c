#include "somma_orari.h"

orario somma_orari(orario o1, orario o2) {
    // Calcolo la somma dei minuti
    int smm = o1.mm + o2.mm;
    // Calcolo il riporto
    int rhh = smm / 60; // divisione
    // Preparo una struttura per il risultato
    orario res;
    res.mm = smm % 60;
    res.hh = (o1.hh + o2.hh + rhh) % 24;
    // Restituisco il risultato
    return res;
}
