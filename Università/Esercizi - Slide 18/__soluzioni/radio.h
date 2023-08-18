#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NCODICE 6
#define NTITOLO 26
#define NNOME 41
#define NDEDICA 50

typedef struct {
    char codice[NCODICE];
    char titolo[NTITOLO];
    char artista[NNOME];
    char genere;
    int anno;
    int minuti, secondi;
} Canzone;

typedef struct {
    char nome_ascoltatore[NNOME];
    char titolo[NTITOLO];
    char dedica[NDEDICA];
} Richiesta;

int leggiCanzoni(char* nomefile, Canzone playlist[]);

void stampaCanzone(Canzone c);

int leggiRichieste(char* nomefile, Richiesta richieste[]);

void stampaRichiesta(Richiesta c);

int richAscoltatore(Canzone c[], int dimC,
                    Richiesta r[], int dimR,
                    char *ascoltatore);

void ordina(Canzone playlist[], int dimC);

int inserisciRichiesta(FILE *fp,
                       Canzone c[], int dimC,
                       Richiesta r[], int *dimR);
