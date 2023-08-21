#ifndef MANAGER_H
#define MANAGER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR_CIVICO 51
#define MAX_CHAR_COMUNICAZIONE_A 101
#define MAX_CHAR_DESCRIZIONE_E 51

typedef struct{
    int codice_condominio;
    int CAP;
    char via_residenza[MAX_CHAR_CIVICO];
    int numero_civico;
}Condominio;

typedef struct{
    char tipologia;
    int codice_condominio;
    char comunicazione[MAX_CHAR_COMUNICAZIONE_A];
}ComA;

typedef struct {
    char tipologia;
    int codice_condominio;
    int importo_monetario;
    char descrizione[MAX_CHAR_DESCRIZIONE_E];
    int anno;
    int mese;
    int giorno;
}ComE;

Condominio* readcondomini(char* fileName, int *dim); 

ComA* readComA(char* fileName, int *dim);

ComE* readComE(char* fileName, int *dim);

void swap(ComE *a, ComE *b);

int bubble_sort(ComE v[], int n);

ComE* stampaCondominio(Condominio *c, int dimC, ComA *a, int dimA, ComE *e, int dimE);

#endif