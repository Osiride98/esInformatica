#include<stdio.h>
#include<string.h>

#define N 1
#define MAX_LENGHT 127
typedef struct{
    char nome [MAX_LENGHT];
    float prezzo;
}prodotto;

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

//printf("valore di n fuori = %d\n", n);

inserisci_prodotto(p1, arrayProdotti, &n);

//printf("valore di n fuori 2 = %d\n", n);

stampa_prodotti(arrayProdotti, n);

}
