#include "prodotti.h"

prodotto leggi_prodotto() {
    prodotto res;
    printf("Inserire nome e prezzo: ");
    scanf("%s%f", res.nome, &res.prezzo);
    return res;
}

void stampa_prodotti(prodotto* l, int n) {
    printf("\nPRODOTTI:\n");
    for(int i = 0; i < n; ++i)
        printf("%s %.2f\n", l[i].nome, l[i].prezzo);
    printf("\n");
}

int trova_prodotto(char * nome, prodotto *l, int n) {
    int i;
    for(i = 0; i < n; ++i) {
        if (strcmp(l[i].nome, nome) == 0)
            break;
    }
    return i;
}

int inserisci_prodotto(prodotto p, prodotto *l, int *n) {
    // Determino se il prodotto sia presente
    int pos = trova_prodotto(p.nome, l, *n);
    // Inserisco o rimpiazzo il prodotto
    l[pos] = p;
    // Se il prodotto è nuovo, aggiorno la dimensione logica
    if (pos == *n)
        *n += 1;
    // Restituisco la posizione di inserimento
    return pos;
}

