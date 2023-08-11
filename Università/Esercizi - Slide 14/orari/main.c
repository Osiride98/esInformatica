#include "orari.h"
#include "orari.c"

#define N 5

int main(){

    int n=2;

    // PARTE 1
    printf("PARTE 1 ====\n");

    orario o1;       // inizializzo due variabili contenenti la struttura di "orario"
    leggi_orario(&o1);

    stampa_orario(o1);

    // PARTE 2
    printf("PARTE 2 ====\n");
    orario o2;
    leggi_orario(&o2);

    int res = confronta_orario(o1, o2);
    printf("valore res = %d", res);

    orario l[N]; 

    if(res == -1){
        l[0] = o1;
        l[1] = o2;

        }else if(res == 1){
            l[0] = o2;
            l[1] = o1;
            }

    stampa_orari(l, n);

    // PARTE 3
    printf("PARTE 3 ====\n");

    orario t;

    for(int i = 0; i < 3; ++i) {
        leggi_orario(&t);
        inserisci_orario(l, &n, t);
    }
     stampa_orari(l, n);

}