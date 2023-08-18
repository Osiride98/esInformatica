#ifndef PERSONE_H
#define PERSONE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 255

typedef struct{
    char nome[MAX_CHAR];
    char cognome[MAX_CHAR];
}persona;

persona leggi_persona();

void stampa_persona(persona *array, int n); // ricorda di definire le variabili che passi

void ordina_persone(persona *array, int n);

void swap(persona *a, persona *b);

int bubble_sort(persona v[], int n);

#endif