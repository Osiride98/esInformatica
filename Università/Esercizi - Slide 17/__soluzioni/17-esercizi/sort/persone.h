#ifndef PERSONE_H_
#define PERSONE_H_

#include <stdio.h>
#include <string.h>

#define NS 256

typedef struct {
	char nome[NS];
	char cognome[NS];
} Persona;

Persona leggi_persona();
void stampa_persona(Persona p);
void ordina_persone(Persona *p, int n);

#endif
