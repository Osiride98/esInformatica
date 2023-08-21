#ifndef MANAGER_H_
#define MANAGER_H_

#include <stdio.h>
#include <stdlib.h>

#define NVIA 51
#define NMSG 101
#define NDESC 51

typedef struct {
    int codice;
    int cap;
    char via[NVIA];
    int civico;
} Condominio;

typedef struct {
    int codice;
    char msg[NMSG];
} ComA;

typedef struct {
    int codice;
    int valore;
    char desc[NDESC];
    int anno;
    int mese;
    int giorno;
} ComE;

Condominio * readcondomini(char *fileName, int *dim);

void stampa_condominio(Condominio c);

ComA * readComA(char *fileName, int *dim);

void stampaComA(ComA c);

ComE * readComE(char *fileName, int *dim);

void stampaComE(ComE c);

ComE * stampaCondominio(Condominio *c, int dimC,
                ComA *a, int dimA, ComE *e, int dimE);

#endif
