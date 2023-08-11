#include "prodotti.h"

#define NNOME 128
#define N 10
#define N2 2

int main() {
    prodotto listino[N];
    int n = N2;
    
    // Riempio il listino con N prodotti
    printf("PARTE 1 ==== \n");
    for(int i = 0; i < n; ++i)
        listino[i] = leggi_prodotto();
    stampa_prodotti(listino, n);

    // Cerco un prodotto
    char nome[NNOME];
    printf("PARTE 2 ==== \n");
    printf("Inserire il nome di un prodotto da cercare: ");
    scanf("%s", nome);
    int pos = trova_prodotto(nome, listino, n);
    if (pos == n)
        printf("Prodotto non trovato\n");
    else
        printf("Prodotto trovato in posizione %d\n", pos);

    // Leggo ed inserisco un prodotto
    printf("PARTE 3 ==== \n");
    prodotto p = leggi_prodotto();
    pos = inserisci_prodotto(p, listino, &n);
    printf("Prodotto inserito in posizione %d\n", pos);
    stampa_prodotti(listino, n);
}
