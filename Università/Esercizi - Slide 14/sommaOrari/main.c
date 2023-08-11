#include "orari.h"
#include "orari.c"
#include "somma_orari.h"
#include "somma_orari.c"

#define N 3

#define N 3

int main(int argc, char *argv[]) {
    orario orari[N];
    int n = 0; // Dimensione logica iniziale
    orario o;

    // Leggo & inserisco in ordine tre orari
    for(int i  = 0; i < N; ++i) {
        // Leggo un orario
        leggi_orario(&o);
        // Lo inserisco nell'array, rispettando l'ordine
        inserisci_orario(orari, &n, o);
    }

    // Parto dall'orario iniziale
    orario s = orari[0];
    // Sommo i rimanenti
    for(int i = 1; i < N; ++i)
        s = somma_orari(s, orari[i]);
    // Stampo il risultato
    printf("Somma: ");
    stampa_orario(s);
}