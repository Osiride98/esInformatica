#include "prodotti.h"
#include "prodotti.c"

int main (){

//PARTE 1 

printf("---Parte 1---\n");

prodotto p;
prodotto arrayProdotti[N];

for (int i = 0; i <= N; i++){

    leggi_prodotto(&p);

    arrayProdotti[i] = p;
}

stampa_prodotti(arrayProdotti, N);

// PARTE 2

printf("---Parte 2---\n");

int n = N;

char newProdotto [MAX_LENGHT];

printf("Inserisci prodotto da cercare :");
scanf("%s", &newProdotto);

trova_prodotto(newProdotto, arrayProdotti, n);


// PARTE 3

printf("---Parte 3---\n");

prodotto p1;

leggi_prodotto(&p1);

inserisci_prodotto(p1, arrayProdotti, &n);

stampa_prodotti(arrayProdotti, n);

}
