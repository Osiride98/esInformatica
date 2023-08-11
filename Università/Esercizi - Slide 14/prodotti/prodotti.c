#include "prodotti.h"

void leggi_prodotto(prodotto *p){

    printf("\nInserire Nome Prodotto = ");
    scanf("%s", p->nome);

    printf("\nInserire Importo Prodotto = ");
    scanf("%f", &p->prezzo);

}

void stampa_prodotti(prodotto* l, int n){

    for (int i = 0; i <= n; i++){
        printf("prodotto %d -> nome %s - prezzo %.3f\n", i+1, l[i].nome, l[i].prezzo);
    }
}

int trova_prodotto(char *p, prodotto *l, int n){

    int research = 0;
    
    for(int k = 0; k <= n ; k++){
       
        if(strcmp(p,l[k].nome)==0){
            printf("%s presente\n");
            research = 1;
            }
    }
    if(research == 0){
    printf("Assente\n");
        }
}

int inserisci_prodotto(prodotto p, prodotto *l, int *n){

    int countPos = 0;
    int prod = 0; 

    for(int k = 0; k <= *n ; k++){

        countPos = k;

        if(strcmp(p.nome,l[k].nome)==0){
            l[k] = p;
            prod = 1;
        }
    }

    if( prod == 0){

        if(countPos==*n){//printf("valore di n 1 -> %d\n", *n);
            *n = *n +1;
            l[*n] = p;
        }

    printf("posizione lista %d\n", *n+1);
    }
}
