#ifndef PRODOTTI_H 
#define PRODOTTI_H

#include<stdio.h>
#include<string.h>

#define N 1
#define MAX_LENGHT 127

typedef struct{
    char nome [MAX_LENGHT];
    float prezzo;
}prodotto;

void leggi_prodotto(prodotto *p);

void stampa_prodotti(prodotto* l, int n);

int trova_prodotto(char *p, prodotto *l, int n);

int inserisci_prodotto(prodotto p, prodotto *l, int *n);

#endif