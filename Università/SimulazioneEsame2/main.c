#include "compagnia_navi.h"

int main(void)
{
    nave *n;
    partenza *p;
    int i, num_n, num_p, writeRes;
    FILE *fp;

    //test esercizio 1
    n = leggi_navi("navi.txt", &num_n);
    printf("\nElenco Navi:\n");
    for (i = 0; i < num_n; i++)
        stampa_nave(n[i]);
    printf("\nElenco Partenze:\n");
    p = leggi_partenze("partenze.txt", &num_p);
    for (i = 0; i < num_p; i++)
        stampa_partenza(p[i]);

    //test esercizio 2
    if((fp = fopen("partenze.txt", "a+")) == NULL){
        printf("Impossibile aprire il file partenze.txt");
        exit(1);
    }
    writeRes = nuova_partenza(fp, n, num_n);
    printf("\nRisultato inserimento: %d", writeRes);
    fclose(fp);
    
    // test esercizio 3
    ordina_partenze(p, num_p);
    printf("\nPartenze ordinate:\n");
    for (i = 0; i < num_p; i++)
        stampa_partenza(p[i]);

    free(n);
    free(p);
    
    return 0;
}
