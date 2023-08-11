#ifndef PRODOTTO_H_
#define PRODOTTO_H_

#include <stdio.h>
#include <string.h>

#define NNOME 128

typedef struct {
    char nome[NNOME];
    float prezzo;
} prodotto;

prodotto leggi_prodotto();

void stampa_prodotti(prodotto* l, int n);

int trova_prodotto(char * nome, prodotto *l, int n);

int inserisci_prodotto(prodotto p, prodotto *l, int *n);

#endif
