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
	int minuti;
	int secondi;
} Canzone;

typedef struct {
	char nome_asc[NNOME];
	char titolo[NTITOLO];
	char dedica[NDEDICA];
} Richiesta;

int leggiCanzoni(char* nomefile, Canzone playlist[]);
int stampaCanzone(Canzone c);
int leggiRichieste(char* nomefile, Richiesta richieste[]);
int stampaRichiesta(Richiesta r);
