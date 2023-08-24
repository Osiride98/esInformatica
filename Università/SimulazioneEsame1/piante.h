#ifndef PIANTE_H
#define PIANTE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CF_MAX_CHAR 18

typedef struct{
    char codice[7];
    char nome[41];
    int valore;
    int quantita;
    float prezzo;
}Peperoncino;

typedef struct{
    char cf_cliente[CF_MAX_CHAR];
    char codice[7];
    int quantita;
}Acquisto;


int leggiProdotti (char* nomefile, Peperoncino vp[], int* dim);

void stampaProdotto (Peperoncino p);

int leggiAcquisti (char* nomefile, Acquisto va[], int* dim);

void stampaAcquisto (Acquisto a);

int cercaPeperoncino (Peperoncino p[], int dim, char* codice);

float totaleScontrino(Acquisto a[], int dimA, Peperoncino p[], int dimP, 
char *cf);

int registraAcquisto (char* nomefile, Acquisto *a);

#endif