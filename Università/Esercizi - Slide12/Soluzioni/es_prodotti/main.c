#include <stdio.h>
#include <string.h>

#define NNOME 128
#define N 10
#define N2 2

typedef struct {
    char nome[NNOME];
    float prezzo;
} prodotto;

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
