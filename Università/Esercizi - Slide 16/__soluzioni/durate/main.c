#include <stdio.h>
#include "durate.h"

#define N 1024

int main() {
    Durata l[N];
    int n = 0;

    /* Leggo informazioni sulle durate */
    leggi_durate("durate.txt", l, &n); 
    /* stampo le informazioni sulle durate */
    stampa_durate("durate2.txt", l, n); 

    return 0;
}
