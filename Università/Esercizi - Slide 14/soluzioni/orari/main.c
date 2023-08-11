#include "orari.h"
#include "orari.c"

#define N 5

int main() {
    // PARTE 1: lettura di un singolo orario
    orario o;
    printf("PARTE 1 ====\n");
    leggi_orario(&o);
    stampa_orario(o);

    // PARTE 2: lettura di un secondo orario e confronto
    orario o2;
    printf("PARTE 2 ====\n");
    leggi_orario(&o2);
    int cmp = confronto_orario(o, o2);
    printf("Risultato del confronto: %d\n", cmp);

    // PARTE 3: inserimento manuale in array
    orario l[N];
    int n = 2; // in ogni caso inseriremo due orari
    printf("PARTE 3 ====\n");
    if (cmp <= 0) {
        l[0] = o;
        l[1] = o2;
    }
    else {
        l[0] = o2;
        l[1] = o;
    }
    stampa_orari(l, n);

    // PARTE 4: Inserisco 3 orari
    printf("PARTE 4 ====\n");
    orario t;
    for(int i = 0; i < 3; ++i) {
        leggi_orario(&t);
        inserisci_orario(l, &n, t);
    }
    stampa_orari(l, n);
}
