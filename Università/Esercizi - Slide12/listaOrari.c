#include<stdio.h>
#include<string.h>
#include "sort.h"

typedef struct {
    int ore;
    int minuti;
}orario;

void leggi_orario(orario *o){           // in questa funzione utilizzo "*o" puntatore perchè con lo scanf devo andare a scrivere all'interno della cella di memoria negli indirizzi
    printf("Indicare Ora hh =>");
    scanf("%d", &o->ore, &o->minuti);

    printf("Indicare minuti mm =>");
    scanf("%d", &o->minuti);
}

void stampa_orario(orario o){
    printf("Sono le %d:%d", o.ore, o.minuti);
}

int confronta_orario(orario o1, orario o2, int *res){


    if(o1.ore == o2.ore && o1.minuti == o2.minuti){             // nelle condizione degli if devo andare a leggere all'interno delle celle di memoria !!
        printf("sono gli stessi orari\n");
            return *res;

            }else if(o1.ore == o2.ore && o1.minuti<o2.minuti || o1.ore < o2.ore){
                printf("o1 precede o2\n");
                *res = -1;
                return *res;

                    }else if(o1.ore == o2.ore && o1.minuti > o2.minuti || o1.ore > o2.ore){
                        printf("o2 precede o1\n");
                        *res = 1;
                        return *res;
                        }           
}

void inserisci_orario(orario *l, int *n, orario *o) {

    int i, j;

    *n = (*n) + 1;

    printf("Inserisci Ora hh => ");
    scanf("%d", &(o->ore));

    printf("Inserisci minuti mm => ");
    scanf("%d", &(o->minuti));

    for (i = 1; i < *n; i++) {
        
        orario key = *o;

        j = i - 1;

        while (j >= 0 && l[j].ore > key.ore) {                   // Sposta gli elementi dell'array che sono maggiori di key verso la loro posizione corretta nella parte ordinata
            l[j + 1] = l[j];
            j = j - 1;
        }
        l[j + 1] = key;
    }
   

    for(int k = 0; k < *n ; k++){
        printf("Stampo arrayOrari = %d : %d\n", l[k].ore, l[k].minuti);
    }
}

int main(){

    int n=2 , res=0;

    int *r = &res;

    orario o1, o2;          // inizializzo due variabili contenenti la struttura di "orario"

    orario o;

    orario *l[n];           // inizializzo un array puntatore orario

    leggi_orario(&o1);
    leggi_orario(&o2);

    confronta_orario(o1, o2, &res);

    inserisci_orario(*l, &n, &o);

    printf("valore res = %d", *r);

    for(int k = 0; k < n ; k++){
        printf("Stampo arrayOrari = %d : %d\n", l[k]->ore, l[k]->minuti);
    }
}
            
            

