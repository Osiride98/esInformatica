#ifndef CANZONI_H_
#define CANZONI_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char codice[6];
    char titolo[26];
    char artista[41];
    char genere;
    int annoUscita;
    int minDurata;
    int secDurata;
}canzone;

typedef struct{
    char nome_ascoltatore[41];
    char titolo[26];
    char dedica[51];
}richiesta;

typedef struct{
    int minuti;
    int secondi;
}tempo;


int leggiCanzoni (char* nomefile, canzone playlist[]);

void stampaCanzone (canzone c);

int leggiRichieste (char* nomefile, richiesta richieste[]);

void stampaRichiesta (richiesta r);

int richAscoltatore(canzone c[], int dimC, richiesta r[], int dimR, char * ascoltatore);

tempo sommaTempo(tempo t1, tempo t2);

void ordina (canzone playlist[], int dimC);

void swap(canzone *a, canzone *b);

int bubble_sort(canzone v[], int n);


#endif