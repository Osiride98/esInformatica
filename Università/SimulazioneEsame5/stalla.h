#ifndef STALLA_H
#define STALLA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR_CODICE 7
#define MAX_CHAR_RAZZA 31

typedef struct {
    char codice[MAX_CHAR_CODICE];
    char razza[MAX_CHAR_RAZZA];
    char produzione;
}Animale;

typedef struct {
    char razza[MAX_CHAR_RAZZA];
    int peso;
    float litri;
    int alta_qualita;
}Razza;


Animale * leggiAnimali (char * nomefile, int * dimAnimali);
void stampaAnimale (Animale a);

Razza * leggiRazze (char * nomefile, int * dimRazze);
void stampaRazza (Razza r);

float calcolaLitri(Animale a, Razza * r, int dimR);

float calcolaRicavo(Animale * a, int dimA, Razza * r, int dimR, float prezzo, float prezzoAQ);

void swap(Razza *a, Razza *b);
int bubble_sort(Razza a[], int n);
void ordina (Razza* a, int dim);

#endif