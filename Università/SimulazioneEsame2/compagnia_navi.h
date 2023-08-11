#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DIM_CODICE_NAVE 6
#define DIM_CITTA 41

typedef struct
{
    char codice_nave[DIM_CODICE_NAVE];
    char tipo;
} nave;

typedef struct
{
    int id_viaggio;
    char partenza[DIM_CITTA];
    char arrivo[DIM_CITTA];
    char codice_nave[DIM_CODICE_NAVE];
    int orario;
    int ritardo;
} partenza;

nave* leggi_navi(char *nomefile, int *num_n);
void stampa_nave(nave n);
partenza* leggi_partenze(char *nomefile, int *num_p);
void stampa_partenza(partenza p);
int trova_nave(char * codice, nave* n, int num_n);
int nuova_partenza(FILE * fp, nave * n, int num_n);
void ordina_partenze(partenza * p,int num_p);